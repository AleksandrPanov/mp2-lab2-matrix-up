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
    T *pVector;
    size_t size;       // размер вектора
    size_t startIndex; // индекс первого элемента вектора
public:
    static const size_t max_size = std::numeric_limits<unsigned int>::max();

    TVector(): pVector(nullptr), size(0), startIndex(0) {}
    TVector(int size, int startIndex = 0);       //конструктор инициализации
    TVector(size_t size, size_t startIndex = 0); //конструктор инициализации

    template <class TSize, class TStartIndex>
    TVector(TSize size, TStartIndex startIndex) = delete;

    TVector(const TVector &v);                // конструктор копирования
    ~TVector();
    size_t getSize()      { return size;       } // размер вектора
    size_t getStartIndex(){ return startIndex; } // индекс первого элемента
    T& getElement(int i) const;
    T& getElement(size_t i) const;
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
        for (size_t i = 0; i < v.size-v.startIndex; i++) {
            T x;
            in >> x;
            v.pVector[i] = x;
        }
        return in;
    }
    friend std::ostream& operator<<(std::ostream &out, const TVector &v)
    {
        for (size_t i = 0; i < v.size-v.startIndex; i++) {
            out << v.pVector[i] << " ";
        }
        return out;
    }
};

template <class T>//конструктор инициализации
TVector<T>::TVector(int _size, int _startIndex)
{
    if (_startIndex < 0 || _startIndex >= _size || _size > max_size)
        throw "Error";
    size = _size;
    startIndex = _startIndex;
    pVector = new T[size-startIndex];
    for (size_t i = 0; i < size - startIndex; i++)
    {
        pVector[i] = T();
    }
} /*-------------------------------------------------------------------------*/

template <class T>//конструктор инициализации
TVector<T>::TVector(size_t _size, size_t _startIndex)
{
    if (_startIndex < 0 || _startIndex >= _size || _size > max_size)
        throw "Error";
    size = _size;
    startIndex = _startIndex;
    pVector = new T[size - startIndex];
    for (size_t i = 0; i < size - startIndex; i++)
    {
        pVector[i] = T();
    }
} /*-------------------------------------------------------------------------*/

template <class T> //конструктор копирования
TVector<T>::TVector(const TVector<T> &v)
{
    size = v.size;
    startIndex = v.startIndex;
    this->pVector = new T[size - startIndex];
    for (int i = 0; i < size - startIndex; i++)
        pVector[i] = v.pVector[i];
} /*-------------------------------------------------------------------------*/

template <class T> //деструктор
TVector<T>::~TVector()
{
    size = 0;
    startIndex = 0;
    delete[] pVector;
} /*-------------------------------------------------------------------------*/

