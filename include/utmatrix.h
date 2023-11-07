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
    T* pVector;
    size_t size;       // размер вектора
    size_t startIndex; // индекс первого элемента вектора
public:
    static const size_t max_size = std::numeric_limits<unsigned int>::max();

    TVector() :size(0), startIndex(0), pVector(nullptr) {}
    TVector(int size, int startIndex = 0);       //конструктор инициализации
    TVector(size_t size, size_t startIndex = 0); //конструктор инициализации

    template <class TSize, class TStartIndex>
    TVector(TSize size, TStartIndex startIndex) = delete;

    TVector(const TVector& v);                // конструктор копирования
    ~TVector();
    size_t getSize() { return this->size; } // размер вектора
    size_t getStartIndex() { return this->startIndex; } // индекс первого элемента
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
        for (int i = 0; i < v.size - v.startIndex; i++)
        {
            out << v.pVector[i] << " ";
        }
        return out;
    }
};

template <class T>//конструктор инициализации
TVector<T>::TVector(int _size, int startInd) : size(_size), startIndex(startInd)
{
    if (_size < 0 || _size >= max_size || startInd < 0 || startInd >= size) { throw "wrong size or startindex"; }
    //else if (startIndex < 0 || startIndex>=size) { throw "wrong startindex"; }
    else {
        size = _size;
        startIndex = startInd;
        pVector = new T[size - startIndex];
        for (int i = 0; i < size - startIndex; i++)
        {
            pVector[i] = T();
        }
    }
} /*-------------------------------------------------------------------------*/

template <class T>//конструктор инициализации
TVector<T>::TVector(size_t _size, size_t startInd) : size(_size), startIndex(startInd)
{
    if (_size < 0 || _size >= max_size || startInd < 0 || startInd >= size) { throw "wrong size or startindex"; }
    //else if (startIndex < 0 || startIndex>=size) { throw "wrong startindex"; }
    else {
        size = _size;
        startIndex = startInd;
        pVector = new T[size - startIndex];
        for (size_t i = 0; i < size - startIndex; i++)
        {
            pVector[i] = (T)0;
        }
    }
} /*-------------------------------------------------------------------------*/

