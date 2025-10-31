#include <stdio.h>
#include <stdlib.h>
#include "tda_producto.h"
#include "tda_venta.h"
#include "util_ordenamiento.h"

#define N 3

void menuPrincipal(tProducto productos[], int n, tCola *ventas, int *idVentaGlobal);
void registrarVenta(tProducto productos[], int n, tCola *ventas, int *idVentaGlobal);
void mostrarStock(const tProducto productos[], int n);
void ordenarProductos(tProducto productos[], int n);

int main() {
    tProducto productos[N];
    tCola ventas;
    int idVentaGlobal = 1;

    iniciarProducto(&productos[0], 1, "Yerba Mate Tradicional", 10, 2500);
    iniciarProducto(&productos[1], 2, "Yerba Mate Premium", 5, 3500);
    iniciarProducto(&productos[2], 3, "Yerba Mate Organica", 8, 2800);

    crearCola(&ventas);
    menuPrincipal(productos, N, &ventas, &idVentaGlobal);
    return 0;
}

void menuPrincipal(tProducto productos[], int n, tCola *ventas, int *idVentaGlobal) {
    int opcion;

    do {
        system("cls"); // Windows
        // system("clear"); // Linux

        printf("=== SISTEMA MATECONTROL ===\n");
        printf("1. Registrar venta\n");
        printf("2. Mostrar stock\n");
        printf("3. Ordenar productos\n");
        printf("4. Mostrar ventas\n");
        printf("5. Salir\n");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // limpia ENTER

        switch(opcion) {
            case 1:
                registrarVenta(productos, n, ventas, idVentaGlobal);
                break;

            case 2:
                mostrarStock(productos, n);
                break;

            case 3:
                ordenarProductos(productos, n);
                break;

            case 4:
                system("cls");
                printf("=== HISTORIAL DE VENTAS ===\n");

                mostrarCola(*ventas);

                printf("\nPresione ENTER para volver...");
                getchar();
                break;

            case 5:
                break;

            default:
                printf("Opcion invalida. Presione ENTER para continuar...");
                getchar();
        }

    } while(opcion != 5);
}

void registrarVenta(tProducto productos[], int n, tCola *ventas, int *idVentaGlobal) {
    system("cls");

    printf("=== REGISTRAR VENTA ===\n");
    int i;

    for (i = 0; i < n; i++) {
        printf("%d. %s (Stock: %d)\n",
               productos[i].codigo, productos[i].nombre, productos[i].stock);
    }

    int codigo, cantidad;
    printf("\nIngrese codigo de producto: ");
    scanf("%d", &codigo);
    printf("Ingrese cantidad: ");
    scanf("%d", &cantidad);
    getchar();

    for (i = 0; i < n; i++) {
        if (productos[i].codigo == codigo) {

            if (productos[i].stock < cantidad) {
                printf("\nError: stock insuficiente.\n");
                getchar();
                return;
            }

            tVenta v;
            v.idVenta = (*idVentaGlobal)++;
            v.codigoProducto = codigo;
            v.cantidad = cantidad;
            v.total = cantidad * productos[i].precio;

            encolar(ventas, v);

            modificarStock(&productos[i], cantidad);

            printf("\nVenta registrada con exito!\n");
            getchar();
            return;
        }
    }

    printf("\nError: producto no encontrado.\n");
    getchar();
}

void mostrarStock(const tProducto productos[], int n) {
    system("cls");
    printf("=== STOCK DE PRODUCTOS ===\n");

    int i;
    for (i = 0; i < n; i++) {
        printf("%d - %s | Stock: %d | $%.2f\n",
               productos[i].codigo,
               productos[i].nombre,
               productos[i].stock,
               productos[i].precio);
    }

    printf("\nPresione ENTER para volver...");
    getchar();
}

void ordenarProductos(tProducto productos[], int n) {
    system("cls");
    printf("=== PRODUCTOS ORDENADOS POR STOCK ===\n");

    ordenarPorStock(productos, n);

    int i;
    for (i = 0; i < n; i++) {
        printf("%d - %s | Stock: %d\n",
               productos[i].codigo, productos[i].nombre, productos[i].stock);
    }

    printf("\nPresione ENTER para volver...");
    getchar();
}

