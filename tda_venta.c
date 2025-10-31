#include <stdio.h>
#include <stdlib.h>
#include "tda_venta.h"

void crearCola(tCola *c) {
    c->frente = NULL;
    c->final = NULL;
}

int colaVacia(tCola *c) {
    return c->frente == NULL;
}

void encolar(tCola *c, tVenta v) {
    tNodo *nuevo = malloc(sizeof(tNodo));
    nuevo->venta = v;
    nuevo->sig = NULL;

    if (colaVacia(c))
        c->frente = nuevo;
    else
        c->final->sig = nuevo;

    c->final = nuevo;
}

tVenta desencolar(tCola *c) {
    tVenta v = c->frente->venta;
    tNodo *aux = c->frente;

    c->frente = c->frente->sig;

    if (c->frente == NULL)
        c->final = NULL;

    free(aux);
    return v;
}

void mostrarCola(tCola c) {
    tNodo *aux = c.frente;

    while (aux != NULL) {
        printf("Venta #%d | Producto: %d | Cantidad: %d | Total: $%.2f\n",
               aux->venta.idVenta,
               aux->venta.codigoProducto,
               aux->venta.cantidad,
               aux->venta.total);
        aux = aux->sig;
    }
}

