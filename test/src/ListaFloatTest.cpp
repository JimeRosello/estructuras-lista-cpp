#include <string>
#include "Lista.h"
#include "gtest/gtest.h"

using namespace std;

TEST( ListaFloatTest, agregarEnPosicionCeroLanzaExcepcion ) {

    Lista<float> temperaturas;
    temperaturas.agregar(24.2);
    temperaturas.agregar(23.5);
    temperaturas.agregar(14.1);

    ASSERT_THROW( temperaturas.agregar(34.6, 0), ExcepcionElementoInexistente );

}

TEST( ListaFloatTest, agregarEnPosicionMasGrandeQueElTamanioMasUnoLanzaExcepcion ) {

    Lista<float> temperaturas;
    temperaturas.agregar(24.2);
    temperaturas.agregar(23.5);
    temperaturas.agregar(14.1);

    ASSERT_THROW( temperaturas.agregar(34.6, 5), ExcepcionElementoInexistente );
}
