#include "cola.h"

Cola crear_cola(){
    Cola c;
    c.frente = -1;
    c.fin = -1;
    return c;
}

bool es_vacia(Cola c){
    return c.fin == -1;
}

void encolar(Cola* c, Dato d){
    if(es_vacia(*c)){
        c->frente=c->fin=0;
        c->datos[c->frente]= d;
        return;
    }
    if (c->fin < TAM-1)
    {
        c->fin++;
        c->datos[c->fin] = d;
        return;
    }
    printf("La cola esta llena\n");
}

void desencolar(Cola *c, Dato d){
    if (!es_vacia(*c))
    {
        for (int i = 1; i <=c->fin; i++)
        {
            c->datos[i-1]=c->datos[i];
            return;
        }
        printf("La cola esta vacia\n");
    }
    
}
void print_cola(Cola c){
    if (es_vacia(c))
    {
        printf("[]\n");
        return;
    }
    printf("[");
    }
