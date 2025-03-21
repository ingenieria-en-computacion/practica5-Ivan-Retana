#include "nodo.h"
#include <stdlib.h>

Nodo *crear_nodo(Dato d){
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo ->dato=d;
    nuevo->sig=NULL;
    return nuevo;

}

void borrar_nodo(Nodo *n){
    if(n->sig==NULL){
        free(n);
    }
}
void print_nodo(Nodo *n){
    printf("Dato: %i. \nSig: %p\n", n->dato, n->sig);
}
