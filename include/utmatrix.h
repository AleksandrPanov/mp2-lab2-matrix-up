// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора
#pragma once

#include <iostream>
#include <limits>
#include <algorithm>

// Шаблон вектора
template <class T>
class TVector
{
protected:
    T* pVector;
    size_t size;       // размер вектора
    size_t startIndex; // индекс первого элемента вектора
public:
    static const size_t max_size = std::numeric_limits<unsigned int>::max();

    TVector():size(0), startIndex(0), pVector(nullptr) {}
    TVector(int size, int startIndex = 0);       //конструктор инициализации
    TVector(size_t size, size_t startIndex = 0); //конструктор инициализации

    template <class TSize, class TStartIndex>
    TVector(TSize size, TStartIndex startIndex) = delete;

    TVector(const TVector& v);                // конструктор копирования
    ~TVector();
    size_t getSize() { return size; } // размер вектора
    size_t getStartIndex() { return startIndex; } // индекс первого элемента
    T& getElement(int i);
    T& getElement(size_t i);
    void setElement(int index, T element);
    void setElement(size_t index, T element);

    T& operator[](int pos);                  // доступ
    T& operator[](size_t pos);               // доступ
    bool operator==(const TVector& v) const; // сравнение
    bool operator!=(const TVector& v) const; // сравнение
    TVector& operator=(const TVector& v);    // присваивание


    // скалярные операции
    TVector operator+(const T& val); // прибавить скаляр
    TVector operator-(const T& val); // вычесть скаляр
    TVector operator*(const T& val); // умножить на скаляр

    // векторные операции
    TVector operator+(const TVector& v); // сложение
    TVector operator-(const TVector& v); // вычитание
    T operator*(const TVector& v);       // скалярное произведение

    // ввод-вывод
    friend std::istream& operator>>(std::istream& in, TVector& v)
    {
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const TVector& v)
    {
        return out;
    }
};

template <class T>//конструктор инициализации
TVector<T>::TVector(int _size, int startIndex): size(_size), startIndex(startIndex)
{
    if (size < 0 || startIndex < 0 || size >=max_size) throw(1);
    pVector = new T[size-startIndex];
    std::fill(&pVector[0], &pVector[size - startIndex - 1] + 1, (T)0);
} /*-------------------------------------------------------------------------*/

template <class T>//конструктор инициализации
TVector<T>::TVector(size_t _size, size_t startIndex):size(_size), startIndex(startIndex)
{
    if (size < 0 || startIndex < 0 || size >=max_size) throw(1);
    pVector = new T[size-startIndex];
    std::fill(&pVector[0], &pVector[size - startIndex - 1] + 1, (T)0);
} /*-------------------------------------------------------------------------*/

template <class T> //конструктор копирования
TVector<T>::TVector(const TVector<T>& v)
{
    size = v.size;
    this->startIndex = v.startIndex;
    if (size != 0) {
        this->pVector = new T[size-startIndex];
        for (int i = 0; i < size-startIndex; i++)
            this->pVector[i] = v.pVector[i];
    }
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
    if (pos>=size || pos < 0) throw(1);
    else return pVector[(size_t)(pos-startIndex)];
} /*-------------------------------------------------------------------------*/

