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

	while(close==false)
	{
		while(SDL_PollEvent( &Evento )!=0)
		{
			if(Evento.type == SDL_QUIT)
			{
				close =true;
			}
			if(Evento.type == SDL_KEYDOWN)
			{
				switch(Evento.key.keysym.sym)
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
			if(Evento.type == SDL_KEYUP)
			{
				switch(Evento.key.keysym.sym)
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
			//			if(Evento.type == SDL_KEYUP)
			//			{
			//				switch(Evento.key.keysym.sym)
			//				{
			//					case(asd):
			//						break;
			//				}
			//			}
		}
		
		if(FPESSES +10 < SDL_GetTicks())
		{
			if(player_getCima(player))
			{
				if(player_getY(player)-player_getVelocidade(player) > 0 && player_getY(player)-player_getVelocidade(player)< tela_getHeight(tela))
					player_setY(player, player_getY(player)-player_getVelocidade(player));
			}
			if(player_getBaixo(player))
			{
				if(player_getY(player)+player_getVelocidade(player) > 0 && player_getY(player)+player_getVelocidade(player)< tela_getHeight(tela))
					player_setY(player, player_getY(player)+player_getVelocidade(player));
			}
			if(player_getEsquerda(player))
			{
				if(player_getX(player)-player_getVelocidade(player) > 0 && player_getX(player)-player_getVelocidade(player)< tela_getWidth(tela))
					player_setX(player, player_getX(player)-player_getVelocidade(player));
			}
			if(player_getDireita(player))
			{
				if(player_getX(player)+player_getVelocidade(player) > 0 && player_getX(player)+player_getVelocidade(player)< tela_getWidth(tela))
					player_setX(player, player_getX(player)+player_getVelocidade(player));
			}
			FPESSES = SDL_GetTicks();
		}

		SDL_RenderClear(tela_getRenderizador(tela));
		SDL_RenderCopy( tela_getRenderizador(tela), player_getTextura(player), NULL, player_getPosicao(player));
		SDL_RenderPresent(tela_getRenderizador(tela));
		//	SDL_FillRect( tela_fundo, NULL, SDL_MapRGB( tela_fundo->format, 32, 44, 100 ));
		//		SDL_UpdateWindowSurface( window );
	}

	delete_tela(tela);
	delete_player(player);
//	sair(window);

	return 0;
}
