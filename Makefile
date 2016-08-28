#FONTE Especifica quais arquivos vão ser compilados como parte do projeto
FONTE = main.c
OBJETO = $(FONTE:.c=.o)
PASTA_FONTE=sources

#EXE especifica o nome do executavel
EXE = jogo

#Bandeiras de Compilador
PASSO1 = -c
PASSO2 = -o

#LINKERS
LINKER= -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer 

#ESPECIFICA COMPILADOR
CC = gcc

#Esse é o Alvo que compila o executável
all :
	cd $(PASTA_FONTE); $(CC) $(PASSO1) $(FONTE)
	cd $(PASTA_FONTE); $(CC) $(PASSO2) ./$(EXE) $(OBJETO) $(LINKER)
	echo "Removendo Arquivos remanescentes da compilação"
	cd $(PASTA_FONTE); rm $(OBJETO)
