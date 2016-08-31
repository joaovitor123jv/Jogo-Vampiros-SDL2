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

typedef struct Texto Texto;

Texto* new_texto(void);
void delete_texto(Texto*);

//SETTERS
bool texto_setFonte(Texto*, char*, int);
void texto_setCor(Texto*, int, int, int);
void texto_setTexto(Texto*, char*);
void texto_updateTexto(Texto*, Tela*);
void texto_setPosicao(Texto*, int, int);

//COMANDOS
void texto_toString(Texto*);
void texto_print(Texto*, Tela*);
