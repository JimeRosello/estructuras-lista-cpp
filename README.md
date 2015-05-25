Algoritmos y Programación 2 - FI UBA

# Estructura Dinámica de Datos: Lista

## Marco Teórico

### Estructura de Datos

Una estructura de datos es una colección de elementos cuya organización 
lógica refleja una relación entre ellos.
    
Se caracterizan por las operaciones de acceso que se utilizan para almacenar
y recuperar los elementos individuales.

### Estructura de Datos Estática

La estructura lógica de los elementos que la componen permanece invariante 
a lo largo de toda su utilización. Ejemplo: Array

### Estructura de Datos Dinámica

La estructura lógica de los elementos que la componen sufre modificaciones
a lo largo de su utilización. Ejemplos: Lista, Pila, Cola.

### Lista    
    
Una Lista es una estructura de datos dinámica; es una secuencia de cero o 
más elementos.
    
Todos los elementos son accesibles y se pueden insertar y suprimir en 
cualquier posición.
    
## Enunciado
 
Diseñar e implementar el TDA Lista.
    
## Desarrollo

Definición basada en templates de la clase Lista<T>.

Provee un cursor que permite recorrer todos los elementos secuencialmente.

Implementación simplemente enlaza. 

* `Lista<T>` : [Lista.h](../master/src/Lista.h)
    
* `Nodo<T>` : [Nodo.h](../master/src/Nodo.h)
    
* Ejemplo : [ejemplo.cpp](../master/src/ejemplo.cpp)

## Extensión

Extensión de la implementación que utiliza excepciones para manipular 
situaciones anómalas en las cuales se rompe el contrato.

* `Lista<T>` : [Lista.h](../excepciones/src/Lista.h)
    



    