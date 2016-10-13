#include"../Tela/Tela.h"
#include"Animacao.h"

void main()
{
	char close = 0;
	Tela* tela = new_tela();
	tela_setSize(tela, 800, 600);
	tela_setTitle(tela, "Qualquer coisa, é só um teste");
	tela_setCor(tela, 50,50,50);
	tela_setAlpha(tela, 0xFF);

/*	Animacao* direita = new_animacao();
	Animacao* baixo = new_animacao();
	Animacao* esquerda = new_animacao();*/
	Animacao* animacao = new_animacao();


	animacao_loadSheet(animacao, tela, "../../images/sprites/spritesheet.png", 4, 12);
	animacao_setTamanhoTotal(animacao, 300, 300);
	animacao_setPosicao(animacao, 0, 0);
	animacao_start(animacao);
/*
	animacao_loadSheet(direita, tela, "../../images/sprites/spritesheet.png", 4, 12);
	animacao_setTamanhoTotal(direita, 300, 300);
	animacao_setPosicao(direita, 100, 100);
	animacao_setLinha(direita, 1);
	animacao_start(direita);

	animacao_loadSheet(esquerda, tela, "../../images/sprites/spritesheet.png", 4, 12);
	animacao_setTamanhoTotal(esquerda, 300, 300);
	animacao_setPosicao(esquerda, 200, 100);
	animacao_setLinha(esquerda, 3);
	animacao_start(esquerda);
	
	animacao_loadSheet(baixo, tela, "../../images/sprites/spritesheet.png", 4, 12);
	animacao_setTamanhoTotal(baixo, 300, 300);
	animacao_setPosicao(baixo, 400, 400);
	animacao_setLinha(baixo, 2);
	animacao_start(baixo);
*/
	tela_update(tela);
	while(!close)
	{
		while(tela_getEvento(tela))
		{
			close = tela_getSair(tela);
		}
		tela_limpa(tela);
		animacao_print(animacao, tela);
/*		animacao_print(direita, tela);
		animacao_print(esquerda, tela);
		animacao_print(baixo, tela);*/
		tela_update(tela);
	}
	delete_tela(tela);
	delete_animacao(animacao);
/*	delete_animacao(direita);
	delete_animacao(esquerda);
	delete_animacao(baixo);*/
	return;
}
