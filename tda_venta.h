#ifndef TDA_VENTA_H
#define TDA_VENTA_H

typedef struct {
    int idVenta;
    int codigoProducto;
    int cantidad;
    float total;
} tVenta;

typedef struct nodo {
    tVenta venta;
    struct nodo *sig;
} tNodo;

typedef struct {
    tNodo *frente;
    tNodo *final;
} tCola;

void crearCola(tCola *c);
int colaVacia(tCola *c);
void encolar(tCola *c, tVenta v);
tVenta desencolar(tCola *c);
void mostrarCola(tCola c);

#endif

