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
    size_t Memsize;
public:
    static const size_t max_size = std::numeric_limits<unsigned int>::max();

    TVector() :size(0), startIndex(0), pVector(nullptr) {};
    TVector(size_t n);
    TVector(int size, int startIndex = 0);   //конструктор инициализации
    TVector(size_t size, size_t startIndex = 0); //конструктор инициализации

    template <class TSize, class TStartIndex>
    TVector(TSize size, TStartIndex startIndex) = delete;

    TVector(const TVector &v);                // конструктор копирования
    ~TVector();
    size_t getSize()      { return size;       } // размер вектора
    size_t getStartIndex(){ return startIndex; } // индекс первого элемента
    size_t getmaxSize() { return max_size; }
    T& getElement(int i) const;
    T& getElement(size_t i) const;
    void setElement(int index, T element);
    void setElement(size_t index, T element);

    T& operator[](int pos);                 // доступ
    T& operator[](size_t pos);           // доступ
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
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const TVector& v)
    {
        return out;
    }
};


template <class T>//конструктор инициализации
TVector<T>::TVector(int _size, int startIndex)
{
    if (_size >= max_size || startIndex < 0 || startIndex >= _size)
        throw 'FALL';
    size =_size;
    this->startIndex = startIndex;
    Memsize = size - startIndex;
    pVector = new T[Memsize];
    for (int i = 0; i < Memsize; i++)
        pVector[i] = T();
}/*-------------------------------------------------------------------------*/

template <class T>//конструктор инициализации
TVector<T>::TVector(size_t size, size_t startIndex)
{
    if (size >= max_size || startIndex < 0 || startIndex >= size)
        throw 'FALL';
    this->size = size;
    this->startIndex = startIndex;
    Memsize = size - startIndex;
    pVector = new T[Memsize];
    for (int i = 0; i < Memsize; i++)
        pVector[i] = T();
} /*-------------------------------------------------------------------------*/

template <class T> //конструктор копирования
TVector<T>::TVector(const TVector<T> &v)
{
    size = v.size;
    startIndex = v.startIndex;
    Memsize = size-startIndex;
    pVector = new T[Memsize];
    for (int i = 0; i < Memsize; i++) {
        pVector[i] = v.pVector[i];
    }
} /*-------------------------------------------------------------------------*/

template <class T> //деструктор
TVector<T>::~TVector()
{
    size = 0;
    delete[] pVector;
    startIndex = 0;
    Memsize = 0;
} /*-------------------------------------------------------------------------*/

