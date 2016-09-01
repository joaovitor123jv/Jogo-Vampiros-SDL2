#pragma once

#include "../Texto/Texto.h"
#include "../Retangulo/Retangulo.h"

#ifndef bool
#define bool char
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#ifndef FONTE_PADRAO
#define FONTE_PADRAO "fonte.ttf"
#endif

#ifndef TAMANHO_PADRAO
#define TAMANHO_PADRAO 40
#endif

typedef struct Botao Botao;

//CONSTRUTOR
Botao* new_botao();

//DESTRUTOR
void delete_botao(Botao*);

//SETTERS
void botao_setCorDentro(Botao*, int, int, int);
void botao_setCorFora(Botao*, int, int, int);
void botao_setCorClique(Botao*, int, int, int);
void botao_setCorTexto(Botao*, int, int, int);
void botao_setTexto(Botao*, char*);
void botao_setPosicao(Botao*, int, int);
//void botao_setTamanho(Botao*, int);


//COMANDOS
void botao_print(Botao*, Tela*);
void botao_update(Botao*, Tela*);
bool botao_ouvinte(Botao*, Tela*);
