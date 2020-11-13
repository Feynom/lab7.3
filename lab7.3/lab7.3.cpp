#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>

using namespace std;

//ІТЕРАЦІЙНИЙ СПОСІБ

void CreateMatrix_i(int** a, const int n, const int low, const int high);
void PrintMatrix_i(int** a, const int n);
void Search_i(int** a, int* row, int* col, const int n);
//РЕКУРСИВНИЙ СПОСІБ
void CreateMatrix_r(int** a, const int n, const int low, const int high, int i, int j);
void PrintMatrix_r(int** a, const int n, int i, int j);
void Search_r(int** a, int* row, int* col, const int n, int i, int num, int f, int r);

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;

    int low;
    int high;

    cout << "Введіть розмір квадратної матриці: "; cin >> n;
    cout << "Введіть діапазон:" << endl;
    cout << "\nLow = "; cin >> low;
    cout << "High = "; cin >> high;
    
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    int* Row = new int[n];
    int* Col = new int[n];

    cout << "\nІТЕРАЦІЙНИЙ СПОСІБ:" << endl; cout << endl;
    CreateMatrix_i(a, n, low, high);
    PrintMatrix_i(a, n); cout << endl;
    Search_i(a, Row, Col, n); cout << endl;



    cout << "\nРЕКУРСИВНИЙ СПОСІБ:" << endl; cout << endl;
    CreateMatrix_r(a, n, low, high, 0, 0);
    PrintMatrix_r(a, n, 0, 0); cout << endl;
    cout << "k =";
    Search_r(a, Row, Col, n, 0, 0, 0, 0); cout << endl;
   
    delete[] Col;
    delete[] Row;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

//ІТЕРАЦІЙНИЙ СПОСІБ

void CreateMatrix_i(int** a, const int n, const int low, const int high)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = low + rand() % (high - low + 1);
}

void PrintMatrix_i(int** a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}
void Search_i(int** a, int* row, int* col, const int n)
{
    cout << "k =";
    for (int num = 0; num < n; num++)
    {
        int f = 0;
        int r = 0;
        for (int i = 0; i < n; i++)
        {  
            row[f] = a[num][i];
            col[f] = a[i][num];
            if (row[f] == col[f])
                r++;
            if (r == n)
                cout << setw(3) << num + 1;
            f++;
        }
    } 
}

//РЕКУРСИВНИЙ СПОСІБ

void CreateMatrix_r(int** a, const int n, const int low, const int high, int i, int j)
{
    if (j < n)
    {
        a[i][j] = low + rand() % (high - low + 1);
        return CreateMatrix_r(a, n, low, high, i, j + 1);
    }
    if (i < n - 1)
        return CreateMatrix_r(a, n, low, high, i + 1, 0);
}
void PrintMatrix_r(int** a, const int n, int i, int j)
{
    if (j < n)
    {
        cout << setw(4) << a[i][j];
        return PrintMatrix_r(a, n, i, j + 1);
    }
    cout << endl;
    if (i < n - 1)
        return PrintMatrix_r(a, n, i + 1, 0);
}
void Search_r(int** a,int* row, int* col, const int n, int i, int num, int f, int r)
{
    if (i < n)
    {
        row[f] = a[num][i];
        col[f] = a[i][num];
        if (row[f] == col[f])
            r++;
        if (r == n)
            cout << setw(3) << num + 1;
        f++;
        return Search_r(a, row, col, n, i + 1, num, f, r);
    }
    f = 0;
    r = 0;
    if (num < n - 1)
        return Search_r(a, row, col, n, 0, num + 1, r, f);

}
