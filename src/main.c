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
	Retangulo* retangulo = new_retangulo();
	Botao* botao = new_botao();
	Botao* btSair = new_botao();
	
	Tela* tela = new_tela();
	tela_setTitle(tela, "Teste de orientação a objetos em C ");
	tela_setSize(tela, 1000, 700);
	tela_setCor(tela, 50, 50, 50);

	retangulo_setTamanho(retangulo, 300, 200);
	retangulo_setPosicao(retangulo, 200, 300);
	retangulo_setCor(retangulo, 32, 120, 14);
	
	texto_setFonte(texto, "fonte.ttf", 50);
	SDL_Color cor;
	cor.r = 10;
	cor.g = 50;
	cor.b = 100;
	texto_setCor(texto, 10, 50, 100);
	texto_setTexto(texto, "Testando");
	texto_updateTexto(texto,tela);
	texto_setPosicao(texto, 200, 300);

	player_setVelocidade(player,  5);
	player_setTextura(player, tela, "images/sprites/player.png");
	player_setX(player, 10);
	player_setY(player, 10);
	player_setVelocidade(player2, 2);
	player_setTextura(player2, tela, "images/sprites/player.png");
	player_setX(player2, 90);
	player_setY(player2, 90);

	botao_setCorTexto(botao, 132, 223, 123);
	botao_setCorDentro(botao, 100, 40, 50);
	botao_setCorFora(botao, 40, 100, 50);
	botao_setCorClique(botao, 50, 40, 100);
	botao_setTexto(botao, "Testando 1 2 3");
	botao_update(botao, tela);
	botao_setPosicao(botao, 400, 200);

	botao_setCorTexto(btSair, 200, 30, 50);
	botao_setCorDentro(btSair, 40, 200, 200);
	botao_setCorFora(btSair, 40, 100, 100);
	botao_setCorClique(btSair, 50, 100, 100);
	botao_setTexto(btSair, "Sair");
	botao_update(btSair, tela);
	botao_setPosicao(btSair, 400, 500);


	player_toString(player2);
	player_toString(player);
	texto_toString(texto);
	FPESSES = SDL_GetTicks();

	while(!close)
	{
		while(tela_getEvento(tela))
		{
			close = tela_getSair(tela);
			if(tela_getTeclaApertada(tela))
			{
				switch(tela_getTecla(tela))
				{
					case(SDLK_w):
						player_setCima(player,true);
						player_setCima(player2,true);
						break;
					case(SDLK_a):
						player_setEsquerda(player, true);
						player_setEsquerda(player2, true);
						break;
					case(SDLK_s):
						player_setBaixo(player, true);
						player_setBaixo(player2, true);
						break;
					case(SDLK_d):
						player_setDireita(player, true);
						player_setDireita(player2, true);
						break;
					default:
						break;
				}
			}
			else if(tela_getTeclaSolta(tela))
			{
				switch(tela_getTecla(tela))
				{
					case(SDLK_w):
						player_setCima(player,false);
						player_setCima(player2,false);
						break;
					case(SDLK_a):
						player_setEsquerda(player, false);
						player_setEsquerda(player2, false);
						break;
					case(SDLK_s):
						player_setBaixo(player, false);
						player_setBaixo(player2, false);
						break;
					case(SDLK_d):
						player_setDireita(player, false);
						player_setDireita(player2, false);
						break;
					default:
						break;
				}
			}
			else 
			{
				tela_getMouse(tela);
				botao_ouvinte(botao, tela);
				close = botao_ouvinte(btSair, tela);
			}


		}
		
		if(FPESSES +10 < SDL_GetTicks())
		{
			player_movimenta(player, tela);//Leia: player se movimenta pela tela
			player_movimenta(player2, tela);
			FPESSES = SDL_GetTicks();
		}

		tela_limpa(tela);
		botao_print(botao, tela);
		player_print(player, tela);
		retangulo_printCompleto(retangulo, tela);
		player_print(player2, tela);
		texto_print(texto, tela);
		botao_print(btSair, tela);
		tela_update(tela);
	}

	delete_botao(botao);
	delete_botao(btSair);
	delete_texto(texto);
	delete_tela(tela);
	delete_player(player);
	delete_player(player2);
//	sair(window);

	return 0;
}
