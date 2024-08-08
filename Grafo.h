#pragma once
#include "Dupla.h"
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include "List_8.h"
#include "Nodee.h" 
#include "Lista1.h"
#include <utility>
#define TAM 1000

class Grafo
{
private:
	map<string, Dupla> gr;
	int lastPosition; 
	int cantNodes;
	Lista1 list1; 
	string obtenerClaveAleatoria(); 
public:
	Grafo();
	Grafo(const Grafo& other);  // Constructor de copia 
	Grafo& operator=(const Grafo& other);  // Operador de asignación 
	void insertar(string vo, vector <string> vds);
	void readFile();
	void mostrarGrafo();

	pair<string,string> obtenerConexionAleatoria();  
	void mostrarList1();
	void contraer(string vo, string vd);
	int getCantNodes();

	int minCut(Grafo aux);

};

inline string Grafo::obtenerClaveAleatoria()
{
	if (gr.empty()) { 
		throw std::out_of_range("El grafo está vacío.");
	}
	std::random_device rd; 
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<> dis(0, gr.size() - 1); 

	auto it = gr.begin(); 
	std::advance(it, dis(gen));
	return it->first;
}

inline Grafo::Grafo()
{
	lastPosition = -1;
	cantNodes = 0;
}

inline Grafo::Grafo(const Grafo& other)
{
	this->lastPosition = other.lastPosition;
	this->cantNodes = other.cantNodes;
	this->list1 = other.list1;

	// Copiar profundamente el mapa `gr`
	for (const auto& pair : other.gr) {
		string key = pair.first;
		Dupla value = pair.second;
		this->gr[key] = value;
	}
}
inline Grafo& Grafo::operator=(const Grafo& other)
{
	if (this == &other) {
		return *this;
	}

	this->lastPosition = other.lastPosition; 
	this->cantNodes = other.cantNodes; 
	this->list1 = other.list1; 

	// Limpiar el mapa actual `gr`
	this->gr.clear(); 

	// Copiar profundamente el mapa `gr`
	for (const auto& pair : other.gr) { 
		string key = pair.first; 
		this->gr[key] = pair.second;  
	}

	return *this;
}
inline void Grafo::insertar(string vo, vector<string> vds)
{
	for (const string& vd : vds)
	{
		Nodee<string> ins(vo, vd);
		gr[vo].list()->InsertLast(ins);

	}
	list1.add(vo);
	cantNodes++;
}

inline void Grafo::readFile()
{
	//"D:\\Universidad\\1-2024\\Estructura_de_datos\\MinCutPrueba.txt"
	//D:\\Universidad\\1-2024\\Estructura_de_datos\\MIN_CUT_CON_NOMBRES.txt
	fstream archivo("D:\\Universidad\\1-2024\\Estructura_de_datos\\MIN_CUT_CON_NOMBRES.txt");
	string line;
	while (getline(archivo, line))
	{
		if (line.empty()) continue;

		istringstream iss(line);
		string vo;
		iss >> vo;

		vector<string> connections;
		string vd;
		while (iss >> vd && vd != "-1") {
			connections.push_back(vd);
		}

		this->insertar(vo, connections);
	}
	archivo.close();
}


inline void Grafo::mostrarGrafo()
{
	for (auto& pair : gr) {
		std::cout << "Nodo " << pair.first << ": ";
		pair.second.list()->Show();
	}
}

inline int Grafo::minCut(Grafo aux)
{
	for (int i = 0; i < aux.getCantNodes() - 2; i++)
	{
		auto par = aux.obtenerConexionAleatoria();
		aux.contraer(par.second, par.first);
	}
	int x;
	for (auto& pair : aux.gr) {
		x = pair.second.list()->getCantidad(); 
	}
	return x;
}

inline std::pair<std::string, std::string> Grafo::obtenerConexionAleatoria() 
{ 

	std::string vo = list1.obtenerElementoAleatorio();
	std::string vd = gr[vo].list()->getRandom().getVertDest();
	return std::make_pair(vo, vd);
}
/*	std::string vo = list1.obtenerElementoAleatorio(); // Usamos list1 para obtener vo
	if (gr.find(vo) == gr.end()) {
		throw std::invalid_argument("El nodo no existe en el grafo.");
	}
	std::string vd = gr[vo].list()->getRandom().getVertDest();
	// Devuelve un pair que contiene vo y vd
	return std::make_pair(vo, vd);*/
inline void Grafo::mostrarList1()
{
	cout << endl; 
	for (int i = 0; i <= list1.pos; i++)
	{
		cout << list1.posibles[i]<<endl;
	}
	cout << endl;
}

inline void Grafo::contraer(string vo, string vd)
{
	Node<Nodee<string>>* current = gr[vd].list()->getFirst(); 
	while (current != nullptr) 
	{
		string ady = current->getElement().getVertDest();

		if (ady != vo) 
		{
			gr[vo].list()->InsertLast(Nodee<string>(vo, ady));
			gr[ady].list()->InsertLast(Nodee<string>(ady, vo));
		}

		Nodee<string> nodoEliminar("", vd); 
		gr[ady].list()->Delete(nodoEliminar);  
		current = current->getNext(); 
	} 
	gr.erase(vd);
}
/*// Verifica si ambos nodos existen en el grafo
	if (gr.find(vo) == gr.end() || gr.find(vd) == gr.end()) 
	{
		throw std::invalid_argument("Uno o ambos nodos no existen en el grafo.");
	}

	// Obten la lista de adyacentes de vd
	List_8<Nodee<string>>* adyacentes = gr[vd].list();
	Node<Nodee<string>>* current = adyacentes->getFirst();

	// Recorre todos los adyacentes de vd
	while (current != nullptr) 
	{
		string ady = current->getElement().getVertDest();

		// Si el adyacente no es vo, agrega las conexiones correspondientes
		if (ady != vo) 
		{
			gr[vo].list()->InsertLast(Nodee<string>(vo, ady));
			gr[ady].list()->InsertLast(Nodee<string>(ady, vo));
		}

		Nodee<string> nodoEliminar("", vd); 
		gr[ady].list()->Delete(nodoEliminar);  
		current = current->getNext(); 
	} 
	gr.erase(vd);*/
inline int Grafo::getCantNodes()
{
	return cantNodes;
}

