#include "../Animacao/Animacao.h"
#include "Player.h"

struct Player
{
	int velocidade;
	bool cima;
	bool baixo;
	bool esquerda;
	bool direita;
	Animacao* animacao;
	SDL_Rect posicao;
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
	player->animacao = new_animacao();
	return player;
}

/*Destrutor*/
int delete_player(Player* player)
{
	if(player == NULL)
	{
		printf(" EM: Player->delete_player(Player*)\n");
		printf(" \tPlayer* == NULL, abortando\n");
		return ERRO;
	}
	if(player->animacao != NULL)
	{
		delete_animacao(player->animacao);
		player->animacao=NULL;
	}
	free(player);
	if(player != NULL)
	{
		player= NULL;
	}
	return OK;
}

/*GETTERS*/
Animacao* player_getAnimacao(Player* player)
{
	if(player == NULL)
	{
		printf(" EM: Player->player_getAnimacao(Player*)\n");
		printf(" \t ERRO: Player* == NULL, abortando\n");
		return NULL;
	}
	return player->animacao;
}

Imagem* player_getImagem(Player* player)
{
	if(player == NULL)
	{
		printf(" EM: Player->player_getImagem(Player*)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return NULL;
	}
	if(player->animacao == NULL)
	{
		printf(" EM: Player->player_getImagem(Player*)\n");
		printf(" \tERRO: Player*->animacao == NULL\n");
		printf(" \tCarregou a tabela de Sprites ? (abortando)\n");
		return NULL;
	}
	return animacao_getImagemCompleta(player->animacao);
}

int player_getVelocidade(Player* player)
{
	if(player == NULL)
	{
		printf(" EM: Player->player_getVelocidade(Player*)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return ERRO;
	}
	return player->velocidade;
}

int player_getX(Player* player)
{
	if(player == NULL)
	{
		printf(" EM: Player->player_getX(Player*)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return ERRO;
	}
	return player->posicao.x;
}

int player_getY(Player* player)
{
	if(player == NULL)
	{
		printf(" EM: Player->player_getY(Player*)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return ERRO;
	}
	return player->posicao.y;
}

int player_getWidth(Player* player)
{
	if(player == NULL)
	{
		printf(" EM: Player->player_getWidth(Player*)\n");
		printf(" \tERRO: Player* == NULL, abortando \n");
		return ERRO;
	}
	if(player->animacao == NULL)
	{
		printf(" EM: Player->player_getWidth(Player*)\n");
		printf(" \tERRO: animacao não inicializada\n");
		printf(" \tDica: carregue a tabela de sprites antes de chamar essa função\n");
		printf(" \tAbortando\n");
		return ERRO;
	}
	return animacao_getWidth(player->animacao);
}

int player_getHeight(Player* player)
{
	if(player == NULL)
	{
		printf(" EM: Player->player_getHeight(Player*)\n");
		printf(" \tERRO: Player* == NULL\n");
		return ERRO;
	}
	if(player->animacao == NULL)
	{
		printf(" EM: Player->player_getHeight(Player*)\n");
		printf(" \tERRO: animacao não inicializada\n");
		printf(" \tDica: carregue a tabela de sprites antes de chamar essa função\n");
		printf(" \tAbortando\n");
		return ERRO;
	}
	return animacao_getHeight(player->animacao);
}

SDL_Rect* player_getPosicao(Player* player)
{
	if(player == NULL)
	{
		printf(" EM: Player->player_getPosicao(Player*)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return NULL;
	}
	return &player->posicao;
}

bool player_getBaixo(Player* player)
{
	if(player == NULL)
	{
		printf(" EM: Player->player_getBaixo(Player*)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return false;
	}
	return player->baixo;
}

bool player_getCima(Player* player)
{
	if(player == NULL)
	{
		printf(" EM: Player->player_getCima(Player*)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return false;
	}
	return player->cima;
}
bool player_getEsquerda(Player* player)
{
	if(player == NULL)
	{
		printf(" EM: Player->player_getEsquerda(Player*)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return false;
	}
	return player->esquerda;
}
bool player_getDireita(Player* player)
{
	if(player == NULL)
	{
		printf(" EM: Player->player_getDireita(Player*)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return false;
	}
	return player->direita;
}

/*SETTERS*/
void player_setTamanhoTotal(Player* player, int width, int height)
{
	if(player == NULL)
	{
		printf(" EM: Player-> player_setTamanhoTotal(Player*, int, int)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return;
	}
	if(player->animacao == NULL)
	{
		printf(" EM: Player->player_setTamanhoTotal(Player*, int, int)\n");
		printf(" \tERRO: Player*->animacao == NULL\n");
		printf(" \tCarregou a tabela de sprites ?\n");
		printf(" \tAbortando\n");
		return;
	}
	animacao_setTamanhoTotal(player->animacao, width, height);
	return;
}

void player_setX(Player* player, int x)/* Para Movimentação Facilitada */
{
	if(player == NULL)
	{
		printf(" EM: Player->player_setX(Player*, int)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return;
	}
	if(player->animacao == NULL)
	{
		printf(" EM: Player->player_setX(Player*, int)\n");
		printf(" \tERRO: Player*->animacao == NULL\n");
		printf(" \tCarregou a tabela de sprites ? (abortando)\n");
		return;
	}
	player->posicao.x = x;
	animacao_setPosicao(player->animacao, player->posicao.x, player->posicao.y);
	return;
}

void player_setY(Player* player, int y)/* Para Movimentação facilitada */
{
	if(player == NULL)
	{
		printf(" EM: Player->player_setY(Player*, int)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return;
	}
	if(player->animacao == NULL)
	{
		printf(" EM: Player->player_setY(Player*, int)\n");
		printf(" \tERRO: Player*->animacao == NULL\n");
		printf(" \tCarregou a tabela de sprites ? (abortando)\n");
		return;
	}
	player->posicao.y = y;
	animacao_setPosicao(player->animacao, player->posicao.x, player->posicao.y);
	return;
}

void player_setPosicao(Player* player, int x, int y)/* Para posicionamento inicial */
{
	if(player == NULL)
	{
		printf(" EM: Player-> player_setPosicao(Player*, int, int)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return;
	}
	if(player->animacao == NULL)
	{
		printf(" EM: Player-> player_setPosicao(Player*, int, int)\n");
		printf(" \tERRO: Player*->animacao == NULL\n");
		printf(" \tCarregou a tabela de sprites ? (abortando)\n");
		return;
	}
	animacao_setPosicao(player->animacao, x, y);
	player_setX(player, x);
	player_setY(player, y);
	return;
}

void player_setVelocidade(Player* player, int velocidade)
{
	if(player == NULL)
	{
		printf(" EM: Player->player_getVelocidade(Player*, int)");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return;
	}
	player->velocidade = velocidade;
}

void player_setBaixo(Player* player, bool x)
{
	if(player ==NULL)
	{
		printf(" EM: Player->player_setBaixo(Player*, bool)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return;
	}
	if(player->animacao ==NULL)
	{
		printf(" EM: Player->player_setBaixo(Player*, bool)\n");
		printf(" \tERRO: Animacao de player == NULL, abortando\n");
		return;
	}
	player->baixo = x;
	if(player->baixo)/* Dessa forma buga menos a parte de print da animacao */
	{
		animacao_setLinha(player->animacao, 0);/* Muda Posicao da animação */
		animacao_start(player->animacao);
	}
	else
	{
		animacao_stop(player->animacao);
	}
	return;
}

void player_setCima(Player* player, bool x)
{
	if(player ==NULL)
	{
		printf(" EM: Player->player_setCima(Player*, bool)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return;
	}
	if(player->animacao ==NULL)
	{
		printf(" EM: Player->player_setCima(Player*, bool)\n");
		printf(" \tERRO: Animacao de player == NULL, abortando\n");
		return;
	}
	player->cima = x;
	if(player->cima)/* Dessa forma buga menos a parte de print da animacao */
	{
		animacao_setLinha(player->animacao, 3);/* Muda Posicao da animação */
		animacao_start(player->animacao);
	}
	else
	{
		animacao_stop(player->animacao);
	}
	return;
}

void player_setEsquerda(Player* player, bool x)
{
	if(player ==NULL)
	{
		printf(" EM: Player->player_setEsquerda(Player*, bool)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return;
	}
	if(player->animacao ==NULL)
	{
		printf(" EM: Player->player_setEsquerda(Player*, bool)\n");
		printf(" \tERRO: Animacao de player == NULL, abortando\n");
		return;
	}
	player->esquerda = x;
	if(player->esquerda)/* Dessa forma buga menos a parte de print da animacao */
	{
		animacao_setLinha(player->animacao, 1);/* Muda Posicao da animação */
		animacao_start(player->animacao);
	}
	else
	{
		animacao_stop(player->animacao);
	}
	return;
}

void player_setDireita(Player* player, bool x)
{
	if(player ==NULL)
	{
		printf(" EM: Player->player_setDireita(Player*, bool)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return;
	}
	if(player->animacao ==NULL)
	{
		printf(" EM: Player->player_setDireita(Player*, bool)\n");
		printf(" \tERRO: Animacao de player == NULL, abortando\n");
		return;
	}
	player->direita = x;
	if(player->direita)/* Dessa forma buga menos a parte de print da animacao */
	{
		animacao_setLinha(player->animacao, 2);/* Muda Posicao da animação */
		animacao_start(player->animacao);
	}
	else
	{
		animacao_stop(player->animacao);
	}
	return;
}


void player_toString(Player* player)
{
	printf("Jogador:  X = %d,  Y = %d,  W = %d,  H = %d,   Velocidade = %d\n ", player->posicao.x, player->posicao.y, player->posicao.w, player->posicao.h, player->velocidade);
}

/*COMANDOS*/
void player_start(Player* player)
{
	if(player == NULL)
	{
		printf(" EM: Player-> player_start(Player*)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return;
	}
	animacao_start(player->animacao);
	return;
}

void player_stop(Player* player)
{
	if(player == NULL)
	{
		printf(" EM: Player-> player_stop(Player*)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return;
	}
	animacao_stop(player->animacao);
	return;
}

bool player_loadSheet(Player* player, Tela* tela, char* endereco, int linhas, int colunas)
{
	if(player == NULL)
	{
		printf(" EM: Player->player_loadSheet(Player*, Tela*, char*, int, int)\n");
		printf(" \tERRO: Player* == NULL\n");
		return false;
	}
	if(tela == NULL)
	{
		printf(" EM: Player->player_loadSheet(Player*, Tela*, char*, int, int)\n");
		printf(" \tERRO: Tela* == NULL\n");
		return false;
	}
	if(endereco == NULL)
	{
		printf(" EM: Player->player_loadSheet(Player*, Tela*, char*, int, int)\n");
		printf(" \tERRO: char* == NULL\n");
		return false;
	}
	animacao_loadSheet(player->animacao, tela, endereco, linhas, colunas);
	animacao_setDefaultSprite(player->animacao, 0);
	animacao_setLinha(player->animacao, 0);
	animacao_stop(player->animacao);
	return true;
}


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
	animacao_print(player->animacao, tela);
	return true;
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
	if(player == NULL)
	{
		printf(" EM: Player->player_ouvinte(Player*, Tela*)\n");
		printf(" \tERRO: Player* == NULL, abortando\n");
		return;
	}
	if(tela == NULL)
	{
		printf(" EM: Player->player_ouvinte(Player*, Tela*)\n");
		printf(" \tERRO: Tela* == NULL, abortando\n");
		return;
	}
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
