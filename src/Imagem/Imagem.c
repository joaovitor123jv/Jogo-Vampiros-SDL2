#include"Imagem.h"

struct Imagem
{
	SDL_Rect posicao;
	SDL_Texture* textura;
	char* endereco;
};


/*CONSTRUTOR*/
Imagem* new_imagem(void)
{
	Imagem* imagem = malloc(sizeof(Imagem));
	imagem->posicao.x = 0;
	imagem->posicao.y = 0;
	imagem->posicao.w = 0;
	imagem->posicao.h = 0;
	imagem->textura = NULL;
	imagem->endereco = NULL;
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
void imagem_setPosicao(Imagem* imagem, int x, int y)
{
	if(imagem == NULL)
	{
		printf("Imagem não inicializada\n");
		return;
	}
	imagem->posicao.x = x;
	imagem->posicao.y = y;
	return;
}

bool imagem_setTamanho(Imagem* imagem, Tela* tela, int w, int h)
{
	if(imagem == NULL)
	{
		printf(" EM: Imagem-> imagem_setTamanho(Imagem*, int, int)\n");
		printf(" \tERRO: argumento Imagem* == NULL, abortando\n");
		return false;
	}
	if(tela == NULL)
	{
		printf(" EM: Imagem-> imagem_setImagem(Imagem*, Tela*, char*)\n");
		printf(" \tERRO: Argumento Tela* == NULL, abortando\n");
		return false;
	}
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
	SDL_QueryTexture(imagem->textura, NULL, NULL, &w, &h);
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
