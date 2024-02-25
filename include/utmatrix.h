//// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
////
//// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
////   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
////
//// Верхнетреугольная матрица - реализация на основе шаблона вектора
//#pragma once
//
//#include <iostream>
//#include <limits>
//#include <math.h>
//
//
//// Шаблон вектора
//template <class T>
//class TVector
//{
//protected:
//    T *pVector;
//    size_t size;       // размер вектора
//    size_t startIndex; // индекс первого элемента вектора
//public:
//    static const size_t max_size = std::numeric_limits<unsigned int>::max();
//
//    TVector(): size(0),startIndex(0),pVector(nullptr) {}
//    TVector(int size, int startIndex = 0);       //конструктор инициализации
//    TVector(size_t size, size_t startIndex = 0); //конструктор инициализации
//
//    template <class TSize, class TStartIndex>
//    TVector(TSize size, TStartIndex startIndex) = delete;
//
//    TVector(const TVector &v);                // конструктор копирования
//    ~TVector();
//    size_t getSize()    { return size;       }  // размер вектора
//    size_t getStartIndex() { return startIndex; }  // индекс первого элемента
//    T& getElement(int i);
//    T& getElement(size_t i);
//    void setElement(int index, T element);
//    void setElement(size_t index, T element);
//
//
//    TVector cut(TVector &v);
//
//
//    T& operator[](int pos);                  // доступ
//    T& operator[](size_t pos);               // доступ
//    bool operator==(const TVector &v) const; // сравнение
//    bool operator!=(const TVector &v) const; // сравнение
//    TVector& operator=(const TVector &v);    // присваивание
//    
//
//    // скалярные операции
//    TVector operator+(const T &val); // прибавить скаляр
//    TVector operator-(const T &val); // вычесть скаляр
//    TVector operator*(const T &val); // умножить на скаляр
//
//    // векторные операции
//    TVector operator+(const TVector &v); // сложение
//    TVector operator-(const TVector &v); // вычитание
//    T operator*(const TVector &v);       // скалярное произведение
//
//    // ввод-вывод
//    friend std::istream& operator>>(std::istream &in, TVector &v)
//    {
//        return in;
//    }
//    friend std::ostream& operator<<(std::ostream &out, const TVector &v)
//    {
//        return out;
//    }
//};
//
//template <class T>//конструктор инициализации
//TVector<T>::TVector(int _size, int startIndex)
//{
//    if (startIndex < 0 || _size>99999999 || _size<0 || startIndex>_size)
//    {
//        throw 123;
//    }
//    else
//    {
//        this->startIndex = startIndex;
//        size = _size;
//        pVector = new T[_size - startIndex];
//        for (int i = 0; i < size - startIndex; i++)
//            pVector[i] = (T)1;
//    }
//} /*-------------------------------------------------------------------------*/
//
//template <class T>//конструктор инициализации
//TVector<T>::TVector(size_t _size, size_t startIndex)
//{
//    if (startIndex < 0 || _size>TVector::max_size || _size<0 || startIndex>_size)
//    {
//        throw 123;
//    }
//    else
//    {
//        this->startIndex = startIndex;
//        size = _size;
//        pVector = new T[_size - startIndex];
//        for (size_t i = 0ull; i < size - startIndex; i++)
//            pVector[i] = (T)1; // было 0 XDDDDDDDDDDDDDDDDDD
//    }
//} /*-------------------------------------------------------------------------*/
//
//template <class T> //конструктор копирования
//TVector<T>::TVector(const TVector<T> &v)
//{
//    this->size = v.size;
//    this->startIndex = v.startIndex;
//    this->pVector = new T[size - startIndex];
//    for (int i = 0; i < size - startIndex; i++)
//    {
//        this->pVector[i] = v.pVector[i];
//    }
//} /*-------------------------------------------------------------------------*/
//
//template <class T> //деструктор
//TVector<T>::~TVector()
//{
//    size = 0;
//    startIndex = 0;
//    delete[]pVector;
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // доступ
//T& TVector<T>::operator[](int pos)
//{
//    if (pos>=this->size|| pos<0)
//    {
//        throw 123;
//    }
//    else
//    {
//        if (pos < this->startIndex)
//        {
//            T temp = 0;
//            return temp;
//        }
//        else
//            return pVector[pos-startIndex];
//        
//    }
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // доступ
//T& TVector<T>::operator[](size_t pos)
//{
//    if (pos >= this->size || pos < 0)
//    {
//        throw 123;
//    }
//    else
//    {
//        if (pos < this->startIndex)
//        {
//            T temp = 0;
//            return temp;
//        }
//        else
//            return pVector[pos - this->startIndex];
//
//    }
//} /*-------------------------------------------------------------------------*/
//
//
//
//template <class T> // сравнение
//bool TVector<T>::operator==(const TVector &v) const
//{
//    if (size != v.size || startIndex != v.startIndex)
//        return false;
//    else
//    {
//        for (int i = 0; i < size - startIndex; i++)
//            if (pVector[i] != v.pVector[i])
//                return false;
//        return true;
//    }
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // сравнение
//bool TVector<T>::operator!=(const TVector &v) const
//{
//    if (*this == v)
//        return 0;
//    else
//        return 1;
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // присваивание
//TVector<T>& TVector<T>::operator=(const TVector &v)
//{
//    if (this != &v)
//    {
//        size = v.size;
//        startIndex = v.startIndex;
//        delete[] this->pVector;
//        this->pVector = new T[size - startIndex];
//        for (int i = 0; i < size - startIndex; i++)
//            pVector[i] = v.pVector[i];
//    }
//    return *this;
//        
//    
//} /*-------------------------------------------------------------------------*/
//template <class T>
//TVector<T> TVector<T>::cut(TVector<T> &v)
//{
//    int c = 0;
//    while (v[c] == 0 && c<size-1)
//        c++;
//    int s = v.size;
//    TVector<int> ans(s,c);
//    for (int i = c; i < v.size; i++)
//        ans[i] = v[i];
//    return ans;
//}
//
//template <class T> // прибавить скаляр
//TVector<T> TVector<T>::operator+(const T &val)
//{
//    
//    if (val != 0)
//    {
//        
//        TVector<T> ans(this->size);
//
//        for (int i = 0; i < this->startIndex; i++)
//        {
//            ans[i] = val;
//        }
//        for (int i = this->startIndex; i < this->size; i++)
//            ans[i] = this->pVector[i-this->startIndex] + val;
//        T i = 0;
//        ans = ans.cut(ans);
//        return ans;
//    }
//    else
//        return *this;
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // вычесть скаляр
//TVector<T> TVector<T>::operator-(const T &val)
//{
//    int temp = -val;
//    return (*this + temp);
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // умножить на скаляр
//TVector<T> TVector<T>::operator*(const T &val)
//{
//    if (val != 0)
//    {
//        for (int i = 0; i < size - startIndex; i++)
//            this->pVector[i] = this->pVector[i] * val;
//    }
//    else
//        for (int i = 0; i < size - startIndex; i++)
//        {
//            this->pVector[i] = 0;
//            this->startIndex = size;
//        }
//    return *this;
//            
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // сложение
//TVector<T> TVector<T>::operator+(const TVector<T> &v)
//{
//    
//    if (v.size == size)
//    {
//        TVector<T> ans(v.size);
//        TVector<T> tempv(v);
//        for (int i = 0; i < v.size; i++)
//            if ((i < v.startIndex) && (i < this->startIndex))
//            {
//                ans[i] = 0;
//            }
//                
//        if (tempv.startIndex <= startIndex)
//        {
//            for (int i = tempv.startIndex; i < startIndex; i++)
//            {
//                ans[i] = tempv[i];
//            }
//            for (int i = startIndex; i < tempv.size; i++)
//            {
//                ans[i] = tempv[i] + this->operator[](i);
//            }
//                
//        }
//        else
//        {
//            for (int i = startIndex; i < tempv.startIndex; i++)
//                ans[i] = this->pVector[i-startIndex];
//            for (int i = tempv.startIndex; i < tempv.size; i++)
//                ans[i] = tempv[i] + this->pVector[i-startIndex];
//        }
//       
//        ans = ans.cut(ans);
//        return ans;
//    }
//    else
//        throw 555;
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // вычитание
//TVector<T> TVector<T>::operator-(const TVector<T> &v)
//{
//    auto temp = v;
//    temp = temp*(-1);
//    
//    return (*this + temp);
//
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // скалярное произведение
//T TVector<T>::operator*(const TVector<T> &v)
//{
//    T sum = 0;
//    TVector <T> cop = v;
//    if (this->size == v.size)
//    {
//        if (v.startIndex < this->startIndex)
//        {
//            for (int i = startIndex; i < size; i++)
//            {
//                sum += cop[i] * this->operator[](i);
//            }
//        }
//        else
//            for (int i = v.startIndex; i < size; i++)
//                sum += cop[i] * this->operator[](i);
//        T ans = sqrt(sum);
//        return ans;
//    }
//    else
//        throw 7;
//} /*-------------------------------------------------------------------------*/
//
//template <class T>
//T& TVector<T>::getElement(int pos)
//{
//    if (pos >= this->size || pos < 0)
//    {
//        throw 123;
//    }
//    else
//    {
//        if (pos < this->startIndex)
//        {
//            T temp = 0;
//            return temp;
//        }
//        else
//            return pVector[pos - startIndex];
//    }
//}
//
//template <class T>
//T& TVector<T>::getElement(size_t pos)
//{
//    if (pos >= this->size || pos < 0)
//    {
//        throw 123;
//    }
//    else
//    {
//        if (pos < this->startIndex)
//        {
//            T temp = 0;
//            return temp;
//        }
//        else
//            return pVector[pos - startIndex];
//    }
//}
//
//template <class T>
//void TVector<T>::setElement(int index, T element)
//{
//    if (index >= 0)
//    {
//
//
//        if (index >= this->startIndex)
//        {
//            T temp = getElement(index);
//            this->pVector[index - startIndex] = temp;
//        }
//        else
//        {
//            
//        }
//    }
//    else
//        throw 123;
//}
//
//template <class T>
//void TVector<T>::setElement(size_t index, T element)
//{
//    if (index >= 0)
//    {
//
//
//        if (index >= this->startIndex)
//        {
//            T temp = getElement(index);
//            this->pVector[index - startIndex] = temp;
//        }
//        else
//        {
//            
//        }
//    }
//    else
//        throw 123;
//}
//
//// Верхнетреугольная матрица
//// val1 val2 val3 ... valn-1 valn
//// 0    val2 val3 ... valn-1 valn
//// 0    0    val3 ... valn-1 valn
//// ..............................
//// 0    0    0    ... 0      valn 
//template <class T>
//class TMatrix : public TVector<TVector<T> >
//{
//public:
//    TMatrix(int s);
//    TMatrix(size_t s);
//
//    template <class TSize>
//    TMatrix(TSize size) = delete;
//
//    TMatrix(const TMatrix &mt);               // копирование
//    TMatrix(const TVector<TVector<T> > &mt);  // преобразование типа
//    bool operator==(const TMatrix &mt) const; // сравнение
//    bool operator!=(const TMatrix &mt) const; // сравнение
//    TMatrix& operator= (const TMatrix &mt);   // присваивание
//    TMatrix operator+ (const TMatrix &mt);    // сложение
//    TMatrix operator- (const TMatrix &mt);    // вычитание
//
//    // ввод / вывод
//    friend std::istream& operator>>(std::istream &in, TMatrix &mt)
//    {
//      for (int i = 0; i < mt.size; i++)
//        in >> mt.pVector[i];
//      return in;
//    }
//    friend std::ostream & operator<<( std::ostream &out, const TMatrix &mt)
//    {
//      for (int i = 0; i < mt.size; i++)
//        out << mt.pVector[i] << std::endl;
//      return out;
//    }
//};
//
//template <class T>
//TMatrix<T>::TMatrix(int s): TVector<TVector<T>>(s)
//{
//    
//    for (int i = 0; i < s; i++)
//    {
//        this->pVector[i] = TVector<T>(s,i);
//        
//    }
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // конструктор копирования
//TMatrix<T>::TMatrix(const TMatrix<T> &mt):
//  TVector<TVector<T>>(mt)
//{
//   
//    this->size = mt.size;
//    for (int i = 0; i < this->size; i++)
//        TVector<TVector<T>>::pVector[i] = mt.pVector[i];
//}
//
//template <class T> // конструктор преобразования типа
//TMatrix<T>::TMatrix(const TVector<TVector<T> > &mt):
//  TVector<TVector<T> >(mt) 
//{
//    TVector<TVector<T> >::size = mt.size;
//    TVector<TVector<T> >::pVector = new TVector<T>[TVector<TVector<T> >::size];
//    for (size_t i = 0; i < TVector<TVector<T> >::size; i++)
//    {
//        TVector<TVector<T> >::pVector[i] = mt.pVector[i];
//    }
//}
//
//template <class T> // сравнение
//bool TMatrix<T>::operator==(const TMatrix<T> &mt) const
//{
//    for (int i = 0; i < this->size; i++)
//    {
//        if (this->pVector[i] != mt.pVector[i])
//            return false;
//    }
//    return true;
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // сравнение
//bool TMatrix<T>::operator!=(const TMatrix<T> &mt) const
//{
//    if (*this == mt)
//        return false;
//    else
//        return true;
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // присваивание
//TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &mt)
//{
//    /*this->size = mt.size;
//    delete[]this->pVector;
//    auto pVector = new TVector<TVector<T>>(mt.size);
//    
//    for (int i = 0; i < size; i++)
//    {
//        
//        this->pVector[i] = mt.pVector[i];
//    }*/
//    
//    for (int i = 0; i < this->size; i++)
//        std::cout << TVector<TVector<T>>::pVector[i];
//    this->size = mt.size;
//    delete[]TVector<TVector<T>>::pVector;
//    TVector<TVector<T>>::pVector = new TVector<T>[this->size];
//    for (int i = 0; i < this->size; i++)
//    {
//        TVector<TVector<T>>::pVector[i] = TVector<T>(this->size);
//        TVector<TVector<T>>::pVector[i] = mt.pVector[i];
//    }
//
//        
//    return *this;
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // сложение
//TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &mt)
//{
//    if (this->size == mt.size)
//    {
//        for (int i = 0; i < this->size; i++)
//            TVector<TVector<T>>::pVector[i] = TVector<TVector<T>>::pVector[i] + mt.pVector[i];
//        return *this;
//    }
//        
//    else
//        throw 'hh';
//} /*-------------------------------------------------------------------------*/
//
//template <class T> // вычитание
//TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &mt)
//{
//    if (this->size == mt.size)
//    {
//        for (int i = 0; i < this->size; i++)
//            TVector<TVector<T>>::pVector[i] = TVector<TVector<T>>::pVector[i] - mt.pVector[i];
//        return *this;
//    }
//    else
//        throw 'hh';
//} /*-------------------------------------------------------------------------*/

