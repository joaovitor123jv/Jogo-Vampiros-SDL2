#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdlib.h>
#include"../Tela/Tela.h"
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

Player* new_player(void);//construtor

//int delete_player(Player* player);//destrutor
int delete_player();

//Getters
int player_getHeight(Player* player);
int player_getWidth(Player* player);
int player_getX(Player* player);
int player_getY(Player* player);
int player_getVelocidade(Player* player);

unsigned short player_getBaixo(Player* player);
unsigned short player_getCima(Player* player);
unsigned short player_getEsquerda(Player* player);
unsigned short player_getDireita(Player* player);

SDL_Texture* player_getTextura(Player* player);
SDL_Rect* player_getPosicao(Player* player);

//Setters
void player_setVelocidade(Player* player, int velocidade);
void player_setY(Player* player, int y);
void player_setX(Player* player, int x);
void player_setWidth(Player* player, int w);
void player_setHeight(Player* player, int h);

void player_setBaixo(Player* player, unsigned short x);
void player_setEsquerda(Player* player, unsigned short x);
void player_setDireita(Player* player, unsigned short x);
void player_setCima(Player* player, unsigned short x);
int player_setTextura(Player* player, Tela* tela, char* endereco);

void player_toString(Player* player);

//COMANDOS
bool player_print(Player *, Tela*);
void player_movimenta(Player*, Tela*);
