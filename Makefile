#FONTE Especifica quais arquivos vão ser compilados como parte do projeto
FONTE = "sources/main.c"
OBJETO = "main.o"

#OBJ_NAME especifica o nome do executavel
OBJ_NAME = jogo

#Bandeiras de Compilador
PASSO1 = -c
PASSO2 = -o

#LINKERS
LINKER1="-lSDL2"
LINKER2="-lSDL2_image"
LINKER3="-lSDL2_ttf"
LINKER4="-lSDL2_mixer"


#ESPECIFICA COMPILADOR
CC = gcc

#Esse é o Alvo que compila o executável
all :
	$(CC) $(PASSO1) $(FONTE)
	$(CC) $(PASSO2) $(OBJ_NAME) $(OBJETO) $(LINKER1) $(LINKER2) $(LINKER3) $(LINKER4)
	echo "Removendo Arquivos remanescentes da compilação"
	rm $(OBJETO)
