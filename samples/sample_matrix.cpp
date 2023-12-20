// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include "utmatrix.h"
//---------------------------------------------------------------------------

int main()
{
    TMatrix<int> m(4);
    m[0].setElement(0,4);

    std::cout << m[0].getElement(0);
    // << "\n" << m2;
    //std::cout << a;
    //std::cout << a;
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
    TMatrix<int> d = a;
    std::cout << d;
    return 0;*/
}
//---------------------------------------------------------------------------
