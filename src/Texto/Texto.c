#include"Texto.h"
#include<SDL2/SDL_image.h>

struct Texto
{
	TTF_Font* fonte;
	SDL_Rect posicao;
	SDL_Color cor;
	SDL_Texture* textura;
	char* nomeFonte;
	char* texto;
	int tamanhoMaximoString;
	int tamanhoFonte;
};

/*CONSTRUTOR*/
Texto* new_texto()/*Construtor OK*/
{
	Texto* texto = malloc(sizeof(Texto));
	if(texto == NULL)
	{
		printf("Não foi possível inicializar o texto\n");
		return NULL;
	}
	if(TTF_Init() == -1)
	{
		printf("Não foi possível inicializar a SDL_TTF \n");
		return NULL;
	}
	texto->fonte = NULL;
	texto->posicao.x = 0;
	texto->posicao.y = 0;
	texto->posicao.h = 0;
	texto->posicao.w = 0;
	texto->cor.r = 0;/*RED  0->255*/
	texto->cor.g = 0;/*Green 0->255*/
	texto->cor.b = 0;/*Blue 0->255*/
	texto->cor.a = 0;/*Alpha 0->255*/
	texto->textura = NULL;
	texto->nomeFonte = NULL;
	texto->texto = NULL;
	texto_setCor(texto, 0x88, 0x88, 0x88);
	texto_setTamanhoMaximoString(texto, 32); /* Já define tamanho máximo como 32 e aloca */
	texto->tamanhoFonte = 0;
	texto_setFonte(texto, FONTE_PADRAO_TEXTO, TAMANHO_PADRAO_TEXTO);
	return texto;
}


/*DESTRUTOR*/
void delete_texto(Texto* texto)
{
	if(texto == NULL)
	{
		printf("Em: Texto-> delete_texto()\n");
		printf("\tEstrutura não inicializada\n");
		return;
	}
	if(texto->nomeFonte != NULL)
	{
		/*		free(texto->nomeFonte);*/
		texto->nomeFonte = NULL;
	}
	if(texto->texto != NULL)
	{
		free(texto->texto);
		texto->texto=NULL;
	}
	if(texto->textura != NULL)
	{
		SDL_DestroyTexture(texto->textura);
		texto->textura = NULL;
	}
	if(texto->fonte != NULL)
	{
		TTF_CloseFont(texto->fonte);
		texto->fonte=NULL;
	}
	/*
	   if(texto->cor !=NULL)
	   {
	   free(color);
	   color = NULL;
	   }*/
	free(texto);
	texto = NULL;
}

/*GETTERS*/
TTF_Font* texto_getFont(Texto* texto)
{
	if(texto == NULL)
	{
		printf(" EM: Texto-> texto_getFont(Texto*)\n");
		printf(" \tArgumento Texto* == NULL, Abortando\n");
		return NULL;
	}
	return texto->fonte;
}

/*Função privada*/
int texto_getTamanhoMaximoString(Texto* texto)
{
	if(texto == NULL)
	{
		printf("EM: Texto-> texto_getTamanhoMaximoString(Texto*)\n");
		printf("\t ERRO: argumento Texto* igual a NULL\n");
		return ERRO;
	}
	return texto->tamanhoMaximoString -1;
}

int texto_getTamanhoString(Texto* texto)
{
	if(texto == NULL)
	{
		printf("EM: Texto-> texto_getTamanhoString(Texto*)\n");
		printf("\t ERRO: argumento Texto* igual a NULL\n");
		return ERRO;
	}
	if(texto->texto == NULL)
	{
		return 0;
	}
	return strlen(texto->texto);
}

char* texto_getTexto(Texto* texto)
{
	if(texto == NULL)
	{
		return NULL;
	}
	return texto->texto;
}

