#pragma once

#include <utility>
#include <climits>
#include "List_8.h"
#include "Nodee.h"
class Dupla
{
private:
	List_8<Nodee<string>>* m_list;
	bool m_marca;
	string m_padre;
	int m_distancia;
	int tamList;
public:
	Dupla();
	Dupla(const Dupla& other);
	Dupla& operator=(const Dupla& other);
	~Dupla() {};
	List_8<Nodee<string>>* list();
	bool& marca();
	string& padre();
	int& distancia();
	void setMarca(bool marca);
	void setPadre(string padre);
	void setDistancia();
};

inline Dupla::Dupla()
	:m_marca(false), m_padre(""), m_distancia(INT_MAX)
{
	m_list = new List_8<Nodee<string>>();
	tamList = 0; 
}
inline Dupla::Dupla(const Dupla& other) { 
	this->m_marca = other.m_marca;
	this->m_padre = other.m_padre; 
	this->m_distancia = other.m_distancia; 
	this->tamList = other.tamList;

	// Copiar profundamente la lista `m_list`
	this->m_list = new List_8<Nodee<string>>(*other.m_list); 
}
inline Dupla& Dupla::operator=(const Dupla& other) {  
	if (this == &other) {
		return *this;
	}

	this->m_marca = other.m_marca;
	this->m_padre = other.m_padre;
	this->m_distancia = other.m_distancia;
	this->tamList = other.tamList;

	// Liberar la lista actual `m_list`
	delete this->m_list;

	// Copiar profundamente la lista `m_list`
	this->m_list = new List_8<Nodee<string>>(*other.m_list); 

	return *this;
}
inline List_8<Nodee<string> >* Dupla::list()
{
	return m_list;
}

inline bool& Dupla::marca()
{
	return m_marca;
}

inline string& Dupla::padre()
{
	return m_padre;
}

inline int& Dupla::distancia()
{
	return m_distancia;
}

inline void Dupla::setMarca(bool marca)
{
	this->m_marca = marca;
}

inline void Dupla::setPadre(string padre)
{
	this->m_padre = padre;
}

inline void Dupla::setDistancia()
{
	this->m_distancia = INT_MAX;
}

