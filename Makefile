#FONTE Especifica quais arquivos vão ser compilados como parte do projeto
FONTE=main.c
USUARIO=Usuario.c
TELA=Tela.c
PLAYER=Player.c
TEXTO=Texto.c
RETANGULO=Retangulo.c
BOTAO=Botao.c
IMAGEM=Imagem.c
CAIXA_TEXTO=CaixaTexto.c

PASTA_FONTE=src
PASTA_TELA=Tela
PASTA_PLAYER=Player
PASTA_TEXTO=Texto
PASTA_RETANGULO=Retangulo
PASTA_BOTAO=Botao
PASTA_IMAGEM=Imagem
PASTA_CAIXA_TEXTO=CaixaTexto

OBJETO = $(FONTE:.c=.o) $(TELA:.c=.o) $(PLAYER:.c=.o) $(TEXTO:.c=.o) $(RETANGULO:.c=.o) $(BOTAO:.c=.o) $(IMAGEM:.c=.o) $(CAIXA_TEXTO:.c=.o)

#EXE especifica o nome do executavel
EXE = jogo

#Bandeiras de Compilador
OTIMIZADOR=-o3
PASSO1 = -c
PASSO2 =$(OTIMIZADOR) -o

#Atenção! Passo 2 com Otimização 3  (de 0 → 3)

#LINKERS
LINKER= -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer 

#ESPECIFICA COMPILADOR
CC = gcc

#Esse é o Alvo que compila o executável
all :
	echo "Compilando arquivos para funcionamento da tela"
	cd $(PASTA_FONTE)/$(PASTA_TELA); $(CC) $(PASSO1) $(TELA)
	cd $(PASTA_FONTE)/$(PASTA_TELA); mv $(TELA:.c=.o) ../
	echo "Compilando arquivos para funcionamento do player"
	cd $(PASTA_FONTE)/$(PASTA_PLAYER); $(CC) $(PASSO1) $(PLAYER)
	cd $(PASTA_FONTE)/$(PASTA_PLAYER); mv $(PLAYER:.c=.o) ../
	echo "Compilando arquivos para funcionamento do texto"
	cd $(PASTA_FONTE)/$(PASTA_TEXTO); $(CC) $(PASSO1) $(TEXTO)
	cd $(PASTA_FONTE)/$(PASTA_TEXTO); mv $(TEXTO:.c=.o) ../
	echo "Compilando arquivos para funcionamento do Retângulo (Botão) (1)"
	cd $(PASTA_FONTE)/$(PASTA_RETANGULO); $(CC) $(PASSO1) $(RETANGULO)
	cd $(PASTA_FONTE)/$(PASTA_RETANGULO); mv $(RETANGULO:.c=.o) ../
	echo "Compilando arquivos para funcionamento do Botao (Botão) (2)"
	cd $(PASTA_FONTE)/$(PASTA_BOTAO); $(CC) $(PASSO1) $(BOTAO)
	cd $(PASTA_FONTE)/$(PASTA_BOTAO); mv $(BOTAO:.c=.o) ../
	echo "Compilando arquivos para funcionamento de Imagem "
	cd $(PASTA_FONTE)/$(PASTA_IMAGEM); $(CC) $(PASSO1) $(IMAGEM)
	cd $(PASTA_FONTE)/$(PASTA_IMAGEM); mv $(IMAGEM:.c=.o) ../
	echo "Compilando arquivos para funcionamento de Entrada de Texto "
	cd $(PASTA_FONTE)/$(PASTA_CAIXA_TEXTO); $(CC) $(PASSO1) $(CAIXA_TEXTO)
	cd $(PASTA_FONTE)/$(PASTA_CAIXA_TEXTO); mv $(CAIXA_TEXTO:.c=.o) ../
	echo "Compilando arquivos para funcionamento do principal"
	cd $(PASTA_FONTE); $(CC) $(PASSO1) $(FONTE)
	cd $(PASTA_FONTE); $(CC) $(PASSO2) ../$(EXE) $(OBJETO) $(LINKER)
	echo "Removendo Arquivos remanescentes da compilação"
	cd $(PASTA_FONTE); rm $(OBJETO)


run:
	./$(EXE)
