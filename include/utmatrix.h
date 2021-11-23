// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора
#pragma once

#include <iostream>
#include <limits>

// Шаблон вектора
template <class T>
class TVector
{
protected:
    T *pVector = nullptr;
    size_t size = 0;       // размер вектора с нулями
    size_t memSize = 0;    // размер памяти
    size_t startIndex = 0; // индекс первого элемента вектора
public:
    static const size_t max_size = std::numeric_limits<unsigned int>::max();

    TVector();                                   //конструктор по умолчанию
    TVector(int _size, int _startIndex = 0);       //конструктор инициализации
    TVector(size_t _size, size_t _startIndex = 0); //конструктор инициализации

    template <class TSize, class TStartIndex>
    TVector(TSize _size, TStartIndex _startIndex) = delete;

    TVector(const TVector &v);                // конструктор копирования
    ~TVector();
    size_t getSize()      { return size;       } // размер вектора
    size_t getMemSize()   { return memSize     } // размер памяти
    size_t getStartIndex(){ return startIndex; } // индекс первого элемента
    T& getElement(int i);
    T& getElement(size_t i);
    void setElement(int index, T element);
    void setElement(size_t index, T element);

    T& operator[](int pos);                  // доступ
    T& operator[](size_t pos);               // доступ
    bool operator==(const TVector &v) const; // сравнение
    bool operator!=(const TVector &v) const; // сравнение
    TVector& operator=(const TVector &v);    // присваивание


    // скалярные операции
    TVector operator+(const T &val); // прибавить скаляр
    TVector operator-(const T &val); // вычесть скаляр
    TVector operator*(const T &val); // умножить на скаляр

    // векторные операции
    TVector operator+(const TVector &v); // сложение
    TVector operator-(const TVector &v); // вычитание
    T operator*(const TVector &v);       // скалярное произведение

    // ввод-вывод
    friend std::istream& operator>>(std::istream &in, TVector &v)
    {
        for (size_t i = 0; i < v.size; i++)
        {
            if (i < v.startIndex)
            {
                int tmp = 0;
                in >> tmp;
            } else
                in >> v.pVector[i-v.startIndex];
        }
        return in;
    }
    friend std::ostream& operator<<(std::ostream &out, const TVector &v)
    {
        for (size_t i = 0; i < v.size; i++)
        {
            if (i < v.startIndex)
            {
                out << 0 << ' ';
            }
            else
                out << v.pVector[i - v.startIndex] << ' ';
        }
        return out;
    }
};

template <class T>
TVector<T>::TVector()
{
    size = 0;
    memSize = 0;
    startIndex = 0;
    pVector = nullptr;
}

template <class T>//конструктор инициализации
TVector<T>::TVector(int _size, int _startIndex = 0): size((size_t)_size), startIndex((size_t)_startIndex)
{
    if (size == 0) {
        memSize = 0;
        startIndex = 0;
        pVector = nullptr;
    }
    else
    {
        if (_size < 0 || _startIndex < 0 || startIndex >= size)
            throw -1;
        memSize = size - startIndex;
        pVector = new T[memSize];
        for (size_t i = 0; i < memSize; i++)
            pVector[i] = 0;
    }
} /*-------------------------------------------------------------------------*/

template <class T>//конструктор инициализации
TVector<T>::TVector(size_t _size, size_t _startIndex = 0) : size(_size), startIndex(_startIndex)
{
    if (size == 0) 
    {
        memSize = 0;
        startIndex = 0;
        pVector = nullptr;
    }
    else
    {
        if (size > max_size || startIndex >= size)
            throw - 1;
        memSize = size - startIndex;
        pVector = new T[memSize];
        for (size_t i = 0; i < memSize; i++)
            pVector[i] = 0;
    }
} /*-------------------------------------------------------------------------*/

template <class T> //конструктор копирования
TVector<T>::TVector(const TVector<T> &v)
{
    if (&v != this) {
        if (memSize != v.memSize) {
            delete[] pVector;
            memSize = v.memSize;
            pVector = new T[memSize];
        }
        size = v.size;
        startIndex = v.startIndex;
        for (size_t i=0; i < memSize; i++)
        {
            pVector[i] = v.pVector[i];
        }
    }
} /*-------------------------------------------------------------------------*/

template <class T> //деструктор
TVector<T>::~TVector()
{
    delete[] pVector;
} /*-------------------------------------------------------------------------*/

