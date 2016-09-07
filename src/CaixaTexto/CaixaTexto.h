#include"../Tela/Tela.h"
#include"../Retangulo/Retangulo.h"
#include"../Texto/Texto.h"

#ifndef FONTE_PADRAO
#define FONTE_PADRAO "fonte.ttf"
#endif

#ifndef TAMANHO_PADRAO
#define TAMANHO_PADRAO 40
#endif

typedef struct CaixaTexto CaixaTexto;

//CONSTRUTOR
CaixaTexto* new_caixaTexto(void);

//DESTRUTOR
void delete_caixaTexto(CaixaTexto*);

//SETTERS
void caixaTexto_setTamanho(CaixaTexto*, Tela*, int, int);
//void caixaTexto_setFonte(CaixaTexto*, char*, int);

//COMANDOS
void caixaTexto_ouvinte(CaixaTexto*, Tela*);
void caixaTexto_print(CaixaTexto*, Tela*);
