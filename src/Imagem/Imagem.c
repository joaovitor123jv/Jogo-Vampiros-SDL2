#include"Imagem.h"

struct Imagem
{
	SDL_Rect posicao;
	SDL_Texture* textura;
	bool haveTransparency;
	int rTransparency;
	int gTransparency;
	int bTransparency;
	char* endereco;
};


/*CONSTRUTOR*/
Imagem* new_imagem(void)
{
	Imagem* imagem = malloc(sizeof(Imagem));
	int flags, initted;
	if(imagem == NULL)
	{
		printf(" EM: Imagem->new_imagem()\n");
		printf(" \tERROR: Couldn't initialize Image, aborting\n");
		return NULL;
	}
	flags = IMG_INIT_PNG|IMG_INIT_JPG;
	initted = IMG_Init(flags);
	if(initted&flags != flags)
	{
		printf(" EM: Imagem->new_imagem()\n");
		printf(" \tFailed to load PNG and JPG support\n");
		printf(" \tERROR: %s\n", IMG_GetError());
		return;
	}
	imagem->posicao.x = 0;
	imagem->posicao.y = 0;
	imagem->posicao.w = 0;
	imagem->posicao.h = 0;
	imagem->textura = NULL;
	imagem->endereco = NULL;
	imagem->haveTransparency = false;
	return imagem;
}

/*DESTRUTOR*/
void delete_imagem(Imagem* imagem)
{
	if(imagem == NULL)
	{
		printf("Imagem não inicializada\n");
		return;
	}
	if(imagem->textura != NULL)
	{
		SDL_DestroyTexture(imagem->textura);
	}
	if(imagem->endereco != NULL)
	{
		imagem->endereco = NULL;
	}
	free(imagem);
	imagem = NULL;
}

/*COMANDOS*/
void imagem_print(Imagem* imagem, Tela* tela)
{
	if(imagem == NULL || tela == NULL)
	{
		printf(" EM: Imagem-> imagem_print(Imagem*, Tela*)\n");
		printf("\tERRO: Tela e/ou Imagem não inicializados \n");
		return;
	}
	SDL_RenderCopyEx(tela_getRenderizador(tela), imagem->textura, NULL, &imagem->posicao, 0.0,  NULL, SDL_FLIP_NONE);
}

void imagem_printPart(Imagem* imagem, Tela* tela, SDL_Rect corte)
{
	SDL_Rect quadrado;
	if(imagem == NULL)
	{
		printf(" EM: Imagem-> imagem_printPart(Imagem*, Tela*, SDL_Rect)\n");
		printf(" \tERRO: argumento Imagem* == NULL, abortando\n");
		return;
	}
	if(tela == NULL)
	{
		printf(" EM: Imagem-> imagem_printPart(Imagem*, Tela*, SDL_Rect)\n");
		printf(" \tERRO: argumento Imagem* == NULL, abortando\n");
		return;
	}
	if(&corte == NULL)
	{
		printf(" EM: Imagem-> imagem_printPart(Imagem*, Tela*, SDL_Rect)\n");
		printf(" \tArgumento SDL_Rect inválido\n");
	}
	quadrado.x = imagem->posicao.x;
	quadrado.y = imagem->posicao.y;
	quadrado.w = corte.w;
	quadrado.h = corte.h;
	SDL_RenderCopy(tela_getRenderizador(tela), imagem->textura, &corte, &quadrado);/* Renderizador, textura, recorte, quadrado */
	/* SDL_RenerCopyEx(tela_getRenderizador(tela), imagem->textura, NULL, &quadrado, ,&corte, 0); */
	return;
}

SDL_Surface* imagem_carregaImagem(Imagem* imagem, Tela* tela, char* endereco)
{
	if(imagem == NULL || tela == NULL)
	{
		printf("Imagem ou Tela não inicializada\n");
		return NULL;
	}
	if(endereco == NULL)
	{
		printf("Endereço inválido\n");
		return NULL;
	}
	int tamanho;
	tamanho = strlen(endereco);
	if(!(tamanho < TAMANHO_MAX_ENDERECO))
	{
		printf("Endereco muito grande\n");
		return NULL;
	}
	imagem->endereco = malloc(tamanho * sizeof(char));
/*	imagem->endereco = endereco;*/
	strcpy(imagem->endereco, endereco);
	if(imagem->endereco == NULL)
	{
		printf("ERRO, não foi possível armazenar o endereço da imagem (memória insuficiente)\n");
		return NULL;
	}
	
	SDL_Surface* surfaceOtimizada = NULL;
	SDL_Surface* surfacePrimaria = NULL;
	surfacePrimaria = IMG_Load(imagem->endereco);
	if(surfacePrimaria == NULL)
	{
		printf("Não foi possível carregar a imagem (1) \n");
		return NULL;
	}

	if(imagem->haveTransparency)/* Suporte a transparencia mesmo em não png */
	{
		SDL_SetColorKey(surfacePrimaria, SDL_TRUE, SDL_MapRGB(surfacePrimaria->format, imagem->rTransparency, imagem->gTransparency, imagem->bTransparency));
	}

	surfaceOtimizada = SDL_ConvertSurface( surfacePrimaria, SDL_GetWindowSurface(tela_getJanela(tela))->format , 0);
	if(surfaceOtimizada == NULL)
	{
		printf("Não foi possível otimizar imagem em relação à sua tela \n");
		return NULL;
	}
	SDL_FreeSurface(surfacePrimaria);
	return surfaceOtimizada;

}