void texto_getDimensao(Texto* texto, SDL_Surface* surface)
{
	if(texto == NULL)
	{
		printf("EM: Texto->texto_getDimensao(Texto*, SDL_Surface*);\n");
		printf("\t ERRO: Texto* não existe (NULL)\n");
		return;
	}
	if(surface == NULL)
	{
		printf("EM: Texto->texto_getDimensao(Texto*, SDL_Surface*);\n");
		printf("\t ERRO: SDL_Surface* não existe (NULL)\n");
		return;
	}
	texto->posicao.w = surface->w;
	texto->posicao.h = surface->h;
}

int texto_getWidth(Texto* texto)
{
	if(texto != NULL)
	{
		return texto->posicao.w;
	}
	return ERRO;
}

int texto_getHeight(Texto* texto)
{
	if(texto != NULL)
	{
		return texto->posicao.h;
	}
	return ERRO;
}

int texto_getX(Texto* texto)
{
	if(texto != NULL)
	{
		return texto->posicao.x;
	}
	return ERRO;
}

int texto_getY(Texto* texto)
{
	if(texto != NULL)
	{
		return texto->posicao.y;
	}
	return ERRO;
}


/*SETTERS*/
bool texto_setTamanhoMaximoString(Texto* texto, int tamanhoString)
{
	if(texto == NULL)
	{
		printf(" EM: Texto->texto_setTamanhoString(Texto*, int)\n");
		printf("\t ERRO: argumento Texto* igual a NULL, abortando\n");
		return false;
	}
	if(tamanhoString <0)
	{
		printf(" EM: Texto->texto_setTamanhoMaximoString(Texto*, int)\n");
		printf("\t ERRO: argumanto int (tamanho da String) não pode ser negativo, abortando\n");
		return false;
	}
	texto->tamanhoMaximoString = tamanhoString + 2;
	return true;
}

bool texto_setTamanhoString(Texto* texto, int tamanhoString)
{
	if(texto == NULL)
	{
		printf(" EM: Texto->texto_setTamanhoString(Texto*, int)\n");
		printf("\t ERRO: argumento Texto* igual a NULL, abortando\n");
		return false;
	}
	if(tamanhoString >= texto->tamanhoMaximoString || tamanhoString < 0)
	{
		printf(" EM: Texto->texto_setTamanhoString(Texto*, int)\n");
		printf("\t ERRO: argumento int (tamanho da String) não pode ser negativo, nem maior que o tamanho máximo anteriormente definido \"%d\" abortando\n", texto_getTamanhoMaximoString(texto));
		printf("\t Tamanho recebido → %d\n", tamanhoString);
		return false;
	}
	if(texto->texto == NULL)
	{
		texto->texto = malloc((tamanhoString + 1) * (sizeof(char)));
		return true;
	}
	texto->texto = realloc(texto->texto, (tamanhoString + 1) * (sizeof(char)));
	if(texto->texto == NULL)
	{
		printf(" EM: Texto-> texto_setTamanhoString(Texto*, int)\n");
		printf("\t ERRO: Não foi possível alocar memória suficiente\n");
		return false;
	}
	return true;
}


bool texto_setFonte(Texto* texto, char* endereco, int tamanhoFonte) /*OK*/
{
	int size;
	if(texto == NULL)
	{
		printf("EM: Texto-> texto_setFonte(Texto*, char*, int)\n");
		printf("\tERRO: Texto não inicializado\n");
		return false;
	}
	if(endereco == NULL)
	{
		printf("Em: Texto-> setFonte(Texto*, char*, int)\n");
		printf("\tEndereço inválido TEXTO->setFonte \n");
		printf("\tFonte passada == %s\n", endereco);
		return false;
	}
	if(tamanhoFonte == 0)
	{
		printf("Aviso Em: (Texto) -> texto_setFonte(Texto*, char*, int)\n");
		printf("\tTamanho de fonte invisível (0), continuar ?\n");
	}
	size = strlen(endereco);
	if(!(size < TAMANHO_MAX_TEXTO))
	{
		printf("Endereço muito extenso TEXTO->setFonte\n");
		return false;
	}
	texto->nomeFonte = malloc( size * sizeof(char) );
	if(tamanhoFonte < 0 )
	{
		printf("EM: Texto->texto_setFonte(Texto*, char*, int)\n");
		printf("Tamanho inválido para a fonte \n");
		return false;
	}
	texto->tamanhoFonte = tamanhoFonte;
	if(texto->nomeFonte == NULL)
	{
		printf("Em: Texto->texto_setFonte(Texto*, char*, int)\n");
		printf("\tErro: não foi possível inicializar fonte (memória insuficiente)\n");
		return false;
	}
	texto->nomeFonte = endereco;
	if(texto->nomeFonte == NULL)
	{
		printf("EM: Texto-> texto_setFonte(Texto*, char*, int) \n");
		printf("ERRO: Texto apontando para NULL (não foi possível atribuir fonte selecionada)\n");
		return false;
	}

	if(texto->fonte != NULL)/* Tratamento de erros */
	{
		TTF_CloseFont(texto->fonte);
		texto->fonte = NULL;
	}
	texto->fonte = TTF_OpenFont(texto->nomeFonte, texto->tamanhoFonte);
	if(texto->fonte == NULL)
	{
		printf("Não foi possível carregar a fonte\n");
		return false;
	}
	return true;
}

