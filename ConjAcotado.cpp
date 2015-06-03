
#include "ConjAcotado.h"
#include <cassert>
#include <cstddef>
#include <vector>


//Para poder declarar
ConjAcotado::ConjAcotado() {};

//Costo: O(cota) tiempo
ConjAcotado::ConjAcotado(unsigned int cota) {
    for(auto i = 0; i < cota; ++i) {
        idx.push_back(elems.end());
    }
};

//Costo: O(other.cota()). //constructor por copia
ConjAcotado::ConjAcotado(const ConjAcotado& other) : elems(other.elems), idx(other.idx) {};

//Costo: O(other.cota())
ConjAcotado ConjAcotado::operator=(const ConjAcotado& other)
{
       if(this!=&other){ //Comprueba que no se esté intentanod igualar un objeto a sí mismo
         this->elems = other.elems;
         this->idx  = other.idx ;
  }
  return *this;
}

//Costo: O(cota())
ConjAcotado::~ConjAcotado() {};

//Costo: O(1) //elems es un iterador
bool ConjAcotado::pertenece(unsigned int elem) const {
    return idx[elem] != elems.end(); //
};

void ConjAcotado::agregar(unsigned int elem) {
    elems.push_front(elem); //guarda en la lista
    idx[elem] = elems.begin(); // guarda el iterador en el vector
};

void ConjAcotado::eliminar(unsigned int elem) {
    elems.erase(idx[elem]);
    idx[elem] = elems.end();
};

bool ConjAcotado::empty() const {
    return elems.empty();
};

//Costo: O(size())
bool ConjAcotado::operator==(const ConjAcotado& other) const
{
    assert(false);
}

//Costo: O(1)
unsigned int ConjAcotado::cota() const {
    return idx.size();
};

unsigned int ConjAcotado::size() const {
    return elems.size();
};

//Costo: O(1)
ConjAcotado::iterator ConjAcotado::begin() const {
    iterator it;
    it.actual = elems.begin();
    it.conj = this;
    return it;
};

ConjAcotado::iterator ConjAcotado::end() const {
    iterator it;
    it.actual = elems.end();
    it.conj = this;
    return it;
};


//Este hay que agregar
// no retorna nada porque es un constructor
ConjAcotado::iterator::iterator() {
    const ConjAcotado* c = NULL;

    conj = c;
  //iterator end() { return &students[100]; }

};

ConjAcotado::iterator::iterator(const ConjAcotado::iterator& other)  {
    assert(false);
};

ConjAcotado::iterator& ConjAcotado::iterator::operator=(const ConjAcotado::iterator& other) {
    assert(false);
};

ConjAcotado::iterator& ConjAcotado::iterator::operator++(){
    assert(false);
};

ConjAcotado::iterator& ConjAcotado::iterator::operator++(int){
    assert(false);
};

ConjAcotado::iterator& ConjAcotado::iterator::operator--(){
    assert(false);
};

ConjAcotado::iterator& ConjAcotado::iterator::operator--(int){
    assert(false);
};

unsigned int ConjAcotado::iterator::operator*() const{
    assert(false);
};

bool ConjAcotado::iterator::operator==(const ConjAcotado::iterator& other){
    return (*this == other);
};

bool ConjAcotado::iterator::operator!=(const ConjAcotado::iterator& other){
    return not(*this == other);
};
