// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
    TMatrix<int> a(5), b(5), c(5);
    int i, j;
    setlocale(LC_ALL, "Russian");
    std::cout << "Тестирование программ поддержки представления треугольных матриц"
              << std::endl;
    for (i = 0; i < 5; i++)
    {
        for (j = i; j < 5; j++)
        {
            //a[i][j] =  i * 10 + j;
            //b[i][j] = (i * 10 + j) * 100;
            a[i][j] = 1;
            b[i][j] = 1;
        }
    }
    c = a + b;
    std::cout << "Matrix a = " << std::endl << a << std::endl;
    std::cout << "Matrix b = " << std::endl << b << std::endl;
    std::cout << "Matrix c = a + b" << std::endl << c << std::endl;

    TVector<int> f(3, 0), g(3, 0);
    for (int i = 0; i < 3; i++)
    {
        f[i] = 1;
    }
    g[0] = f[0] + 1;
    g[1] = g[0] + f[0];
    g[2] = 0;
    std::cout << g<<std::endl;
    TVector<int> m = g;
    std::cout << m << std::endl;
    if(m==g)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    
}
//---------------------------------------------------------------------------
