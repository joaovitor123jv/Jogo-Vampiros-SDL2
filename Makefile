#FONTE Especifica quais arquivos vão ser compilados como parte do projeto
FONTE=main.c
USUARIO=Usuario.c
TELA=Tela.c
PLAYER=Player.c

OBJETO = $(FONTE:.c=.o) $(TELA:.c=.o) $(PLAYER:.c=.o)
PASTA_FONTE=src
PASTA_TELA=Tela
PASTA_PLAYER=Player

#EXE especifica o nome do executavel
EXE = jogo

#Bandeiras de Compilador
PASSO1 = -c
PASSO2 =-o3 -o

#Atenção! Passo 2 com Otimização 3  (de 0 → 3)

#LINKERS
LINKER= -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer 

#ESPECIFICA COMPILADOR
CC = gcc

#Esse é o Alvo que compila o executável
all :
	cd $(PASTA_FONTE)/$(PASTA_TELA); $(CC) $(PASSO1) $(TELA)
	cd $(PASTA_FONTE)/$(PASTA_TELA); mv $(TELA:.c=.o) ../
	cd $(PASTA_FONTE)/$(PASTA_PLAYER); $(CC) $(PASSO1) $(PLAYER)
	cd $(PASTA_FONTE)/$(PASTA_PLAYER); mv $(PLAYER:.c=.o) ../
	cd $(PASTA_FONTE); $(CC) $(PASSO1) $(FONTE)
	cd $(PASTA_FONTE); $(CC) $(PASSO2) ../$(EXE) $(OBJETO) $(LINKER)
	echo "Removendo Arquivos remanescentes da compilação"
	cd $(PASTA_FONTE); rm $(OBJETO)
