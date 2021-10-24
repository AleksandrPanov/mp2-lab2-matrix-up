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
    static const size_t max_size = std::numeric_limits<int>::max();
    TVector() {}
    TVector(int size, int startIndex = 0);       //конструктор инициализации
	TVector(size_t size, size_t startIndex = 0); //конструктор инициализации

    template <class TSize, class TStartIndex>
    TVector(TSize size, TStartIndex startIndex) = delete;

    TVector(const TVector &v);                // конструктор копирования
    ~TVector();
    size_t getSize() const     { return size;       } // размер вектора
    size_t getStartIndex() const { return startIndex; } // индекс первого элемента
    T& getElement (int i) const;
    T& getElement (size_t i) const;
    void setElement(int index, T element);
    void setElement(size_t index, T element);

    T& operator[] (int pos);                  // доступ
    T& operator[] (size_t pos);               // доступ
	T operator[] (size_t pos) const;
	T operator[] (int pos) const;
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
		{
			in >> v[i];
		}
        return in;
    }
    friend std::ostream& operator<<(std::ostream &out, const TVector &v)
    {
		for (size_t i = 0; i < v.getStartIndex(); ++i)
		{
			out << 0 << ' ';
		}
		for (size_t i = v.getStartIndex(); i < v.getSize(); ++i)
		{
			out << v[i] << ' ';
		}
        return out;
    }
private:
};

template<class T>
TVector<T>::TVector() :size(0), startIndex(0), pVector(nullptr)
{
}

template <class T>//конструктор инициализации
TVector<T>::TVector(int _size, int _startIndex)
{
	if (_size < 0 || _startIndex < 0 || _startIndex >= _size) throw "Bad size/startIndex";
	size = _size;
	startIndex = _startIndex;
	pVector = new T[size - startIndex];
}

template <class T>//конструктор инициализации
TVector<T>::TVector(size_t _size, size_t _startIndex)
{
	if(_startIndex >= _size) throw "Bad startIndex";
	else if (_size > max_size) throw "Size is too big";
	size = _size;
	startIndex = _startIndex;
	if (_size - _startIndex > 0)
		pVector = new T[size - startIndex];
}


template <class T> //конструктор копирования
TVector<T>::TVector(const TVector<T> &v) :size(0), startIndex(0), pVector(nullptr)
{
	*this = v;
}

template <class T> //деструктор
TVector<T>::~TVector()
{
	delete[] pVector;
}

template <class T> // доступ
T& TVector<T>::operator[](int pos)
{
	if (pos >= size || pos < 0)
		throw "Out of bounds";
	else if (pos >= startIndex)
		return pVector[pos - startIndex];
}

template <class T> // доступ
T& TVector<T>::operator[](size_t pos)
{
	if (pos >= size)
		throw "Out of bounds";
	else if (pos >= startIndex)
		return pVector[pos - startIndex];
}

template<class T>
T TVector<T>::operator[](size_t pos) const
{
	if (pos > size || pos < startIndex)
		throw "Out of bounds";
	else if (pos >= startIndex)
		return pVector[pos - startIndex];
}

template<class T>
T TVector<T>::operator[](int pos) const
{
	if (pos > size || pos < 0 || pos < startIndex)
		throw "Out of bounds";
	else if (pos >= startIndex)
		return pVector[pos - startIndex];
}

template <class T> // сравнение
bool TVector<T>::operator==(const TVector &v) const
{
	if (startIndex != v.getStartIndex() || size != v.getSize()) return false;
	for (int i = 0; i < size - startIndex; ++i)
	{
		if (pVector[i] != v[i + startIndex]) return false;
	}
    return true;
}

template <class T> // сравнение
bool TVector<T>::operator!=(const TVector &v) const
{
	if (startIndex != v.getStartIndex() || size != v.getSize()) return true;
	for (int i = 0; i < size - startIndex; ++i)
	{
		if (pVector[i] != v[i + startIndex]) return true;
	}
	return false;
}

template <class T> // присваивание
TVector<T>& TVector<T>::operator=(const TVector &v)
{
	if (this != &v)
	{
		size = v.getSize();
		startIndex = v.getStartIndex();
		if(pVector != nullptr)
			delete[] pVector;
		pVector = new T[size - startIndex];
		for (size_t i = 0; i < size - startIndex; ++i)
		{
			pVector[i] = v[i + startIndex];
		}
	}
	return *this;
} 

