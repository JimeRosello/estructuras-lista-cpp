#include <string>
#include "Lista.h"
#include "gtest/gtest.h"

using namespace std;

TEST( ListaStringTest, crear ) {

    Lista<string> nombres;

    ASSERT_TRUE( nombres.estaVacia() );
}

TEST( ListaIntTest, crear ) {

    Lista<int> edades;

    ASSERT_TRUE( edades.estaVacia() );
}

TEST( ListaStringTest, agregarUnElemento ) {

    Lista<string> nombres;

    nombres.agregar("Valentina");

    ASSERT_FALSE( nombres.estaVacia() );
    ASSERT_EQ( 1, nombres.contarElementos());
}

TEST( ListaIntTest, agregarUnElemento ) {

    Lista<int> edades;

    edades.agregar(34);

    ASSERT_FALSE( edades.estaVacia() );
    ASSERT_EQ( 1, edades.contarElementos() );
}

TEST( ListaStringTest, agregarMultiplesElementos ) {

    Lista<string> nombres;

    nombres.agregar("Santiago");
    nombres.agregar("Agustina");
    nombres.agregar("Marcelo");
    nombres.agregar("Facundo");

    ASSERT_FALSE( nombres.estaVacia() );
    ASSERT_EQ( 4, nombres.contarElementos() );
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

TEST( ListaStringTest, obtenerElementoUnico ) {

    Lista<string> nombres;
    nombres.agregar("Juan");

    string primero = nombres.obtener(1);

    ASSERT_EQ( "Juan", primero);
}

TEST( ListaIntTest, obtenerElementoUnico ) {

    Lista<int> edades;
    edades.agregar(3);

    int primero = edades.obtener(1);

    ASSERT_EQ( 3, primero);
}

TEST( ListaStringTest, obtenerElementoCentral ) {

    Lista<string> nombres;
    nombres.agregar("Oscar");
    nombres.agregar("Paula");
    nombres.agregar("Carolina");
    nombres.agregar("Santiago");
    nombres.agregar("Marcos");

    string tercero = nombres.obtener(3);

    ASSERT_EQ( "Carolina", tercero );
}

TEST( ListaStringTest, obtenerTodosLosElementos ) {

    Lista<string> nombres;
    nombres.agregar("Martin");
    nombres.agregar("Juliana");
    nombres.agregar("Nicolas");
    nombres.agregar("Carolina");
    nombres.agregar("Sofia");
    nombres.agregar("Lucas");

    ASSERT_EQ( "Juliana", nombres.obtener(2) );
    ASSERT_EQ( "Carolina", nombres.obtener(4) );
    ASSERT_EQ( "Lucas", nombres.obtener(6) );
    ASSERT_EQ( "Sofia", nombres.obtener(5) );
    ASSERT_EQ( "Martin", nombres.obtener(1) );
    ASSERT_EQ( "Nicolas", nombres.obtener(3) );
}

TEST( ListaStringTest, agregarAlPrincipio ) {

    Lista<string> opciones;
    opciones.agregar("Arriba");
    opciones.agregar("Derecha");
    opciones.agregar("Izquierda");

    opciones.agregar("Abajo", 1);

    ASSERT_EQ( 4, opciones.contarElementos() );
    ASSERT_EQ( "Abajo", opciones.obtener(1) );
    ASSERT_EQ( "Arriba", opciones.obtener(2) );
}

TEST( ListaStringTest, agregarAlFinal ) {

    Lista<string> opciones;
    opciones.agregar("Primera");
    opciones.agregar("Segunda");
    opciones.agregar("Tercera");
    opciones.agregar("Cuarta");

    opciones.agregar("Quinta", 5);

    ASSERT_EQ( 5, opciones.contarElementos() );
    ASSERT_EQ( "Quinta", opciones.obtener(5) );
    ASSERT_EQ( "Cuarta", opciones.obtener(4) );
}

TEST( ListaStringTest, agregarAlMedio) {

    Lista<string> opciones;
    opciones.agregar("Uno");
    opciones.agregar("Dos");
    opciones.agregar("Cuatro");
    opciones.agregar("Cinco");

    opciones.agregar("Tres", 3);

    ASSERT_EQ( 5, opciones.contarElementos() );
    ASSERT_EQ( "Tres", opciones.obtener(3) );
    ASSERT_EQ( "Dos", opciones.obtener(2) );
    ASSERT_EQ( "Cuatro", opciones.obtener(4) );
}

TEST( ListaFloatTest, agregarEnPosicionCeroEsIgnorado ) {

    Lista<float> temperaturas;
    temperaturas.agregar(24.2);
    temperaturas.agregar(23.5);
    temperaturas.agregar(14.1);

    temperaturas.agregar(34.6, 0);

    ASSERT_EQ( 3, temperaturas.contarElementos() );
}

TEST( ListaFloatTest, agregarEnPosicionMasGrandeQueElTamanioMasUnoEsIgnorado ) {

    Lista<float> temperaturas;
    temperaturas.agregar(24.2);
    temperaturas.agregar(23.5);
    temperaturas.agregar(14.1);

    temperaturas.agregar(34.6, 5);

    ASSERT_EQ( 3, temperaturas.contarElementos() );
}

TEST( ListaStringTest, asignarUnicoElemento ) {

    Lista<string> titulos;
    titulos.agregar("Algebra I");

    titulos.asignar("Ecuaciones Diferenciales", 1);

    ASSERT_EQ( 1, titulos.contarElementos() );
    ASSERT_EQ( "Ecuaciones Diferenciales", titulos.obtener(1) );
}

TEST( ListaStringTest, asignarMultiplesElementos ) {

    Lista<string> titulos;
    titulos.agregar("A I");
    titulos.agregar("F I");
    titulos.agregar("Quimica");
    titulos.agregar("AM II");

    titulos.asignar("Algebra I", 1);
    titulos.asignar("Fisica I", 2);
    titulos.asignar("Analisis Matematico II", 4);

    ASSERT_EQ( 4, titulos.contarElementos() );
    ASSERT_EQ( "Algebra I", titulos.obtener(1) );
    ASSERT_EQ( "Fisica I", titulos.obtener(2) );
    ASSERT_EQ( "Quimica", titulos.obtener(3) );
    ASSERT_EQ( "Analisis Matematico II", titulos.obtener(4) );
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

TEST( ListaStringTest, recorrerListaVacia ) {

    Lista<string> etapas;

    etapas.iniciarCursor();

    ASSERT_FALSE( etapas.avanzarCursor() );
}

TEST( ListaStringTest, recorrerElementoUnico ) {

    Lista<string> etapas;
    etapas.agregar("Mantenimiento");

    etapas.iniciarCursor();
    ASSERT_TRUE( etapas.avanzarCursor() );
    ASSERT_EQ( "Mantenimiento", etapas.obtenerCursor() );
    ASSERT_FALSE( etapas.avanzarCursor() );

}

TEST( ListaStringTest, recorrerMultiplesElementos ) {

    Lista<string> etapas;
    etapas.agregar("Recoleccion");
    etapas.agregar("Evaluacion");
    etapas.agregar("Migracion");
    etapas.agregar("Implantacion");
    etapas.agregar("Mantenimiento");

    etapas.iniciarCursor();

    ASSERT_TRUE( etapas.avanzarCursor() );
    ASSERT_EQ( "Recoleccion", etapas.obtenerCursor() );
    ASSERT_TRUE( etapas.avanzarCursor() );
    ASSERT_EQ( "Evaluacion", etapas.obtenerCursor() );
    ASSERT_TRUE( etapas.avanzarCursor() );
    ASSERT_EQ( "Migracion", etapas.obtenerCursor() );
    ASSERT_TRUE( etapas.avanzarCursor() );
    ASSERT_EQ( "Implantacion", etapas.obtenerCursor() );
    ASSERT_TRUE( etapas.avanzarCursor() );
    ASSERT_EQ( "Mantenimiento", etapas.obtenerCursor() );
    ASSERT_FALSE( etapas.avanzarCursor() ) << "NO quedan elementos por recorrer";
}

TEST( ListaStringTest, obtenerCursorMultiplesVecesNoAvanzaElCursor ) {

    Lista<string> etapas;
    etapas.agregar("Migracion");
    etapas.agregar("Implantacion");
    etapas.agregar("Mantenimiento");
    etapas.iniciarCursor();
    etapas.avanzarCursor();

    ASSERT_EQ( "Migracion", etapas.obtenerCursor() );
    ASSERT_EQ( "Migracion", etapas.obtenerCursor() );
    ASSERT_EQ( "Migracion", etapas.obtenerCursor() );
}
