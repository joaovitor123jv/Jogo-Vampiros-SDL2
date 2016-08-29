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
typedef struct Tela Tela;

Tela* new_tela();

int tela_setSize(Tela* tela, int width, int height);

int tela_setTitle(Tela* tela, char *titulo);

int delete_tela(Tela* tela);
int tela_getWidth(Tela* tela);
int tela_getHeight(Tela* tela);

SDL_Renderer* tela_getRenderizador(Tela* tela);
