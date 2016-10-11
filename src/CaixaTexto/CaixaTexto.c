#include "CaixaTexto.h"

struct CaixaTexto
{
	Texto* texto;
	Retangulo* retangulo;
	char* entrada;
	char* composicao;
	bool ativo;
	int cursor;
	int selecao;
	int tamanhoDeAlocacao;
};


/*CONSTRUTOR*/
CaixaTexto* new_caixaTexto(void)
{
	int tamanhoDeAlocacao;
	CaixaTexto* caixaTexto = malloc(sizeof(CaixaTexto));
	caixaTexto->texto = new_texto();
	caixaTexto->retangulo = new_retangulo();
	if(caixaTexto-> retangulo == NULL)
	{
		printf("ERRO: Não foi possível criar o retângulo da caixa de texto\n");
		return NULL;
	}
	texto_setFonte(caixaTexto->texto, FONTE_PADRAO, TAMANHO_PADRAO);/*Texto se encarrega do tratamento de erros*/
	texto_setTexto(caixaTexto->texto, " ");/*Por padrão inicializa zerado*/
	retangulo_setCor(caixaTexto->retangulo, 0xFF, 0xFF, 0xFF);/*Cor branca por padrão*/
	texto_setCor(caixaTexto->texto, 0x01, 0x01, 0x01);

	caixaTexto_setTamanhoString(caixaTexto, 32); /* Determina tamanho máximo padrão da String de entrada */

	if(caixaTexto->entrada == NULL)
	{
		printf("Em: CaixaTexto->new_caixaTexto()\n" );
		printf("\tNão foi possível alocar o suficiente para a caixa de texto (entrada de texto )\n");
		return NULL;
	}
	caixaTexto->composicao = NULL;
	caixaTexto->cursor = 0;
	caixaTexto->selecao = 0;	
	caixaTexto->ativo = false;
/*	printf("SEM PROBLEMAS ATÉ AQUI\n");*/
	return caixaTexto;/*Sem problemas até aqui*/
}


/*DESTRUTOR*/
void delete_caixaTexto(CaixaTexto* caixaTexto)
{
	if(caixaTexto == NULL)
	{
		return;
	}
	if(caixaTexto->retangulo == NULL)
	{
		printf("EM: CaixaTexto -> delete_caixaTexto(CaixaTexto*)\n");
		printf("\tEstrutura (retângulo, não inicializada)\n");
	}
	if(caixaTexto->texto == NULL)
	{
		printf("EM: CaixaTexto -> delete_caixaTexto(CaixaTexto*)\n");
		printf("\tEstrutura (texto, não inicializada)\n");
	}
	if(caixaTexto->entrada == NULL)
	{
		printf("EM: CaixaTexto -> delete_caixaTexto(CaixaTexto*)\n");
		printf("\t caixaTexto->entrada não inicializada");
	}
	else
	{
		free(caixaTexto->entrada);
	}
	delete_retangulo(caixaTexto->retangulo);
	caixaTexto->retangulo = NULL;
	caixaTexto->composicao = NULL;
	caixaTexto->entrada = NULL;
	delete_texto(caixaTexto->texto);
	caixaTexto->texto = NULL;
	return;
}


/*SETTERS*/
void caixaTexto_setTamanhoString(CaixaTexto* caixaTexto, int tamanhoDeAlocacao)
{
	if(caixaTexto == NULL)
	{
		printf("EM: CaixaTexto-> caixaTexto_setTamanhoString(CaixaTexto*, int)\n");
		printf("\t ERRO: Argumento CaixaTexto* igual a NULL\n");
		return;
	}
	if(tamanhoDeAlocacao < 0)
	{
		printf("EM: CaixaTexto-> caixaTexto_setTamanhoString(CaixaTexto*, int)\n");
		printf("\t ERRO: Tamanho de alocação não pode ser negativo\n");
		return;
	}
	caixaTexto->tamanhoDeAlocacao = tamanhoDeAlocacao;
	texto_setTamanhoMaximoString(caixaTexto->texto, tamanhoDeAlocacao);
	if(caixaTexto->entrada == NULL)
	{
		caixaTexto->entrada = malloc((caixaTexto->tamanhoDeAlocacao+1) * (sizeof(char)));
	}
	else
	{
		caixaTexto->entrada = realloc(caixaTexto->entrada, (1 + caixaTexto->tamanhoDeAlocacao) * (sizeof(char)));
	}
	if(caixaTexto->entrada == NULL)
	{
		printf(" EM: CaixaTexto-> caixaTexto_setTamanhoString(CaixaTexto*, int)\n");
		printf("\tERRO: Não foi possível alocar memória suficiente\n");
	}
	return;
}

void caixaTexto_setPosicao(CaixaTexto* caixaTexto, int x, int y )
{
	if(caixaTexto == NULL)
	{
		printf("Em: CaixaTexto->caixaTexto_setPosicao(CaixaTexto*, int, int);\n" );
		printf("\tCaixaTexto == NULL\n" );
		return;
	}
	retangulo_setPosicao(caixaTexto->retangulo, x, y);
	texto_setPosicao(caixaTexto->texto, x, y);
	return;
}

void caixaTexto_setTamanho(CaixaTexto* caixaTexto, Tela* tela, int w, int h)/*OK*/
{
	if(caixaTexto == NULL || tela == NULL)
	{
		printf("EM: CaixaTexto -> setTamanho(CaixaTexto*, Tela*)\n");
		printf("\t Estrutura (CaixaTexto ou Tela), nao inicializada \n");
		return;
	}
	if(caixaTexto->texto == NULL)
	{
		printf("EM: CaixaTexto -> caixaTexto_setTamanho(CaixaTexto*, Tela*, int, int)\n");
		printf("\t texto (da caixa de texto) não existe\n");
	}
	texto_setTamanho(caixaTexto->texto, h);
	texto_updateTexto(caixaTexto->texto, tela);
	retangulo_setTamanho(caixaTexto->retangulo, w, h);
	return;
}

