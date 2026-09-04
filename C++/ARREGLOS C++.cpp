#include <iostream>

using namespace std;

// Función auxiliar para imprimir el arreglo estático
void imprimirArreglo(const int arr[], int tamano) {
    cout << "[";
    for (int i = 0; i < tamano; i++) {
        cout << arr[i] << (i < tamano - 1 ? ", " : "");
    }
    cout << "]" << endl;
}

// BÚSQUEDA SECUENCIAL
int busqueda_secuencial(const int arr[], int tamano, int objetivo) {
    for (int i = 0; i < tamano; i++) {
        if (arr[i] == objetivo) {
            return i;  // DEVUELVE EL INDICE SI LO ENCUENTRA
        }
    }
    return -1;  // DEVUELVE -1 SI NO LO ENCUENTRA
}

// BÚSQUEDA BINARIA
int busqueda_binaria(const int arr[], int tamano, int objetivo) {
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
    // ARREGLO BASE (con capacidad reservada para 10 elementos)
    int arreglo[10] = {10, 20, 30, 40, 50};
    int tamano = 5; // Número de elementos ocupados actualmente

    // RECORRIDO SECUENCIAL
    cout << "1. Recorrido Secuencial " << endl;
    for (int i = 0; i < tamano; i++) {
        cout << "Indice " << i << ": " << arreglo[i] << endl;
    }

    // RECORRIDO INVERSO
    cout << "\n2. Recorrido Inverso" << endl;
    for (int i = tamano - 1; i >= 0; i--) {
        cout << "Indice " << i << ": " << arreglo[i] << endl;
    }

    // INSERCIÓN AL INICIO
    cout << "\n3. Insercion al Inicio" << endl;
    // Desplazamos todos los elementos una posición a la derecha
    for (int i = tamano; i > 0; i--) {
        arreglo[i] = arreglo[i - 1];
    }
    arreglo[0] = 5;  // Inserta el 5 en el índice 0
    tamano++;
    cout << "Arreglo tras insertar 5 al inicio: ";
    imprimirArreglo(arreglo, tamano);

    // INSERCIÓN AL FINAL
    cout << "\n4. Insercion al Final" << endl;
    arreglo[tamano] = 60;  // Agrega el 60 al final
    tamano++;
    cout << "Arreglo tras insertar 60 al final: ";
    imprimirArreglo(arreglo, tamano);

    // ELIMINACIÓN AL INICIO
    cout << "\n5. Eliminacion al Inicio" << endl;
    int eliminado_inicio = arreglo[0];  // ELIMINA EL DATO QUE ESTA EN EL INDICE 0 
    // Desplazamos todos los elementos una posición a la izquierda
    for (int i = 0; i < tamano - 1; i++) {
        arreglo[i] = arreglo[i + 1];
    }
    tamano--;
    cout << "Elemento eliminado: " << eliminado_inicio << endl;
    cout << "Arreglo resultante: ";
    imprimirArreglo(arreglo, tamano);

    // ELIMINACIÓN AL FINAL
    cout << "\n6. Eliminacion al Final" << endl;
    int eliminado_final = arreglo[tamano - 1];  // ELIMINA EL ULTIMO ELEMENTO 
    tamano--;
    cout << "Elemento eliminado: " << eliminado_final << endl;
    cout << "Arreglo resultante: ";
    imprimirArreglo(arreglo, tamano);

    // ELIMINACIÓN ELEGIDA (Por índice)
    cout << "\n7. Eliminacion Elegida " << endl;
    int indice_eliminar = 2;  // ELEJIMOS EL INDICE A ELIMINAR
    int eliminado_elegido = arreglo[indice_eliminar];
    // Desplazamos los elementos a la izquierda desde el índice a borrar
    for (int i = indice_eliminar; i < tamano - 1; i++) {
        arreglo[i] = arreglo[i + 1];
    }
    tamano--;
    cout << "Elemento eliminado en indice " << indice_eliminar << ": " << eliminado_elegido << endl;
    cout << "Arreglo resultante: ";
    imprimirArreglo(arreglo, tamano);

    // BÚSQUEDA SECUENCIAL
    cout << "\n8. Busqueda Secuencial" << endl;
    int objetivo_sec = 40;
    int pos_sec = busqueda_secuencial(arreglo, tamano, objetivo_sec);
    cout << "Buscando " << objetivo_sec << ": Encontrado en indice " << pos_sec << endl;

    // 9. BÚSQUEDA BINARIA
    cout << "\n9. Busqueda Binaria" << endl;
    // HAY QUE RECORDAR QUE EN LA BUSQUEDA BINARIA EL ARREGLO DEBE ESTAR ORDENADO
    int arreglo_ordenado[] = {10, 20, 30, 40, 50, 60, 70};
    int tamano_ordenado = 7;
    int objetivo_bin = 50;
    int pos_bin = busqueda_binaria(arreglo_ordenado, tamano_ordenado, objetivo_bin);
    cout << "Arreglo ordenado: ";
    imprimirArreglo(arreglo_ordenado, tamano_ordenado);
    cout << "Buscando " << objetivo_bin << " via Binaria: Encontrado en indice " << pos_bin << endl;

    return 0;
}