template <class T> // доступ
T& TVector<T>::operator[](int pos)
{
    if (pos < 0 || pos >= size)
        throw 'FALL';
    return pVector[pos-startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // доступ
T& TVector<T>::operator[](size_t pos)
{
    if (pos < 0 || pos >= size)
        throw 'FALL';
    return pVector[pos - startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator==(const TVector &v) const
{
    if (size != v.size || startIndex!=v.startIndex) {
        return false;
    }
    else {
        for (int i = 0; i < Memsize; i++) {
            if (pVector[i] != v.pVector[i]) {
                return false;
            }
        }
        return true;
    }
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator!=(const TVector &v) const
{
    if (size != v.size || startIndex != v.startIndex) {
        return true;
    }
    else {
        for (int i = 0; i < Memsize; i++) {
            if (pVector[i] != v.pVector[i]) {
                return true;
            }
        }
        return false;
    }
} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TVector<T>& TVector<T>::operator=(const TVector &v)
{
    size = v.size;
    startIndex = v.startIndex;
    Memsize = size-startIndex;
    delete[] pVector;
    pVector = new T[Memsize];
    for (int i = 0; i < Memsize; i++) {
        pVector[i] = v.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // прибавить скаляр
TVector<T> TVector<T>::operator+(const T &val)
{
    TVector A(size, startIndex);
    for (int i = 0; i < A.Memsize; i++) {
        A.pVector[i] = pVector[i] + val;
    }
    return A;
} /*-------------------------------------------------------------------------*/

template <class T> // вычесть скаляр
TVector<T> TVector<T>::operator-(const T &val)
{
    TVector A(size, startIndex);
    for (int i = 0; i < A.Memsize; i++) {
        A.pVector[i] = pVector[i] - val;
    }
    return A;
} /*-------------------------------------------------------------------------*/

template <class T> // умножить на скаляр
TVector<T> TVector<T>::operator*(const T &val)
{
    TVector A(size, startIndex);
    for (int i = 0; i < A.Memsize; i++) {
        A.pVector[i] =pVector[i]* val;
    }
    return A;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TVector<T> TVector<T>::operator+(const TVector<T> &v)
{
    if (size != v.size || startIndex != v.startIndex) {
        throw 'FALL';
    }
    TVector A(size, startIndex);
    for (int i = 0; i < A.Memsize; i++) {
        A.pVector[i] =pVector[i]+v.pVector[i];
    }
    return A;
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TVector<T> TVector<T>::operator-(const TVector<T> &v)
{
    if (size != v.size || startIndex != v.startIndex) {
        throw 'FALL';
    }
    TVector A(size, startIndex);
    for (int i = 0; i < A.Memsize; i++) {
        A.pVector[i] = pVector[i] - v.pVector[i];
    }
    return A;
} /*-------------------------------------------------------------------------*/

template <class T> // скалярное произведение
T TVector<T>::operator*(const TVector<T> &v)
{
    if (size != v.size || startIndex != v.startIndex) {
        throw 'FALL';
    }
    T sum=0;
    for (int i = 0; i < Memsize; i++) {
        sum=sum+(pVector[i] *v.pVector[i]);
    }
    return sum;
} /*-------------------------------------------------------------------------*/

template <class T>
T& TVector<T>::getElement(int index)const
{
    if (index < 0 || index + startIndex >= size) {
        throw 'FALL';
    }
    return pVector[index];
}

template <class T>
void TVector<T>::setElement(int index, T element)
{
    if (index < 0 || index + startIndex >= size) {
        throw 'FALL';
    }
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
TMatrix<T>::TMatrix(int s) : TVector<TVector<T>>(s)
{
    if (static_cast<unsigned long long>(static_cast<unsigned long long>(s) * static_cast<unsigned long long>(s)) > static_cast<unsigned long long>(TVector<T>::max_size)) {
        throw 'FALL';
    }
    for (int i = 0; i < s; i++) {
        TVector<T> a(s, i);
        TVector<TVector<T>>::pVector[i] = a;
    }
} /*-------------------------------------------------------------------------*/

template <class T> // конструктор копирования
TMatrix<T>::TMatrix(const TMatrix<T> &mt):
TVector<TVector<T> >(mt) {}

template <class T> // конструктор преобразования типа
TMatrix<T>::TMatrix(const TVector<TVector<T> > &mt):
  TVector<TVector<T> >(mt) {}

template <class T> // сравнение
bool TMatrix<T>::operator==(const TMatrix<T> &mt) const
{
    if (this->size != mt.size || this->startIndex != mt.startIndex)
        return false;
    for (int i = 0; i < this->size; i++) {
        if (this->pVector[i] != mt.pVector[i])
            return false;
    }
    return true;
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TMatrix<T>::operator!=(const TMatrix<T> &mt) const
{
    if (this->size != mt.size || this->startIndex != mt.startIndex)
        return true;
    for (int i = 0; i < this->size; i++) {
        if (this->pVector[i] != mt.pVector[i])
            return true;
    }
    return false;
} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &mt)
{
    TVector<TVector<T>>::size = mt.size;
    this->startIndex = mt.startIndex;
    delete[] TVector<TVector<T>>::pVector;
    pVector = new TVector<T>[TVector<TVector<T>>::size];
    for (int i = 0; i < size; i++) {
        this->setElement(i, mt.getElement(i));
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &mt)
{
    if (this->size != mt.size) {
        throw 'FALL';
    }
    for (int i = 0; i < this->size; i++)
        this->pVector[i]=this->pVector[i]+mt.pVector[i];
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &mt)
{
    if (this->size != mt.size) {
        throw 'FALL';
    }
    for (int i = 0; i < this->size; i++)
        this->pVector[i] = this->pVector[i] - mt.pVector[i];
    return *this;
} /*-------------------------------------------------------------------------*/
