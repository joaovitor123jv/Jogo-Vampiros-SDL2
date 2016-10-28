FONTE=main.c
USUARIO=Usuario.c
TELA=Tela.c
PLAYER=Player.c
TEXTO=Texto.c
RETANGULO=Retangulo.c
BOTAO=Botao.c
IMAGEM=Imagem.c
CAIXA_TEXTO=CaixaTexto.c
ANIMACAO=Animacao.c

PASTA_FONTE=src
PASTA_TELA=Tela
PASTA_PLAYER=Player
PASTA_TEXTO=Texto
PASTA_RETANGULO=Retangulo
PASTA_BOTAO=Botao
PASTA_IMAGEM=Imagem
PASTA_CAIXA_TEXTO=CaixaTexto

OBJETO = $(TELA:.c=.o) $(TEXTO:.c=.o) $(RETANGULO:.c=.o) $(BOTAO:.c=.o) $(IMAGEM:.c=.o) $(CAIXA_TEXTO:.c=.o)

#EXE especifica o nome do executavel
EXE = play

#Bandeiras de Compilador
WARNING_FLAGS=-Wunused-result
OTIMIZADOR=-o3 -ansi
PASSO1 = -c -ansi
PASSO2 = $(WARNING_FLAGS) $(OTIMIZADOR) -o

#Atenção! Passo 2 com Otimização 3  (de 0 → 3)

#LINKERS
LINKER= -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer 

#ESPECIFICA COMPILADOR
CC = gcc

#ESPECIFICA PROGRAMA DEBUGGER A SER USADO
DEBUGGER=valgrind

#Esse é o Alvo que compila o executável
all : Tela Player Texto Retangulo Botao Imagem CaixaTexto telaDeLogin Animacao
	@echo
	@echo "Compilando arquivos para funcionamento do principal"
	cd $(PASTA_FONTE); $(CC) $(PASSO1) $(FONTE)
	cd $(PASTA_FONTE); $(CC) $(PASSO2) ../$(EXE) $(FONTE:.c=.o) $(OBJETO) $(ANIMACAO:.c=.o) $(PLAYER:.c=.o) $(LINKER)
	@echo
	@echo "Removendo Arquivos remanescentes da compilação"
	cd $(PASTA_FONTE); rm $(OBJETO) $(FONTE:.c=.o) $(ANIMACAO:.c=.o) $(PLAYER:.c=.o)

#----------------------------------------------------------------------------------------------
#TELA DE LOGIN
TELA_DE_LOGIN=telaDeLogin.c

telaDeLogin: Bibliotecas 
	@echo
	@echo "Compilando arquivos para funcionamento da Tela de Login"
	cd $(PASTA_FONTE); $(CC) $(PASSO1) $(TELA_DE_LOGIN)
	cd $(PASTA_FONTE); $(CC) $(PASSO2) ../$(TELA_DE_LOGIN:.c=) $(TELA_DE_LOGIN:.c=.o) $(OBJETO) $(LINKER)
	@echo
	@echo "Removendo Arquivos remanescentes da Tela de Login"
	cd $(PASTA_FONTE); rm $(TELA_DE_LOGIN:.c=.o)
#FIM TELA_DE_LOGIN ----------------------------------------------------------------------------




#BIBLIOTECAS ----------------------------------------------------------------------------------
Bibliotecas: Tela Player Texto Retangulo Botao Imagem CaixaTexto

Tela:
	@echo
	@echo "Compilando arquivos para funcionamento da tela"
	cd $(PASTA_FONTE)/$(PASTA_TELA); $(CC) $(PASSO1) $(TELA)
	cd $(PASTA_FONTE)/$(PASTA_TELA); mv $(TELA:.c=.o) ../

Player: Tela Animacao
	@echo
	@echo "Compilando arquivos para funcionamento do player"
	cd $(PASTA_FONTE)/$(PASTA_PLAYER); $(CC) $(PASSO1) $(PLAYER)
	cd $(PASTA_FONTE)/$(PASTA_PLAYER); mv $(PLAYER:.c=.o) ../

Texto: Tela
	@echo
	@echo "Compilando arquivos para funcionamento do texto"
	cd $(PASTA_FONTE)/$(PASTA_TEXTO); $(CC) $(PASSO1) $(TEXTO)
	cd $(PASTA_FONTE)/$(PASTA_TEXTO); mv $(TEXTO:.c=.o) ../

Retangulo: Tela
	@echo
	@echo "Compilando arquivos para funcionamento do Retângulo (Botão) (1)"
	cd $(PASTA_FONTE)/$(PASTA_RETANGULO); $(CC) $(PASSO1) $(RETANGULO)
	cd $(PASTA_FONTE)/$(PASTA_RETANGULO); mv $(RETANGULO:.c=.o) ../

Botao: Tela Retangulo Texto
	@echo
	@echo "Compilando arquivos para funcionamento do Botao (Botão) (2)"
	cd $(PASTA_FONTE)/$(PASTA_BOTAO); $(CC) $(PASSO1) $(BOTAO)
	cd $(PASTA_FONTE)/$(PASTA_BOTAO); mv $(BOTAO:.c=.o) ../

Imagem: Tela
	@echo
	@echo "Compilando arquivos para funcionamento de Imagem "
	cd $(PASTA_FONTE)/$(PASTA_IMAGEM); $(CC) $(PASSO1) $(IMAGEM)
	cd $(PASTA_FONTE)/$(PASTA_IMAGEM); mv $(IMAGEM:.c=.o) ../

CaixaTexto: Tela Retangulo Texto
	@echo
	@echo "Compilando arquivos para funcionamento de Entrada de Texto "
	cd $(PASTA_FONTE)/$(PASTA_CAIXA_TEXTO); $(CC) $(PASSO1) $(CAIXA_TEXTO)
	cd $(PASTA_FONTE)/$(PASTA_CAIXA_TEXTO); mv $(CAIXA_TEXTO:.c=.o) ../

Animacao: Tela Texto Imagem
	@echo
	@echo "Compilando arquivos para funcionamento de Animacao de Personagem "
	cd $(PASTA_FONTE)/$(ANIMACAO:.c=); $(CC) $(PASSO1) $(ANIMACAO)
	cd $(PASTA_FONTE)/$(ANIMACAO:.c=); mv $(ANIMACAO:.c=.o) ../

#FIM BIBLIOTECAS----------------------------------------------------------------------------



	


run:
	./$(EXE)

debug:
	$(DEBUGGER) ./$(EXE)
