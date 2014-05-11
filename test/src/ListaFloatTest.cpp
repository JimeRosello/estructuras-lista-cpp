#include <string>
#include "Lista.h"
#include "gtest/gtest.h"

using namespace std;

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