#pragma once

#include <iostream>
#include <limits>
#include <algorithm>

struct OutOfIndException {
    int a;
};

struct OverLimitException {
    int b;
};

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

    TVector() : size(0), startIndex(0), pVector(nullptr) {}
    TVector(int size, int startIndex = 0);      //конструктор инициализации
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
TVector<T>::TVector(int _size, int _startIndex = 0) : size(_size), startIndex(startIndex)
{
    size = _size;
    startIndex = _startIndex;
    if (size <= 0 || startIndex < 0 || size>max_size || startIndex > size) {
        throw OutOfIndException();
    }
    else {
        pVector = new T[size - startIndex];
        for (int i = 0; i < size - startIndex; i++) {
            pVector[i] = T();
        }
    }
} /*-------------------------------------------------------------------------*/

template <class T>//конструктор инициализации
TVector<T>::TVector(size_t _size, size_t startIndex) : size(_size), startIndex(startIndex)
{
    if (_size > max_size) {
        throw OverLimitException();
    }
    else {
        size = _size;
        startIndex = startIndex;
        pVector = new T[_size - startIndex];
        for (size_t i = 0; i < size - startIndex; i++) {
            pVector[i] = (T)1;
        }
    }
} /*-------------------------------------------------------------------------*/

template <class T> //конструктор копирования
TVector<T>::TVector(const TVector<T>& v)
{
    //delete[] pVector;
    startIndex = v.startIndex;
    size = v.size;
    pVector = new T[v.size];
    if (size > 0)
        for (size_t i = 0; i < size - startIndex; i++) {
            pVector[i] = v.pVector[i];

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
    if (pos < 0 || pos >= size) {
        throw OutOfIndException();
    }
    if (pos < startIndex) {
        T temp = 0;
        return temp;
    }
    return pVector[pos - startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // доступ
T& TVector<T>::operator[](size_t pos)
{
    if (pos < 0 || pos >= size) {
        throw OutOfIndException();
    }
    else if (pos < startIndex) {
        T temp = 0;
        return temp;
    }
    return pVector[pos - startIndex];
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator==(const TVector& v) const
{
    if (this == &v) return true;
    if ((v.size != size) || (v.startIndex != startIndex)) return false;
    for (size_t i = 0; i < v.size - v.startIndex; i++) {
        if (pVector[i] != v.pVector[i]) return false;
    }
    return true;
} /*-------------------------------------------------------------------------*/

template <class T> // сравнение
bool TVector<T>::operator!=(const TVector& v) const
{
    if (*this == v) return false;
    return true;
} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TVector<T>& TVector<T>::operator=(const TVector& v)
{
    if (this != &v) {
        pVector = new T[v.size - v.startIndex];
        startIndex = v.startIndex;
        size = v.size;
        for (size_t i = 0; i < size - startIndex; i++) {
            pVector[i] = v.pVector[i];
        }
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // прибавить скаляр
TVector<T> TVector<T>::operator+(const T& val)
{
    if (val) {
        startIndex = 0;
        for (int i = 0; i < size; i++) {
            pVector[i] += val;
        }
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // вычесть скаляр
TVector<T> TVector<T>::operator-(const T& val)
{
    int negval = -val;
    return (*this + negval);
} /*-------------------------------------------------------------------------*/

template <class T> // умножить на скаляр
TVector<T> TVector<T>::operator*(const T& val)
{
    if (val == 0) {
        startIndex = size;
        pVector[size] = 0;
    }
    for (int i = 0; i < size; i++) {
        pVector[i] *= val;
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TVector<T> TVector<T>::operator+(const TVector<T>& v)
{
    if (size != v.size) {
        throw OutOfIndException();
    }
    else {
        TVector<T> temp(size);
        temp.size = size;
        if (startIndex == v.startIndex) {
            temp.startIndex = startIndex;
            for (int i = temp.startIndex; i < size; i++) {
                temp.pVector[i - startIndex] = pVector[i] + v.pVector[i];
            }
        }
        else {
            if (startIndex < v.startIndex) {
                temp.startIndex = startIndex;
                for (int i = temp.startIndex; i < v.startIndex; i++) {
                    temp.pVector[i] = pVector[i];
                }
                for (int i = v.startIndex; i < v.size; i++) {
                    temp.pVector[i] = pVector[i] + v.pVector[i];
                }
            }
            else {
                temp.startIndex = v.startIndex;
                for (int i = temp.startIndex; i < startIndex; i++) {
                    temp.pVector[i] = v.pVector[i];
                }
                for (int i = startIndex; i < size; i++) {
                    temp.pVector[i] = pVector[i] + v.pVector[i];
                }
            }
        }
        return temp;
    }
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TVector<T> TVector<T>::operator-(const TVector<T>& v)
{
    if (size != v.size) {
        throw OutOfIndException();
    }
    else {
        TVector<T> temp(v.size);
        temp = v;
        temp = temp * (-1);
        return temp + *this;
    }
} /*-------------------------------------------------------------------------*/

template <class T> // скалярное произведение
T TVector<T>::operator*(const TVector<T>& v)
{
    T sum = 0;

    if (size != v.size) {
        throw OutOfIndException();
    }
    else {
        TVector<T> temp(v.size);
        if (startIndex > v.startIndex) temp.startIndex = startIndex;
        else temp.startIndex = v.startIndex;
        for (int i = temp.startIndex; i < size; i++) {
            sum += v.pVector[i] * pVector[i];
        }
        return sum;
    }

} /*-------------------------------------------------------------------------*/

template <class T>
T& TVector<T>::getElement(int index)
{
    if (index < 0 || index >= size) {
        throw OutOfIndException();
    }
    if (index < startIndex) {
        T temp = 0;
        return temp;
    }
    return pVector[index - startIndex];
}

template <class T>
void TVector<T>::setElement(int index, T element)
{
    if (index < 0 || index >= size) {
        throw OutOfIndException();
    }
    if (index < startIndex) {
        TVector<T> res((int)size, index);
        res.pVector[0] = element;
        for (int i = 1; i < startIndex - index; i++)
            res.pVector[i] = 0;
        for (int i = startIndex - index; i < size - index; i++)
            res.pVector[i] = pVector[i + index - startIndex];
        *this = res;
    }
    else pVector[index - startIndex] = element;
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
    if (static_cast<unsigned long long>(s * s) > TVector<T>::max_size)
        throw OverLimitException();
    for (int i = 0; i < s; i++)
        TVector<TVector<T>>::pVector[i] = TVector<T>(s, i);
} /*-------------------------------------------------------------------------*/

template <class T> // конструктор копирования
TMatrix<T>::TMatrix(const TMatrix<T>& mt) :TVector<TVector<T>>(mt) {}

template <class T> // конструктор преобразования типа
TMatrix<T>::TMatrix(const TVector<TVector<T> >& mt) : TVector<TVector<T> >(mt) {}

template <class T> // сравнение
bool TMatrix<T>::operator==(const TMatrix<T>& mt) const
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
bool TMatrix<T>::operator!=(const TMatrix<T>& mt) const
{
    if (*this == mt) return false;
    return true;
} /*-------------------------------------------------------------------------*/

template <class T> // присваивание
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& mt)
{
    if (this == &mt)
        return *this;
    this->size = mt.size;
    this->startIndex = mt.startIndex;
    delete[] this->pVector;
    this->pVector = new TVector<T>[this->size];
    for (int i = 0; i < this->size; i++)
        TVector<TVector<T>>::pVector[i] = mt.pVector[i];
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // сложение
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& mt)
{
    if (this->size != mt.size || this->startIndex != mt.startIndex) {
        throw OutOfIndException();
    }
    for (int i = 0; i < this->size; i++)
        TVector<TVector<T>>::pVector[i] = TVector<TVector<T>>::pVector[i] + mt.pVector[i];
    return *this;
} /*-------------------------------------------------------------------------*/

template <class T> // вычитание
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& mt)
{
    if (this->size != mt.size || this->startIndex != mt.startIndex) {
        throw OutOfIndException();
    }
    for (int i = 0; i < this->size; i++)
        TVector<TVector<T>>::pVector[i] = TVector<TVector<T>>::pVector[i] - mt.pVector[i];
    return *this;
} /*-------------------------------------------------------------------------*/