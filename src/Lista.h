#ifndef LISTA_H_
#define LISTA_H_

#include "Nodo.h"

/*
 * Una Lista es una colecci�n din�mica de elementos dispuestos en una secuencia.
 *
 * Define operaciones para agregar, remover, acceder y cambiar elementos
 * en cualquier posici�n.
 *
 * Tiene un cursor que permite recorrer todos los elementos secuencialmente.
 *
 */
template<class T> class Lista {

    private:

        Nodo<T>* primero;

        unsigned int tamanio;

        Nodo<T>* cursor;

    public:

        /*
         * post: Lista vac�a.
         */
        Lista();

        /*
         * post: indica si la Lista tiene alg�n elemento.
         */
        bool estaVacia();

        /*
         * post: devuelve la cantidad de elementos que tiene la Lista.
         */
        unsigned int contarElementos();

        /*
         * post: agrega el elemento al final de la Lista, la posici�n:
         *       contarElementos() + 1.
         */
        void agregar(T elemento);

        /*
         * pre : posici�n pertenece al intervalo: [1, contarElementos() + 1]
         * post: agrega el elemento en la posici�n indicada.
         *
         */
        void agregar(T elemento, unsigned int posicion);

        /*
         * pre : posici�n pertenece al intervalo: [1, contarElementos()]
         * post: devuelve el elemento en la posici�n indicada.
         */
        T obtener(unsigned int posicion);

        /*
         * pre : posicio� pertenece al intervalo: [1, contarElementos()]
         * post: cambia el elemento en la posici�n indicada por el
         *       elemento dado.
         */
        void asignar(T elemento, unsigned int posicion);

        /*
         * pre : posici�n pertenece al intervalo: [1, contarElementos()]
         * post: remueve de la Lista el elemento en la posici�n indicada.
         */
        void remover(unsigned int posicion);

        /*
         * post: deja el cursor de la Lista preparado para hacer un nuevo
         *       recorrido sobre sus elementos.
         */
        void iniciarCursor();

        /*
         * pre : se ha iniciado un recorrido (invocando el m�todo
         *       iniciarCursor()) y desde entonces no se han agregado o
         *       removido elementos de la Lista.
         * post: mueve el cursor y lo posiciona en el siguiente elemento
         *       del recorrido.
         *       El valor de retorno indica si el cursor qued� posicionado
         *       sobre un elemento o no (en caso de que la Lista est� vac�a o
         *       no existan m�s elementos por recorrer.)
         */
        bool avanzarCursor();

        /*
         * pre : el cursor est� posicionado sobre un elemento de la Lista,
         *       (fue invocado el m�todo avanzarCursor() y devolvi� true)
         * post: devuelve el elemento en la posici�n del cursor.
         *
         */
        T obtenerCursor();

        /*
         * post: libera los recursos asociados a la Lista.
         */
        ~Lista();

    private:

};

template<class T> Lista<T>::Lista() {

    this->primero = NULL;
    this->cursor = NULL;
    this->tamanio = 0;
}
;

template<class T> bool Lista<T>::estaVacia() {

    return (this->tamanio == 0);
}

template<class T> unsigned int Lista<T>::contarElementos() {

    return this->tamanio;
}

template<class T> void Lista<T>::agregar(T elemento) {

    this->agregar(elemento, this->tamanio + 1);
}

template<class T> void Lista<T>::agregar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio + 1)) {

        Nodo<T>* aAgregar = new Nodo<T>(elemento);

        if (this->primero == NULL) {

            this->primero = aAgregar;

        } else {

            Nodo<T>* anterior = this->primero;
            for (unsigned int i = 1; i < posicion; i++) {

                anterior = anterior->obtenerSiguiente();
            }

            anterior->cambiarSiguiente(aAgregar);
            aAgregar->cambiarSiguiente(anterior->obtenerSiguiente());
        }

        this->tamanio++;
    }

}

template<class T> T Lista<T>::obtener(unsigned int posicion) {

    T elemento;

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        Nodo<T>* actual = this->primero;

        for (unsigned int i = 1; i < posicion; i++) {

            actual = actual->obtenerSiguiente();
        }

        elemento = actual->obtenerDato();
    }

    return elemento;
}

template<class T> void Lista<T>::asignar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        Nodo<T>* actual = this->primero;

        for (unsigned int i = 1; i < posicion; i++) {

            actual = actual->obtenerSiguiente();
        }

        actual->cambiarDato(elemento);
    }
}

template<class T> void Lista<T>::remover(unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        Nodo<T>* aRemover;

        if (posicion == 1) {

            aRemover = this->primero;

        } else {

            Nodo<T>* anterior = this->primero;
            for (unsigned int i = 1; i < posicion - 1; i++) {

                anterior = anterior->obtenerSiguiente();
            }
            aRemover = anterior->obtenerSiguiente();
            anterior->cambiarSiguiente(aRemover->obtenerSiguiente());
        }

        delete aRemover;
        this->tamanio--;
    }
}

template<class T> void Lista<T>::iniciarCursor() {

    this->cursor = NULL;
}

template<class T> bool Lista<T>::avanzarCursor() {

    if (this->cursor == NULL) {

        this->cursor = this->primero;

    } else {

        this->cursor = this->cursor->obtenerSiguiente();
    }

    /* pudo avanzar si el cursor ahora apunta a un nodo */
    return (this->cursor != NULL);
}

template<class T> T Lista<T>::obtenerCursor() {

    T elemento;

    if (this->cursor != NULL) {

        elemento = this->cursor->obtenerDato();
    }

    return elemento;
}

template<class T> Lista<T>::~Lista() {

    while (this->primero != NULL) {

        Nodo<T>* aBorrar = this->primero;
        this->primero = this->primero->obtenerSiguiente();

        delete aBorrar;
    }
}

#endif /* LISTA_H_ */
