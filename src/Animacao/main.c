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

	while(!close)
	{
		while(tela_getEvento(tela))
		{
			close = tela_getSair(tela);
		}
		tela_limpa(tela);
		animacao_printTotal(animacao, tela);
		tela_update(tela);
	}
	return;
}
