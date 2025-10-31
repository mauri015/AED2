#ifndef TDA_PRODUCTO_H
#define TDA_PRODUCTO_H

typedef struct {
    int codigo;
    char nombre[30];
    int stock;
    float precio;
} tProducto;

void iniciarProducto(tProducto *p, int cod, char *nombre, int stock, float precio);
void mostrarProducto(tProducto p);
void modificarStock(tProducto *p, int cantidadVendida);

#endif

