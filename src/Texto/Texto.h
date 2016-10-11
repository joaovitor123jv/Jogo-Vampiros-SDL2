#pragma once

#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL.h>
#include"../Tela/Tela.h"
#include<string.h>

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#ifndef bool
#define bool char
#endif

#ifndef TAMANHO_MAX_TEXTO
#define TAMANHO_MAX_TEXTO 300
#endif

#ifndef ERRO
#define ERRO -1
#endif

#ifndef FONTE_PADRAO_TEXTO
#define FONTE_PADRAO_TEXTO "fonts/MankSans.ttf"
#endif

#ifndef TAMANHO_PADRAO_TEXTO
#define TAMANHO_PADRAO_TEXTO 40
#endif

typedef struct Texto Texto;

Texto* new_texto(void);
void delete_texto(Texto*);

/*SETTERS*/
bool texto_setFonte(Texto*, char*, int);
void texto_setCor(Texto*, int, int, int);
void texto_setTexto(Texto*, char*);
void texto_updateTexto(Texto*, Tela*);
void texto_setPosicao(Texto*, int, int);
void texto_setTamanho(Texto*, int);
bool texto_setTamanhoString(Texto*, int);
bool texto_setTamanhoMaximoString(Texto*, int);

/*GETTERS*/
int texto_getY(Texto*);
int texto_getX(Texto*);
int texto_getWidth(Texto*);
int texto_getHeight(Texto*);
char* texto_getTexto(Texto*);
TTF_Font* texto_getFont(Texto*);

/*COMANDOS*/
void texto_toString(Texto*);
void texto_print(Texto*, Tela*);
