#include"Animacao.h"

struct Animacao
{
	SDL_Rect* posicao;
	SDL_Texture* imagem;
	SDL_Rect total;
	int linhas;
	int colunas;
};

/* CONSTRUTOR */ 
Animacao* new_animacao(void) 
{
	Animacao* animacao = malloc(sizeof(Animacao)); 
	if(animacao == NULL) 
	{
		printf("EM: Animacao-> new_animacao(void)\n"); 
		printf("\tERRO: Não foi possível criar animação:\n");
		printf("\tMemória insuficiente\n");
		return NULL;
	}
	animacao->imagem = NULL;
	animacao->posicao = NULL;
	animacao->total = { 0, 0, 0, 0};
	linhas = 0;
	colunas = 0;
	return animacao;
}

/* DESTRUTOR */
void delete_animacao(Animacao* animacao)
{
	if(animacao == NULL)
	{
		printf("EM: Animacao-> delete_animacao(Animacao*)\n");
		printf("\tERRO: argumento Animacao* igual a NULL\n");
		return;
	}
	if(animacao->imagem != NULL)
	{
		SDL_DestroyTexture(animacao->imagem);
		animacao->imagem = NULL;
	}
	if(animacao->posicao != NULL)
	{
		free(animacao->posicao);
		animacao->posicao = NULL;
	}
	free(animacao);
	animacao = NULL;
}
