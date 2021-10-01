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

    explicit TVector(int size, int startIndex = 0);       //конструктор инициализации
    explicit TVector(size_t size = 1, size_t startIndex = 0); //конструктор инициализации

    template <class OtherTypes>
    TVector(OtherTypes size, OtherTypes startIndex) = delete;

    TVector(const TVector &v);                // конструктор копирования
    ~TVector();
    size_t getSize()       const { return size;       } // размер вектора
    size_t getStartIndex() const { return startIndex; } // индекс первого элемента
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
        for (size_t i = v.getStartIndex(); i < v.getSize(); ++i)
            in >> v[i];
        return in;
    }
    friend std::ostream& operator<<(std::ostream &out, const TVector &v)
    {
        TVector& nc = const_cast<TVector&>(v);
        for (size_t i = 0; i < v.getSize(); ++i)
        {
            if (i < nc.getStartIndex())
                out << 0;
            else
                out << nc[i];
            out << " ";
        }
        return out;
    }
};

template <class T>//конструктор инициализации
TVector<T>::TVector(int size, int startIndex) :
    TVector(static_cast<size_t>(size), static_cast<size_t>(startIndex))
{
    if (size <= 0 || startIndex < 0 || startIndex >= size)
        throw std::runtime_error("Incorrect size or startIndex");
} /*-------------------------------------------------------------------------*/

template <class T>//конструктор инициализации
TVector<T>::TVector(size_t size, size_t startIndex) :
    size(size), 
    startIndex(startIndex)
{
    if (size > max_size || startIndex < 0 || startIndex >= size)
        throw std::runtime_error("Incorrect size or startIndex");

    pVector = new T[size - startIndex];

    if (std::is_arithmetic<T>::value)
        for (size_t i = 0; i < size - startIndex; ++i)
            pVector[i] = T(0);
} /*-------------------------------------------------------------------------*/

template <class T> //конструктор копирования
TVector<T>::TVector(const TVector<T> &v) :
    TVector(v.size, v.startIndex)
{
    for (size_t i = 0; i < size - startIndex; ++i)
        pVector[i] = v.pVector[i];
} /*-------------------------------------------------------------------------*/

template <class T> //деструктор
TVector<T>::~TVector()
{
    delete[] pVector;
} /*-------------------------------------------------------------------------*/

template <class T> // доступ
T& TVector<T>::operator[](int pos)
{
    if (pos < startIndex || pos >= size)
        throw std::out_of_range("Incorrect index");

    return pVector[pos - startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // доступ
T& TVector<T>::operator[](size_t pos)
{
    if (pos < startIndex || pos >= size)
        throw std::out_of_range("Incorrect index");

    return pVector[pos - startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator==(const TVector &v) const
{
    if(size != v.size || startIndex != v.startIndex)
        return false;

    for (size_t i = 0; i < size - startIndex; ++i)
        if (pVector[i] != v.pVector[i])
            return false;

    return true;
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator!=(const TVector &v) const
{
    return !operator==(v);
} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TVector<T>& TVector<T>::operator=(const TVector &v)
{
    if (this == &v)
        return *this;

    size = v.size;
    startIndex = v.startIndex;

    if (pVector)
        delete[] pVector;

    pVector = new T[size - startIndex];
    for (size_t i = 0; i < size - startIndex; ++i)
        pVector[i] = v.pVector[i];

    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // прибавить скаляр
TVector<T> TVector<T>::operator+(const T &val)
{
    TVector result(size, startIndex);

    for (size_t i = 0; i < size - startIndex; ++i)
        result.pVector[i] = pVector[i] + val;

    return result;
} /*-------------------------------------------------------------------------*/

template <class T> // вычесть скаляр
TVector<T> TVector<T>::operator-(const T &val)
{
    return operator+(-val);
} /*-------------------------------------------------------------------------*/

template <class T> // умножить на скаляр
TVector<T> TVector<T>::operator*(const T &val)
{
    TVector result(size, startIndex);

    for (size_t i = 0; i < size - startIndex; ++i)
        result.pVector[i] = pVector[i] * val;

    return result;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TVector<T> TVector<T>::operator+(const TVector<T> &v)
{
    if (size != v.size || startIndex != v.startIndex)
        throw std::runtime_error("Different size or startIndex");

    TVector result(size, startIndex);

    for (size_t i = 0; i < size - startIndex; ++i)
        result.pVector[i] = pVector[i] + v.pVector[i];

    return result;
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TVector<T> TVector<T>::operator-(const TVector<T> &v)
{
    if (size != v.size || startIndex != v.startIndex)
        throw std::runtime_error("Different size or startIndex");

    TVector result(size, startIndex);

    for (size_t i = 0; i < size - startIndex; ++i)
        result.pVector[i] = pVector[i] - v.pVector[i];

    return result;
} /*-------------------------------------------------------------------------*/

template <class T> // скалярное произведение
T TVector<T>::operator*(const TVector<T> &v)
{
    if (size != v.size || startIndex != v.startIndex)
        throw std::runtime_error("Different size or startIndex");

    T sum = 0;
    for (size_t i = 0; i < size - startIndex; ++i)
        sum += pVector[i] * v.pVector[i];

    return sum;
} /*-------------------------------------------------------------------------*/

template <class T>
T& TVector<T>::getElement(int index)
{
    if (index < startIndex || index >= size)
        throw std::out_of_range("Incorrect index");

    return pVector[index];
}

template <class T>
void TVector<T>::setElement(int index, T element)
{
    if (index < startIndex || index >= size)
        throw std::out_of_range("Incorrect index");

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
    //bool operator==(const TMatrix &mt) const; // сравнение
    //bool operator!=(const TMatrix &mt) const; // сравнение
    //TMatrix& operator= (const TMatrix &mt);   // присваивание
    //TMatrix operator+ (const TMatrix &mt);    // сложение
    //TMatrix operator- (const TMatrix &mt);    // вычитание

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
TMatrix<T>::TMatrix(int s) :
    TVector<TVector<T> >(s)
{
    for (size_t i = 0; i < s; ++i)
        this->pVector[i] = TVector<T>(static_cast<size_t>(s), i);
} /*-------------------------------------------------------------------------*/

template <class T>
TMatrix<T>::TMatrix(size_t s) :
    TVector<TVector<T> >(s)
{
    for (size_t i = 0; i < s; ++i)
        this->pVector[i] = TVector<T>(s, i);
} /*-------------------------------------------------------------------------*/

template <class T> // конструктор копирования
TMatrix<T>::TMatrix(const TMatrix<T>& mt) :
    TVector<TVector<T> >(mt)
{   };

template <class T> // конструктор преобразования типа
TMatrix<T>::TMatrix(const TVector<TVector<T> >& mt) :
    TVector<TVector<T> >(mt)
{   };

//template <class T> // сравнение
//bool TMatrix<T>::operator==(const TMatrix<T> &mt) const
//{
//    return TVector::operator==(mt);
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // сравнение
//bool TMatrix<T>::operator!=(const TMatrix<T> &mt) const
//{
//    return !operator==(mt);
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // присваивание
//TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &mt)
//{
//    TVector::operator=(mt);
//    return *this;
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // сложение
//TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &mt)
//{
//    return TVector::operator+(mt);
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // вычитание
//TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &mt)
//{
//    return TVector::operator-(mt);
//} /*-------------------------------------------------------------------------*/
