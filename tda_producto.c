#include <stdio.h>
#include <string.h>
#include "tda_producto.h"

void iniciarProducto(tProducto *p, int cod, char *nombre, int stock, float precio) {
    p->codigo = cod;
    strcpy(p->nombre, nombre);
    p->stock = stock;
    p->precio = precio;
}

void mostrarProducto(tProducto p) {
    printf("%d - %s | Stock: %d | $%.2f\n", p.codigo, p.nombre, p.stock, p.precio);
}

void modificarStock(tProducto *p, int cantidadVendida) {
    p->stock -= cantidadVendida;
}

