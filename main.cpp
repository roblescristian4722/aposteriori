#include <iostream>
#include <fstream>
#include <chrono>
#include "ord.h"
using namespace std;

int main(int argc, char* argv[])
{
    unsigned long long arr[100000];
    unsigned long long* arrCopia;
    unsigned long long* arrInverso;
    int n;
    long comp = 0;
    long asig = 0;
    string nombre;

    void (*algoritmo)(int n, unsigned long long arr[], long& comp, long& asig);

    n = atoi(argv[1]);

    srand(time(NULL));
    crear_datos(n, arr);

    for (int j = 0; j < 5; ++j)
    {
        switch(j)
        {
            case 0:
                nombre = "burbuja";
                algoritmo = burbuja;
            break;
            case 1:
                nombre = "insercion";
                algoritmo = insercion;
            break;
            case 2:
                nombre = "shell_sort";
                algoritmo = shell_sort;
            break;
            case 3:
                nombre = "seleccion";
                algoritmo = seleccion;
            break;
            case 4:
                nombre = "quick_sort";
            break;
        }

        arrCopia = new unsigned long long [100000];
        arrInverso = new unsigned long long [100000];

        for (int i = 0; i < n; ++i)
            arrCopia[i] = arr[i];

        asig = 0;
        comp = 0;
        
        // Aleatorio
        auto start = chrono::high_resolution_clock::now();
        if (j == 4)
            quick_sort(arrCopia, 0, n - 1, comp, asig);
        else
            algoritmo(n, arrCopia, comp, asig);
        auto stop = chrono::high_resolution_clock::now();
        auto miliSeg = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        llenar_archivo(nombre, n, miliSeg, comp, asig);            

        asig = 0;
        comp = 0;

        // Ordenado
        start = chrono::high_resolution_clock::now();
        if (j == 4)
            quick_sort(arrCopia, 0, n - 1, comp, asig);
        else
            algoritmo(n, arrCopia, comp, asig);
        stop = chrono::high_resolution_clock::now();
        miliSeg = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        llenar_archivo(nombre, n, miliSeg, comp, asig);  

        asig = 0;
        comp = 0;

        // Inversamente ordenado
        for (int i = 0; i < n; ++i)
            arrInverso[n - 1 - i] = arrCopia[i];
        
        delete[] arrCopia;
        arrCopia = nullptr;
        
        start = chrono::high_resolution_clock::now();
        if (j == 4)
            quick_sort(arrInverso, 0, n - 1, comp, asig);
        else
            algoritmo(n, arrInverso, comp, asig);
        stop = chrono::high_resolution_clock::now();
        miliSeg = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        llenar_archivo(nombre, n, miliSeg, comp, asig);

        delete[] arrInverso;
        arrInverso = nullptr;
    }
    return 0;
}