#include"../Tela/Tela.h"
#include"../Retangulo/Retangulo.h"
#include"../Texto/Texto.h"

#ifndef FONTE_PADRAO
#define FONTE_PADRAO "fonte.ttf"
#endif

#ifndef TAMANHO_PADRAO
#define TAMANHO_PADRAO 40
#endif

#ifndef ERRO
#define ERRO -1
#endif

#ifndef bool
#define bool char
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

typedef struct CaixaTexto CaixaTexto;

/*CONSTRUTOR*/
CaixaTexto* new_caixaTexto(void);

/*DESTRUTOR*/
void delete_caixaTexto(CaixaTexto*);

/*SETTERS*/
void caixaTexto_setTamanhoString(CaixaTexto*, int);
void caixaTexto_setTamanho(CaixaTexto*, Tela*, int, int);
void caixaTexto_setPosicao(CaixaTexto*, int, int);
void caixaTexto_setFonte(CaixaTexto*, char*, int);
void caixaTexto_setCorFundo(CaixaTexto*, int, int, int);
void caixaTexto_setCorTexto(CaixaTexto*, int, int, int);

/* GETTERS */
int caixaTexto_getTamanhoString(CaixaTexto*);

/*COMANDOS*/
void caixaTexto_ouvinte(CaixaTexto*, Tela*);
void caixaTexto_print(CaixaTexto*, Tela*);
