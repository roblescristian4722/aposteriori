#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;

// PROTOTIPOS
void crear_datos(int n, unsigned long long arr[]);
void llenar_archivo(string alg, int n, chrono::nanoseconds miliSeg, long& comp, long& asig);
void burbuja(int n, unsigned long long arr[], long& comp, long& asig);
void insercion(int n, unsigned long long arr[], long& comp, long& asig);
void shell_sort(int n, unsigned long long arr[], long& comp, long& asig);
void seleccion(int n, unsigned long long arr[], long& comp, long& asig);
void quick_sort(unsigned long long arr[], int inicio, int fin, long& comp, long& asig);
unsigned int quick_sort_dividir(unsigned long long arr[], int inicio, int fin, long& comp, long& asig);