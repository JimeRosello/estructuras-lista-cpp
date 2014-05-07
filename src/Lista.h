#ifndef LISTA_H_
#define LISTA_H_

/*
 * Una Lista es una colección dinámica de elementos dispuestos en una secuencia.
 *
 * Define operaciones para agregar, remover, acceder y cambiar elementos
 * en cualquier posición.
 *
 * Tiene un cursor que permite recorrer todos los elementos secuencialmente.
 *
 */
template <class T> class Lista {

    public:

        /*
         * post: Lista vacía.
         */
        Lista();

        /*
         * post: indica si la Lista tiene algún elemento.
         */
        bool estaVacia();

        /*
         * post: devuelve la cantidad de elementos que tiene la Lista.
         */
        unsigned int contarElementos();

        /*
         * post: agrega el elemento al final de la Lista, la posición:
         *       contarElementos() + 1.
         */
        void agregar(T elemento);

        /*
         * pre : posición pertenece al intervalo: [1, contarElementos() + 1]
         * post: agrega el elemento en la posición indicada.
         *
         */
        void agregar(T elemento, unsigned int posicion);

        /*
         * pre : posición pertenece al intervalo: [1, contarElementos()]
         * post: devuelve el elemento en la posición indicada.
         */
        T obtener(unsigned int posicion);

        /*
         * pre : posicioó pertenece al intervalo: [1, contarElementos()]
         * post: cambia el elemento en la posición indicada por el
         *       elemento dado.
         */
        void asignar(T elemento, unsigned int posicion);

        /*
         * pre : posición pertenece al intervalo: [1, contarElementos()]
         * post: remueve de la Lista el elemento en la posición indicada.
         */
        void remover(unsigned int posicion);

        /*
         * post: deja el cursor de la Lista preparado para hacer un nuevo
         *       recorrido sobre sus elementos.
         */
        void iniciarCursor();

        /*
         * pre : se ha iniciado un recorrido (invocando el método
         *       iniciarCursor()) y desde entonces no se han agregado o
         *       removido elementos de la Lista.
         * post: mueve el cursor y lo posiciona en el siguiente elemento
         *       del recorrido.
         *       El valor de retorno indica si el cursor quedó posicionado
         *       sobre un elemento o no (en caso de que la Lista esté vacía o
         *       no existan más elementos por recorrer.)
         */
        bool avanzarCursor();

        /*
         * pre : el cursor está posicionado sobre un elemento de la Lista,
         *       (fue invocado el método avanzarCursor() y devolvió true)
         * post: devuelve el elemento en la posición del cursor.
         *
         */
        T obtenerCursor();

        /*
         * post: libera los recursos asociados a la Lista.
         */
        ~Lista();
};


#endif /* LISTA_H_ */
