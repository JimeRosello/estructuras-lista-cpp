Algoritmos y Programaci�n 2 - FI UBA

# Estructura Din�mica de Datos: Lista

## Marco Te�rico

### Estructura de Datos

Una estructura de datos es una colecci�n de elementos cuya organizaci�n 
l�gica refleja una relaci�n entre ellos.
    
Se caracterizan por las operaciones de acceso que se utilizan para almacenar
y recuperar los elementos individuales.

### Estructura de Datos Est�tica

La estructura l�gica de los elementos que la componen permanece invariante 
a lo largo de toda su utilizaci�n. Ejemplo: Array

### Estructura de Datos Din�mica

La estructura l�gica de los elementos que la componen sufre modificaciones
a lo largo de su utilizaci�n. Ejemplos: Lista, Pila, Cola.

### Lista    
    
Una Lista es una estructura de datos din�mica; es una secuencia de cero o 
m�s elementos.
    
Todos los elementos son accesibles y se pueden insertar y suprimir en 
cualquier posici�n.
    
## Enunciado
 
Dise�ar e implementar el TDA Lista.
    
## Desarrollo

Definici�n basada en templates de la clase Lista<T>.

Provee un cursor que permite recorrer todos los elementos secuencialmente.

Implementaci�n simplemente enlaza. 

* `Lista<T>` : [Lista.h](../master/src/Lista.h)
    
* `Nodo<T>` : [Nodo.h](../master/src/Nodo.h)
    
* Ejemplo : [ejemplo.cpp](../master/src/ejemplo.cpp)

## Extensi�n

Extensi�n de la implementaci�n que utiliza excepciones para manipular 
situaciones an�malas en las cuales se rompe el contrato.

* `Lista<T>` : [Lista.h](../excepciones/src/Lista.h)
    



    