template <class T> // доступ
T& TVector<T>::operator[](int pos)
{
    if (pos - startIndex < 0 || pos >= size)
        throw "Error";
    return this->pVector[pos-startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // доступ
T& TVector<T>::operator[](size_t pos)
{
    if (pos - startIndex < 0 || pos >= size)
        throw "Error";
    return this->pVector[pos-startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator==(const TVector &v) const
{
    if(size != v.size || startIndex != v.startIndex)
        return false;
    for (size_t i = 0; i < size - startIndex; i++)
    {
        if (this->pVector[i] != v.pVector[i])
            return false;
    }
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
    if (this == &v)
        return *this;
    size = v.size;
    startIndex = v.startIndex;
    delete[] pVector;
    pVector = new T[size - startIndex];
    for (size_t i = 0; i < size - startIndex; i++)
    {
        pVector[i] = v.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // прибавить скаляр
TVector<T> TVector<T>::operator+(const T &val)
{
    for (size_t i = 0; i < size - startIndex; i++)
    {
        pVector[i] = pVector[i] + val;
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // вычесть скаляр
TVector<T> TVector<T>::operator-(const T &val)
{
    for (size_t i = 0; i < size - startIndex; i++)
    {
        pVector[i] = pVector[i] - val;
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // умножить на скаляр
TVector<T> TVector<T>::operator*(const T &val)
{
    for (size_t i = 0; i < size - startIndex; i++)
    {
        pVector[i] = pVector[i]*val;
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TVector<T> TVector<T>::operator+(const TVector<T> &v)
{
    if ((size - startIndex) != (v.size - v.startIndex))
        throw "Error";
    for (size_t i = 0; i < size - startIndex; i++)
    {
        pVector[i] = pVector[i] + v.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TVector<T> TVector<T>::operator-(const TVector<T> &v)
{
    if ((size - startIndex) != (v.size - v.startIndex))
        throw "Error";
    for (size_t i = 0; i < size - startIndex; i++)
    {
        pVector[i] = pVector[i] - v.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // скалярное произведение
T TVector<T>::operator*(const TVector<T> &v)
{
    if (size != v.size || startIndex!= v.startIndex)
        throw "Error";
    T res = 0;
    for (size_t i = 0; i < size - startIndex; i++)
    {
        res = pVector[i] * v.pVector[i] + res;
    }
    return res;
} /*-------------------------------------------------------------------------*/

template <class T>
T& TVector<T>::getElement(int index) const
{
    if (index >= (size - startIndex) || index<0)
        throw "Error";
    return pVector[index];
}

template <class T>
T& TVector<T>::getElement(size_t index) const
{
    if (index >= (size - startIndex) || index < 0)
        throw "Error";
    return pVector[index];
}

template <class T>
void TVector<T>::setElement(int index, T element)
{
    if (index >= (size - startIndex) || index < 0)
        throw "Error";
    pVector[index] = element;
}

template <class T>
void TVector<T>::setElement(size_t index, T element)
{
    if (index >= (size - startIndex) || index < 0)
        throw "Error";
    pVector[index] = element;
}

// Верхнетреугольная матрица
// val1 val2 val3 ... valn-1 valn
// 0    val2 val3 ... valn-1 valn
// 0    0    val3 ... valn-1 valn
// ..............................
// 0    0    0    ... 0      valn 
template <class T>
class TMatrix : public TVector<TVector<T> >
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
      for (int i = 0; i < mt.size; i++)
        in >> mt.pVector[i];
      return in;
    }
    friend std::ostream & operator<<( std::ostream &out, const TMatrix &mt)
    {
      for (int i = 0; i < mt.size; i++)
        out << mt.pVector[i] << std::endl;
      return out;
    }
};

template <class T>
TMatrix<T>::TMatrix(int s): TVector<TVector<T> >(s)
{
    for (int i = 0; i < s; i++)
    {
        TVector<TVector<T> >::pVector[i] = TVector<T>(s, i);
    }
} /*-------------------------------------------------------------------------*/

template <class T>
TMatrix<T>::TMatrix(size_t s) : TVector<TVector<T> >(s)
{
    for (size_t i = 0; i < s; i++)
    {
        TVector<TVector<T> >::pVector[i] = TVector<T>(s, i);
    }
} /*-------------------------------------------------------------------------*/

template <class T> // конструктор копирования
TMatrix<T>::TMatrix(const TMatrix<T> &mt):TVector<TVector<T> >(mt)
{
    TVector<TVector<T> >::size = mt.size;
    TVector<TVector<T> >::pVector = new TVector<T>[TVector<TVector<T> >::size];
    for (size_t i = 0; i < TVector<TVector<T> >::size; i++)
    {
        TVector<TVector<T> >::pVector[i] = mt.pVector[i];
    }
}

template <class T> // конструктор преобразования типа
TMatrix<T>::TMatrix(const TVector<TVector<T> > &mt):TVector<TVector<T> >(mt) 
{
    TVector<TVector<T> >::size = mt.size;
    TVector<TVector<T> >::pVector = new TVector<T>[TVector<TVector<T> >::size];
    for (size_t i = 0; i < TVector<TVector<T> >::size; i++)
    {
        TVector<TVector<T> >::pVector[i] = mt.pVector[i];
    }
}

template <class T> // сравнение
bool TMatrix<T>::operator==(const TMatrix<T> &mt) const
{
    if (TVector<TVector<T> >::size != mt.size)
        return false;
    for (size_t i = 0; i < TVector<TVector<T> >::size; i++)
    {
        if (TVector<TVector<T> >::pVector[i] != mt.pVector[i])
            return false;
    }
    return true;
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TMatrix<T>::operator!=(const TMatrix<T> &mt) const
{
    return !(*this == mt);
} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &mt)
{
    if (this == &mt)
        return *this;
    delete[] TVector<TVector<T> >::pVector;
    TVector<TVector<T> >::size = mt.size;
    TVector<TVector<T> >::pVector = new TVector<T>[TVector<TVector<T> >::size];
    for (size_t i = 0; i < TVector<TVector<T>>::size; i++)
    {
        TVector<TVector<T> >::pVector[i] = mt.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &mt)
{
    if (TVector<TVector<T> >::size != mt.size)
        throw "Error";
    for (size_t i = 0; i < TVector<TVector<T> >::size; i++)
    {
        TVector<TVector<T> >::pVector[i] = TVector<TVector<T> >::pVector[i] + mt.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &mt)
{
    if (TVector<TVector<T> >::size != mt.size)
        throw "Error";
    for (size_t i = 0; i < TVector<TVector<T> >::size; i++)
    {
        TVector<TVector<T> >::pVector[i] = TVector<TVector<T> >::pVector[i] - mt.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/
