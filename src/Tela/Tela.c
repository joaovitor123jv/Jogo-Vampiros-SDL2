#include"Tela.h"
#include<SDL2/SDL_image.h>/* To use the IMG_Quit */
#define TAMANHO_MAXIMO_TITULO 200;

struct Tela
{
	SDL_Color cor;
	SDL_Surface *tela;
	SDL_Window *janela;
	char *titulo;
	SDL_Event evento;
	SDL_Point mouse;
	SDL_Renderer *renderizador;
	unsigned int width;
	unsigned int height;
};


/*CONSTRUTOR*/
Tela* new_tela(void)
{
	Tela* tela = malloc(sizeof(Tela));
	if(tela == NULL)
	{
		return NULL;
	}
	if(SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		printf(" EM: Tela->new_tela()\n");
		printf(" \tERRO: Failed to init SDL2, aborting\n");
		return NULL;
	}
	tela->width = 100;
	tela->height = 100;
	tela->titulo = "Janela";
	tela->cor.r = 50;
	tela->cor.g = 150;
	tela->cor.b = 90;
	tela->cor.a = 0xFF;
	tela->mouse.x = 0;
	tela->mouse.y = 0;
	if(tela_upgrade(tela) == ERRO)
	{
		return NULL;
	}
	return tela;
}

/*DESTRUTOR*/
int delete_tela(Tela* tela)
{
	if(tela == NULL)
	{
		return TELA_NAO_INICIALIZADA;
	}
	SDL_Quit();
	IMG_Quit();
	SDL_DestroyWindow(tela->janela);
	if(tela->janela != NULL)
	{
		tela->janela = NULL;
	}
	if(tela->tela != NULL)
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


/*SETTERS*/
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

bool tela_setFullScreen(Tela* tela)
{
	if(tela == NULL)
	{
		return false;
	}
	if(SDL_GetWindowFlags(tela->janela) != SDL_WINDOW_FULLSCREEN)
	{
		SDL_SetWindowFullscreen(tela->janela, SDL_WINDOW_FULLSCREEN);
	}
	return true;
}

int tela_setTitle(Tela* tela, char *titulo)
{
	if(tela == NULL)
	{
		return TELA_NAO_INICIALIZADA;
	}
	if(titulo == NULL)
	{
		tela->titulo = " ";
	}
	tela->titulo = titulo;
	return OK;
}

int tela_setCor(Tela* tela, int r, int g, int b)
{
	if(tela == NULL)
	{
		return TELA_NAO_INICIALIZADA;
	}
	tela->cor.g = g;
	tela->cor.r = r;
	tela->cor.b = b;
}

int tela_setAlpha(Tela* tela, int alpha)
{
	if(tela == NULL)
	{
		return TELA_NAO_INICIALIZADA;
	}
	tela->cor.a = alpha;
}



/*GETTERS*/
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

void tela_getMousePos(Tela* tela, int *x, int *y)
{
	if(tela == NULL)
	{
		return;
	}
	*x = tela->mouse.x;
	*y = tela->mouse.y;
}


SDL_Renderer* tela_getRenderizador(Tela* tela)
{
	return tela->renderizador;
}

SDL_Window* tela_getJanela(Tela* tela)
{
	if(tela == NULL)
	{
		printf("ERRO, tela não inicializada\n");
		return NULL;
	}
	return tela->janela;
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

void tela_getMouse(Tela* tela)
{
	if(tela == NULL)
	{
		return;
	}
	SDL_GetMouseState(&tela->mouse.x, &tela->mouse.y);
}

bool tela_getTeclaApertada(Tela* tela)
{
	if(tela == NULL)
	{
		return false;
	}
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
	if(tela == NULL)
	{
		return false;
	}
	if(tela_getTipoEvento(tela) == SDL_KEYUP)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool tela_getMovimentoMouse(Tela* tela)
{
	if(tela == NULL)
	{
		return false;
	}
	if(tela_getTipoEvento(tela) == SDL_MOUSEMOTION)
	{
		return true;
	}
	else
	{
		return false;
	}
}


SDL_Event* tela_getEventoRaw(Tela* tela)
{
	if(tela == NULL)
	{
		return NULL;
	}
	return &tela->evento;
}



/*COMANDOS*/
int tela_upgrade(Tela* tela)
{
	if(tela == NULL)
	{
		printf("Em: Tela->tela_upgrade(Tela*))\n");
		printf("\t Tela == NULL\n");
		return ERRO;
	}
	if(tela->janela != NULL)
	{
		SDL_DestroyWindow(tela->janela);
	}
	tela->janela = SDL_CreateWindow(tela->titulo, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, tela->width, tela->height, SDL_WINDOW_BORDERLESS);
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
	SDL_SetRenderDrawColor(tela->renderizador, tela->cor.r, tela->cor.g, tela->cor.b, tela->cor.a);
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
		SDL_SetRenderDrawColor(tela->renderizador, tela->cor.r, tela->cor.g, tela->cor.b, tela->cor.a);
		SDL_RenderClear(tela->renderizador);
	}
}
