# Jogo-Vampiros-SDL2

#Problema Não está em (texto), mas em (caixaTexto)

Porque fiz testes de atualização de texto, com o botão (entrar), e não deu problema, sendo que o texto, tem mais de 31 caracteres.

*Desenvolver uma "classe" para _armazenar_ e cuidar de Strings (Ponteiros para caracter)*

#Isso será um "Futuro jogo de Vampiros" escrito em C

Para compilar (NO GNU/LINUX) faça-o com "make"
Como o "jogo" é pequeno demais, ainda não é necessária sua instalação
O comando "make" irá compilar, linkar tudo, gerar seu executavel, e limpar os arquivos objetos "*.o"


Para rodar o programa há duas maneiras (pelo terminal)

	→Usando o Make
		→Basta digitar onde o "Makefile" estiver (supondo que não moveu nenhum arquivo do lugar):
			make run

	→Rodando diretamente
		→Supondo que não moveu qualquer arquivo do lugar, haverá um arquivo executavel (de nome "jogo") na pasta do projeto, execute-o com:
			./jogo

→ Ambos os comandos são para a pasta que estão os dados dos arquivos

→ Faz-se necessária a instalação  das bibliotecas SDL2, SDL2_image, SDL2_ttf

→ Recomendo a instalação de SDL2-mixer também, para compilar no futuro (suporte a áudio)

	→Organização melhorada
		→Arquivos de gerenciamento da janela/tela em  Tela/
		→Arquivos de gerenciamento de animações/player em Player/ (por enquanto)


Testado em:
	→GNU/Linux Debian Jessie (8)
	→GNU/Linux Slackware 14.2
	→GNU/Lunux Linux Mint Rebecca
	→GNU/Linux Ubuntu 14.04
