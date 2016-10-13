#include"../Tela/Tela.h"
#include"../Imagem/Imagem.h"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdlib.h>
#include<stdio.h>

#include<pthread.h> /* Para usar threads */

#ifndef bool
#define bool char
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

typedef struct Animacao Animacao;

/* CONSTRUTOR */
Animacao* new_animacao(void);

/* DESTRUTOR */
void delete_animacao(Animacao*);

/* SETTERS */
bool animacao_setTamanhoTotal(Animacao*, int, int);
bool animacao_setPosicao(Animacao*, int, int);
bool animacao_setParte(Animacao*, int, int);

/* COMANDOS */
bool animacao_loadSheet(Animacao*, Tela*, char*, int, int);
void animacao_printTotal(Animacao*, Tela*);
