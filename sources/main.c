#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_mixer.h>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "estruturas.h"

const unsigned short false = 0;
const unsigned short true = 1;

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600; 
void sair(SDL_Window *janela);

int main( int argc, char* args[] )
{
	//	char nomejanela[32] = "Teste de Jogo";
	//	SDL_Window *window = NULL;
	//	SDL_Surface *screenSurface = NULL;
	//	SDL_Event Evento;
	
	sprite player;
	player.velocidade = 4;
	
	int FPESSES;
	unsigned short int cima=false, baixo=false, esquerda=false, direita=false;
	
	
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "Erro ao inicializar SDL, código => %s\n", SDL_GetError() );
	}
	else
	{
		window = SDL_CreateWindow( nomejanela, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL );
		if( window == NULL )
		{
			printf("Erro ao inicializar Janela, código => %s\n", SDL_GetError() );
		}
		else
		{
			//			tela_fundo = SDL_GetWindowSurface( window );
			Renderizador = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
			if(Renderizador == NULL)
			{
				printf("Erro, janela Renderizada nao foi criada , %s\n", SDL_GetError());
			}
			else
			{
				SDL_SetRenderDrawColor( Renderizador, 0, 134, 140, 0);
				player.textura = IMG_LoadTexture( Renderizador, "images/sprites/player.png");
				SDL_QueryTexture(player.textura, NULL, NULL, &player.w, &player.h);
				player.x = 10;
				player.y = 10;
				player.posicao.w = player.w;
				player.posicao.h = player.h;
				player.posicao.x = player.x;
				player.posicao.y = player.y;
			}
		}
	}
	FPESSES = SDL_GetTicks();
	unsigned short close=false;
	printf("Close = %d\n", close);
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
						cima = true;
						break;
					case(SDLK_a):
						esquerda = true;
						break;
					case(SDLK_s):
						baixo = true;
						break;
					case(SDLK_d):
						direita = true;
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
						cima = false;
						break;
					case(SDLK_a):
						esquerda = false;
						break;
					case(SDLK_s):
						baixo = false;
						break;
					case(SDLK_d):
						direita = false;
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
			if(cima == true )
			{
				if(player.posicao.y-player.velocidade > 0 && player.posicao.y-player.velocidade< SCREEN_HEIGHT)
					player.posicao.y -= player.velocidade;
			}
			if(baixo == true)
			{
				if(player.posicao.y+player.velocidade > 0 && player.posicao.y+player.velocidade< SCREEN_HEIGHT)
					player.posicao.y += player.velocidade;
			}
			if(esquerda == true)
			{
				if(player.posicao.x-player.velocidade > 0 && player.posicao.x-player.velocidade< SCREEN_WIDTH)
					player.posicao.x -= player.velocidade;
			}
			if(direita == true)
			{
				if(player.posicao.x+player.velocidade > 0 && player.posicao.x+player.velocidade< SCREEN_WIDTH)
					player.posicao.x += player.velocidade;
			}
			FPESSES = SDL_GetTicks();
		}

		SDL_RenderClear(Renderizador);
		SDL_RenderCopy( Renderizador, player.textura, NULL, &player.posicao);
		SDL_RenderPresent(Renderizador);
		//	SDL_FillRect( tela_fundo, NULL, SDL_MapRGB( tela_fundo->format, 32, 44, 100 ));
		//		SDL_UpdateWindowSurface( window );
	}

	sair(window);

	return 0;
}

void sair(SDL_Window *janela)
{
	SDL_DestroyWindow(janela);
	SDL_Quit();
}
