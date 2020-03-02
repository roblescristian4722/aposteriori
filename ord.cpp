#include "ord.h"
// FUNCIONES
void crear_datos(int n, unsigned long long arr[])
{
    string nString = "datos_" + to_string(n) + ".txt";
    fstream archivo(nString, ios::out);
    unsigned long long tmp;
    for (int i = 0; i < n; i++)
    {
        tmp = rand();
        archivo << tmp << endl;
        arr[i] = tmp;
    }
}

void llenar_archivo(string alg, int n, chrono::nanoseconds miliSeg, long& comp, long& asig)
{
    string nombre = "resultado_";
    nombre += to_string(n) + "_" + alg + ".txt";
    fstream archivo(nombre, ios::out | ios::app);
    archivo << "Comparaciones: " << comp << endl
            << "Asignaciones: " << asig << endl
            << "Segundos: " << float(miliSeg.count()) / 1000000000 << endl 
            << "Nanosegundos: " << float(miliSeg.count()) << endl
            << "---------------------------------------------" << endl;
}

void burbuja(int n, unsigned long long arr[], long& comp, long& asig)
{
    cout << "bur" << endl;
    unsigned long long tmp;
    for (int i = 0; i <= n - 2; i++)
        for (int j = 0; j <= n - 2; j++)
        {
            ++comp;
            if (arr[j] > arr[j + 1])
            {
                ++asig;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
}

void insercion(int n, unsigned long long arr[], long& comp, long& asig)
{
    cout << "asi" << endl;
    unsigned long long tmp;
    int j;

    for (int i = 1; i < n; i++)
    {
        tmp = arr[i];
        j = i - 1;
        ++comp;
        while (j >= 0 && arr[j] > tmp)
        {
            ++asig;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

void shell_sort(int n, unsigned long long arr[], long& comp, long& asig)
{
    cout << "shell" << endl;
    unsigned long long tmp;
    int brecha = n / 2;
    int j;
    while (brecha > 0)
    {
        for (int i = brecha; i < n; ++i)
        {
            tmp = arr[i];
            j = i;
            ++comp;
            while (j >= brecha && arr[j - brecha] > tmp)
            {
                ++asig;
                arr[j] = arr[j - brecha];
                j -= brecha;
            }
            arr[j] = tmp;
        }
        brecha /= 2;
    }
}

void seleccion(int n, unsigned long long arr[], long& comp, long& asig)
{
    cout << "sel" << endl;
    unsigned long long tmp;
    int min;
    for (int i = 0; i < n - 1; ++i)
    {
        min = i;
        for (int j = i + 1; j < n; ++j)
        {
            ++comp;
            if (arr[j] < arr[min])
                min = j;
        }
        ++asig;
        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

void quick_sort(unsigned long long arr[], int inicio, int fin, long& comp, long& asig)
{
    cout << "quick" << endl;
    unsigned int pivote;

    if (inicio < fin)
    {
        pivote = quick_sort_dividir(arr, inicio, fin, comp, asig);
        quick_sort(arr, inicio, pivote - 1, comp, asig);
        quick_sort(arr, pivote + 1, fin, comp, asig);
    }
}

unsigned int quick_sort_dividir(unsigned long long arr[], int inicio, int fin, long& comp, long& asig)
{
    int izq;
    int der;
    unsigned int tmp;
    unsigned int pivote;

    izq = inicio;
    der = fin;
    pivote = arr[inicio];

    while (izq < der)
    {
        while (arr[der] > pivote)
            --der;
        while (arr[izq] <= pivote && izq < der)
            ++izq;
        ++comp;
        if (izq < der)
        {
            ++asig;
            tmp = arr[izq];
            arr[izq] = arr[der];
            arr[der] = tmp;
        }
    }

    tmp = arr[inicio];
    arr[inicio] = arr[der];
    arr[der] = tmp;
    
    return der;
}