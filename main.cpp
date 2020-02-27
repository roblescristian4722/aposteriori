#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

enum ARG
{
    ARG_COMANDO = 0,
    ARG_ALG,
    ARG_TAM
};

void burbuja(int n, unsigned long long arr[]);
void insercion(int n, unsigned long long arr[]);
void shell_sort(int n, unsigned long long arr[]);
void seleccion(int n, unsigned long long arr[]);
void crear_datos(int n, unsigned long long arr[]);

int main(int argc, char* argv[])
{
    unsigned long long arr[100000];
    int n = atoi(argv[1]);
    
    srand(time(NULL));

    crear_datos(n, arr);
    seleccion(n, arr);

    return 0;
}

void crear_datos(int n, unsigned long long arr[])
{
    string nString = "datos_" + to_string(n) + ".txt";
    unsigned long long tmp;
    fstream archivo(nString, ios::out);
    for (int i = 0; i < n; i++)
    {
        tmp = rand();
        archivo << tmp << endl;
        arr[i] = tmp;
    }
}

void burbuja(int n, unsigned long long arr[])
{
    string nombre = "resultado_burbuja_";
    nombre += to_string(n) + ".txt";
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
    
    fstream archivo(nombre, ios::out | ios::app);
    for(int i = 0; i < n; i++)
        archivo << arr[i] << endl;
    archivo << "---------------------------------------------\n";
}

void insercion(int n, unsigned long long arr[])
{
    unsigned long long tmp;
    string nombre = "resultado_insercion_";
    nombre += to_string(n) + ".txt";
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

    fstream archivo(nombre, ios::out | ios::app);
    for(int i = 0; i < n; i++)
        archivo << arr[i] << endl;
    archivo << "---------------------------------------------\n";
}

void shell_sort(int n, unsigned long long arr[])
{
    unsigned long long tmp;
    string nombre = "resultado_shell_sort_";
    nombre += to_string(n) + ".txt";

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

    fstream archivo(nombre, ios::out | ios::app);
    for(int i = 0; i < n; i++)
        archivo << arr[i] << endl;
    archivo << "---------------------------------\n";
}

void seleccion(int n, unsigned long long arr[])
{
    unsigned long long tmp;
    string nombre = "resultado_seleccion_";
    nombre += to_string(n) + ".txt";

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
    
    fstream archivo(nombre, ios::out | ios::app);
    for(int i = 0; i < n; i++)
        archivo << arr[i] << endl;
    archivo << "---------------------------------\n";
}