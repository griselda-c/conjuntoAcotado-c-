
#include <list>
#include <vector>

#ifndef CONJACOTADO_H
#define CONJACOTADO_H

class ConjAcotado {
    //Representa un conjunto de numeros naturales.
    //Puede contener unicamente numeros entre 0 y un valor maximo, llamado cota superior, es decir.
    //  pertenece(n) esta definido si y solo si 0 <= n < cota
    //Por otra parte, ofrece las operaciones tipicas de un conjunto:
    //  ConjAcotado(): crea un conjunto con cota 0 (no sirve para nada, pero permite definir variables no inicializadas)
    //  ConjAcotado(cota): crea un nuevo conjunto con la cota dada.
    //  ConjAcotado(conjAcotado) y operator= hacen lo esperado.
    //  pertenece(n): indica si n pertenece o no al conjunto (precondicion: 0 <= n < cota)
    //  agregar(n): agrega n al conjunto; si ya pertenece, no hace nada (precondicion: 0 <= n < cota)
    //  eliminar(n): elimina n del conjunto; si no pertenece, no hace nada (precondicion: 0 <= n < cota)
    //  size(): indica la cantidad de elementos del conjunto (no confundir con la cota)
    //  cota(): indica el valor máximo + 1 que puede contener el conjunto.
    //  empty(): indica si el conjunto esta vacio
    //  operator==; indica si dos conjuntos tienen los mismos elementos
    //  begin(), cbegin(): iterador al primer elemento
    //  end(), cend(): iterador al elemento pasado al ultimo.
    //
    //Iteradores: son bidireccionales (deberian cumplir el estandar C++, aunque no lo hacen por pereza).
    //  Todas las operaciones cuestan O(1) tiempo.
public:
    //Todas de costo O(1)
    class iterator {
    public:
        iterator();

        iterator(const iterator& other);
        iterator& operator=(const iterator& other);

        iterator& operator++();
        iterator& operator++(int);

        iterator& operator--();
        iterator& operator--(int);

        unsigned int operator*() const;

        bool operator==(const iterator& other);
        bool operator!=(const iterator& other);

    private:
        std::list<int>::const_iterator actual;
        const ConjAcotado* conj;
        friend class ConjAcotado;
    };


    //Para poder declarar
    ConjAcotado();

    //Costo: O(cota) tiempo
    ConjAcotado(unsigned int cota);

    //Costo: O(other.cota()).
    ConjAcotado(const ConjAcotado& other);

    //Costo: O(other.cota())
    ConjAcotado operator=(const ConjAcotado& other);

    //Costo: O(cota())
    ~ConjAcotado();

    //Costo: O(1)
    bool pertenece(unsigned int elem) const;

    void agregar(unsigned int elem);

    void eliminar(unsigned int elem);

    bool empty() const;

    //Costo: O(size())
    bool operator==(const ConjAcotado& other) const;

    //Costo: O(1)
    unsigned int cota() const;

    unsigned int size() const;

    //Costo: O(1)
    ConjAcotado::iterator begin() const;

    ConjAcotado::iterator end() const;
    ConjAcotado::iterator cbegin() const;
    ConjAcotado::iterator cend() const;


private:
    std::list<int> elems;
    std::vector< std::list<int>::const_iterator > idx;
};

#endif //CONJACOTADO_H
