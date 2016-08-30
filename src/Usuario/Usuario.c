#include"Usuario.h"

typedef struct Private
{
	char* nome;
	char* senha;
	char* email;
}Private;

char* usuario_getNome();
void usuario_setNome(char* nome);

Usuario* new_usuario(void)
{
	Usuario* usr = malloc(sizeof(usr));
	usr->private = (Private*)malloc(sizeof(Private));
	usr->setNome = usuario_setNome;
	usr->getNome = usuario_getNome;
	return usr;
}

void usuario_setNome(char *nome)
{
	__usuario__->private->nome = nome;
}


char* usuario_getNome()
{
	return __usuario__->private->nome;
}


Usuario* usuario(Usuario* __usuario)
{
	__usuario__ = __usuario;
	return __usuario;
}
