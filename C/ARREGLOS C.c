#include <stdio.h>

void imprimirArreglo(int arr[], int tamano) {
    printf("[");
    for (int i = 0; i < tamano; i++) {
        printf("%d%s", arr[i], (i < tamano - 1) ? ", " : "");
    }
    printf("]\n");
}

// BÚSQUEDA SECUENCIAL
int busqueda_secuencial(int arr[], int tamano, int objetivo) {
    for (int i = 0; i < tamano; i++) {
        if (arr[i] == objetivo) {
            return i;  // DEVUELVE EL INDICE SI LO ENCUENTRA
        }
    }
    return -1;  // DEVUELVE -1 SI NO LO ENCUENTRA
}

// BÚSQUEDA BINARIA
int busqueda_binaria(int arr[], int tamano, int objetivo) {
    int inicio = 0;
    int fin = tamano - 1;
    
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (arr[medio] == objetivo) {
            return medio;
        } else if (arr[medio] < objetivo) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1;
}

int main() {
    // ARREGLO BASE (con espacio suficiente para inserciones)
    int arreglo[10] = {10, 20, 30, 40, 50};
    int n = 5; // Tamaño actual del arreglo

    // RECORRIDO SECUENCIAL
    printf("1. Recorrido Secuencial \n");
    for (int i = 0; i < n; i++) {
        printf("Indice %d: %d\n", i, arreglo[i]);
    }

    // RECORRIDO INVERSO
    printf("\n2. Recorrido Inverso\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("Indice %d: %d\n", i, arreglo[i]);
    }

    // INSERCIÓN AL INICIO
    printf("\n3. Insercion al Inicio\n");
    // Desplazar elementos a la derecha
    for (int i = n; i > 0; i--) {
        arreglo[i] = arreglo[i - 1];
    }
    arreglo[0] = 5;  // Inserta el 5 en el índice 0
    n++;
    printf("Arreglo tras insertar 5 al inicio: ");
    imprimirArreglo(arreglo, n);

    // INSERCIÓN AL FINAL
    printf("\n4. Insercion al Final\n");
    arreglo[n] = 60;  // Agrega el 60 al final
    n++;
    printf("Arreglo tras insertar 60 al final: ");
    imprimirArreglo(arreglo, n);

    // ELIMINACIÓN AL INICIO
    printf("\n5. Eliminacion al Inicio\n");
    int eliminado_inicio = arreglo[0];  // ELIMINA EL DATO QUE ESTA EN EL INDICE 0
    for (int i = 0; i < n - 1; i++) {
        arreglo[i] = arreglo[i + 1];
    }
    n--;
    printf("Elemento eliminado: %d\n", eliminado_inicio);
    printf("Arreglo resultante: ");
    imprimirArreglo(arreglo, n);

    // ELIMINACIÓN AL FINAL
    printf("\n6. Eliminacion al Final\n");
    int eliminado_final = arreglo[n - 1];  // ELIMINA EL ULTIMO ELEMENTO
    n--;
    printf("Elemento eliminado: %d\n", eliminado_final);
    printf("Arreglo resultante: ");
    imprimirArreglo(arreglo, n);

    // ELIMINACIÓN ELEGIDA (Por índice)
    printf("\n7. Eliminacion Elegida \n");
    int indice_eliminar = 2;  // ELEJIMOS EL INDICE A ELIMINAR
    int eliminado_elegido = arreglo[indice_eliminar];
    for (int i = indice_eliminar; i < n - 1; i++) {
        arreglo[i] = arreglo[i + 1];
    }
    n--;
    printf("Elemento eliminado en indice %d: %d\n", indice_eliminar, eliminado_elegido);
    printf("Arreglo resultante: ");
    imprimirArreglo(arreglo, n);

    // BÚSQUEDA SECUENCIAL
    printf("\n8. Busqueda Secuencial\n");
    int objetivo_sec = 40;
    int pos_sec = busqueda_secuencial(arreglo, n, objetivo_sec);
    printf("Buscando %d: Encontrado en indice %d\n", objetivo_sec, pos_sec);

    // 9. BÚSQUEDA BINARIA
    printf("\n9. Busqueda Binaria\n");
    // HAY QUE RECORDAR QUE EN LA BUSQUEDA BINARIA EL ARREGLO DEBE ESTAR ORDENADO
    int arreglo_ordenado[] = {10, 20, 30, 40, 50, 60, 70};
    int n_ord = 7;
    int objetivo_bin = 50;
    int pos_bin = busqueda_binaria(arreglo_ordenado, n_ord, objetivo_bin);
    printf("Arreglo ordenado: ");
    imprimirArreglo(arreglo_ordenado, n_ord);
    printf("Buscando %d via Binaria: Encontrado en indice %d\n", objetivo_bin, pos_bin);

    return 0;
}