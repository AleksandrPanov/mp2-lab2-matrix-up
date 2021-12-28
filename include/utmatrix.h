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

    TVector(int size, int startIndex = 0);       //конструктор инициализации
    TVector(size_t size = 0, size_t startIndex = 0); //конструктор инициализации

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
        for (int i = 0; i < v.size; i++)
            in >> v.pVector[i];
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const TVector& v)
    {
        for (int i = 0; i < v.startIndex; i++)
        {
            out << '0' << ' ';
        }
        for (int i = 0; i < v.size; i++)
        {
            out << v.pVector[i] << ' ';
        }
        out << std::endl;
        return out;
    }
};

template <class T>//конструктор инициализации
TVector<T>::TVector(int _size, int startIndex)
{
    if ((_size < 0) || (startIndex < 0)) throw "incorrect";

    if (_size > max_size) throw "incorrect";
    else size = _size;

    if (startIndex > max_size - size) throw "startIndex out of range";
    else this->startIndex = startIndex;

    if (_size != 0) pVector = new T[_size];
}

template <class T>//конструктор инициализации
TVector<T>::TVector(size_t _size, size_t startIndex)
{
    if (_size > max_size) throw "incorrect";
    else size = _size;

    if (startIndex > max_size - size) throw "incorrect";
    else this->startIndex = startIndex;

    if (_size != 0) pVector = new T[_size];
    else pVector = nullptr;
}

template <class T> //конструктор копирования
TVector<T>::TVector(const TVector<T>& v)
{
    size = v.size;
    startIndex = v.startIndex;
    if (size != 0) {
        pVector = new T[size];
    }
    for (size_t i = 0; i < size; i++)
    {
        pVector[i] = v.pVector[i];
    }
}

template <class T> //деструктор
TVector<T>::~TVector()
{
    delete[] pVector;
} /*-------------------------------------------------------------------------*/

template <class T> // доступ
T& TVector<T>::operator[](int pos)
{
    if ((pos - startIndex < 0) || (pos - startIndex >= size))
        throw pos;
    return pVector[pos - startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // доступ
T& TVector<T>::operator[](size_t pos)
{
    if ((pos - startIndex < 0) || (pos - startIndex >= size))
        throw pos;
    return pVector[pos - startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator==(const TVector& v) const
{
    if (this != &v)
    {
        if (size != v.size)
        {
            return -1;
        }
        if (startIndex != v.startIndex)
        {
            return -1;
        }
        for (int i = 0; i < size; i++)
        {
            if (pVector[i] != v.pVector[i])
            {
                return -1;
            }
        }
    }
    return 1;
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator!=(const TVector& v) const
{
    return !(*this == v);
} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TVector<T>& TVector<T>::operator=(const TVector& v)
{
    if (this == &v) 
        return *this;
    if (pVector != nullptr) 
        delete[] pVector;
        size = v.size;
        startIndex = v.startIndex;
    if (size != 0) 
        pVector = new T[size];
    for (size_t i = 0; i < size; i++)
    {
        pVector[i] = v.pVector[i];
    }
    return *this;
}

template <class T> // прибавить скаляр
TVector<T> TVector<T>::operator+(const T& val)
{
    TVector<T> v(*this);
    for (int i = 0; i < v.size; i++)
    {
        v.pVector[i] += val;
    }
    return v;
} /*-------------------------------------------------------------------------*/

template <class T> // вычесть скаляр
TVector<T> TVector<T>::operator-(const T& val)
{
    TVector<T> v(*this);
    for (int i = 0; i < v.size; i++)
    {
        v.pVector[i] -= val;
    }
    return v;
} /*-------------------------------------------------------------------------*/

template <class T> // умножить на скаляр
TVector<T> TVector<T>::operator*(const T& val)
{
    TVector<T> v(*this);
    for (int i = 0; i < v.size; i++)
    {
        v.pVector[i] *= val;
    }
    return v;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TVector<T> TVector<T>::operator+(const TVector<T>& v)
{
    if (size != v.size || startIndex != v.startIndex)
    {
        throw v.size;
    }
    TVector<T> res(size, startIndex);
    for (int i = 0; i < size; i++)
    {
        res.pVector[i] = pVector[i] + v.pVector[i];
    }
    return res;
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TVector<T> TVector<T>::operator-(const TVector<T>& v)
{
    if (size != v.size || startIndex != v.startIndex)
    {
        throw v.size;
    }
    TVector<T> res(size, startIndex);
    for (int i = 0; i < size; i++)
    {
        res.pVector[i] = pVector[i] - v.pVector[i];
    }
    return res;
} /*-------------------------------------------------------------------------*/

template <class T> // скалярное произведение
T TVector<T>::operator*(const TVector<T>& v)
{
    if (size != v.size)
    {
        throw v.size;
    }
    T res = pVector[0] * v.pVector[0];
    for (int i = 1; i < size; i++)
    {
        res += pVector[i] * v.pVector[i];
    }
    return res;
} /*-------------------------------------------------------------------------*/

template <class T>
T& TVector<T>::getElement(int index)
{
    return pVector[index];
}

template <class T>
T& TVector<T>::getElement(size_t index)
{
    return pVector[index];
}

template <class T>
void TVector<T>::setElement(int index, T element)
{
    pVector[index] = element;
}

template <class T>
void TVector<T>::setElement(size_t index, T element)
{
    pVector[index] = element;
}

template <class T>
void TVector<T>::setElement(size_t index, T element)
{
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
TMatrix<T>::TMatrix(int s) : TVector<TVector<T> >(s)
{
    for (int i = 0; i < s; ++i)
        TVector<TVector<T>>::pVector[i] = TVector<T>(s, i);
}

template <class T>
TMatrix<T>::TMatrix(size_t s) : TVector<TVector<T> >(s)
{
    for (size_t i = 0; i < s; ++i)
        TVector<TVector<T>>::pVector[i] = TVector<T>(s, i);
}

template <class T> // конструктор копирования
TMatrix<T>::TMatrix(const TMatrix<T>& mt) :
    TVector<TVector<T> >(mt) {}

template <class T> // конструктор преобразования типа
TMatrix<T>::TMatrix(const TVector<TVector<T> >& mt) :
    TVector<TVector<T> >(mt) {};

/*template <class T> // сравнение
bool TMatrix<T>::operator==(const TMatrix<T> &mt) const
{
    if (this != &mt)
    {
        if (size != mt.size)
            return -1;
        for (int i = 0; i < size; i++)
        {
            if (pVector[i] != mt.pVector[i])
                return -1;
        }
    }
    return 1;
} /*-------------------------------------------------------------------------

template <class T> // сравнение
bool TMatrix<T>::operator!=(const TMatrix<T> &mt) const
{
    return !(*this == mt);
} /*-------------------------------------------------------------------------

template <class T> // присваивание
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &mt)
{
    if (this != &mt)
    {
        if (size != mt.size)
        {
            delete[]pVector;
            size = mt.size;
            pVector = new TVector <T>[size];
        }
        for (int i = 0; i < size; i++)
        {
            pVector[i] = mt.pVector[i];
        }
        startIndex = mt.startIndex;
    }
    return(*this);
} /*-------------------------------------------------------------------------

template <class T> // сложение
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &mt)
{
    return TVector<TVector<T>>::operator+(mt);
} /*-------------------------------------------------------------------------

template <class T> // вычитание
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &mt)
{
    return TVector<TVector<T>>::operator-(mt);
} /*-------------------------------------------------------------------------
*/