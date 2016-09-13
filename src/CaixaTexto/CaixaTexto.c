#include "CaixaTexto.h"

struct CaixaTexto
{
	Texto* texto;
	Retangulo* retangulo;
	char* entrada;
	char* composicao;
	int cursor;
	int selecao;
};


//CONSTRUTOR
CaixaTexto* new_caixaTexto(void)
{
	CaixaTexto* caixaTexto = malloc(sizeof(CaixaTexto));
	if(caixaTexto == NULL)
	{
		printf("ERRO: Não foi possível criar Caixa de Texto\n");
		return NULL;
	}
	caixaTexto->retangulo = new_retangulo();
	if(caixaTexto-> retangulo == NULL)
	{
		printf("ERRO: Não foi possível criar o retângulo da caixa de texto\n");
		return NULL;
	}
	caixaTexto->texto = new_texto();
	if(caixaTexto->texto == NULL)
	{
		printf("ERRO: Não foi possível criar o Texto da caixa de texto \n");
		return NULL;
	}
	if(!texto_setFonte(caixaTexto->texto, FONTE_PADRAO, TAMANHO_PADRAO))
	{
		printf("EM: CaixaTexto-> new_caixaTexto()\n");
		printf("\tEntrada de texto indisponível (CaixaTexto->Construtor->setFonte())\n");
		return NULL;
	}
//	texto_setCor(caixaTexto->texto, 0, 0, 0);//Cor preta por padrão  (o que o Texto já faz)
	retangulo_setCor(caixaTexto->retangulo, 0xFF, 0xFF, 0xFF);//Cor branca por padrão
	caixaTexto->entrada = NULL;
	caixaTexto->composicao = NULL;
	caixaTexto->cursor = 0;
	caixaTexto->selecao = 0;	
	return caixaTexto;
}


//DESTRUTOR
void delete_caixaTexto(CaixaTexto* caixaTexto)
{
	if(caixaTexto == NULL)
	{
		return;
	}
	delete_retangulo(caixaTexto->retangulo);
	caixaTexto->retangulo = NULL;
	caixaTexto->texto = NULL;
	caixaTexto->composicao = NULL;
	delete_texto(caixaTexto->texto);
	caixaTexto->texto = NULL;
	return;
}


//SETTERS
void caixaTexto_setTamanho(CaixaTexto* caixaTexto, Tela* tela, int w, int h)
{
	if(caixaTexto == NULL || tela == NULL)
	{
		return;
	}
	texto_setTamanho(caixaTexto->texto, h);
//	texto_updateTexto(caixaTexto->texto, tela);
	retangulo_setTamanho(caixaTexto->retangulo, w, h);
}

void caixaTexto_setCorFundo(CaixaTexto* caixaTexto, int r, int g, int b)
{
	if(caixaTexto == NULL)
	{
		printf("em CaixaTexto:	caixaTexto_setCorFundo(CaixaTexto*, int, int, int) \n");
		printf("caixaTexto não inicializada\n");
		return;
	}
	retangulo_setCor(caixaTexto->retangulo, r, g, b);
	return;
}


void caixaTexto_setCorTexto(CaixaTexto* caixaTexto, int r, int g, int b)
{
	if(caixaTexto == NULL)
	{
		printf("em CaixaTexto:	caixaTexto_setCorTexto(CaixaTexto*, int, int, int) \n");
		printf("caixaTexto não inicializada\n");
		return;
	}
	texto_setCor(caixaTexto->texto, r, g, b);
	return;
}

void caixaTexto_setFonte(CaixaTexto* caixaTexto, char *fonte, int tamanho)
{
	if(caixaTexto == NULL)
	{
		printf("Caixa de texto não criada (CaixaTexto->setFonte(CaixaTexto*, int, int, int))\n");
		return ;
	}
	if(caixaTexto->texto == NULL)
	{
		printf("ERRO: Não foi possível criar o Texto da caixa de texto \n");
		return ;
	}
	if(!texto_setFonte(caixaTexto->texto, fonte, tamanho))//ERRO AQUI
	{
		printf("Aviso: Não foi possível definir fonte padrão a ser usada!(CaixaTexto->Construtor)\n");
	}
}


//COMANDOS
void caixaTexto_print(CaixaTexto* caixaTexto, Tela* tela)
{
	if(caixaTexto == NULL || tela == NULL)
	{
		return;
	}
	retangulo_printCompleto(caixaTexto->retangulo, tela);
	texto_print(caixaTexto->texto, tela);
}

void caixaTexto_ouvinte(CaixaTexto* caixaTexto, Tela* tela)
{
	int x ,y;
	if(caixaTexto == NULL || tela == NULL)
	{
		return;
	}
	SDL_Event* evento = tela_getEventoRaw(tela);
	if(tela_getTipoEvento(tela) == SDL_TEXTINPUT)
	{
		strcat(caixaTexto->entrada, evento->text.text);
		texto_setTexto(caixaTexto->texto, caixaTexto->entrada); 
		texto_updateTexto(caixaTexto->texto, tela);
		return;
	}
	if(tela_getTipoEvento(tela) == SDL_TEXTEDITING)
	{
		caixaTexto->composicao = evento->edit.text;
		caixaTexto->cursor = evento->edit.start;
		caixaTexto->selecao = evento->edit.length;
		return;
	}
	else
	{
		tela_getMousePos(tela, &x, &y);
		if((x >= retangulo_getX(caixaTexto->retangulo) && x <= (retangulo_getX(caixaTexto->retangulo)) + retangulo_getWidth(caixaTexto->retangulo)) && (y >= retangulo_getY(caixaTexto->retangulo) && y <= (retangulo_getY(caixaTexto->retangulo) + retangulo_getHeight(caixaTexto->retangulo))))
		{
			if(tela_getTipoEvento(tela) == SDL_MOUSEBUTTONDOWN)
			{
				SDL_StartTextInput();
			}
			return;
		}
		else
		{
			if(tela_getTipoEvento(tela) == SDL_MOUSEBUTTONUP)
			{
				SDL_StopTextInput();
			}
			return;
		}
	}
	return;
}