/*SETTERS*/
void imagem_setTransparencyColor(Imagem* imagem, int r, int g, int b)
{
	if(imagem == NULL)
	{
		printf(" At: Imagem-> imagem_setTransparencyColor(Imagem*, int, int, int)\n");
		printf(" \tERROR: Imagem* == NULL, aborting\n");
		return;
	}
	if(!((r >= 0 && r < 256) && (g >= 0 && g < 256) && (b >= 0 && b < 256)))
	{
		printf(" At: Imagem-> imagem_setTransparencyColor(Imagem*, int, int, int)\n");
		printf(" \tERROR: int argument must e positive and not bigger than 255, aborting\n");
		return;
	}
	imagem->haveTransparency = true;
	imagem->rTransparency=r;
	imagem->gTransparency=g;
	imagem->bTransparency=b;
	return;
}

void imagem_setPosicao(Imagem* imagem, int x, int y)
{
	if(imagem == NULL)
	{
		printf(" At: Imagem-> imagem_setPosicao\n");
		printf(" \tImagem not initialized, aborting\n");
		return;
	}
	imagem->posicao.x = x;
	imagem->posicao.y = y;
	return;
}

bool imagem_setTamanho(Imagem* imagem, int w, int h)
{
	if(imagem == NULL)
	{
		printf(" EM: Imagem-> imagem_setTamanho(Imagem*, int, int)\n");
		printf(" \tERRO: argumento Imagem* == NULL, abortando\n");
		return false;
	}
	/* 
	if(tela == NULL)
	{
		printf(" EM: Imagem-> imagem_setImagem(Imagem*, Tela*, char*)\n");
		printf(" \tERRO: Argumento Tela* == NULL, abortando\n");
		return false;
		}*/
	if(w < 0  || h < 0)
	{
		printf(" EM: Imagem-> imagem_setTamanho(Imagem*, int, int)\n");
		printf(" \tERRO: Argumento \"int\" não pode ser negativo, abortando\n");
		return false;
	}
	/*
	SDL_Surface* surface = imagem_carregaImagem(imagem, tela, imagem->endereco);
	if(surface == NULL)
	{
		printf("ERRO: Não foi possível carregar imagem\n");
		return false;
	}
	imagem_getTamanhoSurface(imagem, surface->w, surface->h);
	if(imagem->textura != NULL)
	{
		SDL_DestroyTexture(imagem->textura);
		imagem->textura == NULL;
	}
	imagem->textura = SDL_CreateTextureFromSurface(tela_getRenderizador(tela), surface);
	SDL_FreeSurface(surface);
	if(imagem->textura == NULL)
	{
		printf("Erro ao converter para textura\n");
		return false;
	}
	*/
/*	SDL_QueryTexture(imagem->textura, NULL, NULL, &w, &h);*/
	imagem->posicao.w = w;
	imagem->posicao.h = h;
	return true;
}


bool imagem_setImagem(Imagem* imagem, Tela* tela, char* endereco)
{
	if(imagem == NULL)
	{
		printf(" EM: Imagem-> imagem_setImagem(Imagem*, Tela*, char*)\n");
		printf(" \tERRO: Argumento Imagem* == NULL, abortando\n");
		return false;
	}
	if(tela == NULL)
	{
		printf(" EM: Imagem-> imagem_setImagem(Imagem*, Tela*, char*)\n");
		printf(" \tERRO: Argumento Tela* == NULL, abortando\n");
		return false;
	}
	if(endereco == NULL)
	{
		printf(" EM: Imagem-> imagem_setImagem(Imagem*, Tela*, char*)\n");
		printf(" \tERRO: Argumento char* == NULL, abortando\n");
		return false;
	}
	SDL_Surface* surface = imagem_carregaImagem(imagem, tela, endereco);
	if(surface == NULL)
	{
		printf("ERRO: Não foi possível carregar imagem\n");
		return false;
	}
	imagem_getTamanhoSurface(imagem, surface->w, surface->h);
	if(imagem->textura != NULL)
	{
		SDL_DestroyTexture(imagem->textura);
		imagem->textura == NULL;
	}
	imagem->textura = SDL_CreateTextureFromSurface(tela_getRenderizador(tela), surface);
	SDL_FreeSurface(surface);
	if(imagem->textura == NULL)
	{
		printf("Erro ao converter para textura\n");
		return false;
	}
	return true;
}

/* GETTERS */

void imagem_getTamanhoSurface(Imagem* imagem, int w, int h)
{
	if(imagem == NULL)
	{
		printf("Imagem não inicializada\n");
		return;
	}
	imagem->posicao.h = h;
	imagem->posicao.w = w;
	return;
}

int imagem_getWidth(Imagem* imagem)
{
	if(imagem == NULL)
	{
		printf(" EM: Imagem-> imagem_getWidth(Imagem*)\n");
		printf(" \tArgumento Imagem* == NULL, abortando\n");
		return -1;
	}
	return imagem->posicao.w;
}

int imagem_getHeight(Imagem* imagem)
{
	if(imagem == NULL)
	{
		printf(" EM: Imagem-> imagem_getHeight(Imagem*)\n");
		printf(" \tArgumento Imagem* == NULL, abortando\n");
		return -1;
	}
	return imagem->posicao.h;
}

int imagem_getX(Imagem* imagem)
{
	if(imagem == NULL)
	{
		printf(" EM: Imagem-> imagem_getX(Imagem*)\n");
		printf(" \tArgumento Imagem* == NULL, abortando\n");
		return -1;
	}
	return imagem->posicao.x;
}
int imagem_getY(Imagem* imagem)
{
	if(imagem == NULL)
	{
		printf(" EM: Imagem-> imagem_getY(Imagem*)\n");
		printf(" \tArgumento Imagem* == NULL, abortando\n");
		return -1;
	}
	return imagem->posicao.y;
}
