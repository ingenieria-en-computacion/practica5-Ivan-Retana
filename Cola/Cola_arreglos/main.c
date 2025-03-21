#include "cola.h"

int main(){
    Cola c;
    c = crear_cola();
    print_cola(c);
    encolar(&c, 14);
    encolar(&c, 32);
    encolar(&c, 4);
    encolar(&c, 2);
    print_cola(c);
    desencolar(&c);
    desencolar(&c);
    print_cola(c);
    
    return 0;
}
