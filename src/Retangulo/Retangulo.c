#include "Retangulo.h"

struct Retangulo
{
	SDL_Color cor;
	SDL_Rect posicao;
};

//CONSTRUTOR
Retangulo* new_retangulo()
{
	Retangulo* retangulo = malloc(sizeof(Retangulo));
	if(retangulo == NULL)
	{
		printf("Não há memória suficiente para a criação de um retângulo\n");
		return NULL;
	}
	retangulo->cor.r = 0;
	retangulo->cor.g = 0;
	retangulo->cor.b = 0;
	retangulo->cor.a = 0xFF;
	retangulo->posicao.x = 0;
	retangulo->posicao.y = 0;
	retangulo->posicao.w = 0;
	retangulo->posicao.h = 0;
	return retangulo;
}

//DESTRUTOR
void delete_retangulo(Retangulo* retangulo)
{
	if(retangulo == NULL)
	{
		printf("Erro: retângulo não inicializado\n");
		return;
	}
	free(retangulo);
	retangulo = NULL;
}

//SETTERS
bool retangulo_setTamanho(Retangulo* retangulo, int width, int height)
{
	if(retangulo == NULL)
	{
		return false;
	}
	retangulo->posicao.w = width;
	retangulo->posicao.h = height;
	return true;
}

bool retangulo_setPosicao(Retangulo* retangulo, int x, int y)
{
	if(retangulo == NULL)
	{
		return false;
	}
	retangulo->posicao.x = x;
	retangulo->posicao.y = y;
	return true;
}

bool retangulo_setCor(Retangulo* retangulo, int r, int g, int b)
{
	if(retangulo == NULL)
	{
		return false;
	}
	retangulo->cor.r = r;
	retangulo->cor.g = g;
	retangulo->cor.b = b;
}

bool retangulo_setAlpha(Retangulo* retangulo, int alpha)
{
	if(retangulo == NULL)
	{
		return false;
	}
	retangulo->cor.a = alpha;
}

//GETTERS
int retangulo_getX(Retangulo* retangulo)
{
	if(retangulo == NULL)
	{
		return ARGUMENTO_INEXISTENTE;
	}
	return retangulo->posicao.x;
}

int retangulo_getY(Retangulo* retangulo)
{
	if(retangulo == NULL)
	{
		return ARGUMENTO_INEXISTENTE;
	}
	return retangulo->posicao.y;
}

int retangulo_getWidth(Retangulo* retangulo)
{
	if(retangulo == NULL)
	{
		return ARGUMENTO_INEXISTENTE;
	}
	return retangulo->posicao.w;
}

int retangulo_getHeight(Retangulo* retangulo)
{
	if(retangulo == NULL)
	{
		return ARGUMENTO_INEXISTENTE;
	}
	return retangulo->posicao.h;
}

//COMANDOS
bool retangulo_print(Retangulo* retangulo, Tela* tela)
{
	if(retangulo == NULL || tela == NULL)
	{
		return false;
	}
	SDL_SetRenderDrawColor(tela_getRenderizador(tela), retangulo->cor.r, retangulo->cor.g, retangulo->cor.b, retangulo->cor.a);//Esse 0xFF é o "alpha"
	SDL_RenderDrawRect(tela_getRenderizador(tela), &retangulo->posicao);
	return true;
}

bool retangulo_printCompleto(Retangulo* retangulo, Tela* tela)
{
	if(retangulo == NULL || tela == NULL)
	{
		return false;
	}
	SDL_SetRenderDrawColor(tela_getRenderizador(tela), retangulo->cor.r, retangulo->cor.g, retangulo->cor.b, retangulo->cor.a);//Esse 0xFF é o "alpha"
	SDL_RenderFillRect(tela_getRenderizador(tela), &retangulo->posicao);
	return true;
}
