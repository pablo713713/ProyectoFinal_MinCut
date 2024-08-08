#include "Lista1.h"
#include <iostream>
#include <random>
using namespace std;
Lista1::Lista1()
{
	this->pos = -1;
}

void Lista1::add(std::string vd)
{
	pos++;
	posibles[pos] = vd;
}
std::string Lista1::obtenerElementoAleatorio()
{
	string vd;
	std::random_device rd;   
	std::mt19937 gen(rd());   
	std::uniform_int_distribution<> dis(0, pos); 
	int aleatorio= dis(gen); 
	vd= posibles[aleatorio]; 
	posibles[aleatorio] = posibles[pos];
	pos--;
	return vd;
}
