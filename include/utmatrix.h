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

    TVector();
    TVector(int size, int startIndex = 0);       //конструктор инициализации
    TVector(size_t size, size_t startIndex = 0); //конструктор инициализации

    template <class TSize, class TStartIndex>
    TVector(TSize size, TStartIndex startIndex) = delete;

    TVector(const TVector &v);                // конструктор копирования
    ~TVector();
    size_t getSize()      { return size;       } // размер вектора
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
        return in;
    }
    friend std::ostream& operator<<(std::ostream &out, const TVector &v)
    {
        return out;
    }
};

template <class T>
TVector<T>::TVector() {
    size = 0;
    startIndex = 0;
    pVector = nullptr;
}
template <class T>//конструктор инициализации
TVector<T>::TVector(int _size, int _startIndex)
{
    if ((_size < 0) || (_size > max_size) || (_startIndex < 0) || (_startIndex > max_size))
        throw "error";
    else
        size = _size;
        startIndex = _startIndex;
    pVector = new T[_size];
}

template <class T>//конструктор инициализации
TVector<T>::TVector(size_t _size, size_t _startIndex)
{
    if ((_size < 0) || (_size > max_size) || (_startIndex < 0) || (_startIndex > max_size))
        throw "error";
    else
        size = _size;
        startIndex = _startIndex;
    pVector = new T[_size];
} 

template <class T> //конструктор копирования
TVector<T>::TVector(const TVector<T> &v) 
{
    size = v.size;
    startIndex = v.startIndex;
    pVector = new T[size];
    for (int i = 0; i < size; i++)
        pVector[i] = v.pVector[i];
} 

template <class T> //деструктор
TVector<T>::~TVector()
{
    delete[]pVector;
    size = 0;
    startIndex = 0;
} 

template <class T> // доступ
T& TVector<T>::operator[](int pos)
{
    if ((pos < startIndex) || (pos > max_size)) throw "error"; 
    else return pVector[pos - startIndex];
} 

template <class T> // доступ
T& TVector<T>::operator[](size_t pos)
{
    if ((pos < startIndex) || (pos > max_size)) throw "error";
    else return pVector[pos - startIndex];
} 

template <class T> // сравнение
bool TVector<T>::operator==(const TVector& v) const
{
    if (size != v.size || startIndex!= v.startIndex)
        return false;
    for (int i = 0; i < size - startIndex; i++) {
        if (pVector[i] != v.pVector[i])
            return false;
    }
    return true;
}

template <class T> // сравнение
bool TVector<T>::operator!=(const TVector &v) const
{
    return !(*this == v);
}

template <class T> // присваивание
TVector<T>& TVector<T>::operator=(const TVector &v)
{
    if (this == &v)
        return *this;
    size = v.size;
    startIndex = v.startIndex;
    delete[] pVector;
    pVector = new T[size - startIndex];
    for (int i = 0; i < size - startIndex; i++)
        pVector[i] = v.pVector[i];
    return *this;
} 

template <class T> // прибавить скаляр
TVector<T> TVector<T>::operator+(const T &val)
{
    TVector <T> tmp(*this);
    for (int i = 0; i < size; i++)
        tmp.pVector[i] += val;
    return tmp;
}

template <class T> // вычесть скаляр
TVector<T> TVector<T>::operator-(const T &val)
{
    TVector <T> tmp(*this);
    for (int i = 0; i < size; i++)
        tmp.pVector[i] -= val;
    return tmp;
} 

template <class T> // умножить на скаляр
TVector<T> TVector<T>::operator*(const T &val)
{
    TVector <T> tmp(*this);
    for (int i = 0; i < size; i++)
        tmp.pVector[i] *= val;
    return tmp;
} 

template <class T> // сложение
TVector<T> TVector<T>::operator+(const TVector<T>& v) 
{
    if (this->size != v.size || this->startIndex != v.startIndex) throw "error";
    TVector<T> tmp(*this);
    for (int i = 0; i < this->size; i++)
        tmp.pVector[i] += v.pVector[i];
    return tmp;
}

template <class T> // вычитание
TVector<T> TVector<T>::operator-(const TVector<T> &v)
{
    if (this->size != v.size || this->startIndex != v.startIndex) throw "error";
    TVector<T> tmp(*this);
    for (int i = 0; i < size; i++)
        tmp.pVector[i] -= (v.pVector[i]);
    return tmp;
} 

template <class T> // скалярное произведение
T TVector<T>::operator*(const TVector<T> &v)
{
    if (this->size != v.size || this->startIndex != v.startIndex) throw "error";
    T tmp = 0;
    for (int i = 0; i < size; i++)
        tmp += pVector[i] * v.pVector[i];
    return tmp;
} 

template <class T>
T& TVector<T>::getElement(int index)
{
    if ((index < 0) || (index >= size)) throw "error";
    return pVector[index];
}

template <class T>
void TVector<T>::setElement(int index, T element)
{
    if ((index < 0) || (index >= size)) throw "error";
    pVector [index] = element;
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
TMatrix<T>::TMatrix(int s): TVector<TVector<T>> (s)
{
    if (s > (TVector<T>::max_size)) throw "error";
    for (int i = 0; i < s; i++) {
        TVector<T> v(s, i);
        TVector<TVector<T>>::pVector[i] = v;
    }
} 

template <class T> // конструктор копирования
TMatrix<T>::TMatrix(const TMatrix<T> &mt): TVector<TVector<T> >(mt) {
    TVector<TVector<T>>::size = mt.size;
    TVector<TVector<T>>::startIndex = mt.startIndex;
    pVector = new TVector<T>[TVector<TVector<T>>::size];
    for (int i = 0; i < TVector<TVector<T>>::size; i++)
        TVector<TVector<T>>::pVector[i] = mt.pVector[i];
}

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
}

template <class T> // сравнение
bool TMatrix<T>::operator!=(const TMatrix<T> &mt) const
{
    return !(*this == mt);
}

template <class T> // присваивание
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &mt)
{
    if (this == &mt) {
        return *this;
    this->startIndex = mt.startIndex;
    this->size = mt.size;
    delete[] this->pVector;
    this->pVector = new TVector<T>[this->size];
    for (int i = 0; i < this->size; i++)
        TVector<TVector<T>>::pVector[i] = mt.pVector[i];
    }
    return *this;
} 

template <class T> // сложение
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &mt)
{
    if (this->size != mt.size) throw "error";
    TMatrix <T>tmp(*this);
    for (int i = 0; i < tmp.size; i++)
        tmp.TVector<TVector<T>>::pVector[i] = tmp.TVector<TVector<T>>::pVector[i] + mt.pVector[i];
    return tmp;
} 

template <class T> // вычитание
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &mt)
{
    if (this->size != mt.size) throw "error";
    TMatrix <T>tmp(*this);
    for (int i = 0; i < tmp.size; i++)
        tmp.TVector<TVector<T>>::pVector[i] = tmp.TVector<TVector<T>>::pVector[i] - mt.pVector[i];
    return tmp;
} 