void texto_setCor(Texto* texto, int r, int g, int b)/*OK*/
{
	if(texto !=NULL)
	{
		if((r > 255 || r < 0 ) || (g > 255 || g < 0 ) || (b > 255 || b < 0 ) )
		{
			printf("EM: Texto-> texto_setCor(Texto*, int, int, int)\n");
			printf("\t Valores de cor inválidos\n");
			return;
		}
		if(r == 0 && b == 0 && g == 0)
		{
			printf("Aviso em Texto-> setCor\n");
			printf("\tTodas as cores selecionadas estão com valor zerado, é preto ?\n");
		}
		texto->cor.r = r;
		texto->cor.g = g;
		texto->cor.b = b;
	}
}

void texto_setTexto(Texto* texto, char* linha)/*OK*/
{
	if(texto == NULL)
	{
		printf(" EM: Texto->setTexto(Texto*, char*)\n");
		printf("\t ERRO: argumento Texto* igual a NULL\n");
		return;
	}
	
	if( strlen(linha) > texto_getTamanhoMaximoString(texto))
	{
		printf("EM: Texto-> texto_setTexto(Texto*, char*)\n");
		printf("\t ERRO: argmento char* excede tamanho proposto\n");
		printf("\t argumento de entrada tem %d caracteres\n", strlen(linha));
		printf("\t suporta %d caracteres\n", texto_getTamanhoMaximoString(texto));
		return;
	}
	if(! (texto_setTamanhoString(texto, strlen(linha) + 1)))
	{
		printf("EM: Texto->texto_setTexto(Texto*, char*)\n");
		printf("\tNão foi possível alocar memória para o texto recebido\n");
		printf("\tTexto recebido : ↓\n\t\t%s\n\n", linha);
		return;
	}
	strcpy(texto->texto, linha);
	if(texto->texto == NULL)
	{
		printf("EM: Texto->texto_setTexto(Texto*, char*)\n");
		printf("\tErro: não foi possível copiar texto(string) String == NULL\n");
		return;
	}
/*	texto->texto = linha;*/
	if(texto->texto == NULL)
	{
		printf("EM: Texto->texto_setTexto(Texto*, char*)\n");
		printf("\tErro: não foi possível copiar string\n");
		return;
	}
	return;
}


void texto_setPosicao(Texto* texto, int x, int y)
{
	if(texto == NULL)
	{
		printf("Estrutura não inicializada\n");
		return;
	}
	texto->posicao.x = x;
	texto->posicao.y = y;
}

void texto_setTamanho(Texto* texto, int tamanho)
{
	if(texto == NULL)
	{
		printf("EM: Texto -> texto_setTamanho(Texto*, int)\n");
		printf("\t Estrutura (Texto) não inicializada\n");
		return;
	}
	if(tamanho <0)
	{
		printf("EM: Texto -> texto_setTamanho(Texto*, int)\n");
		printf("\t Tamanho inválido \n");
		return;
	}
	if(texto->nomeFonte == NULL)
	{
		printf("EM: Texto-> texto_setTamanho(Texto*, int)\n");
		printf("\tNome da fonte de texto, inexistente\n");
	}
	texto_setFonte(texto, texto->nomeFonte, tamanho);
	return;
}

