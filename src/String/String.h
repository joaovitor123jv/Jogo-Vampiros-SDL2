#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#ifndef TAMANHO_MAXIMO_TEXTO
#define TAMANHO_MAXIMO_TEXTO 10
#endif

#ifndef bool
#define bool char
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

typedef struct String String;

/* Construtor */
String* new_String();

/* Destrutor */
void delete_string(String*);

/* Setters */
bool string_setTexto(String*, char*);

/* Getters */
