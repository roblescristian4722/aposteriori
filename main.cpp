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
void crear_datos(int n, unsigned long long arr[]);

int main(int argc, char* argv[])
{
    unsigned long long arr[100000];
    int n = atoi(argv[1]);
    
    srand(time(NULL));

    crear_datos(n, arr);
    burbuja(n, arr);
    burbuja(n, arr);

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