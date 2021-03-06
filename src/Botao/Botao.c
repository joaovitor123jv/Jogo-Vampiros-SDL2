#include"Botao.h"

struct Botao
{
	Texto* texto;
	Retangulo* retangulo;
	SDL_Color cor1;
	SDL_Color cor2;
	SDL_Color cor3;
	bool clique;
	bool dentro;
};

/*CONSTRUTOR*/
Botao* new_botao()
{
	Botao* botao = malloc(sizeof(Botao));
	botao->texto = new_texto();
	texto_setFonte(botao->texto, FONTE_PADRAO, TAMANHO_PADRAO);
/*	texto_setCor(botao->texto, 0, 0, 0);  (Texto já faz isso no construtor)*/
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
	botao_setCorTexto(botao, 255, 255, 255);
	botao_setCorFora(botao, 0x31, 0x61, 0x94);
	botao_setCorDentro(botao, 0x21, 0x41, 0x74);
	botao_setCorClique(botao, 0x21, 0x39, 0x5B);
	return botao;
}

/*DESTRUTOR*/
void delete_botao(Botao* botao)
{
	if(botao == NULL)
	{
		return;
	}
	if(botao->texto != NULL)
	{
		delete_texto(botao->texto);
		botao->texto = NULL;
	}
	if(botao->retangulo != NULL)
	{
		delete_retangulo(botao->retangulo);
		botao->retangulo = NULL;
	}
	free(botao);
	botao = NULL;
	return;
}

/*SETTERS*/
void botao_setCorDentro(Botao* botao, int r, int g, int b)
{
	if(botao == NULL)
	{
		return;
	}
	if( (r<0||r>255) || (g<0||g>255) || (b<0||b>255) )
	{
		printf("EM: Botao-> botao_setCorDentro(Botao*, int, int, int)\n");
		printf("\tValor(es) de cor inválido(s)\n");
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
	if( (r<0||r>255) || (g<0||g>255) || (b<0||b>255) )
	{
		printf("EM: Botao-> botao_setCorFora(Botao*, int, int, int)\n");
		printf("\tValor(es) de cor inválido(s)\n");
		return;
	}
	botao->cor3.r = r;
	botao->cor3.g = g;
	botao->cor3.b = b;
}

void botao_setCorClique(Botao* botao, int r, int g, int b)
{
	if(botao == NULL)
	{
		return;
	}
	if( (r<0||r>255) || (g<0||g>255) || (b<0||b>255) )
	{
		printf("EM: Botao-> botao_setCorClique(Botao*, int, int, int)\n");
		printf("\tValor(es) de cor inválido(s)\n");
		return;
	}
	botao->cor2.r = r;
	botao->cor2.g = g;
	botao->cor2.b = b;
}

void botao_setCorTexto(Botao* botao, int r, int g, int b)
{
	if(botao == NULL)
	{
		return;
	}
	if( (r<0||r>255) || (g<0||g>255) || (b<0||b>255) )
	{
		printf("EM: Botao-> botao_setCorTexto(Botao*, int, int, int)\n");
		printf("\tValor(es) de cor inválido(s)\n");
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

/*TODO*/
void botao_setTamanho(Botao* botao, Tela* tela, int tamanho)
{
	texto_setTamanho(botao->texto, tamanho);
	texto_updateTexto(botao->texto, tela);
	retangulo_setTamanho(botao->retangulo, texto_getWidth(botao->texto), texto_getHeight(botao->texto));
}

/* GETTERS */
int botao_getWidth(Botao* botao)
{
	if(botao == NULL)
	{
		printf(" EM: Botao-> botao_getWidth(Botao*)\n");
		printf(" \tERRO: Argumento igual a NULL\n");
		return -1;
	}
	return retangulo_getWidth(botao->retangulo);
}

int botao_getHeight(Botao* botao)
{
	if(botao == NULL)
	{
		printf(" EM: Botao-> botao_getHeight(Botao*)\n");
		printf(" \tERRO: Argumento igual a NULL\n");
		return -1;
	}
	return retangulo_getHeight(botao->retangulo);
}

/*COMANDOS*/
void botao_print(Botao* botao, Tela* tela)
{
	if(botao == NULL || tela == NULL)
	{
		printf(" EM: Botao-> botao_print(Botao*, Tela*);\n");
		printf(" \tERRO: Argumento Botao* e/ou Tela*, igual a NULL, abortando\n");
		return;
	}
	if(botao->dentro)
	{
		retangulo_setCor(botao->retangulo, botao->cor1.r, botao->cor1.g, botao->cor1.b);
		if(botao->clique)
		{
			retangulo_setCor(botao->retangulo, botao->cor2.r, botao->cor2.g, botao->cor2.b);
		}
	}
	if(!botao->dentro)
	{
		retangulo_setCor(botao->retangulo, botao->cor3.r, botao->cor3.g, botao->cor3.b);
	}
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

bool botao_ouvinte(Botao* botao, Tela* tela)
{
	int x, y;
	if(tela == NULL || botao == NULL)
	{
		return false;
	}

	tela_getMousePos(tela, &x, &y);/*Obtem posição do mouse*/

	if(tela_getTipoEvento(tela) == SDL_MOUSEBUTTONDOWN)
	{
		botao->clique = true;
	}
	else
	{
		botao->clique = false;
	}

	if((x >= retangulo_getX(botao->retangulo) && x <= (retangulo_getX(botao->retangulo)) + retangulo_getWidth(botao->retangulo)) && (y >= retangulo_getY(botao->retangulo) && y <= (retangulo_getY(botao->retangulo) + retangulo_getHeight(botao->retangulo))))
	{
		botao->dentro = true;
		if(botao->clique)
		{
			return true;
		}
	}
	else
	{
		botao->dentro = false;
		return false;
	}
	return false;
}
