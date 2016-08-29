#include"Tela.h"
#define TAMANHO_MAXIMO_TITULO 200;

struct Tela
{
	SDL_Surface *tela;
	SDL_Window *janela;
	char *titulo;
	SDL_Event evento;
	SDL_Renderer *renderizador;
	unsigned int width;
	unsigned int height;
};


int tela_upgrade(Tela* tela)
{
	SDL_DestroyWindow(tela->janela);
	tela->janela = SDL_CreateWindow(tela->titulo, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, tela->width, tela->height, SDL_WINDOW_OPENGL);
	if(tela->janela == NULL)
	{
		printf("Erro ao inicializar janela\n");
		return ERRO;
	}
	tela->renderizador = SDL_CreateRenderer( tela->janela, -1, SDL_RENDERER_ACCELERATED);
	if(tela->renderizador == NULL)
	{
		printf("Erro ao renderizar janela\n");
		return ERRO;
	}
	SDL_SetRenderDrawColor(tela->renderizador, 0, 134, 140, 0);
	return  OK;
}

Tela* new_tela(void)
{
	Tela* tela = malloc(sizeof(Tela));
	if(tela == NULL)
	{
		return NULL;
	}
	tela->width = 100;
	tela->height = 100;
	tela->titulo = "Janela";
	if(tela_upgrade(tela) == ERRO)
	{
		return NULL;
	}
	return tela;
}


int tela_setSize(Tela* tela, int width, int height)
{
	if(tela == NULL)
	{
		return TELA_NAO_INICIALIZADA;
	}
	tela->width = width;
	tela->height = height;
	return tela_upgrade(tela);
}

int tela_setTitle(Tela* tela, char *titulo)
{
	if(tela == NULL)
	{
		return TELA_NAO_INICIALIZADA;
	}
	tela->titulo = titulo;
}


int delete_tela(Tela* tela)
{
	if(tela == NULL)
	{
		return TELA_NAO_INICIALIZADA;
	}
	SDL_Quit();
	SDL_DestroyWindow(tela->janela);
	if(tela->janela != NULL)
	{
		tela->janela = NULL;
	}
	if(tela->tela == NULL)
	{
		SDL_FreeSurface(tela->tela);
	}
	free(tela);
	if(tela != NULL)
	{
		tela = NULL;
	}
	return OK;
}


int tela_getWidth(Tela* tela)
{
	return tela->width;
}

int tela_getHeight(Tela* tela)
{
	return tela->height;
}

SDL_Renderer* tela_getRenderizador(Tela* tela)
{
	return tela->renderizador;
}
