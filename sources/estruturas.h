SDL_Surface *tela_fundo;
SDL_Surface *player;
SDL_Window *window;
char nomejanela[32] = "Teste de jogo";
SDL_Event Evento;
SDL_Renderer *Renderizador;

typedef struct Sprite
{
	SDL_Texture *textura;
	int h;
	int w;
	int x;
	int y;
	int velocidade;
	SDL_Rect posicao;
}sprite;
