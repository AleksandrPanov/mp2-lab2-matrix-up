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
        for (j = i; j < 5; j++ )
        {
            a[i][j] =  i * 10 + j;
            b[i][j] = (i * 10 + j) * 100;
        }
    c = a + b;
    std::cout << "Matrix a = " << std::endl << a << std::endl;
    std::cout << "Matrix b = " << std::endl << b << std::endl;
    std::cout << "Matrix c = a + b" << std::endl << c << std::endl;

    /*TMatrix<int> m1(3);
    TMatrix<int> m2(3);
    m1[0][0] = 1; m2[0][0] = 1;
    m1[0][1] = 2; m2[0][1] = 2;
    m1[0][2] = 3; m2[0][2] = 3;
    m1[1][1] = 4; m2[1][1] = 4;
    m1[1][2] = 5; m2[1][2] = 5;
    m1[2][2] = 6; m2[2][2] = 6;

    std::cout << std::endl << m1 << std::endl;
    std::cout << std::endl << m2 << std::endl;

    m1 == m2;

    //std::cout << std::endl << m << std::endl;*/

}
//---------------------------------------------------------------------------
