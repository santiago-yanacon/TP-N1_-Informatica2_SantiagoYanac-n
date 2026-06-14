#define cant_articulos 60

#define SUCURSAL1 0
#define SUCURSAL2 1
#define SUCURSAL3 2
#define TOTAL 3

typedef struct {
    char descripcion[90];
    int cant_sucursal[3];
    int total;
}articulos_t;

void CargaDeFichas(articulos_t *articulos);
void MuestraDeFichas(articulos_t *articulos);
void OrdenamientoDeFichas(articulos_t *articulos);
