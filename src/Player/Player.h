#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdlib.h>
#include"../Tela/Tela.h"
#include "../Animacao/Animacao.h"
#ifndef ERRO
#define ERRO -1
#endif

#ifndef OK
#define OK 0
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

typedef struct Player Player;

/* CONSTRUTOR */
Player* new_player(void);

/* DESTRUTOR */
int delete_player(Player* player);

/*GETTERS*/
int player_getHeight(Player* player);
int player_getWidth(Player* player);
int player_getX(Player* player);
int player_getY(Player* player);
int player_getVelocidade(Player* player);

bool player_getBaixo(Player* player);
bool player_getCima(Player* player);
bool player_getEsquerda(Player* player);
bool player_getDireita(Player* player);

SDL_Rect* player_getPosicao(Player* player);
Imagem* player_getImagem(Player*);
Animacao* player_getAnimacao(Player*);

/*SETTERS*/
void player_setVelocidade(Player* player, int velocidade);
void player_setY(Player* player, int y);
void player_setX(Player* player, int x);
void player_setTamanhoTotal(Player*, int, int);

void player_setBaixo(Player* player, bool x);
void player_setEsquerda(Player* player, bool x);
void player_setDireita(Player* player, bool x);
void player_setCima(Player* player, bool x);

/*COMANDOS*/
void player_start(Player*);
void player_stop(Player*);
bool player_print(Player *, Tela*);
void player_movimenta(Player*, Tela*);
void player_ouvinte(Player*, Tela*);
bool player_loadSheet(Player*, Tela*, char*, int, int);

void player_toString(Player* player);
