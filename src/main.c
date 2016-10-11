#include"Includes.h"

int main( int argc, char* args[] )
{
	bool close=false;
	int FPESSES;
	int w, h;

	system("./telaDeLogin");

	Player* player = new_player();
	Player* player2 = new_player();
	Botao* botao = new_botao();
	Botao* btSair = new_botao();
	Botao* btFullScreen = new_botao();
/*	Imagem* imagem = new_imagem();*/
	
	Tela* tela = new_tela();
	tela_setTitle(tela, "Tela de Login ");
	tela_setSize(tela, 800, 600);
	tela_setCor(tela, 50, 50, 70);
	tela_setAlpha(tela, 50);

/*	imagem_setImagem(imagem, tela, "images/fundo.png");*/

	player_setVelocidade(player,  5);
	player_setTextura(player, tela, "images/sprites/player.png");
	player_setX(player, 10);
	player_setY(player, 10);
	player_setVelocidade(player2, 2);
	player_setTextura(player2, tela, "images/sprites/player.png");
	player_setX(player2, 90);
	player_setY(player2, 90);

	botao_setTexto(botao, "Entrar");
	botao_update(botao, tela);
	botao_setPosicao(botao, 250, 500);

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
			player_ouvinte(player2, tela);
			if(botao_ouvinte(botao, tela))
			{
			}
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
			player_movimenta(player2, tela);
			FPESSES = SDL_GetTicks();
		}

		tela_limpa(tela);
/*		imagem_print(imagem, tela);*/
		botao_print(botao, tela);
		player_print(player, tela);
		player_print(player2, tela);
		botao_print(btSair, tela);
		botao_print(btFullScreen, tela);
		tela_update(tela);
	}

	delete_botao(botao);
	delete_botao(btFullScreen);
	delete_botao(btSair);


/*	delete_imagem(imagem);*/

	delete_tela(tela);
	delete_player(player);
	delete_player(player2);

	return 0;
}
