#include "CaixaTexto.h"

struct CaixaTexto
{
	char* entrada;
	char* composicao;
	int cursor;
	int selecao;
	Retangulo* retangulo;
	Texto* texto;
};


//CONSTRUTOR
CaixaTexto* new_caixaTexto(void)
{
	CaixaTexto* caixaTexto = malloc(sizeof(CaixaTexto));
	if(caixaTexto == NULL)
	{
		printf("ERRO: Não foi possível criar Caix de Texto\n");
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
	texto_setCor(caixaTexto->texto, 0, 0, 0);//Cor preta por padrão
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
void caixaTexto_setTamanho(CaixaTexto* caixaTexto, int w, int h)
{
	if(caixaTexto == NULL)
	{
		return;
	}
	retangulo_setTamanho(caixaTexto->retangulo, w, h);
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
