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


//CONSTRUTOR
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

//DESTRUTOR
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


//SETTERS
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



//GETTERS
int tela_getWidth(Tela* tela)
{
	return tela->width;
}

int tela_getHeight(Tela* tela)
{
	return tela->height;
}

bool tela_getSair(Tela* tela)
{
	if(tela == NULL)
	{
		return true;
	}
	if(tela->evento.type == SDL_QUIT)
	{
		return true;
	}
	return false;
}

bool tela_getEvento(Tela* tela)
{
	return SDL_PollEvent( &tela->evento );
}

SDL_Renderer* tela_getRenderizador(Tela* tela)
{
	return tela->renderizador;
}

SDL_EventType tela_getTipoEvento(Tela* tela)
{
	if(tela != NULL)
	{
		return tela->evento.type;
	}
}

SDL_Keycode tela_getTecla(Tela* tela)
{
	if(tela != NULL)
	{
		return tela->evento.key.keysym.sym;
	}
}

bool tela_getTeclaApertada(Tela* tela)
{
	if(tela->evento.type == SDL_KEYDOWN)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool tela_getTeclaSolta(Tela* tela)
{
	if(tela_getTipoEvento(tela) == SDL_KEYUP)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//COMANDOS
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

void tela_update(Tela* tela)
{
	if(tela != NULL)
	{
		SDL_RenderPresent(tela->renderizador);
	}
}

void tela_limpa(Tela* tela)
{
	if(tela !=NULL)
	{
		SDL_RenderClear(tela->renderizador);
	}
}
