#include"../Tela/Tela.h"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct Animacao Animacao;

/* CONSTRUTOR */
Animacao* new_animacao(void);

/* DESTRUTOR */
void delete_animacao(Animacao*);
