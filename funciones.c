#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void CargaDeFichas(articulos_t *articulos)
{
    int opc = 0, sucursal, i, articulo_index;
    char articulo[90];

    do {
        printf("Ingrese la descripcion del articulo: \n");
        scanf("%s", articulo);

        i = 0;

        while ((articulos + i)->descripcion[0] && strcmp(articulo, (articulos + i)->descripcion))i++;

        if(i>= cant_articulos) break; /*Evita que se desborden los punteros*/

        articulo_index = i;
        strcpy((articulos + articulo_index)->descripcion, articulo);

        printf("\n%s, Indice: %d\n",(articulos + articulo_index)->descripcion, articulo_index + 1);

        do
        {
            printf("Para que sucursal va a realizar la carga? (1, 2, 3): ");
            scanf("%d", &sucursal);
            if(sucursal > 3 || sucursal < 1) printf("Sucursal invalida. Vuelva a intentar. \n");
        }while(sucursal > 3 || sucursal < 1);  /*Validacion del numero de sucursal*/

        do
        {
            printf("Ingrse la cantidad del articulo para la sucursal %d: ", sucursal);
            scanf("%d", &(articulos + articulo_index)->cant_sucursal[sucursal - 1]);
            if((articulos + articulo_index)->cant_sucursal[sucursal - 1] < 1)
            printf("Ingrese una cantidad valida mayor que cero. \n");
        }while((articulos + articulo_index)->cant_sucursal[sucursal - 1] < 1); /*Validacion de cantidades mayores que cero*/



        (articulos + articulo_index)->total =
            (articulos + articulo_index)->cant_sucursal[SUCURSAL1] +
            (articulos + articulo_index)->cant_sucursal[SUCURSAL2] +
            (articulos + articulo_index)->cant_sucursal[SUCURSAL3];
        do
        {
            printf("Desea ingresar otro articulo? 1-SI 2-NO\n");
            scanf("%d", &opc);
            if(opc > 2 || opc < 1) printf("Ingrese una opcion valida, 1 o 2.\n");
        }while(opc > 2 || opc < 1); /*Validacion opciones validas*/


    } while (opc == 1);
}

void OrdenamientoDeFichas(articulos_t *articulos)
{
    int i, opc=0, aux=0;
    char articulo_aux[90];

    for (opc = 1; opc < cant_articulos; opc++)
    {
        for (i = 0; i < cant_articulos - 1; i++)
        {
            if ((articulos + i)->total < (articulos + i + 1)->total)
            {
                strcpy(articulo_aux, (articulos + i)->descripcion);
                strcpy((articulos + i)->descripcion, (articulos + i + 1)->descripcion);
                strcpy((articulos + i + 1)->descripcion, articulo_aux);

                aux = (articulos + i)->cant_sucursal[SUCURSAL1];
                (articulos + i)->cant_sucursal[SUCURSAL1] = (articulos + i + 1)->cant_sucursal[SUCURSAL1];
                (articulos + i + 1)->cant_sucursal[SUCURSAL1] = aux;

                aux = (articulos + i)->cant_sucursal[SUCURSAL2];
                (articulos + i)->cant_sucursal[SUCURSAL2] = (articulos + i + 1)->cant_sucursal[SUCURSAL2];
                (articulos + i + 1)->cant_sucursal[SUCURSAL2] = aux;

                aux = (articulos + i)->cant_sucursal[SUCURSAL3];
                (articulos + i)->cant_sucursal[SUCURSAL3] = (articulos + i + 1)->cant_sucursal[SUCURSAL3];
                (articulos + i + 1)->cant_sucursal[SUCURSAL3] = aux;

                aux = (articulos + i)->total;
                (articulos + i)->total = (articulos + i + 1)->total;
                (articulos + i + 1)->total = aux;
            }
        }
    }
}

void MuestraDeFichas(articulos_t *articulos)
{
    int i = 0;
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while (i < cant_articulos && (articulos + i)->descripcion[0])
    {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n",
               (articulos + i)->descripcion,
               (articulos + i)->cant_sucursal[SUCURSAL1],
               (articulos + i)->cant_sucursal[SUCURSAL2],
               (articulos + i)->cant_sucursal[SUCURSAL3],
               (articulos + i)->total);
        i++;
    }
}