void caixaTexto_setCorFundo(CaixaTexto* caixaTexto, int r, int g, int b)/* OK */
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


void caixaTexto_setCorTexto(CaixaTexto* caixaTexto, int r, int g, int b)/* OK */
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

void caixaTexto_setFonte(CaixaTexto* caixaTexto, char *fonte, int tamanho)/* OK */
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
	if(!texto_setFonte(caixaTexto->texto, fonte, tamanho))
	{
		printf("Aviso: Não foi possível definir fonte padrão a ser usada!(CaixaTexto->Construtor)\n");
	}
	return;
}

/* GETTERS */
int caixaTexto_getTamanhoString(CaixaTexto* caixaTexto)/* OK */
{
	if(caixaTexto == NULL)
	{
		printf("EM: CaixaTexto-> caixaTexto_getTamanhoString(CaixaTexto*)\n");
		printf("\t ERRO: argumento CaixaTexto* igual a NULL\n");
		return ERRO;
	}
	if(caixaTexto->tamanhoDeAlocacao < 0)
	{
		printf("EM: CaixaTexto-> caixaTexto_getTamanhoString(CaixaTexto*)\n");
		printf("\t AVISO: caixaTexto->tamanhoDeAlocacao alterado indevidamente \n");
		return ERRO;
	}
	return caixaTexto->tamanhoDeAlocacao;
}


/*COMANDOS*/
void caixaTexto_removeUltimaLetra(CaixaTexto* caixaTexto)
{
	int posicao;
	if(caixaTexto == NULL)
	{
		printf("EM: CaixaTexto->caixaTexto_removeUltimaLetra(CaixaTexto*)\n");
		printf("\tErro: argumento CaixaTexto* igual a NULL\n");
		return;
	}
	if(strlen(caixaTexto->entrada) <= 1)
	{
		caixaTexto->entrada[0] = ' ';
		texto_setTexto(caixaTexto->texto, caixaTexto->entrada);
		return;
	}
	posicao = strlen(caixaTexto->entrada)-1;
	caixaTexto->entrada[posicao] = '\0';
	texto_setTexto(caixaTexto->texto, caixaTexto->entrada);
	return;
}

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
		printf("Em: CaixaTexto-> caixaTexto_ouvinte(CaixaTexto*, Tela*);\n");
		printf("\t CaixaTexto ou Tela == NULL\n");
		return;
	}
	if(tela_getTipoEvento(tela )== SDL_KEYDOWN && caixaTexto->ativo)
	{
		if(tela_getTecla(tela)== SDLK_BACKSPACE)
		{
			caixaTexto_removeUltimaLetra(caixaTexto);
/*			TTF_SetFontOutline(texto_getFont(caixaTexto->texto), 1);*/
			texto_updateTexto(caixaTexto->texto, tela);
		}
	}
	else if((tela_getTipoEvento(tela) == SDL_TEXTINPUT) && caixaTexto->ativo)
	{
		if(caixaTexto->texto == NULL || caixaTexto->entrada == NULL )
		{
			printf("EM: CaixaTexto->caixaTexto_ouvinte(CaixaTexto*, Tela*) \n" );
			printf("\tTexto ou Entrada == NULL\n");
			printf("\t\tTexto == %d\n", caixaTexto->texto);
			printf("\t\tEntrada == %d\n", caixaTexto->entrada);
			return;
		}

		if( strlen(caixaTexto->entrada) >= caixaTexto_getTamanhoString(caixaTexto))
		{
			printf("EM: CaixaTexto-> caixaTexto_ouvinte(CaixaTexto*, Tela*)\n");
			printf("\t Aviso: tamanho máximo atingido, abortando\n");
			return;
		}
		strcat(caixaTexto->entrada, tela_getEventoRaw(tela)->text.text);
		if((strlen(caixaTexto->entrada)) > caixaTexto_getTamanhoString(caixaTexto))
		{
			printf("EM: CaixaTexto->caixaTexto_ouvinte(CaixaTexto*, Tela*);\n" );
			printf("\tEstouro de memória (entrada)\n" );
			return;
		}
		texto_setTexto(caixaTexto->texto, caixaTexto->entrada); 
		texto_updateTexto(caixaTexto->texto, tela);
		return;
	}
	else if(tela_getTipoEvento(tela) == SDL_TEXTEDITING && caixaTexto->ativo)
	{
		SDL_Event* evento = tela_getEventoRaw(tela);
		caixaTexto->composicao = evento->edit.text;
		caixaTexto->cursor = evento->edit.start;
		caixaTexto->selecao = evento->edit.length;
		return;
	}

	tela_getMousePos(tela, &x, &y);
	if((x >= retangulo_getX(caixaTexto->retangulo) && x <= (retangulo_getX(caixaTexto->retangulo)) + retangulo_getWidth(caixaTexto->retangulo)) && (y >= retangulo_getY(caixaTexto->retangulo) && y <= (retangulo_getY(caixaTexto->retangulo) + retangulo_getHeight(caixaTexto->retangulo))))
	{
		if(tela_getTipoEvento(tela) == SDL_MOUSEBUTTONDOWN)
		{
			SDL_StartTextInput();
			caixaTexto->ativo = true;
		}
		return;
	}
	else if(tela_getTipoEvento(tela) == SDL_MOUSEBUTTONDOWN)
	{
		SDL_StopTextInput();
		caixaTexto->ativo = false;
		return;
	}
	return;
}
