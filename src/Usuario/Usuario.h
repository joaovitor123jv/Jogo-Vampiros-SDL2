#include<stdlib.h>
#include<string.h>
struct Usuario
{
	struct Private* private;
	void (*setNome)(char* nome);
	char *(*getNome)();
};

typedef struct Usuario Usuario;


Usuario* __usuario__;
Usuario* new_usuario(void);
Usuario* usuario(Usuario* __usuario);

