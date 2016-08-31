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
	Texto* texto = new_texto();
	
	Tela* tela = new_tela();
	tela_setTitle(tela, "Teste de orientação a objetos em C ");
	tela_setSize(tela, 800, 600);
	
	texto_setFonte(texto, "fonte.ttf", 50);
	SDL_Color cor;
	cor.r = 10;
	cor.g = 50;
	cor.b = 100;
	texto_setCor(texto, 10, 50, 100);
	texto_setTexto(texto, "Testando");
	texto_updateTexto(texto,tela);
	texto_setPosicao(texto, 200, 300);

	player_setVelocidade(player,  5);
	player_setTextura(player, tela, "images/sprites/player.png");
	player_setX(player, 10);
	player_setY(player, 10);

	player_toString(player);
	texto_toString(texto);
	FPESSES = SDL_GetTicks();

	while(!close)
	{
		while(tela_getEvento(tela))
		{
			close = tela_getSair(tela);
			if(tela_getTeclaApertada(tela))
			{
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

		tela_limpa(tela);
		player_print(player, tela);
		texto_print(texto, tela);
		tela_update(tela);
	}

	delete_texto(texto);
	delete_tela(tela);
	delete_player(player);
//	sair(window);

	return 0;
}
