#include "cola.h"
#include "nodo.h"

Cola* crear_cola(){
       Cola *c =(Cola*)malloc(sizeof(Cola));
       c->frente=NULL;
       c->fin;
       return c;

}

bool es_vacia(Cola c){
    return c.fin ==-1;
}

void encolar(Cola* c, Dato d){
    Nodo *nuevo =crear_nodo(nodo(d));
    if (es_vacia(*c)){
    c->frente=c->fin=0;
    c->datos[c->frente]= d;
    return;
    }
    c->fin->sig = nuevo;
    c->fin =nuevo;
