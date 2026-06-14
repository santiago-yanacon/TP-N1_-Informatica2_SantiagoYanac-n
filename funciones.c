#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void CargaDeFichas(articulos_t *articulos)
{
    int i, opc=0, sucursal, articulo_index;
    char articulo[90];

    do{
        printf("Ingrese la descripcion del articulo: \n");
        scanf("%s", articulo);

        i=0;

        while(articulos[i].descripcion[0] && strcmp(articulo, articulos[i].descripcion)) i++;
        articulo_index=i;
        strcpy(articulos[i].descripcion, articulo);

        printf("\n%s, Indice: %d\n", articulos[articulo_index].descripcion, articulo_index+1);

        printf("Para que sucursal va a realizar la carga?(1,2,3): ");
        scanf("%d", &sucursal);

        printf("Ingrse la cantidad del articulo para la sucursal%d: ", sucursal);
        scanf("%d", &articulos[articulo_index].cant_sucursal[sucursal-1]);

        articulos[articulo_index].total=articulos[articulo_index].cant_sucursal[SUCURSAL1]+articulos[articulo_index].cant_sucursal[SUCURSAL2]+articulos[articulo_index].cant_sucursal[SUCURSAL3];

        printf("Desea ingresar otro articulo? 1-SI 2-NO\n");
        scanf("%d", &opc);

    }while(opc==1);
}

void OrdenamientoDeFichas(articulos_t *articulos)
{
    int i=0, opc=0, articulo_index=0; /*articulo index será nuesto auxiliar*/
    char articulo[90];

    for ( opc = 1; opc < cant_articulos; opc++)
    {
        for ( i = 0; i < cant_articulos-1; i++)
        {
            if(articulos[i].total<articulos[i+1].total){

                strcpy(articulo, articulos[i].descripcion);
                strcpy(articulos[i].descripcion, articulos[i+1].descripcion);
                strcpy(articulos[i+1].descripcion, articulo);

                articulo_index = articulos[i].cant_sucursal[1];
                articulos[i].cant_sucursal[1] = articulos[i+1].cant_sucursal[1];
                articulos[i+1].cant_sucursal[1] = articulo_index;

                articulo_index = articulos[i].cant_sucursal[2];
                articulos[i].cant_sucursal[2] = articulos[i+1].cant_sucursal[2];
                articulos[i+1].cant_sucursal[2] = articulo_index;

                articulo_index = articulos[i].cant_sucursal[3];
                articulos[i].cant_sucursal[3] = articulos[i+1].cant_sucursal[3];
                articulos[i+1].cant_sucursal[3] = articulo_index;

                articulo_index = articulos[i].total;
                articulos[i].total = articulos[i+1].total;
                articulos[i+1].total = articulo_index;
            }

        }

    }
}

void MuestraDeFichas(articulos_t *articulos)
{
    int i=0;
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while(i < cant_articulos && articulos[i].descripcion[0]){
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n",
                articulos[i].descripcion,
                articulos[i].cant_sucursal[SUCURSAL1],
                articulos[i].cant_sucursal[SUCURSAL2],
                articulos[i].cant_sucursal[SUCURSAL3],
                articulos[i].total);
        i++;
    }
}
