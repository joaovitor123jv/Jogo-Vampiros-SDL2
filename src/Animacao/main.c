#include"../Tela/Tela.h"
#include"Animacao.h"

void main()
{
	char close = 0;
	Tela* tela = new_tela();
	tela_setSize(tela, 800, 600);
	tela_setTitle(tela, "Qualquer coisa, é só um teste");
	tela_setCor(tela, 50,50,50);

	Animacao* animacao = new_animacao();
	animacao_loadSheet(animacao, tela, "../../images/sprites/spritesheet.png", 4, 3);
	animacao_setTamanhoTotal(animacao, 300, 300);
	animacao_setPosicao(animacao, 0, 0);
		tela_limpa(tela);

	animacao_setParte(animacao, 2, 2);
		animacao_print(animacao, tela);

	animacao_setParte(animacao, 1, 1);
	animacao_setPosicao(animacao, 100, 100);
		animacao_print(animacao, tela);


	tela_update(tela);
	while(!close)
	{
		while(tela_getEvento(tela))
		{
			close = tela_getSair(tela);
		}
	}
	delete_tela(tela);
	delete_animacao(animacao);
	return;
}
