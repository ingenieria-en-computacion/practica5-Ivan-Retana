#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINEA 256


typedef struct NodoPila {
    char dato;
    struct NodoPila* siguiente;
} NodoPila;


typedef struct NodoCola {
    char dato;
    struct NodoCola* siguiente;
} NodoCola;

typedef struct {
    NodoCola *frente, *final;
} Cola;


void push(NodoPila** cima, char c) {
    NodoPila* nuevo = (NodoPila*)malloc(sizeof(NodoPila));
    nuevo->dato = c;
    nuevo->siguiente = *cima;
    *cima = nuevo;
}

char pop(NodoPila** cima) {
    if (*cima == NULL) return '\0';
    NodoPila* temp = *cima;
    char c = temp->dato;
    *cima = temp->siguiente;
    free(temp);
    return c;
}

void encolar(Cola* q, char c) {
    NodoCola* nuevo = (NodoCola*)malloc(sizeof(NodoCola));
    nuevo->dato = c;
    nuevo->siguiente = NULL;
    if (q->final == NULL) {
        q->frente = q->final = nuevo;
    } else {
        q->final->siguiente = nuevo;
        q->final = nuevo;
    }
}

char desencolar(Cola* q) {
    if (q->frente == NULL) return '\0';
    NodoCola* temp = q->frente;
    char c = temp->dato;
    q->frente = temp->siguiente;
    if (q->frente == NULL) q->final = NULL;
    free(temp);
    return c;
}


int es_palindromo(const char* frase) {
    NodoPila* pila = NULL;
    Cola cola = {NULL, NULL};

    
    for (int i = 0; frase[i] != '\0'; i++) {
        if (isalnum(frase[i])) {
            char c = tolower(frase[i]);
            push(&pila, c);
            encolar(&cola, c);
        }
    }

    
    while (pila != NULL) {
        if (pop(&pila) != desencolar(&cola)) {
            return 0;  
        }
    }
    return 1; 
}


void procesar_archivo(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    char linea[MAX_LINEA];
    int num_linea = 1;
    while (fgets(linea, MAX_LINEA, archivo)) {
        linea[strcspn(linea, "\n")] = '\0';  
        if (es_palindromo(linea)) {
            printf("Línea %d: Es un palíndromo -> %s\n", num_linea, linea);
        } else {
            printf("Línea %d: No es un palíndromo -> %s\n", num_linea, linea);
        }
        num_linea++;
    }

    fclose(archivo);
}


int main() {
    const char* archivo_texto = "frases.txt";  
    procesar_archivo(archivo_texto);
    return 0;
}
