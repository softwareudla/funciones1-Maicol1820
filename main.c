#include <stdio.h>
#include "funciones.h"

int main() {
    char productos[10][30];
    float precios[10];
    int cantidad;

    printf("Ingrese el numero de productos (maximo 10): ");
    scanf("%d", &cantidad);

    if (cantidad > 10) {
        printf("El numero maximo de productos es 10.\n");
        return 1; // Salir si la cantidad excede el límite
    }

    LeerNombreProductos(productos, precios, cantidad);
    printf("Precio total del inventario: %.2f\n", CalcularValorTotal(precios, cantidad));
    
    int caro = ProductoMasCaro(precios, cantidad);
    printf("El producto más caro es: %s con un precio de %.2f\n", productos[caro], precios[caro]);
    
    int barato = ProductoMasBarato(precios, cantidad);
    printf("El producto más barato es: %s con un precio de %.2f\n", productos[barato], precios[barato]);
    
    printf("Precio promedio de todos los productos: %.2f\n", CalcularPromedio(precios, cantidad));
    
    char BuscarNombreProducto[30];
    printf("Ingrese el nombre del producto a buscar: ");
    scanf("%29s", BuscarNombreProducto); // Limitar la entrada a 29 caracteres
    
    int indice = BuscarProducto(productos, BuscarNombreProducto, cantidad);
    if (indice != -1) {
        printf("El producto %s tiene un precio de %.2f\n", productos[indice], precios[indice]);
    } else {
        printf("Producto no encontrado.\n");
    }

    return 0;
}
