#include "../Animacao/Animacao.h"
#include "Player.h"

struct Player
{
	int velocidade;
	unsigned short cima;
	unsigned short baixo;
	unsigned short esquerda;
	unsigned short direita;
/*	Animacao* animacao;*/
	SDL_Rect posicao;
	SDL_Texture* textura;
};

/*Construtor*/
Player* new_player(void)
{
	Player* player = malloc(sizeof(Player));
	if(player == NULL)
	{
		return NULL;
	}
	player->posicao.x = 10;
	player->posicao.y = 10;
	player->posicao.w = 10;
	player->posicao.h = 10;
	player->velocidade = 0;
	player->cima = false;
	player->baixo = false;
	player->esquerda = false;
	player->direita = false;
/*	animacao = new_animacao();*/
	return player;
}

/*Destrutor*/
int delete_player(Player* player)
{
	if(player == NULL)
	{
		return ERRO;
	}
/*	delete_animacao(player->animacao);*/
	free(player);
	if(player != NULL)
	{
		player= NULL;
	}
	return OK;
}

/*GETTERS*/
int player_getVelocidade(Player* player)
{
	if(player == NULL)
	{
		return ERRO;
	}
	return player->velocidade;
}

int player_getX(Player* player)
{
	if(player == NULL)
	{
		return ERRO;
	}
	return player->posicao.x;
}

int player_getY(Player* player)
{
	if(player == NULL)
	{
		return ERRO;
	}
	return player->posicao.y;
}

int player_getWidth(Player* player)
{
	if(player == NULL)
	{
		return ERRO;
	}
	return player->posicao.w;
}

int player_getHeight(Player* player)
{
	if(player == NULL)
	{
		return ERRO;
	}
	return player->posicao.h;
}

SDL_Rect* player_getPosicao(Player* player)
{
	if(player == NULL)
	{
		return NULL;
	}
	return &player->posicao;
}

unsigned short player_getBaixo(Player* player)
{
	if(player == NULL)
	{
		return ERRO;
	}
	return player->baixo;
}

unsigned short player_getCima(Player* player)
{
	if(player == NULL)
	{
		return ERRO;
	}
	return player->cima;
}
unsigned short player_getEsquerda(Player* player)
{
	if(player == NULL)
	{
		return ERRO;
	}
	return player->esquerda;
}
unsigned short player_getDireita(Player* player)
{
	if(player == NULL)
	{
		return ERRO;
	}
	return player->direita;
}

SDL_Texture* player_getTextura(Player* player)
{
	return player->textura;
}

/*SETTERS*/
void player_setWidth(Player* player, int w)
{
	if(player != NULL)
	{
		player->posicao.w = w;
	}
}


void player_setHeight(Player* player, int h)
{
	if(player != NULL)
	{
		player->posicao.h = h;
	}
}

void player_setX(Player* player, int x)
{
	if(player != NULL)
	{
		player->posicao.x = x;
	}
}

void player_setY(Player* player, int y)
{
	if(player != NULL)
	{
		player->posicao.y = y;
	}
}

void player_setVelocidade(Player* player, int velocidade)
{
	if(player != NULL)
	{
		player->velocidade = velocidade;
	}
}

void player_setBaixo(Player* player, unsigned short x)
{
	if(player !=NULL)
	{
		player->baixo = x;
	}
}
void player_setCima(Player* player, unsigned short x)
{
	if(player !=NULL)
	{
		player->cima = x;
	}
}
void player_setEsquerda(Player* player, unsigned short x)
{
	if(player !=NULL)
	{
		player->esquerda = x;
	}
}
void player_setDireita(Player* player, unsigned short x)
{
	if(player !=NULL)
	{
		player->direita = x;
	}
}

int player_setTextura(Player* player, Tela* tela, char* endereco)
{
	if(player == NULL)
	{
		return ERRO;
	}
	player->textura = IMG_LoadTexture( tela_getRenderizador(tela), endereco);
	if(player->textura == NULL)
	{
		return ERRO;
	}
	int w, h;
	if(SDL_QueryTexture(player->textura, NULL, NULL, &w, &h))
	{
		return ERRO;
	}
	player->posicao.h = h;
	player->posicao.w = h;
	
	return OK;
}


void player_toString(Player* player)
{
	printf("Jogador:  X = %d,  Y = %d,  W = %d,  H = %d,   Velocidade = %d\n ", player->posicao.x, player->posicao.y, player->posicao.w, player->posicao.h, player->velocidade);
}

/*COMANDOS*/
bool player_print(Player* player, Tela* tela)
{
	if(player == NULL)
	{
		return false;
	}
	if(tela == NULL)
	{
		return false;
	}
/*	animacao_printTotal*/
	SDL_RenderCopy(tela_getRenderizador(tela), player_getTextura(player), NULL, player_getPosicao(player));
}

void player_movimenta(Player* player, Tela* tela)
{
	if(player_getCima(player))
	{
		if(player_getY(player)-player_getVelocidade(player) >= 0 && player_getY(player)-player_getVelocidade(player)<= (tela_getHeight(tela)-player_getHeight(player)))
			player_setY(player, player_getY(player)-player_getVelocidade(player));
	}
	if(player_getBaixo(player))
	{
		if(player_getY(player)+player_getVelocidade(player) >= 0 && player_getY(player)+player_getVelocidade(player)<= (tela_getHeight(tela)-player_getHeight(player)))
			player_setY(player, player_getY(player)+player_getVelocidade(player));
	}
	if(player_getEsquerda(player))
	{
		if(player_getX(player)-player_getVelocidade(player) >= 0 && player_getX(player)-player_getVelocidade(player)<= tela_getWidth(tela) - player_getWidth(player))
			player_setX(player, player_getX(player)-player_getVelocidade(player));
	}
	if(player_getDireita(player))
	{
		if(player_getX(player)+player_getVelocidade(player) >= 0 && player_getX(player)+player_getVelocidade(player)<= tela_getWidth(tela) - player_getWidth(player))
			player_setX(player, player_getX(player)+player_getVelocidade(player));
	}
}

void player_ouvinte(Player* player, Tela* tela)
{
	if(tela_getTeclaApertada(tela))
	{
		switch(tela_getTecla(tela))
		{
			case(SDLK_w):
				player_setCima(player, true);

				break;

			case(SDLK_a):
				player_setEsquerda(player, true);
				break;

			case(SDLK_s):
				player_setBaixo(player, true);
				break;

			case(SDLK_d):
				player_setDireita(player, true);
				break;
		}
	}
	else if(tela_getTeclaSolta(tela))
	{
		switch(tela_getTecla(tela))
		{
			case(SDLK_w):
				player_setCima(player, false);
				break;

			case(SDLK_a):
				player_setEsquerda(player, false);
				break;

			case(SDLK_s):
				player_setBaixo(player, false);
				break;

			case(SDLK_d):
				player_setDireita(player, false);
				break;
		}
	}
	return;
}
