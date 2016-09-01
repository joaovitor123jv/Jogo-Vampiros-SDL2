#include"Botao.h"

struct Botao
{
	Texto* texto;
	Retangulo* retangulo;
	SDL_Color cor1;
	SDL_Color cor2;
	SDL_Color cor3;
};

//CONSTRUTOR
Botao* new_botao()
{
	Botao* botao = malloc(sizeof(Botao));
	botao->texto = new_texto();
	texto_setFonte(botao->texto, FONTE_PADRAO, TAMANHO_PADRAO);
	texto_setCor(botao->texto, 0, 0, 0);
	botao->retangulo = new_retangulo();
	botao->cor1.r = 0;
	botao->cor1.g = 0;
	botao->cor1.b = 0;
	botao->cor2.r = 0;
	botao->cor2.g = 0;
	botao->cor2.b = 0;
	botao->cor3.r = 0;
	botao->cor3.g = 0;
	botao->cor3.b = 0;
	return botao;
}

//DESTRUTOR
void delete_botao(Botao* botao)
{
	if(botao == NULL)
	{
		return;
	}
	delete_texto(botao->texto);
	delete_retangulo(botao->retangulo);
	free(botao);
	botao = NULL;
}

//SETTERS
void botao_setCorDentro(Botao* botao, int r, int g, int b)
{
	if(botao == NULL)
	{
		return;
	}
	botao->cor1.r = r;
	botao->cor1.g = g;
	botao->cor1.b = b;
}

void botao_setCorFora(Botao* botao, int r, int g, int b)
{
	if(botao == NULL)
	{
		return;
	}
	botao->cor2.r = r;
	botao->cor2.g = g;
	botao->cor2.b = b;
}

void botao_setCorClique(Botao* botao, int r, int g, int b)
{
	if(botao == NULL)
	{
		return;
	}
	botao->cor3.r = r;
	botao->cor3.g = g;
	botao->cor3.b = b;
}

void botao_setCorTexto(Botao* botao, int r, int g, int b)
{
	if(botao == NULL)
	{
		return;
	}
	texto_setCor(botao->texto, r, g, b);
}

void botao_setTexto(Botao* botao, char* texto)
{
	if(botao == NULL)
	{
		return;
	}
	texto_setTexto(botao->texto, texto);
	retangulo_setTamanho(botao->retangulo, texto_getWidth(botao->texto), texto_getHeight(botao->texto));
	retangulo_setPosicao(botao->retangulo, texto_getX(botao->texto), texto_getY(botao->texto));
}

void botao_setPosicao(Botao* botao, int x, int y)
{
	if(botao == NULL)
	{
		return;
	}
	texto_setPosicao(botao->texto, x, y);
	retangulo_setPosicao(botao->retangulo, x, y);
}

//TODO
void botao_setTamanho(Botao* botao, int tamanho)
{
}


//COMANDOS
//TODO
void botao_print(Botao* botao, Tela* tela)
{
	retangulo_printCompleto(botao->retangulo, tela);
	texto_print(botao->texto, tela);
}

void botao_update(Botao* botao, Tela* tela)
{
	if(botao == NULL || tela == NULL)
	{
		return;
	}
	texto_updateTexto(botao->texto, tela);
	retangulo_setTamanho(botao->retangulo, texto_getWidth(botao->texto), texto_getHeight(botao->texto));
}
