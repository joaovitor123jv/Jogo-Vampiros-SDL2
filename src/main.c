#include"Includes.h"

void sair(SDL_Window *janela);

int main( int argc, char* args[] )
{
	//	char nomejanela[32] = "Teste de Jogo";
	//	SDL_Window *window = NULL;
	//	SDL_Surface *screenSurface = NULL;
	//	SDL_Event Evento;
	
	
	unsigned short close=false;
	int FPESSES;
	int w, h;
	Player* player = new_player();
	
	Tela* tela = new_tela();
	tela_setTitle(tela, "Teste de orientação a objetos em C ");
	tela_setSize(tela, 800, 600);
	

	player_setVelocidade(player,  5);
	player_setTextura(player, tela, "images/sprites/player.png");
	player_setX(player, 10);
	player_setY(player, 10);
	player_toString(player);

	FPESSES = SDL_GetTicks();

	while(!close)
	{
		while(tela_getEvento(tela))
		{
			close = tela_getSair(tela);
			if(tela_getTeclaApertada(tela))
			{
				printf("Tecla apertada");
				switch(tela_getTecla(tela))
				{
					case(SDLK_w):
						player_setCima(player,true);
						break;
					case(SDLK_a):
						player_setEsquerda(player, true);
						break;
					case(SDLK_s):
						player_setBaixo(player, true);
						break;
					case(SDLK_d):
						player_setDireita(player, true);
						break;
					default:
						break;
				}
			}
			if(tela_getTeclaSolta(tela) == true)
			{
				printf("Tecla Solta");
				switch(tela_getTecla(tela))
				{
					case(SDLK_w):
						player_setCima(player,false);
						break;
					case(SDLK_a):
						player_setEsquerda(player, false);
						break;
					case(SDLK_s):
						player_setBaixo(player, false);
						break;
					case(SDLK_d):
						player_setDireita(player, false);
						break;
					default:
						break;
				}
			}
		}
		
		if(FPESSES +10 < SDL_GetTicks())
		{
			player_movimenta(player, tela);//Leia: player se movimenta pela tela
			FPESSES = SDL_GetTicks();
		}

		SDL_RenderClear(tela_getRenderizador(tela));
		player_print(player, tela);
		SDL_RenderPresent(tela_getRenderizador(tela));
	}

	delete_tela(tela);
	delete_player(player);
//	sair(window);

	return 0;
}
