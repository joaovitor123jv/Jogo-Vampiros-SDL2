#include"Includes.h"

void sair(SDL_Window *janela);

int main( int argc, char* args[] )
{
	bool close=false;
	int FPESSES;
	int w, h;
	Player* player = new_player();
	Player* player2 = new_player();
	Texto* texto = new_texto();
	Texto* texto2 = new_texto();
	CaixaTexto* caixaTexto = new_caixaTexto();
	Botao* botao = new_botao();
	Botao* btSair = new_botao();
	Botao* btFullScreen = new_botao();
/*	Imagem* imagem = new_imagem();*/
	
	Tela* tela = new_tela();
	tela_setTitle(tela, "Tela de Login ");
	tela_setSize(tela, 800, 600);
	tela_setCor(tela, 50, 50, 70);
	tela_setAlpha(tela, 50);
	
	texto_setFonte(texto, "fonte.ttf", 50);
	texto_setCor(texto, 30, 30, 30);
	texto_setTexto(texto, "Tela de Autenticação");
	texto_updateTexto(texto,tela);
	texto_setPosicao(texto, (tela_getWidth(tela)-texto_getWidth(texto))/2, 50);


	texto_setFonte(texto2, "fonte2.ttf", 50);
	texto_setCor(texto2, 30, 30, 30);
	texto_setTexto(texto2, "Tela de Autenticação");
	texto_updateTexto(texto2,tela);
	texto_setPosicao(texto2, (tela_getWidth(tela)-texto_getWidth(texto))/2, 100);

/*	imagem_setImagem(imagem, tela, "images/fundo.png");*/

	player_setVelocidade(player,  5);
	player_setTextura(player, tela, "images/sprites/player.png");
	player_setX(player, 10);
	player_setY(player, 10);
	player_setVelocidade(player2, 2);
	player_setTextura(player2, tela, "images/sprites/player.png");
	player_setX(player2, 90);
	player_setY(player2, 90);

	botao_setCorTexto(botao, 255, 216, 0);
	botao_setCorDentro(botao, 0, 81, 131);
	botao_setCorFora(botao, 0, 52, 83);
	botao_setCorClique(botao, 36, 0, 205);
	botao_setTexto(botao, "Entrar");
	botao_update(botao, tela);
	botao_setPosicao(botao, 250, 500);

	botao_setCorTexto(btSair, 255, 216, 0);
	botao_setCorDentro(btSair, 0, 81, 131);
	botao_setCorFora(btSair, 0, 52, 83);
	botao_setCorClique(btSair, 36, 0, 205);
	botao_setTexto(btSair, "Sair");
	botao_update(btSair, tela);
	botao_setPosicao(btSair, 450, 500);

	botao_setCorTexto(btFullScreen, 255, 216, 0);
	botao_setCorDentro(btFullScreen, 0, 81, 131);
	botao_setCorFora(btFullScreen, 0, 52, 83);
	botao_setCorClique(btFullScreen, 36, 0, 205);
	botao_setTexto(btFullScreen, "Tela Cheia");
	botao_update(btFullScreen, tela);
	botao_setPosicao(btFullScreen, 50, 500);

	caixaTexto_setFonte(caixaTexto, "fonte.ttf", 50);
	caixaTexto_setTamanho(caixaTexto, tela, 500, 40);
	caixaTexto_setPosicao(caixaTexto, 100, 200 );
	caixaTexto_setTamanhoString(caixaTexto, 30);

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
			caixaTexto_ouvinte(caixaTexto, tela);


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
		caixaTexto_print(caixaTexto, tela);
		texto_print(texto, tela);
		texto_print(texto2, tela);
		botao_print(btSair, tela);
		botao_print(btFullScreen, tela);
		tela_update(tela);
	}

	delete_botao(botao);
	delete_botao(btFullScreen);
	delete_botao(btSair);
	delete_texto(texto);
	delete_texto(texto2);

	delete_caixaTexto(caixaTexto);

/*	delete_imagem(imagem);*/

	delete_tela(tela);
	delete_player(player);
	delete_player(player2);

	return 0;
}
