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
    string nombre;

    void (*algoritmo)(int n, unsigned long long arr[]);

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

        // Aleatorio
        auto start = chrono::high_resolution_clock::now();
        if (j == 4)
            quick_sort(arrCopia, 0, n - 1);
        else
            algoritmo(n, arrCopia);
        auto stop = chrono::high_resolution_clock::now();
        auto miliSeg = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        llenar_archivo(nombre, n, arrCopia, miliSeg);            

        // Ordenado
        start = chrono::high_resolution_clock::now();
        if (j == 4)
            quick_sort(arrCopia, 0, n - 1);
        else
            algoritmo(n, arrCopia);
        stop = chrono::high_resolution_clock::now();
        miliSeg = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        llenar_archivo(nombre, n, arrCopia, miliSeg);  

        // Inversamente ordenado
        for (int i = 0; i < n; ++i)
            arrInverso[n - 1 - i] = arrCopia[i];
        
        delete[] arrCopia;
        arrCopia = nullptr;
        
        start = chrono::high_resolution_clock::now();
        if (j == 4)
            quick_sort(arrInverso, 0, n - 1);
        else
            algoritmo(n, arrInverso);
        stop = chrono::high_resolution_clock::now();
        miliSeg = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        llenar_archivo(nombre, n, arrInverso, miliSeg);

        delete[] arrInverso;
        arrInverso = nullptr;
    }
    return 0;
}