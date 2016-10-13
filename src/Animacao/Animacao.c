#include"Animacao.h"

struct Animacao
{
	SDL_Rect** posicao;
	Imagem* imagem;
	SDL_Rect total;
	int linha;
	int coluna;
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
	animacao->linhas = 0;/* Quantidade de linhas */
	animacao->colunas = 0;/* QUantidade de colunas */
	animacao->linha = 0;/* Linha de print */
	animacao->coluna = 0;/* Coluna de print */
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

bool animacao_setPosicao(Animacao* animacao, int x, int y)
{
	if(animacao == NULL)
	{
		printf(" EM: Animacao->animacao_setPosicao(Animacao*, int, int)\n");
		printf(" \tERRO: Animacao* == NULL, abortando\n");
		return false;
	}
	if(animacao->imagem == NULL)
	{
		printf(" EM: Animacao->animacao_setPosicao(Animacao*, int, int)\n");
		printf(" \tERRO: SpriteSheet não inicializada, abortando\n");
		printf(" \tImagem == NULL\n");
		return false;
	}
	if(animacao->posicao == NULL)
	{
		printf(" EM: Animacao->animacao_setPosicao(Animacao*, int, int)\n");
		printf(" \tERRO: SpriteSheet não inicializada, abortando\n");
		printf(" \tTabela de posições == NULL\n");
		return false;
	}
	imagem_setPosicao(animacao->imagem, x, y);
	return true;
}

bool animacao_setParte(Animacao* animacao, int linha, int coluna)
{
	if(animacao == NULL)
	{
		printf(" EM: Animacao->animacao_setPosicao(Animacao*, int, int)\n");
		printf(" \tERRO: Animacao* == NULL, abortando\n");
		return false;
	}
	if(animacao->imagem == NULL)
	{
		printf(" EM: Animacao->animacao_setPosicao(Animacao*, int, int)\n");
		printf(" \tERRO: SpriteSheet não inicializada, abortando\n");
		printf(" \tImagem == NULL\n");
		return false;
	}
	if(animacao->posicao == NULL)
	{
		printf(" EM: Animacao->animacao_setPosicao(Animacao*, int, int)\n");
		printf(" \tERRO: SpriteSheet não inicializada, abortando\n");
		printf(" \tTabela de posições == NULL\n");
		return false;
	}
	if( (linha < 0 || linha>animacao->linhas) || (coluna<0 || coluna>animacao->colunas) )
	{
		printf(" EM: Animacao->animacao_setPosicao(Animacao*, int, int)\n");
		printf(" \tERRO: Argumento inteiro inválido ( need int >= 0), abortando\n");
		return false;
	}
	animacao->linha = linha;
	animacao->coluna = coluna;
	return true;
}

/* COMANDOS */
bool animacao_loadSheet(Animacao* animacao, Tela* tela, char* endereco, int linhas, int colunas)/* OK */
{
	Imagem* imagem = new_imagem();
	int x, y, i;
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
	if(linhas <= 0 || colunas <= 0 )
	{
		printf(" EM: Animacao-> animacao_loadSheet(Animacao*, char*, int, int)\n");
		printf(" \tERRO: argumento \"int\" deve ser positivo, e maior que zero, abortando\n");
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
	if(animacao->posicao == NULL)
	{
		animacao->posicao = (SDL_Rect**)malloc(sizeof(SDL_Rect*) * colunas);
		if(animacao->posicao == NULL)
		{
			printf(" EM: animacao_loadSheet()\n");
			printf(" \tERRO, memória insuficiente\n");
			delete_imagem(imagem);
			return false;
		}
		for(i=0; i<colunas; i++)
		{
			animacao->posicao[i] = (SDL_Rect*)malloc(sizeof(SDL_Rect)*linhas);
			if(animacao->posicao[i] == NULL)
			{
				printf(" EM: animacao_loadSheet\n");
				printf(" \tERRO, memória insuficiente\n");
				delete_imagem(imagem);
				return false;
			}
		}
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
	for(x=0; x<colunas; x++)
	{
		for(y=0; y<linhas; y++)
		{
			animacao->posicao[x][y].x = (int)(imagem_getWidth(imagem)/animacao->colunas) * x;
			animacao->posicao[x][y].y = (int)(imagem_getHeight(imagem)/animacao->linhas) * y;
			animacao->posicao[x][y].w = (int)imagem_getWidth(imagem)/colunas;
			animacao->posicao[x][y].h = (int)imagem_getHeight(imagem)/linhas;
		}
	}
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

void animacao_print(Animacao* animacao, Tela* tela)
{
	if(animacao == NULL)
	{
		printf(" EM: Animacao-> animacao_print(Animacao*, Tela*)\n");
		printf(" \tERRO: Argumento Animacao* == NULL, abortando\n");
		return;
	}
	if(tela == NULL)
	{
		printf(" EM: Animacao-> animacao_print(Animacao*, Tela*)\n");
		printf(" \tERRO: Argumento Tela* == NULL, abortando\n");
		return;
	}
	if(animacao->posicao == NULL)
	{
		printf(" EM: Animacao-> animacao_print(Animacao*, Tela*)\n");
		printf(" \tERRO: Tabela de Sprites não foi carregada, abortando\n");
		return;
	}
	imagem_printPart(animacao->imagem, tela, animacao->posicao[animacao->linha][animacao->coluna]);
	return;
}
