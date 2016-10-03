/* Arquivo para testar ./String.h */
#include"String.h"
#include<stdio.h>

int main()
{
	printf(" Testando 1 2 3\n");
	String* string = new_String();
	printf(" Testado \n");
	string_setTexto(string, "Estou definindo um texto aqui rapá");
	delete_string(string);
	return 0;
}
