#include"../Tela/Tela.h"
#include"../Imagem/Imagem.h"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdlib.h>
#include<stdio.h>

#include<pthread.h> /* Para usar threads */

typedef struct Animacao Animacao;

/* CONSTRUTOR */
Animacao* new_animacao(void);

/* DESTRUTOR */
void delete_animacao(Animacao*);

/* COMANDOS */
bool animacao_loadTabela(Animacao*, Tela*, char*, int, int);
void animacao_printTotal(Animacao*, Tela*);