template <class T> //конструктор копирования
TVector<T>::TVector(const TVector<T>& v) : size(0), startIndex(0), pVector(nullptr)
{
    size = v.size;
    startIndex = v.startIndex;
    if (size != 0) {
        pVector = new T[size - startIndex];
        for (int i = 0; i < size - startIndex; i++) {
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
T& TVector<T>::operator[](int pos)
{
    if ((pos < 0) || (pos - startIndex >= size)) { throw "wrong pos"; }
    else
        return pVector[pos - startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // доступ
T& TVector<T>::operator[](size_t pos)
{
    if ((pos - startIndex < 0) || (pos - startIndex >= size)) { throw "wrong pos"; }
    else
        return pVector[pos - startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator==(const TVector& v) const
{
    if (size != v.size || startIndex != v.startIndex)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size - startIndex; i++)
            if (pVector[i] != v.pVector[i])
            {
                return false;
            }
    }
    return true;
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator!=(const TVector& v) const
{
    if (this->size != v.size || startIndex != v.startIndex)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < size - startIndex; i++)
            if (pVector[i] != v.pVector[i])
            {
                return true;
            }
    }
    return false;
} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TVector<T>& TVector<T>::operator=(const TVector& v)
{
    if (size != v.size)
    {
        delete[] pVector;
        size = v.size;
        startIndex = v.startIndex;
        pVector = new T[size - startIndex];
    }

    for (int i = 0; i < size - startIndex; i++)
    {
        pVector[i] = v.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // прибавить скаляр
TVector<T> TVector<T>::operator+(const T& val)
{
    for (size_t i = 0; i < size - startIndex; i++)
    {
        pVector[i] += val;
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // вычесть скаляр
TVector<T> TVector<T>::operator-(const T& val)
{
    for (size_t i = 0; i < size - startIndex; i++)
    {
        pVector[i] -= val;
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // умножить на скаляр
TVector<T> TVector<T>::operator*(const T& val)
{
    for (int i = 0; i < size - startIndex; i++)
    {
        pVector[i] *= val;
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TVector<T> TVector<T>::operator+(const TVector<T>& v)
{
    if (size != v.size || startIndex != v.startIndex) { throw "not equal size"; }
    else {
        TVector<T> newvec(size, startIndex);
        for (int i = 0; i < size - startIndex; i++)
        {
            newvec.pVector[i] = pVector[i] + v.pVector[i];
        }
        return newvec;
    }
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TVector<T> TVector<T>::operator-(const TVector<T>& v)
{
    if (size != v.size || startIndex != v.startIndex) { throw "not equal size"; }
    else {
        TVector<T>newvec(size, startIndex);
        for (int i = 0; i < size - startIndex; i++)
        {
            newvec.pVector[i] = pVector[i] - v.pVector[i];
        }
        return newvec;
    }
} /*-------------------------------------------------------------------------*/

template <class T> // скалярное произведение
T TVector<T>::operator*(const TVector<T>& v)
{
    if (size != v.size || startIndex != v.startIndex) { throw "not equal size"; }
    else {
        T res = 0;
        int tmp;
        for (size_t i = 0; i < size - startIndex; i++)
        {
            tmp = pVector[i] * v.pVector[i];
            res += tmp;
        }
        return res;
    }
} /*-------------------------------------------------------------------------*/

template <class T>
T& TVector<T>::getElement(int index)
{
    if (index < 0 || index + startIndex >= size) { throw "wrong index"; }
    else
    {
        return pVector[index];
    }
}

template <class T>
void TVector<T>::setElement(int index, T element)
{
    if (index < 0 || index + startIndex >= size) { throw "wrong index"; }
    else
    {
        pVector[index] = element;
    }
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
    if (s < 0 || static_cast<size_t>(static_cast<size_t>(s) * static_cast<size_t>(s)) >= std::numeric_limits<unsigned int>::max()) { throw "wrong size"; }
    else {
        for (int i = 0; i < s; i++) {
            TVector<TVector<T>>::pVector[i] = TVector<T>(s, i);
        }
    }
} /*-------------------------------------------------------------------------*/

template <class T>
TMatrix<T>::TMatrix(size_t s) : TVector<TVector<T>>(s)
{
    if (s < 0 || static_cast<size_t>(static_cast<size_t>(s) * static_cast<size_t>(s)) >= std::numeric_limits<unsigned int>::max()) { throw "wrong size"; }
    else {
        for (size_t i = 0; i < s; i++) {
            TVector<TVector<T>>::pVector[i] = TVector<T>(s, i);
        }
    }
}

template <class T> // конструктор копирования
TMatrix<T>::TMatrix(const TMatrix<T>& mt) :
    TVector<TVector<T>>(mt) {}

template <class T> // конструктор преобразования типа
TMatrix<T>::TMatrix(const TVector<TVector<T> >& mt) :
    TVector<TVector<T> >(mt) {}

template <class T> // сравнение
bool TMatrix<T>::operator==(const TMatrix<T>& mt) const
{
    if (this->size != mt.size || this->startIndex != mt.startIndex) { return false; }
    else {
        for (int i = 0; i < mt.size; i++) {
            if (mt.pVector[i] != this->pVector[i]) { return false; }
        }
        return true;
    }
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TMatrix<T>::operator!=(const TMatrix<T>& mt) const
{
    if (this->size != mt.size || this->startIndex != mt.startIndex) { return true; }
    else {
        for (int i = 0; i < mt.size; i++) {
            if (mt.pVector[i] != this->pVector[i]) { return true; }
        }
        return false;
    }
} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& mt)
{
    if (this != &mt)
    {
        if (this->size != mt.size)
        {
            this->size = mt.size;
            delete[] this->pVector;
            this->pVector = new TVector<T>[this->size];
        }
        this->startIndex = mt.startIndex;
        for (int i = 0; i < this->size; i++)
        {
            this->pVector[i] = mt.pVector[i];
        }
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& mt)
{
    if (mt.size != this->size) { throw "wrong size"; }
    else {
        for (int i = 0; i < this->size; i++)
        {
            this->pVector[i] = this->pVector[i] + mt.pVector[i];
        }
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& mt)
{
    if (mt.size != this->size) { throw "wrong size"; }
    else {
        for (int i = 0; i < this->size; i++)
        {
            this->pVector[i] = this->pVector[i] - mt.pVector[i];
        }
    }
    return *this;
} /*-------------------------------------------------------------------------*/