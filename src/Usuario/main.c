#include<stdio.h>
#include"Usuario.h"

void main()
{
	Usuario* usr = new_usuario();
	printf("Digite o nome do seu usuario \n");
	char* nome;
	scanf("%s",nome); 
	usuario(usr)->setNome(nome);
	printf("Nome recebido = %s \n", usuario(usr)->getNome());
}
