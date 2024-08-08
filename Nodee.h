#pragma once
#include <iostream>
using namespace std;
template<typename T>
class Nodee
{
private:
    T vo;
    T vd;
    bool present;
public:
    Nodee();
    Nodee(T vo, T vd);
    T getVertOri()const;
    T getVertDest()const;
    void setVertOri(T p);
    void setVertDest(T p);
    bool getPresent()const;
    void setPresent(bool e);
    void show()const;
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Nodee<U>& node);
    bool operator==(const T& rhs) const {
        return this->vd == rhs; // Suponiendo que quieres comparar con el atributo vd
    } 
    template<typename U>
    friend bool operator==(const Nodee<U>& lhs, const Nodee<U>& rhs);
};

template<typename T>
Nodee<T>::Nodee() : vo(T()), vd(T()), present(false) {}

template<typename T>
inline Nodee<T>::Nodee(T vo, T vd)
{
    this->vd = vd;
    this->vo = vo;
    this->present = false;
}


template<typename T>
inline T Nodee<T>::getVertOri() const
{
    return vo;
}

template<typename T>
inline T Nodee<T>::getVertDest() const
{
    return vd;
}

template<typename T>
inline void Nodee<T>::setVertOri(T p)
{
    this->vo = p;
}

template<typename T>
inline void Nodee<T>::setVertDest(T p)
{
    this->vd = p;
}

template<typename T>
bool Nodee<T>::getPresent() const
{
    return present;
}

template<typename T>
void Nodee<T>::setPresent(bool e)
{
    this->present = e;
}

template<typename T>
void Nodee<T>::show() const
{
    std::cout << "Vo: " << vo << "Vd: " << vd; 
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Nodee<T>& node) {
    os << node.getVertDest();
    return os;
}
template<typename T>
bool operator==(const Nodee<T>& lhs, const Nodee<T>& rhs) {
    return lhs.vd == rhs.vd; // Comparación de los miembros vd de los nodos 
} 