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
    TMatrix<int> a(5), b(5), c(5);
    int i, j;
    setlocale(LC_ALL, "Russian");
    std::cout << "������������ �������� ��������� ������������� ����������� ������"
              << std::endl;
    for (i = 0; i < 5; i++)
    {
        for (j = i; j < 5; j++)
        {
            a[i][j] =  i * 10 + j;
            b[i][j] = (i * 10 + j) * 100;
            //a[i][j] = 1;
            //b[i][j] = 1;
        }
    }
    c = a + b;
    std::cout << "Matrix a = " << std::endl << a << std::endl;
    std::cout << "Matrix b = " << std::endl << b << std::endl;
    std::cout << "Matrix c = a + b" << std::endl << c << std::endl;

    TMatrix<int> aa(a);

    if(a==aa)
        std::cout << "Yes, equal" << std::endl;
    else 
        std::cout << "No equal" << std::endl;
    std::cout << a << std::endl << aa << std::endl;


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
    
    TVector<int> k(3, 0);
    for (int i = 0; i < 3; i++)
    {
        k[i] = 1;
    }
    TVector<int> p(k);

    //k.setElement(-1, 99);
    std::cout << p << std::endl << k;
}
//---------------------------------------------------------------------------
