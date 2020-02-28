#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;

// PROTOTIPOS
void crear_datos(int n, unsigned long long arr[]);
void llenar_archivo(string alg, int n, unsigned long long arr[], chrono::nanoseconds miliSeg);
void burbuja(int n, unsigned long long arr[]);
void insercion(int n, unsigned long long arr[]);
void shell_sort(int n, unsigned long long arr[]);
void seleccion(int n, unsigned long long arr[]);
void quick_sort(unsigned long long arr[], int inicio, int fin);
unsigned int quick_sort_dividir(unsigned long long arr[], int inicio, int fin);