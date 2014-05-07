#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif

template<class T> class Nodo {

    private:

        T dato;

        Nodo<T>* siguiente;

    public:

        /*
         * post: el Nodo resulta inicializado con el dato dado
         *       y sin un Nodo siguiente.
         */
        Nodo(T dato) {

            this->dato = dato;
            this->siguiente = NULL;
        }

        /*
         * post: devuelve el valor del dato.
         */
        T getDato() {

            return this->dato;
        }

        /*
         * post: cambia el valor del dato.
         */
        void setDato(T nuevoDato) {

            this->dato = nuevoDato;
        }

        /*
         * post: devuelve el siguiente Nodo.
         */
        Nodo<T>* getSiguiente() {

            return this->siguiente;
        }

        /*
         * post: cambia el siguiente Nodo por nuevoSiguiente.
         */
        void setSiguiente(Nodo<T>* nuevoSiguiente) {

            this->siguiente = nuevoSiguiente;
        }
};


#endif /* NODO_H_ */