template <class T> // доступ
T& TVector<T>::operator[](size_t pos)
{
    if (pos >=size || pos < 0) throw(1);
    else return pVector[pos-startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator==(const TVector& v) const
{
    if (size != v.size || startIndex != v.startIndex) return false;
    else {
        for (int i = 0; i < size-startIndex; i++)
            if (pVector[i] != v.pVector[i]) return false;
    }
    return true;
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator!=(const TVector& v) const
{
    if (size != v.size || startIndex != v.startIndex) return true;
    else {
        for (int i = 0; i < size-startIndex; i++)
            if (pVector[i] == v.pVector[i]) return false;
    }
    return true;

} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TVector<T>& TVector<T>::operator=(const TVector& v)
{
    if (this == &v) return *this;
    this->size = v.size;
    this->startIndex = v.startIndex;
    if (size!=0) 
        delete[] pVector;
    pVector = new T[size-startIndex];
    for (size_t i = 0; i < size-startIndex; i++) {
        this->pVector[i] = v.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // прибавить скаляр
TVector<T> TVector<T>::operator+(const T& val)
{
    startIndex = 0;
    for (int i = 0; i < size-startIndex; i++)
        pVector[i] += val;
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // вычесть скаляр
TVector<T> TVector<T>::operator-(const T& val)
{
    startIndex = 0;
    for (int i = 0; i < size-startIndex; i++)
        pVector[i] -= val;
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // умножить на скаляр
TVector<T> TVector<T>::operator*(const T& val)
{
    for (size_t i = 0; i < size; i++)
        pVector[i] *= val;
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TVector<T> TVector<T>::operator+(const TVector<T>& v)
{
    if (size != v.size) throw(1);
    TVector<T> addition(size, std::min(startIndex,v.startIndex ));
    for (size_t i = 0; i < size-startIndex; i++)
        addition.pVector[i] = pVector[i] + v.pVector[i];
    return addition;
    
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TVector<T> TVector<T>::operator-(const TVector<T>& v)
{
    if (size != v.size) throw(1);
    TVector<T> substraction(size, std::min( startIndex,v.startIndex ));
    for (size_t i = 0; i < size-startIndex; i++)
        substraction.pVector[i] = pVector[i] - v.pVector[i];
    return substraction;
} /*-------------------------------------------------------------------------*/

template <class T> // скалярное произведение
T TVector<T>::operator*(const TVector<T>& v)
{
    if (size != v.size) throw(1);
    T scalar = 0;
    for (size_t i = 0; i < size-startIndex; i++)
        scalar += pVector[i] * v.pVector[i];
    return scalar;
} /*-------------------------------------------------------------------------*/

template <class T>
T& TVector<T>::getElement(int index)
{
    if (index < 0 || index >= size) throw(1);
    return *pVector[index];
}
template <class T>
T& TVector<T>::getElement(size_t index)
{
    if (index < 0 || index >= size) throw(1);
    return *pVector[index];
}

template <class T>
void TVector<T>::setElement(int index, T element)
{
    if (index < 0 || index >=size) throw(1);
    pVector[index] = element; 
}
template <class T>
void TVector<T>::setElement(size_t index, T element)
{
    if (index < 0 || index >=) throw(1);
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

    TMatrix(const TMatrix& mt);               // копирование
    TMatrix(const TVector<TVector<T> >& mt);  // преобразование типа
    bool operator==(const TMatrix& mt) const; // сравнение
    bool operator!=(const TMatrix& mt) const; // сравнение
    TMatrix& operator= (const TMatrix& mt);   // присваивание
    TMatrix operator+ (const TMatrix& mt);    // сложение
    TMatrix operator- (const TMatrix& mt);    // вычитание

    // ввод / вывод
    friend std::istream& operator>>(std::istream& in, TMatrix& mt)
    {
        for (int i = 0; i < mt.size; i++)
            in >> mt.pVector[i];
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const TMatrix& mt)
    {
        for (int i = 0; i < mt.size; i++)
            out << mt.pVector[i] << std::endl;
        return out;
    }
};

template <class T>
TMatrix<T>::TMatrix(int s) : TVector<TVector<T>>(s)
{
    for (int i = 0; i < s; i++)
        pVector[i] = TVector<T>(s, i);
} /*-------------------------------------------------------------------------*/

template <class T> // конструктор копирования
TMatrix<T>::TMatrix(const TMatrix<T>& mt) :
    TVector<TVector<T> >(mt) {}

template <class T> // конструктор преобразования типа
TMatrix<T>::TMatrix(const TVector<TVector<T> >& mt) :
    TVector<TVector<T> >(mt) {}

template <class T> // сравнение
bool TMatrix<T>::operator==(const TMatrix<T>& mt) const
{
    if (size != mt.size || startIndex != mt.startIndex) return false;
    for (int i = 0; i < size; i++)
        if (pVector[i] != mt.pVector[i]) return false;
    return true;
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TMatrix<T>::operator!=(const TMatrix<T>& mt) const
{
    if (size != mt.size || startIndex != mt.startIndex) return true;
    for (int i = 0; i < size; i++)
        if (pVector[i] == mt.pVector) return false;
    return true;
} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& mt)
{
    if (this == &mt) return *this;
    startIndex = mt.startIndex;
    if (size != 0 && size != mt.size) {
        size = mt.size;
        delete[] pVector;
        pVector = new TVector<T>[size];
    }
    for (int i = 0; i < size; i++)
        pVector[i] = mt.pVector[i];
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& mt)
{
    return TVector::operator+(mt);
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& mt)
{
    return TVector::operator-(mt);
} /*-------------------------------------------------------------------------*/
