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

    TVector():size(0), startIndex(0), pVector(nullptr) {}
    TVector(int size, int startIndex = 0);       //конструктор инициализации
    TVector(size_t size, size_t startIndex = 0); //конструктор инициализации

    template <class TSize, class TStartIndex>
    TVector(TSize size, TStartIndex startIndex) = delete;

    TVector(const TVector &v);                // конструктор копирования
    ~TVector();
    size_t getSize() const     { return this->size;       } // размер вектора
    size_t getStartIndex() const{ return this->startIndex; } // индекс первого элемента
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
        
        return in;
    }
    friend std::ostream& operator<<(std::ostream &out, const TVector &v)
    {
        for (int i = 0; i < v.getSize()-v.getStartIndex() ; i++)
            out << v.getElement(i)<<" ";
        return out;
    }
};

template <class T>//конструктор инициализации
TVector<T>::TVector(int _size, int startIndex): size(_size), startIndex(startIndex)
{
    if (size > max_size || startIndex < 0 || startIndex >= size)
        throw 1;
    pVector = new T[size-startIndex];
    for (int i = 0;i<size-startIndex;i++)
        pVector[i]= T();
} /*-------------------------------------------------------------------------*/

template <class T>//конструктор инициализации
TVector<T>::TVector(size_t _size, size_t startIndex) : size(_size), startIndex(startIndex)
{
    if (size > max_size || startIndex < 0 || startIndex >= size)
        throw 1;
    pVector = new T[size-startIndex];
    for (int i = 0; i < size - startIndex; i++)
        pVector[i] = (T)0;
} /*-------------------------------------------------------------------------*/

template <class T> //конструктор копирования
TVector<T>::TVector(const TVector<T> &v) : size(0), startIndex(0), pVector(nullptr)
{
    *this = v;
} /*-------------------------------------------------------------------------*/

template <class T> //деструктор
TVector<T>::~TVector()
{
    delete[] pVector;
} /*-------------------------------------------------------------------------*/

template <class T> // доступ
T& TVector<T>::operator[](int pos)
{
    if (pos-startIndex < 0 || pos >= size)
        throw 1;
    return pVector[pos-startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // доступ
T& TVector<T>::operator[](size_t pos)
{
    if (pos - startIndex < 0 || pos >= size)
        throw 1;
    return *pVector[pos - startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator==(const TVector& v) const
{
    if (size != v.size || startIndex != v.startIndex) return false;
    for (int i = 0; i < size-startIndex; i++)
        if (pVector[i] != v.pVector[i]) return false;
    return true;
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator!=(const TVector &v) const
{
    return !(*this==v);
} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TVector<T>& TVector<T>::operator=(const TVector &v)
{
    if (this == &v) return *this;
    size = v.size;
    startIndex = v.startIndex;
    delete[] pVector;
    pVector = new T[size-startIndex];
    for (int i = 0; i < size-startIndex; i++)
        pVector[i] = v.pVector[i];
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // прибавить скаляр
TVector<T> TVector<T>::operator+(const T &val)
{
    TVector<T> a(size, startIndex);
    for (int i = 0; i < size-startIndex; i++)
        a.pVector[i] = pVector[i] + val;
    return a;
} /*-------------------------------------------------------------------------*/

template <class T> // вычесть скаляр
TVector<T> TVector<T>::operator-(const T &val)
{
    TVector<T> a(size, startIndex);
    for (int i = 0; i < size - startIndex; i++)
        a.pVector[i] = pVector[i] - val;
    return a;
} /*-------------------------------------------------------------------------*/

template <class T> // умножить на скаляр
TVector<T> TVector<T>::operator*(const T &val)
{
    TVector<T> a(size, startIndex);
    for (int i = 0; i < size-startIndex; i++)
        a.pVector[i] = pVector[i] * val;
    return a;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TVector<T> TVector<T>::operator+(const TVector<T> &v)
{
    if (size != v.size || startIndex != v.startIndex) throw 1;
    TVector<T> a(size, startIndex);
    for (int i = 0; i < size-startIndex; i++)
        a.pVector[i] = pVector[i] + v.pVector[i];
    return a;

} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TVector<T> TVector<T>::operator-(const TVector<T> &v)
{
    if (size != v.size || startIndex != v.startIndex) throw 1;
    TVector<T> a(size, startIndex);
    for (int i = 0; i < size-startIndex; i++)
        a.pVector[i] = pVector[i] - v.pVector[i];
    return a;
} /*-------------------------------------------------------------------------*/

template <class T> // скалярное произведение
T TVector<T>::operator*(const TVector<T>& v)
{
    if (size != v.size || startIndex != v.startIndex) throw 1;
    T summ = 0;
    for (int i = 0; i < size - startIndex; i++)
        summ += pVector[i] * v.pVector[i];
    return summ;
} /*-------------------------------------------------------------------------*/

template <class T>
T& TVector<T>::getElement(int index) const
{
    if (index < 0 || index + startIndex >= size) throw 1;
    return pVector[index];
}

template <class T>
void TVector<T>::setElement(int index, T element)
{
    if(index < 0 || index + startIndex >= size) 
        throw 1;
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
TMatrix<T>::TMatrix(int s): TVector<TVector<T>>(s)
{
    if ((s*s) > TVector<T>::max_size)
        throw 1;
    for (int i = 0; i < s; i++) {
        TVector<TVector<T>>::pVector[i] = TVector<T>(s, i);
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
    if (TVector<TVector<T>>::size != mt.size || TVector<TVector<T>>::startIndex != mt.startIndex)
        return false;
    for (int i = 0; i < TVector<TVector<T>>::size; i++) {
        if (TVector<TVector<T>>::pVector[i] != mt.pVector[i])
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
    if (this == &mt) return *this;
    this->size = mt.size;
    this->startIndex = mt.startIndex;
    delete[] this->pVector;
    this->pVector = new TVector<T>[this->size];

    for (int i = 0; i < this->size; i++)
        this->setElement(i, mt.getElement(i));
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &mt)
{
    for (int i = 0; i < this->size; i++)
        this->setElement(i, this->getElement(i) + mt.getElement(i));
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &mt)
{
    for (int i = 0; i < this->size; i++)
        this->setElement(i, this->getElement(i) - mt.getElement(i));
    return *this;
} /*-------------------------------------------------------------------------*/
