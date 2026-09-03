    # ARREGLO BASE

arreglo = [10, 20, 30, 40, 50]

#LOS "F" SON F-STRING PARA QUE EL CODIGO NO QUEDE LARGO 

#RECORRIDO SECUENCIAL
print("1. Recorrido Secuencial ")
for i in range(len(arreglo)):
    print(f"Indice {i}: {arreglo[i]}")

#RECORRIDO INVERSO
print("\n2. Recorrido Inverso")
for i in range(len(arreglo) - 1, -1, -1):
    print(f"Indice {i}: {arreglo[i]}")

#INSERCIÓN AL INICIO
print("\n3. Insercion al Inicio")
arreglo.insert(0, 5)  # Inserta el 5 en el índice 0
print(f"Arreglo tras insertar 5 al inicio: {arreglo}")

#INSERCIÓN AL FINAL
print("\n4. Insercion al Final")
arreglo.append(60)  # Agrega el 60 al final
print(f"Arreglo tras insertar 60 al final: {arreglo}")

#ELIMINACIÓN AL INICIO
print("\n5. Eliminacion al Inicio") 
eliminado_inicio = arreglo.pop(0)  #ELIMINA EL DATO QUE ESTA EN EL INDICE 0 
print(f"Elemento eliminado: {eliminado_inicio}")
print(f"Arreglo resultante: {arreglo}")

#ELIMINACIÓN AL FINAL
print("\n6. Eliminacion al Final")
eliminado_final = arreglo.pop()  #ELIMINA EL ULTIMO ELEMENTO 
print(f"Elemento eliminado: {eliminado_final}")
print(f"Arreglo resultante: {arreglo}")

#ELIMINACIÓN ELEGIDA (Por índice)
print("\n7. Eliminacion Elegida ")
indice_eliminar = 2  # ELEJIMOS EL INDICE A ELIMINAR
eliminado_elegido = arreglo.pop(indice_eliminar)
print(f"Elemento eliminado en indice {indice_eliminar}: {eliminado_elegido}")
print(f"Arreglo resultante: {arreglo}")

#BÚSQUEDA SECUENCIAL
print("\n8. Busqueda Secuencial")
def busqueda_secuencial(arr, objetivo):
    for i in range(len(arr)):
        if arr[i] == objetivo:
            return i  # DEVUELVE EL INDICE SI LO ENCUENTRA
    return -1  # DEVUELVE -1 SI NO LO ENCUENTRA

objetivo_sec = 40
pos_sec = busqueda_secuencial(arreglo, objetivo_sec)
print(f"Buscando {objetivo_sec}: Encontrado en indice {pos_sec}")

# 9. BÚSQUEDA BINARIA
print("\n9. Busqueda Binaria")
def busqueda_binaria(arr, objetivo):
    inicio = 0
    fin = len(arr) - 1
    
    while inicio <= fin:
        medio = (inicio + fin) // 2
        if arr[medio] == objetivo:
            return medio
        elif arr[medio] < objetivo:
            inicio = medio + 1
        else:
            fin = medio - 1
    return -1

#HAY QUE RECORDAR QUE EN LA BUSQUEDA BINARIA EL ARREGLO DEBE ESTAR ORDENADO
arreglo_ordenado = [10, 20, 30, 40, 50, 60, 70]
objetivo_bin = 50
pos_bin = busqueda_binaria(arreglo_ordenado, objetivo_bin)
print(f"Arreglo ordenado: {arreglo_ordenado}")
print(f"Buscando {objetivo_bin} via Binaria: Encontrado en indice {pos_bin}")