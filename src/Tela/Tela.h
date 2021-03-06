#pragma once

#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TELA_NAO_INICIALIZADA -1
#ifndef OK
#define OK 0
#endif

#ifndef ERRO
#define ERRO -10
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

typedef struct Tela Tela;

/*CONSTRUTOR*/
Tela* new_tela();
/*DESTRUTOR*/
int delete_tela(Tela* tela);
/*SETTERS*/
int tela_setSize(Tela* tela, int width, int height);
int tela_setTitle(Tela* tela, char *titulo);
int tela_setCor(Tela*, int, int, int);
int tela_setAlpha(Tela*, int);


/*GETTERS*/
int tela_getWidth(Tela* tela);
int tela_getHeight(Tela* tela);

bool tela_getTeclaApertada(Tela* tela);
bool tela_getTeclaSolta(Tela* tela);

SDL_Keycode tela_getTecla(Tela*);
bool tela_getEvento(Tela*);
bool tela_getSair(Tela*);
void tela_getMouse(Tela*);
void tela_getMousePos(Tela*, int*, int*);
bool tela_getMovimentoMouse(Tela*);

SDL_Event* tela_getEventoRaw(Tela*);
SDL_Window* tela_getJanela(Tela*);
SDL_Renderer* tela_getRenderizador(Tela* tela);

/*COMANDOS*/
void tela_update(Tela*);
void tela_limpa(Tela*);
