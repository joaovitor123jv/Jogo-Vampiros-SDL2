#pragma once

#include<SDL2/SDL.h>
#include<stdio.h>//Para debuggers
#include"../Tela/Tela.h"

#ifndef bool
#define bool char
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#ifndef ARGUMENTO_INEXISTENTE
#define ARGUMENTO_INEXISTENTE -1
#endif

typedef struct Retangulo Retangulo;

//CONSTRUTOR
Retangulo* new_retangulo();

//DESTRUTOR
void delete_retangulo(Retangulo*);

//SETTERS
bool retangulo_setTamanho(Retangulo*, int, int);
bool retangulo_setPosicao(Retangulo*, int, int);
bool retangulo_setCor(Retangulo*, int, int, int);
bool retangulo_setAlpha(Retangulo*, int);

//GETTERS
int retangulo_getX(Retangulo*);
int retangulo_getY(Retangulo*);
int retangulo_getHeight(Retangulo*);
int retangulo_getWidth(Retangulo*);

//COMANDOS
bool retangulo_print(Retangulo*, Tela*);//Desenha contorno do retângulo
bool retangulo_printCompleto(Retangulo*, Tela*);//Preenche toda a área do retângulo
