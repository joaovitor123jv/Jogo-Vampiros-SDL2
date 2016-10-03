#include"./String.h"

struct String
{
	char letra;
	struct String* proximo;
};

/*  String* new_string();  Mudar construtores de TODAS as "classes" de acordo com o exemplo:  new_string() → new_String()  */

String* new_String()
{
	String* string = malloc(sizeof(String));
	if(string == NULL)
	{
		printf("EM: String->new_string()\n");
		printf("\t Não foi possível alocar a memória\n");
	}
	string->letra = '\0';
	string->proximo = NULL;
	return string;
}


bool string_setTexto(String* string, char* texto)
{
	printf(" Função setString Aberta\n");
	if(string == NULL)
	{
		printf(" EM: String-> string_setTexto(String*, char*)\n");
		printf("\t Erro: String* igual a NULL\n");
		return false;
	}
	if(texto == NULL)
	{
		printf(" EM: String-> string_setTexto(String*, char*))\n");
		printf("\t Erro: char* igual a NULL\n");
		return false;
	}
	if(sizeof *texto <= TAMANHO_MAXIMO_TEXTO)
	{
		printf(" Liberado\n");
		return true;

	}
	else
	{
		printf(" Bloqueado\n");
		return false;
	}
}

void delete_string(String *string)
{
	if(string == NULL)
	{
		printf(" EM: String-> delete_string(String*)\n");
		printf("\t ERRO: String* igual a NULL, abortando\n");
		return;
	}
	printf(" Deletando\n");
	free(string);
	printf(" Deletado\n");
	return;
}
