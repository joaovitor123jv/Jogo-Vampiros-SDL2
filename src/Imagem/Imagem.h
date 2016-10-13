#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"../Tela/Tela.h"

#ifndef TAMANHO_MAX_ENDERECO
#define TAMANHO_MAX_ENDERECO 300
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0 
#endif

#ifndef bool
#define bool char
#endif

typedef struct Imagem Imagem;

/*CONSTRUTOR*/
Imagem* new_imagem(void);

/*DESTRUTOR*/
void delete_imagem(Imagem*);

/*SETTERS*/
void imagem_setPosicao(Imagem*, int, int);
bool imagem_setImagem(Imagem*, Tela*, char*);
bool imagem_setTamanho(Imagem*, int, int);

/*GETTERS*/
void imagem_getTamanhoSurface(Imagem*, int, int);
int imagem_getX(Imagem*);
int imagem_getY(Imagem*);
int imagem_getWidth(Imagem*);
int imagem_getHeight(Imagem*);

/*COMANDOS*/
void imagem_print(Imagem*, Tela*);
void imagem_printPart(Imagem*, Tela*, SDL_Rect);
