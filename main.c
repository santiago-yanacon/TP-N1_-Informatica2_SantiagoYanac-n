#include <stdio.h>

#include "funciones.h"

int main()
{
    printf("Bienvenido al Final de Info 1 (Refactor)\n");
    articulos_t articulos[cant_articulos]={0};

    CargaDeFichas(articulos); /*carga de las fichas*/

    OrdenamientoDeFichas(articulos); /*ordenamiento de los datos por totales*/

    printf("----------------Lista ORDENADA por total------------------\n");

    MuestraDeFichas(articulos); /*imprime los datos ordenados por total*/

    return 0;
}
