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

void llenar_archivo(string alg, int n, unsigned long long arr[], chrono::nanoseconds miliSeg)
{
    string nombre = "resultado_";
    nombre += to_string(n) + "_" + alg + ".txt";
    fstream archivo(nombre, ios::out | ios::app);
    for(int i = 0; i < n; i++)
        archivo << arr[i] << endl;
    archivo << "Segundos: " << float(miliSeg.count()) / 1000000000 << endl 
            << "Nanosegundos: " << float(miliSeg.count()) << endl
            << "---------------------------------------------" << endl;
}

void burbuja(int n, unsigned long long arr[])
{
    cout << "bur" << endl;
    unsigned long long tmp;
    for (int i = 0; i <= n - 2; i++)
        for (int j = 0; j <= n - 2; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
}

void insercion(int n, unsigned long long arr[])
{
    cout << "ins" << endl;
    unsigned long long tmp;
    int j;

    for (int i = 1; i < n; i++)
    {
        tmp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > tmp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

void shell_sort(int n, unsigned long long arr[])
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
            while (j >= brecha && arr[j - brecha] > tmp)
            {
                arr[j] = arr[j - brecha];
                j -= brecha;
            }
            arr[j] = tmp;
        }
        brecha /= 2;
    }
}

void seleccion(int n, unsigned long long arr[])
{
    cout << "sel" << endl;
    unsigned long long tmp;
    int min;
    for (int i = 0; i < n - 1; ++i)
    {
        min = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[min])
                min = j;
        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

void quick_sort(unsigned long long arr[], int inicio, int fin)
{
    cout << "quick" << endl;
    unsigned int pivote;

    if (inicio < fin)
    {
        pivote = quick_sort_dividir(arr, inicio, fin);
        quick_sort(arr, inicio, pivote - 1);
        quick_sort(arr, pivote + 1, fin);
    }
}

unsigned int quick_sort_dividir(unsigned long long arr[], int inicio, int fin)
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
        if (izq < der)
        {
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