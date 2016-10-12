#include"Includes.h"

#define BOTAO_ENTRAR_PRESSIONADO 1

int main(/*int argc, char* args[] */)
{
	bool fechar=false;
	int retorno = 0;

	Tela* tela = new_tela();
/*	CaixaTexto* caixaTexto = new_caixaTexto();*/
	Botao* btEntrar = new_botao();
	Botao* btSair = new_botao();
	Botao* btFullScreen = new_botao();
	Texto* txtLogin = new_texto();

	tela_setTitle(tela, "Tela de Login ");
	tela_setSize(tela, 600, 400);
	tela_setCor(tela, 0x17, 0x17, 0x17);
	tela_setAlpha(tela, 50);

	texto_setTexto(txtLogin, "Login: ");
	texto_updateTexto(txtLogin, tela);
	texto_setPosicao(txtLogin, 10, (tela_getHeight(tela)-texto_getHeight(txtLogin))/2);

	botao_setTexto(btEntrar, "Entrar");
	botao_update(btEntrar, tela);
	botao_setPosicao(btEntrar, (tela_getWidth(tela)-botao_getWidth(btEntrar)), 300);

	botao_setTexto(btSair, "Sair");
	botao_update(btSair, tela);
	botao_setPosicao(btSair, (tela_getWidth(tela)-botao_getWidth(btSair))/2, 300);

	botao_setTexto(btFullScreen, "Tela Cheia");
	botao_update(btFullScreen, tela);
	botao_setPosicao(btFullScreen, 0, 300);
/*
	caixaTexto_setFonte(caixaTexto, "fonte.ttf", 50);
	caixaTexto_setTamanho(caixaTexto, tela, 300, 30);
	caixaTexto_setPosicao(caixaTexto, texto_getX(txtLogin)+texto_getWidth(txtLogin), tela_getHeight(tela)/2 );
	caixaTexto_setTamanhoString(caixaTexto, 30);
*/
	while(!fechar)
	{
		while(tela_getEvento(tela))
		{
			fechar= tela_getSair(tela);
			tela_getMouse(tela);
			if(botao_ouvinte(btEntrar, tela))
			{
				retorno = BOTAO_ENTRAR_PRESSIONADO;
				fechar = true;
			}
			if(!fechar)
			{
				fechar = botao_ouvinte(btSair, tela);
			}
			if(botao_ouvinte(btFullScreen, tela))
			{
				tela_setFullScreen(tela);
			}
	/*		caixaTexto_ouvinte(caixaTexto, tela);*/
		}
		tela_limpa(tela);
		texto_print(txtLogin, tela);
		botao_print(btEntrar, tela);
/*		caixaTexto_print(caixaTexto, tela);*/
		botao_print(btSair, tela);
		botao_print(btFullScreen, tela);
		tela_update(tela);
	}

	/* tela de senha */
	if(retorno == BOTAO_ENTRAR_PRESSIONADO)
	{
		tela_setTitle(tela, "Tela de Senha ");

		texto_setTexto(txtLogin, "Senha: ");
		texto_updateTexto(txtLogin, tela);
		texto_setPosicao(txtLogin, 10, (tela_getHeight(tela)-texto_getHeight(txtLogin))/2);

		botao_setTexto(btEntrar, "Entrar");
		botao_update(btEntrar, tela);
		botao_setPosicao(btEntrar, (tela_getWidth(tela)-botao_getWidth(btEntrar)), 300);

		botao_setTexto(btSair, "Sair");
		botao_update(btSair, tela);
		botao_setPosicao(btSair, (tela_getWidth(tela)-botao_getWidth(btSair))/2, 300);

		botao_setTexto(btFullScreen, "Tela Cheia");
		botao_update(btFullScreen, tela);
		botao_setPosicao(btFullScreen, 0, 300);
/*
		caixaTexto_setFonte(caixaTexto, "fonte.ttf", 50);
		caixaTexto_setTamanho(caixaTexto, tela, 300, 30);
		caixaTexto_setPosicao(caixaTexto, texto_getX(txtLogin)+texto_getWidth(txtLogin), tela_getHeight(tela)/2 );
		caixaTexto_setTamanhoString(caixaTexto, 30);*/
		fechar = false;

		while(!fechar)
		{
			while(tela_getEvento(tela))
			{
				fechar= tela_getSair(tela);
				tela_getMouse(tela);
				if(botao_ouvinte(btEntrar, tela))
				{
					retorno = BOTAO_ENTRAR_PRESSIONADO;
				}
					if(!fechar)
				{
					fechar = botao_ouvinte(btSair, tela);
				}
				if(botao_ouvinte(btFullScreen, tela))
				{
					tela_setFullScreen(tela);
				}
			/*	caixaTexto_ouvinte(caixaTexto, tela);*/
			}
			tela_limpa(tela);
			texto_print(txtLogin, tela);
			botao_print(btEntrar, tela);
		/*	caixaTexto_print(caixaTexto, tela);*/
			botao_print(btSair, tela);
			botao_print(btFullScreen, tela);
			tela_update(tela);
		}
	}
	delete_botao(btEntrar);
	delete_botao(btFullScreen);
	delete_botao(btSair);

	delete_texto(txtLogin);
/*	delete_caixaTexto(caixaTexto);*/

	delete_tela(tela);
	return 0;
}
