
#include <string>
#include "Lista.h"
#include "gtest/gtest.h"

template <typename T>
class ListaTest : public ::testing::Test {


};

TYPED_TEST_CASE_P(ListaTest);

TYPED_TEST_P(ListaTest, crearLista) {

    Lista<TypeParam> unaLista;

    ASSERT_TRUE(unaLista.estaVacia());
}

REGISTER_TYPED_TEST_CASE_P(ListaTest, crearLista);

typedef ::testing::Types<char, int, std::string> Tipos;

INSTANTIATE_TYPED_TEST_CASE_P(TiposPrimitivos, ListaTest, Tipos);

