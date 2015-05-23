#include <string>
#include "Lista.h"
#include "gtest/gtest.h"

using namespace std;

TEST( ListaIntTest, crear ) {

    Lista<int> edades;

    ASSERT_TRUE( edades.estaVacia() );
}

TEST( ListaIntTest, agregarUnElemento ) {

    Lista<int> edades;

    edades.agregar(34);

    ASSERT_FALSE( edades.estaVacia() );
    ASSERT_EQ( 1, edades.contarElementos() );
}

TEST( ListaIntTest, agregarMultiplesElementos) {

    Lista<int> edades;

    edades.agregar(23);
    edades.agregar(45);
    edades.agregar(12);
    edades.agregar(21);
    edades.agregar(9);
    edades.agregar(34);

    ASSERT_EQ( 6, edades.contarElementos() );
}

TEST( ListaIntTest, agregarElementosConRepetidos ) {

    Lista<int> edades;

    edades.agregar(32);
    edades.agregar(33);
    edades.agregar(33);
    edades.agregar(9);
    edades.agregar(12);
    edades.agregar(38);
    edades.agregar(12);

    ASSERT_EQ( 7, edades.contarElementos() );
}

TEST( ListaIntTest, obtenerElementoUnico ) {

    Lista<int> edades;
    edades.agregar(3);

    int primero = edades.obtener(1);

    ASSERT_EQ( 3, primero);
}

TEST( ListaIntTest, removerUnicoElemento ) {

    Lista<int> notas;
    notas.agregar(4);

    notas.remover(1);

    ASSERT_EQ( 0, notas.contarElementos() );
    ASSERT_TRUE( notas.estaVacia() );
}

TEST( ListaIntTest, removerPrimerElemento ) {

    Lista<int> notas;
    notas.agregar(9);
    notas.agregar(7);
    notas.agregar(3);
    notas.agregar(4);

    notas.remover(1);

    ASSERT_EQ( 3, notas.contarElementos() );
    ASSERT_EQ( 7, notas.obtener(1) );
}

TEST( ListaIntTest, removerUltimoElemento ) {

    Lista<int> notas;
    notas.agregar(10);
    notas.agregar(9);
    notas.agregar(8);
    notas.agregar(7);

    notas.remover(4);

    ASSERT_EQ( 3, notas.contarElementos() );
    ASSERT_EQ( 8, notas.obtener(3) );
}

TEST( ListaIntTest, removerElementoCentral ) {

    Lista<int> notas;
    notas.agregar(10);
    notas.agregar(9);
    notas.agregar(8);
    notas.agregar(7);
    notas.agregar(6);

    notas.remover(3);

    ASSERT_EQ( 4, notas.contarElementos() );
    ASSERT_EQ( 9, notas.obtener(2) );
    ASSERT_EQ( 7, notas.obtener(3) );
}

TEST( ListaIntTest, removerMultiplesElementos ) {

    Lista<int> notas;
    notas.agregar(10);
    notas.agregar(9);
    notas.agregar(8);
    notas.agregar(7);
    notas.agregar(6);
    notas.agregar(5);
    notas.agregar(4);

    notas.remover(1);
    notas.remover(3);
    notas.remover(2);
    notas.remover(3);

    ASSERT_EQ( 3, notas.contarElementos() );
    ASSERT_EQ( 9, notas.obtener(1) );
    ASSERT_EQ( 6, notas.obtener(2) );
    ASSERT_EQ( 4, notas.obtener(3) );
}


TEST( ListaIntTest, constructorDeCopia ) {

    Lista<int> original;
    original.agregar(5);
    original.agregar(4);
    original.agregar(3);
    original.agregar(2);
    original.agregar(1);

    Lista<int> copia(original);

    copia.agregar(0);
    ASSERT_EQ(5, original.contarElementos());
    ASSERT_EQ(6, copia.contarElementos());
}
