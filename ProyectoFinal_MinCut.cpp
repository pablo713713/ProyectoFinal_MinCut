#include <iostream>
#include <string>
#include "Grafo.h"
#define TAM 5933
//TAM = 58*58*Log58
using namespace std;
void menu()
{
    cout << "Laboratorio Grafos BFS DFS" << endl;
    cout << "1. Obtener Conexion Aleatoria" << endl;
    cout << "2. Archivo" << endl;
    cout << "3. Ver Lista 1" << endl;
    cout << "4. Mostrar" << endl;
    cout << "5. Contraer" << endl; 
    cout << "6. MinCut" << endl;
    cout << "0. Salir" << endl;
}
void e1()
{
    Grafo grafo;
    Grafo aux;
    int opc;
    string vo, vd;
    string posibles[100];

    do {
        menu();
        cin >> opc;

        switch (opc) {
        case 0:
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            cout << "Gracias por usar el grafo" << endl;
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            break;
        case 1:
        {
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            auto par = grafo.obtenerConexionAleatoria();
            cout << "vo: " << par.first << "  vd: " << par.second << endl;
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            break;
        }
        case 2:
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            grafo.readFile();
            cout << "Archivo leido" << endl;
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            break;
        case 3:
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            grafo.mostrarList1();
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            break;
        case 4:
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            grafo.mostrarGrafo();
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            break;
        case 5:
        {
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            auto par = grafo.obtenerConexionAleatoria();
            cout << "  vo: " << par.second << "    vd: " << par.first << endl; 
            grafo.contraer(par.second, par.first);
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            break;
        }
        case 6:
        {
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            aux = grafo;
  
            cout << grafo.minCut(aux) << endl;
            
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            break;
        }
        default:
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            cout << "Ingrese una opcion correcta" << endl;
            cout << "------------------------------------------------------------------------------------------------------" << endl;
            break;
        }

    } while (opc != 0);
}
void correrMinCut()
{
    Grafo grafo;
    Grafo aux;
    grafo.readFile();
    int min = 100;
    int x;
    for (int i = 1; i < TAM; i++) 
    {
        aux = grafo;  
        x = grafo.minCut(aux); 
        cout <<"Iteracion: "<<i<<"  Corte:"<<x << endl;
        if (min > x)
            min = x;

    }
    cout << "El corte minimo es: " << min<<endl;
}
int main()
{
    correrMinCut();
}