/*COMANDOS*/

void texto_updateTexto(Texto* texto, Tela* tela)
{
	if(texto == NULL || tela == NULL)
	{
		printf("EM: Texto-> texto_updateTexto(Texto*, Tela*)\n");
		printf("\tEstrutura (Texto ou Tela) não inicializada \n");
		return;
	}
	if(texto->fonte == NULL)
	{
		printf("EM: Texto -> texto_updateTexto(Texto*, Tela*)\n");
		printf("\tERRO: Fonte == NULL (nao inicializada) \n");
		printf("\t\tAbortando\n");
		return;
	}
	SDL_Surface* surface = NULL;
	/*	surface = TTF_RenderText_Blended(*texto->fonte, texto->texto, texto->cor);*/
	if(texto->fonte == NULL)
	{
		printf("EM: Texto -> texto_updateTexto(Texto*, Tela*)\n");
		printf("\t ERRO: Fonte do texto == NULL\n");
		return;
	}
	if(texto->texto == NULL)
	{
		printf("EM: Texto -> texto_updateTexto(Texto*, Tela*)\n");
		printf("\t ERRO: Texto do texto (string) == NULL\n");
		return;
	}
	/*	
		if(texto->cor == NULL)
		{
		printf("EM: Texto -> texto_updateTexto(Texto*, Tela*)\n");
		printf("\t ERRO: Cor do texto não foi setada (NULL)\n");
		return;
		}
	 */

	if(surface != NULL)
	{
		printf("Já pode arrancar os Cabelos... variável não declarada apontando pro infinito\n");
	}
	/* ERRO AQUI   (TODO)) */
	surface = TTF_RenderUTF8_Solid(texto->fonte, texto->texto, texto->cor);
	if(surface == NULL)
	{
		printf("EM: Texto->texto_updateTexto(Texto*, Tela*);\n");
		printf("\tERRO: Não foi possível renderizar texto corretamente\n");
		printf("\tLog da SDL: %s\n", SDL_GetError());
		SDL_FreeSurface(surface);
		return;
	}
	texto_getDimensao(texto, surface);/*TODO*/
	if(surface == NULL)
	{
		printf("EM: Texto->texto_updateTexto(Texto*, Tela);\n");
		printf("\tErro, não foi possível gerar surface\n");
		SDL_FreeSurface(surface);
		return;
	}

	if(texto->textura != NULL)
	{
		SDL_DestroyTexture(texto->textura); /* Tratamento de erros  */
		texto->textura == NULL;
	}


	texto->textura = SDL_CreateTextureFromSurface(tela_getRenderizador(tela), surface);
	if(texto->textura == NULL)
	{
		printf("EM: Texto->texto_updateTexto(Texto*, Tela*)\n");
		printf("\tErro, não foi possível criar textura a partir de surface\n");
		SDL_FreeSurface(surface);
		return;
	}
	SDL_QueryTexture(texto->textura, NULL, NULL, &texto->posicao.w, &texto->posicao.h);
	SDL_FreeSurface(surface);
	surface=NULL;
	return;
}



void texto_toString(Texto* texto)
{
	if(texto == NULL) return;
	printf("Texto : X = %d, Y = %d, W = %d, H = %d, NomeFonte = %s\n", texto->posicao.x, texto->posicao.y, texto->posicao.w, texto->posicao.h, texto->nomeFonte);
}

void texto_print(Texto* texto, Tela* tela)
{
	if(texto == NULL || tela == NULL)
	{
		printf("EM: Texto-> texto_print(Texto*, Tela*)\n");
		printf("\tErro, Estrutura(s) não inicializada(s)\n");
		return;
	}
	SDL_RenderCopy( tela_getRenderizador(tela), texto->textura, NULL, &texto->posicao);
}
