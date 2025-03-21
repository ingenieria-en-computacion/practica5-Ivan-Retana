#ifndef _NODO_H_
#define _NODO_H_

typedef int Dato;

struct _nodo
{
    Dato dato;
    struct _nodo *sig;
};

typedef struct _nodo Nodo;

Nodo *crear_nodo(Dato d);
void borrar_nodo(Nodo*);
void print_nodo(Nodo*);

#endif
