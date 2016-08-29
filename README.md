# Jogo-Vampiros-SDL2
Isso será um "Futuro jogo de Vampiros" escrito em C

para compilar (NO GNU/LINUX) faça-o com "make"
como o "jogo" é pequeno demais, ainda não é necessária sua instalação
o comando "make" irá compilar, linkar tudo, gerar seu executavel, e
limpar os arquivos objetos "*.o"


Para rodar o programa há duas maneiras (pelo terminal)
	→Usando o Make
		→Basta digitar onde o "Makefile" estiver (supondo que não moveu nenhum arquivo do lugar):
			make run

	→Rodando diretamente
		→Supondo que não moveu qualquer arquivo do lugar, haverá um arquivo executavel (de nome "jogo") na pasta do projeto, execute-o com:
			./jogo

→ Ambos os comandos são para a pasta que estão os dados doa arquivos
→ Faz-se necessária a instalação, na ausência da biblioteca SDL2, SDL2-image
→ Recomendo a instalação de SDL2-mixer e SDL2-ttf também, para compilar no futuro

	→Organização melhorada
		→Arquivos de gerenciamento da janela/tela em  Tela/
		→Arquivos de gerenciamento de animaçoes/player em Player/ (por enquanto)

