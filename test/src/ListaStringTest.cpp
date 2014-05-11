#include <string>
#include "Lista.h"
#include "gtest/gtest.h"

using namespace std;

TEST( ListaStringTest, crear ) {

    Lista<string> nombres;

    ASSERT_TRUE( nombres.estaVacia() );
}

TEST( ListaStringTest, agregarUnElemento ) {

    Lista<string> nombres;

    nombres.agregar("Valentina");

    ASSERT_FALSE( nombres.estaVacia() );
    ASSERT_EQ( 1, nombres.contarElementos());
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

TEST( ListaStringTest, obtenerElementoUnico ) {

    Lista<string> nombres;
    nombres.agregar("Juan");

    string primero = nombres.obtener(1);

    ASSERT_EQ( "Juan", primero);
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