template <class T> // прибавить скаляр
TVector<T> TVector<T>::operator+(const T &val)
{
	TVector<T> res(*this);
	for (size_t i = startIndex; i < size; ++i)
	{
		res[i] += val;
	}
	return res;
} 

template <class T> // вычесть скаляр
TVector<T> TVector<T>::operator-(const T &val)
{
	TVector<T> res(*this);
	for (size_t i = startIndex; i < size; ++i)
	{
		res[i] -= val;
	}
	return res;
} 

template <class T> // умножить на скаляр
TVector<T> TVector<T>::operator*(const T &val)
{
	TVector<T> res(*this);
	for (size_t i = startIndex; i < size; ++i)
	{
		res[i] *= val;
	}
	return res;
} 

template <class T> // сложение
TVector<T> TVector<T>::operator+(const TVector<T> &v)
{
	if (v.getSize() != size || v.getStartIndex() != startIndex) throw "Bad size/startIndex";
	TVector<T> res(*this);
	for (size_t i = startIndex; i < size; ++i)
	{
		res[i] += v[i];
	}
	return res;
} 

template <class T> // вычитание
TVector<T> TVector<T>::operator-(const TVector<T> &v)
{
	if (v.getSize() != size || v.getStartIndex() != startIndex) throw "Bad size/startIndex";
	TVector<T> res(*this);
	for (size_t i = startIndex; i < size; ++i)
	{
		res[i] -= v[i];
	}
	return res;
} 

template <class T> // скалярное произведение
T TVector<T>::operator*(const TVector<T> &v)
{
	T res = 0;
	if (v.getSize() != size || v.getStartIndex() != startIndex) throw "Sizes are not equal";
	for (size_t i = 0; i < size - startIndex; ++i)
	{
		res += pVector[i]*v[i + startIndex];
	}
    return res;
} 

template <class T>
T& TVector<T>::getElement(int index) const
{
	if (index <0 || index > size - startIndex) throw "Out of Bounds";
    return pVector[index];
}

template<class T>
T & TVector<T>::getElement(size_t index) const
{
	if(index > size - startIndex) throw "Out of Bounds";
	return pVector[index];
}

template <class T>
void TVector<T>::setElement(int index, T element)
{
	if (index < 0 || index >= size - startIndex) throw "Out of Bounds";
	pVector[index] = element;
}

template<class T>
void TVector<T>::setElement(size_t index, T element)
{
	if (index >= size - startIndex) throw "Out of Bounds";
	pVector[index] = element;
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
    explicit TMatrix(int s);
	explicit TMatrix(size_t s);

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
	if (static_cast<unsigned long long>(s*s) > max_size) throw "Size is too big";
	for (int i = 0; i < s; ++i)
	{
		TVector<TVector<T>>::pVector[i] = TVector<T>(s, i);
	}
} 

template<class T>
TMatrix<T>::TMatrix(size_t s) : TVector<TVector<T>>(s)
{
	if (static_cast<unsigned long long>(s*s) > max_size) throw "Size is too big";
	for (size_t i = 0; i < s; ++i)
	{
		TVector<TVector<T>>::pVector[i] = TVector<T>(static_cast<size_t>(s), i);
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
	if (mt.getSize() != size) 
		return false;
	for (int i = 0; i < mt.getSize(); ++i)
	{
		if (getElement(i) != mt.getElement(i))
			return false;
	}
	return true;
} 

template <class T> // сравнение
bool TMatrix<T>::operator!=(const TMatrix<T> &mt) const
{
	if (mt.getSize() != size) 
		return true;
	for (int i = 0; i < mt.getSize(); ++i)
	{
		if (getElement(i) != mt.getElement(i))
			return true;
	}
	return false;
} 

template <class T> // присваивание
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &mt)
{
	if (size != mt.getSize() || *this != mt)
	{
		size = mt.getSize();
		delete[] pVector;
		pVector = new TVector<T>[size];
		for (int i = 0; i < size; ++i)
		{
			this->setElement(i, mt.getElement(i));
		}
	}
    return *this;
} 

template <class T> // сложение
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &mt)
{
	for (int i = 0; i < mt.getSize(); ++i)
	{
		this->getElement(i) = this->getElement(i) + mt[i];
	}
    return *this;
}

template <class T> // вычитание
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &mt)
{
	for (int i = 0; i < mt.getSize(); ++i)
	{
		this->getElement(i) = this->getElement(i) - mt[i];
	}
    return *this;
}
