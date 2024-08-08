#pragma once
#include <string>
#define TAM 1000
class Lista1
{
public:
	std::string posibles[TAM];
	int pos;
	
	Lista1();
	void add(std::string vd);
	std::string obtenerElementoAleatorio();

};