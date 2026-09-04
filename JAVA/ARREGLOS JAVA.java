class OperacionesArreglos {

    // Función auxiliar para imprimir el arreglo
    public static void imprimirArreglo(int[] arr, int tamano) {
        System.out.print("[");
        for (int i = 0; i < tamano; i++) {
            System.out.print(arr[i] + (i < tamano - 1 ? ", " : ""));
        }
        System.out.println("]");
    }

    // BÚSQUEDA SECUENCIAL
    public static int busquedaSecuencial(int[] arr, int tamano, int objetivo) {
        for (int i = 0; i < tamano; i++) {
            if (arr[i] == objetivo) {
                return i;  // DEVUELVE EL INDICE SI LO ENCUENTRA
            }
        }
        return -1;  // DEVUELVE -1 SI NO LO ENCUENTRA
    }

    // BÚSQUEDA BINARIA
    public static int busquedaBinaria(int[] arr, int tamano, int objetivo) {
        int inicio = 0;
        int fin = tamano - 1;
        
        while (inicio <= fin) {
            int medio = (inicio + fin) / 2;
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

    public static void main(String[] args) {
        // ARREGLO BASE (con espacio para 10 elementos)
        int[] arreglo = new int[10];
        arreglo[0] = 10;
        arreglo[1] = 20;
        arreglo[2] = 30;
        arreglo[3] = 40;
        arreglo[4] = 50;
        int tamano = 5; // Cantidad de elementos almacenados

        // RECORRIDO SECUENCIAL
        System.out.println("1. Recorrido Secuencial ");
        for (int i = 0; i < tamano; i++) {
            System.out.println("Indice " + i + ": " + arreglo[i]);
        }

        // RECORRIDO INVERSO
        System.out.println("\n2. Recorrido Inverso");
        for (int i = tamano - 1; i >= 0; i--) {
            System.out.println("Indice " + i + ": " + arreglo[i]);
        }

        // INSERCIÓN AL INICIO
        System.out.println("\n3. Insercion al Inicio");
        // Desplazamos los elementos a la derecha
        for (int i = tamano; i > 0; i--) {
            arreglo[i] = arreglo[i - 1];
        }
        arreglo[0] = 5;  // Inserta el 5 en el índice 0
        tamano++;
        System.out.print("Arreglo tras insertar 5 al inicio: ");
        imprimirArreglo(arreglo, tamano);

        // INSERCIÓN AL FINAL
        System.out.println("\n4. Insercion al Final");
        arreglo[tamano] = 60;  // Agrega el 60 al final
        tamano++;
        System.out.print("Arreglo tras insertar 60 al final: ");
        imprimirArreglo(arreglo, tamano);

        // ELIMINACIÓN AL INICIO
        System.out.println("\n5. Eliminacion al Inicio");
        int eliminado_inicio = arreglo[0];  // ELIMINA EL DATO QUE ESTA EN EL INDICE 0 
        // Desplazamos los elementos a la izquierda
        for (int i = 0; i < tamano - 1; i++) {
            arreglo[i] = arreglo[i + 1];
        }
        tamano--;
        System.out.println("Elemento eliminado: " + eliminado_inicio);
        System.out.print("Arreglo resultante: ");
        imprimirArreglo(arreglo, tamano);

        // ELIMINACIÓN AL FINAL
        System.out.println("\n6. Eliminacion al Final");
        int eliminado_final = arreglo[tamano - 1];  // ELIMINA EL ULTIMO ELEMENTO 
        tamano--;
        System.out.println("Elemento eliminado: " + eliminado_final);
        System.out.print("Arreglo resultante: ");
        imprimirArreglo(arreglo, tamano);

        // ELIMINACIÓN ELEGIDA (Por índice)
        System.out.println("\n7. Eliminacion Elegida ");
        int indice_eliminar = 2;  // ELEJIMOS EL INDICE A ELIMINAR
        int eliminado_elegido = arreglo[indice_eliminar];
        // Desplazamos los elementos a la izquierda desde el índice borrado
        for (int i = indice_eliminar; i < tamano - 1; i++) {
            arreglo[i] = arreglo[i + 1];
        }
        tamano--;
        System.out.println("Elemento eliminado en indice " + indice_eliminar + ": " + eliminado_elegido);
        System.out.print("Arreglo resultante: ");
        imprimirArreglo(arreglo, tamano);

        // BÚSQUEDA SECUENCIAL
        System.out.println("\n8. Busqueda Secuencial");
        int objetivo_sec = 40;
        int pos_sec = busquedaSecuencial(arreglo, tamano, objetivo_sec);
        System.out.println("Buscando " + objetivo_sec + ": Encontrado en indice " + pos_sec);

        // 9. BÚSQUEDA BINARIA
        System.out.println("\n9. Busqueda Binaria");
        int[] arreglo_ordenado = {10, 20, 30, 40, 50, 60, 70};
        int tamano_ordenado = 7;
        int objetivo_bin = 50;
        int pos_bin = busquedaBinaria(arreglo_ordenado, tamano_ordenado, objetivo_bin);
        System.out.print("Arreglo ordenado: ");
        imprimirArreglo(arreglo_ordenado, tamano_ordenado);
        System.out.println("Buscando " + objetivo_bin + " via Binaria: Encontrado en indice " + pos_bin);
    }
}