// ARREGLO BASE
let arreglo = [10, 20, 30, 40, 50];

// LOS TEMPLATE LITERALS (${}) CUMPLEN LA FUNCIÓN DE LAS F-STRINGS

// RECORRIDO SECUENCIAL
console.log("1. Recorrido Secuencial ");
for (let i = 0; i < arreglo.length; i++) {
    console.log(`Indice ${i}: ${arreglo[i]}`);
}

// RECORRIDO INVERSO
console.log("\n2. Recorrido Inverso");
for (let i = arreglo.length - 1; i >= 0; i--) {
    console.log(`Indice ${i}: ${arreglo[i]}`);
}

// INSERCIÓN AL INICIO
console.log("\n3. Insercion al Inicio");
arreglo.unshift(5);  // Inserta el 5 en el índice 0
console.log(`Arreglo tras insertar 5 al inicio: [${arreglo.join(", ")}]`);

// INSERCIÓN AL FINAL
console.log("\n4. Insercion al Final");
arreglo.push(60);  // Agrega el 60 al final
console.log(`Arreglo tras insertar 60 al final: [${arreglo.join(", ")}]`);

// ELIMINACIÓN AL INICIO
console.log("\n5. Eliminacion al Inicio");
let eliminado_inicio = arreglo.shift();  // ELIMINA EL DATO QUE ESTA EN EL INDICE 0 
console.log(`Elemento eliminado: ${eliminado_inicio}`);
console.log(`Arreglo resultante: [${arreglo.join(", ")}]`);

// ELIMINACIÓN AL FINAL
console.log("\n6. Eliminacion al Final");
let eliminado_final = arreglo.pop();  // ELIMINA EL ULTIMO ELEMENTO 
console.log(`Elemento eliminado: ${eliminado_final}`);
console.log(`Arreglo resultante: [${arreglo.join(", ")}]`);

// ELIMINACIÓN ELEGIDA (Por índice)
console.log("\n7. Eliminacion Elegida ");
let indice_eliminar = 2;  // ELEJIMOS EL INDICE A ELIMINAR
let eliminado_elegido = arreglo.splice(indice_eliminar, 1)[0];
console.log(`Elemento eliminado en indice ${indice_eliminar}: ${eliminado_elegido}`);
console.log(`Arreglo resultante: [${arreglo.join(", ")}]`);

// BÚSQUEDA SECUENCIAL
console.log("\n8. Busqueda Secuencial");
function busqueda_secuencial(arr, objetivo) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === objetivo) {
            return i;  // DEVUELVE EL INDICE SI LO ENCUENTRA
        }
    }
    return -1;  // DEVUELVE -1 SI NO LO ENCUENTRA
}

let objetivo_sec = 40;
let pos_sec = busqueda_secuencial(arreglo, objetivo_sec);
console.log(`Buscando ${objetivo_sec}: Encontrado en indice ${pos_sec}`);

// 9. BÚSQUEDA BINARIA
console.log("\n9. Busqueda Binaria");
function busqueda_binaria(arr, objetivo) {
    let inicio = 0;
    let fin = arr.length - 1;
    
    while (inicio <= fin) {
        let medio = Math.floor((inicio + fin) / 2);
        if (arr[medio] === objetivo) {
            return medio;
        } else if (arr[medio] < objetivo) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1;
}

let arreglo_ordenado = [10, 20, 30, 40, 50, 60, 70];
let objetivo_bin = 50;
let pos_bin = busqueda_binaria(arreglo_ordenado, objetivo_bin);
console.log(`Arreglo ordenado: [${arreglo_ordenado.join(", ")}]`);
console.log(`Buscando ${objetivo_bin} via Binaria: Encontrado en indice ${pos_bin}`);