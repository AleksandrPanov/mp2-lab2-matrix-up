// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
using namespace std;
//---------------------------------------------------------------------------

int main()
{
    TVector<int> v1(10, 5);
    v1[6] = 1;
    v1[7] = 2;
    TVector<int> v2(v1);
    if (v2 == v1) {
        cout << 1;
    }
    else {
        cout << 0;
    }
    /*TMatrix<int> a(5), b(5), c(5);
    int i, j;
    setlocale(LC_ALL, "Russian");
    std::cout << "Тестирование программ поддержки представления треугольных матриц"
              << std::endl;
    for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++ )
        {
            a[i][j] =  i * 10 + j;
            b[i][j] = (i * 10 + j) * 100;
        }
    c = a + b;
    std::cout << "Matrix a = " << std::endl << a << std::endl;
    std::cout << "Matrix b = " << std::endl << b << std::endl;
    std::cout << "Matrix c = a + b" << std::endl << c << std::endl;
    return 0;*/
}
//---------------------------------------------------------------------------
