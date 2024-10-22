#include <stdio.h>
#include <string.h>
#include "funciones.h"

void LeerNombreProductos(char productos[10][30], float precios[10], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        scanf("%29s", productos[i]); // Limitar la entrada a 29 caracteres
        printf("Ingrese el precio del producto %d: ", i + 1);
        scanf("%f", &precios[i]);
    }
}

float CalcularValorTotal(float precios[10], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    return total;
}

int ProductoMasCaro(float precios[10], int cantidad) {
    int indice = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > precios[indice]) {
            indice = i;
        }
    }
    return indice;
}

int ProductoMasBarato(float precios[10], int cantidad) {
    int indice = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] < precios[indice]) {
            indice = i;
        }
    }
    return indice;
}

float CalcularPromedio(float precios[10], int cantidad) {
    float total = CalcularValorTotal(precios, cantidad); // Llamar correctamente a CalcularValorTotal
    return total / cantidad;
}

int BuscarProducto(char productos[10][30], char nombre[30], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(productos[i], nombre) == 0) {
            return i;
        }
    }
    return -1; // Cambiar a -1 para indicar no encontrado
}
