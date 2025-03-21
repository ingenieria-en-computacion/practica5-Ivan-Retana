#ifndef __COLA_H__
#define __COLA_H__
#include <stdio.h>
#include <stdbool.h>
#define TAM 100

typedef int Dato;

typedef struct _cola
{
    Dato datos[TAM];
    int frente;
    int fin;
    
}Cola;

Cola crear_cola();
bool es_vacia(Cola);
void encolar(Cola*, Dato);
void desencolar(Cola* ,Dato);
void print_cola(Cola);

#endif
