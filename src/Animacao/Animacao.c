#include"Animacao.h"

struct Animacao
{
	SDL_Rect** posicao;
	Imagem* imagem;
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
	animacao->total.x = 0;
	animacao->total.y = 0;
	animacao->total.w = 0;
	animacao->total.h = 0;
	animacao->linhas = 0;
	animacao->colunas = 0;
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
		delete_imagem(animacao->imagem);
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

/* SETTERS */
bool animacao_setTamanhoTotal(Animacao* animacao, int w, int h)
{
	if(animacao == NULL)
	{
		printf(" EM: Animacao-> animacao_setTamanhoTotal(Animacao*, Tela*, int, int)\n");
		printf(" \tERRO: argumento Animacao* igual a NULL, abortando\n");
		return false;
	}
	if(w < 0 || h < 0 )
	{
		printf(" EM: Animacao-> animacao_setTamanhoTotal(Animacao*, Tela*, int, int)\n");
		printf(" \tERRO: argumento \"int\" deve ser positivo, abortando\n");
		return false;
	}
	if(animacao->imagem == NULL)
	{
		printf(" EM: Animacao-> animacao_setTamanhoTotal(Animacao*, Tela*, int, int)\n");
		printf(" \tERRO: não foi possível carregar spritesheet, abortando\n");
		return false;
	}
	return imagem_setTamanho(animacao->imagem, w, h);
}

/* COMANDOS */
bool animacao_loadSheet(Animacao* animacao, Tela* tela, char* endereco, int linhas, int colunas)
{
	Imagem* imagem = new_imagem();
	if(animacao == NULL)
	{
		printf(" EM: Animacao-> animacao_loadSheet(Animacao*, char*, int, int)\n");
		printf(" \tERRO: argumento Animacao* igual a NULL, abortando\n");
		delete_imagem(imagem);
		return false;
	}
	if(endereco == NULL)
	{
		printf(" EM: Animacao-> animacao_loadSheet(Animacao*, char*, int, int)\n");
		printf(" \tERRO: argumento char* igual a NULL, abortando\n");
		delete_imagem(imagem);
		return false;
	}
	if(linhas < 0 || colunas < 0 )
	{
		printf(" EM: Animacao-> animacao_loadSheet(Animacao*, char*, int, int)\n");
		printf(" \tERRO: argumento \"int\" deve ser positivo, abortando\n");
		delete_imagem(imagem);
		return false;
	}
	if(imagem == NULL)
	{
		printf(" EM: Animacao-> animacao_loadSheet(Animacao*, char*, int, int)\n");
		printf(" \tERRO: não foi possível carregar spritesheet, abortando\n");
		delete_imagem(imagem);
		return false;
	}
	if(animacao->imagem != NULL)
	{
		delete_imagem(animacao->imagem);
		animacao->imagem = NULL;
	}
	imagem_setImagem(imagem, tela, endereco);
	animacao->imagem = imagem;
	animacao->linhas = linhas;
	animacao->colunas = colunas;
	return true;
}

void animacao_printTotal(Animacao* animacao, Tela* tela)
{
	if(animacao == NULL)
	{
		printf(" EM: Animacao-> animacao_printTotal(Animacao*, Tela*)\n");
		printf(" \tERRO: argumento Animacao* igual a NULL, abortando\n");
		return;
	}
	if(animacao->imagem == NULL)
	{
		printf(" EM: Animacao-> animacao_printTotal(Animacao*, Tela*)\n");
		printf(" \tERROR: SpriteSheet not loaded \n");
		printf(" \tAnimacao->imagem == NULL, abortando\n");
		return;
	}
	if(tela == NULL)
	{
		printf(" EM: Animacao-> animacao_printTotal(Animacao*, Tela*)\n");
		printf(" \tERRO: argumento Tela* igual a NULL, abortando\n");
		return;
	}
	imagem_print(animacao->imagem, tela);
	return;
}