template <class T> // доступ
T& TVector<T>::operator[](int pos) // почему здесь инт???
{
    if (pos < 0 || pos >= size)
        throw -1;
    if (pos < startIndex)
        throw - 1;
    else
        return pVector[pos - startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // доступ
T& TVector<T>::operator[](size_t pos)
{
    if (pos >= size)
        throw -1;
    if (pos < startIndex)
        return 0;
    else
        return pVector[pos - startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator==(const TVector &v) const
{
    if(size != v.size || startIndex != v.startIndex)
        return false;
    for (size_t i = 0; i < memSize; i++)
        if (pVector[i] != v.pVector[i])
            return false;
    return true;
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator!=(const TVector &v) const
{
    return !(*this == v);
} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TVector<T>& TVector<T>::operator=(const TVector &v)
{
    if (this != &v) {
        if (memSize != v.memSize)
        {
            memSize = v.memSize;
            delete[] pVector;
            pVector = new T[memSize];
        }
        size = v.size;
        startIndex = v.startIndex;
        for (size_t i = 0; i < memSize; i++)
            pVector[i] = v.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // прибавить скаляр
TVector<T> TVector<T>::operator+(const T &val)
{
    for (size_t i = 0; i < memSize; i++)
        pVector[i] = pVector[i] + val;
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // вычесть скаляр
TVector<T> TVector<T>::operator-(const T &val)
{
    for (size_t i = 0; i < memSize; i++)
        pVector[i] = pVector[i] - val;
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // умножить на скаляр
TVector<T> TVector<T>::operator*(const T &val)
{
    for (size_t i = 0; i < memSize; i++)
        pVector[i] = pVector[i] * val;
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TVector<T> TVector<T>::operator+(const TVector<T> &v)
{
    TVector<T> result(*this);
    if (size != v.size || startIndex != v.startIndex)
        throw -1;
    for (size_t i = 0; i < memSize; i++)
        result.pVector[i] = result.pVector[i] + v.pVector[i];
    return result;
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TVector<T> TVector<T>::operator-(const TVector<T> &v)
{
    TVector<T> result(*this);
    if (size != v.size || startIndex != v.startIndex)
        throw -1;
    for (size_t i = 0; i < memSize; i++)
        result.pVector[i] = result.pVector[i] - v.pVector[i];
    return result;
} /*-------------------------------------------------------------------------*/

template <class T> // скалярное произведение
T TVector<T>::operator*(const TVector<T> &v)
{
    if (size != v.size || startIndex != v.startIndex)
        throw -1;
    T sum = 0;
    for (size_t i = 0; i < memSize; i++)
        sum = sum + (pVector[i] * v.pVector[i]);
    return sum;
} /*-------------------------------------------------------------------------*/

template <class T>
T& TVector<T>::getElement(int index) // почему инт???
{
    if (index < 0 || index >= size)
        throw -1;
    if(index < startIndex)
        throw - 1;
    else
        return pVector[index - startIndex];
}

template <class T>
T& TVector<T>::getElement(size_t index)
{
    if (index < startIndex || index >= size)
        throw -1;
    return pVector[index - startIndex];
}

template <class T>
void TVector<T>::setElement(int index, T element)
{
    if (index < 0 || index < startIndex || index >= size)
        throw -1;
    pVector[index - startIndex] = element;
}

template <class T>
void TVector<T>::setElement(size_t index, T element)
{
    if (index < startIndex || index >= size)
        throw -1;
    pVector[index - startIndex] = element;
}

// Верхнетреугольная матрица
// val1 val2 val3 ... valn-1 valn
// 0    val2 val3 ... valn-1 valn
// 0    0    val3 ... valn-1 valn
// ..............................
// 0    0    0    ... 0      valn 
template <class T>
class TMatrix : public TVector<TVector<T>>
{
public:
    TMatrix(int s);
    TMatrix(size_t s);

    template <class TSize>
    TMatrix(TSize size) = delete;

    TMatrix(const TMatrix &mt);               // копирование
    TMatrix(const TVector<TVector<T> > &mt);  // преобразование типа
    bool operator==(const TMatrix &mt) const; // сравнение
    bool operator!=(const TMatrix &mt) const; // сравнение
    TMatrix& operator= (const TMatrix &mt);   // присваивание
    TMatrix operator+ (const TMatrix &mt);    // сложение
    TMatrix operator- (const TMatrix &mt);    // вычитание

    // ввод / вывод
    friend std::istream& operator>>(std::istream &in, TMatrix &mt)
    {
      for (size_t i = 0; i < mt.size; i++)
        in >> mt.pVector[i];
      return in;
    }
    friend std::ostream & operator<<( std::ostream &out, const TMatrix &mt)
    {
      for (size_t i = 0; i < mt.size; i++)
        out << mt.pVector[i] << std::endl;
      return out;
    }
};

template <class T>
TMatrix<T>::TMatrix(int s): TVector<TVector<T>> (s)
{
    if (s < 0)
        throw -1;
    for (size_t i = 0; i < s; i++)
    {
        TMatrix<T>::pVector[i] = TVector<T>((size_t)s, i);
    }
} /*-------------------------------------------------------------------------*/

template <class T>
TMatrix<T>::TMatrix(size_t s): TVector<TVector<T>> (s)
{
    for (size_t i = 0; i < s; i++)
    {
        TMatrix<T>::pVector[i] = TVector<T>(s, i);
    }
}

template <class T> // конструктор копирования
TMatrix<T>::TMatrix(const TMatrix<T> &mt):
  TVector<TVector<T> >(mt) {}

template <class T> // конструктор преобразования типа
TMatrix<T>::TMatrix(const TVector<TVector<T> > &mt):
  TVector<TVector<T> >(mt) {}

template <class T> // сравнение
bool TMatrix<T>::operator==(const TMatrix<T> &mt) const
{
    if (size != mt.size)
        return false;
    for (size_t i = 0; i < size; i++)
        if (pVector[i] != mt.pVector[i])
            return false;
    return true;
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TMatrix<T>::operator!=(const TMatrix<T> &mt) const
{
    if (size != mt.size)
        return true;
    for (size_t i = 0; i < size; i++)
        if (pVector[i] != mt.pVector[i])
            return true;
    return false;
} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &mt)
{
    if (this != &mt)
    {
        if (size != mt.size) // size = memSize в любой матрице
        {
            size = mt.size;
            delete[] pVector;
            pVector = new TVector<T>[size];
        }
        memSize = mt.memSize;
        startIndex = mt.startIndex;
        for (size_t i = 0; i < size; i++)
            pVector[i] = mt.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &mt)
{
    TMatrix<T> result(mt);
    if (size != mt.size)
        throw -1;
    for (size_t i = 0; i < size; i++)
        result.pVector[i] = result.pVector[i] + mt.pVector[i];
    return result;
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &mt)
{
    TMatrix<T> result(mt);
    if (size != mt.size)
        throw -1;
    for (size_t i = 0; i < size; i++)
        result.pVector[i] = result.pVector[i] - mt.pVector[i];
    return result;
} /*-------------------------------------------------------------------------*/
