// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
    /*TMatrix<int> a(5), b(5), c(5);
    int i, j;
    setlocale(LC_ALL, "Russian");
    std::cout << "������������ �������� ��������� ������������� ����������� ������"
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
    std::cout << "Matrix c = a + b" << std::endl << c << std::endl;*/

    TVector<int> vector(5, 2);
    std::cin >> vector;

    TVector<int> vector2(5, 2);
    //std::cin >> vector;
    vector2 = vector + 3;
    std::cout << "\n" << vector2;

}
//---------------------------------------------------------------------------
