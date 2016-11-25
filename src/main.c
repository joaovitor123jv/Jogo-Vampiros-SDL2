#include"Includes.h"

int main( int argc, char* args[] )
{
	bool close=false;
	int FPESSES;
	int w, h;
	int resposta;

	resposta = system("./telaDeLogin");

	if(resposta == 0 || (resposta == 35584))
	{
		printf(" Não Autorizado\n");
		printf(" Retorno : %d\n", resposta);
		return 0;
	}
	else
	{
		printf(" Retorno : %d\n", resposta);
	}

	Player* player = new_player();
	Botao* btSair = new_botao();
	Botao* btFullScreen = new_botao();
	Imagem* imgTeste;
	SDL_Texture* textura;
	int modoImagem;
	Imagem* imagem = new_imagem();
	
	Tela* tela = new_tela();
	tela_setTitle(tela, "Tela de Login ");
	tela_setSize(tela, 800, 600);
	tela_setCor(tela, 50, 50, 70);
	tela_setAlpha(tela, 50);

	imagem_setImagem(imagem, tela, "images/fundo.png");
	imagem_setTamanho(imagem, tela_getWidth(tela), tela_getHeight(tela));

	player_loadSheet(player, tela, "images/sprites/spritesheet.png", 4, 4);
	player_start(player);
	player_setVelocidade(player,  2);
	player_setX(player, 10);
	player_setY(player, 10);
	
	/* Início Teste */
	imgTeste = player_getImagem(player);
	SDL_SetTextureBlendMode(imagem_getTextura(player_getImagem(player)), SDL_BLENDMODE_MOD); /* MOD deu meio certo */
/*	SDL_SetTextureAlphaMod(imagem_getTextura(player_getImagem(player)), 192);*/
	/* Fim teste */

	botao_setTexto(btSair, "Sair");
	botao_update(btSair, tela);
	botao_setPosicao(btSair, 450, 500);

	botao_setTexto(btFullScreen, "Tela Cheia");
	botao_update(btFullScreen, tela);
	botao_setPosicao(btFullScreen, 50, 500);



	FPESSES = SDL_GetTicks();

	while(!close)
	{
		while(tela_getEvento(tela))
		{
			close = tela_getSair(tela);
			tela_getMouse(tela);
			player_ouvinte(player, tela);
			if(!close)
			{
				close = botao_ouvinte(btSair, tela);
			}
			if(botao_ouvinte(btFullScreen, tela))
			{
				tela_setFullScreen(tela);
			}

		}
		
		if(FPESSES +10 < SDL_GetTicks())
		{
			player_movimenta(player, tela);/*Leia: player se movimenta pela tela*/
			FPESSES = SDL_GetTicks();
		}

		tela_limpa(tela);
		imagem_print(imagem, tela);
		player_print(player, tela);
		botao_print(btSair, tela);
		botao_print(btFullScreen, tela);
		tela_update(tela);
	}

	delete_botao(btFullScreen);
	delete_botao(btSair);

	delete_imagem(imagem);

	delete_player(player);

	delete_tela(tela);
	return 0;
}
