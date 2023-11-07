// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include "utmatrix.h"
//---------------------------------------------------------------------------

int main()
{
    TMatrix<int> a(5), b(5), c(5);
    int i, j;
    setlocale(LC_ALL, "Russian");
    std::cout << "text"<< std::endl;
    for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++ )
        {
            a[i][j] =  i * 10 + j;
            b[i][j] = (i * 10 + j) * 100;
        }
    
    std::cout << "Matrix a = " << std::endl << a << std::endl;
    std::cout << "Matrix b = " << std::endl << b << std::endl;
    c = a + b;
    std::cout << "Matrix c = a + b" << std::endl << c << std::endl;
    return 0;
}
//---------------------------------------------------------------------------
