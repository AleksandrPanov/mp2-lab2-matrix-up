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

	TVector();                                   //конструктор по умолчанию
	TVector(int size, int startIndex = 0);       //конструктор инициализации
	TVector(size_t size, size_t startIndex = 0); //конструктор инициализации

	template <class TSize, class TStartIndex>
	TVector(TSize size, TStartIndex startIndex) = delete;

	TVector(const TVector& v);                          // конструктор копирования
	~TVector();
	size_t getSize() const { return size; }             // размер вектора
	size_t getStartIndex() const { return startIndex; } // индекс первого элемента
	T& getElement(int i) const;
	T& getElement(size_t i) const;
	void setElement(int index, T element);
	void setElement(size_t index, T element);

	T& operator[] (int pos);                  // доступ
	T& operator[] (size_t pos);               // доступ
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
		for (size_t i = v.getStartIndex(); i < v.getSize; i++)
		{
			in >> v.pVector[i];
		}
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const TVector& v)
	{
		for (size_t i = 0; i < v.startIndex; i++)
		{
			out << 0 << " ";
		}
		for (size_t i = 0; i < v.size; i++)
		{
			out << v.pVector[i] << " ";
		}
		return out;
	}
};

template<class T>
TVector<T>::TVector()
{
	pVector = nullptr;
	size = 0;
	startIndex = 0;
}

template <class T>//конструктор инициализации
TVector<T>::TVector(int _size, int startIndex)
{
	if (_size < 0 || startIndex < 0 || _size > max_size || startIndex > max_size - size)
	{
		throw "_size or startIndex out of range";
	}
	this->size = _size;
	this->startIndex = startIndex;
	if (size == 0)
	{
		pVector = nullptr;
	}
	else
	{
		pVector = new T[_size];
	}
}
template <class T>//конструктор инициализации
TVector<T>::TVector(size_t _size, size_t startIndex)
{
	if (_size > max_size || startIndex > max_size - size)
	{
		throw "_size or startIndex out of range";
	}
	this->size = _size;
	this->startIndex = startIndex;
	if (size == 0)
	{
		pVector = nullptr;
	}
	else
	{
		pVector = new T[_size];
	}
}

template <class T> //конструктор копирования
TVector<T>::TVector(const TVector<T>& v):size(0), startIndex(0), pVector(nullptr)
{
	if (v != *this)
	{
		size = v.size;
		startIndex = v.startIndex;
		if (size != 0)
		{
			pVector = new T[size];
			for (size_t i = 0; i < size; i++)
			{
				pVector[i] = v.pVector[i];
			}
		}
		else { pVector = nullptr; }
	}
}

template <class T> //деструктор
TVector<T>::~TVector()
{
	delete[] pVector;
	size = 0;
	startIndex = 0;
}

template <class T> // доступ
T& TVector<T>::operator[](int pos)
{
	if (pos - startIndex < 0 || pos - startIndex >= max_size)
	{
		throw "pos out of range";
	}
	return pVector[pos - startIndex];
}

template <class T> // доступ
T& TVector<T>::operator[](size_t pos)
{
	if (pos - startIndex >= max_size)
	{
		throw "pos out of range";
	}
	return pVector[pos - startIndex];
}

template <class T> // сравнение
bool TVector<T>::operator==(const TVector &v) const
{
	if (this == &v)
	{
		return true;
	}
	if (size != v.getSize() || startIndex != v.getStartIndex())
	{
		return false;
	}
	else
	{
		for (size_t i = 0; i < size - startIndex; i++)
		{
			if (pVector[i] != v.pVector[i])
				return false;
		}
	}
	return true;
}

template <class T> // сравнение
bool TVector<T>::operator!=(const TVector &v) const
{
	if (this == &v)
	{
		return true;
	}
	if (startIndex != v.getStartIndex() || size != v.getSize())
	{
		return true;
	}
	for (int i = 0; i < size - startIndex; i++)
	{
		if (pVector[i] != v.pVector[i])
		{
			return true;
		}
	}
	return false;
}

template <class T> // присваивание
TVector<T>& TVector<T>::operator=(const TVector &v)
{
	if (this == &v)
	{
		return *this;
	}
	if (pVector != nullptr)
	{
		delete[] pVector;
	}
	size = v.size;
	startIndex = v.startIndex;
	if (size != 0)
	{
		pVector = new T[size];
	}
	else
	{
		pVector = nullptr;
	}
	for (size_t i = 0; i < size; i++)
	{
		pVector[i] = v.pVector[i];
	}
	return *this;
}

template <class T> // прибавить скаляр
TVector<T> TVector<T>::operator+(const T &val)
{
	TVector<T> vec(*this);
	for (size_t i = 0; i < size; i++)
	{
		vec.pVector[i] += val;
	}
	return vec;
}

template <class T> // вычесть скаляр
TVector<T> TVector<T>::operator-(const T &val)
{
	TVector<T> vec(*this);
	for (size_t i = 0; i < size; i++)
	{
		vec.pVector[i] -= val;
	}
	return vec;
}

template <class T> // умножить на скаляр
TVector<T> TVector<T>::operator*(const T &val)
{
	TVector<T> vec(*this);
	for (size_t i = 0; i < size; i++)
	{
		vec.pVector[i] *= val;
	}
	return vec;
}
template <class T> // сложение
TVector<T> TVector<T>::operator+(const TVector<T> &v)
{
	if (size != v.size || startIndex != v.startIndex)
	{
		throw "sizes or startIndexes are unequal";
	}
	TVector<T> vec(*this);
	for (size_t i = 0; i < size; i++)
	{
		vec.pVector[i] = vec.pVector[i] + v.pVector[i];
	}
	return vec;
}

template <class T> // вычитание
TVector<T> TVector<T>::operator-(const TVector<T> &v)
{
	if (size != v.size || startIndex != v.startIndex)
	{
		throw "sizes or startIndexes are unequal";
	}
	TVector<T> vec(*this);
	for (size_t i = 0; i < size; i++)
	{
		vec.pVector[i] = vec.pVector[i] - v.pVector[i];
	}
	return vec;
}

template <class T> // скалярное произведение
T TVector<T>::operator*(const TVector<T> &v)
{
	if (size != v.size || startIndex != v.startIndex)
	{
		throw "sizes or startIndexes are unequal";
	}
	T result = 0;
	for (size_t i = 0; i < size; i++)
	{
		result += pVector[i] * v.pVector[i];
	}
	return result;
}

template <class T>
T& TVector<T>::getElement(int index) const
{
	if (index < 0 || index >= size - startIndex)
	{
		throw "index out of range";
	}
	return pVector[index];
}

template<class T>
T& TVector<T>::getElement(size_t index) const
{
	if (index >= size - startIndex)
	{
		throw "index out of range";
	}
	return pVector[index];
}

template <class T>
void TVector<T>::setElement(int index, T element)
{
	if (index < 0 || index >= size - startIndex)
	{
		throw "index out of range";
	}
	pVector[index] = element;
}

template <class T>
void TVector<T>::setElement(size_t index, T element)
{
	if (index >= size - startIndex)
	{
		throw "index out of range";
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
class TMatrix : public TVector<TVector<T>>
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
	friend std::ostream& operator<<(std::ostream &out, const TMatrix &mt)
	{
		for (int i = 0; i < mt.size; i++)
			out << mt.pVector[i] << std::endl;
		return out;
	}
};

template <class T>
TMatrix<T>::TMatrix(int s): TVector<TVector<T>>(s)
{
	if ((static_cast<unsigned long long>(s * s) > max_size) || (s < 0))
	{
		throw "size out of range";
	}
	for (int i = 0; i < s; i++)
	{
		TMatrix<T>::pVector[i] = TVector<T>(s, i);
	}
}

template<class T>
TMatrix<T>::TMatrix(size_t s) : TVector<TVector<T>>(s)
{
	if (static_cast<unsigned long long>(s * s) > max_size)
	{
		throw "size out of range";
	}
	for (size_t i = 0; i < s; i++)
	{
		TMatrix<T>::pVector[i] = TVector<T>(s, i);
	}
}


template <class T> // конструктор копирования
TMatrix<T>::TMatrix(const TMatrix<T> &mt) :
	TVector<TVector<T> >(mt) {}

template <class T> // конструктор преобразования типа
TMatrix<T>::TMatrix(const TVector<TVector<T> > &mt) :
	TVector<TVector<T> >(mt) {}

template <class T> // сравнение
bool TMatrix<T>::operator==(const TMatrix<T> &mt) const
{
	if (this == &mt)
	{
		return true;
	}
	if (mt.getSize() != size)
	{
		return false;
	}
	for (int i = 0; i < mt.getSize(); i++)
	{
		if (getElement(i) != mt.getElement(i))
		{
			return false;
		}
	}
	return true;
}

template <class T> // сравнение
bool TMatrix<T>::operator!=(const TMatrix<T> &mt) const
{
	if (this == &mt)
	{
		return false;
	}
	if (mt.getSize() != size)
	{
		return true;
	}
	for (int i = 0; i < mt.getSize(); i++)
	{
		if (getElement(i) != mt.getElement(i))
		{
			return true;
		}
	}
	return false;
}

template <class T> // присваивание
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &mt)
{
	if (this == &mt)
	{
		return *this;
	}
	size = mt.getSize();
	delete[] pVector;
	pVector = new TVector<T>[size];
	for (int i = 0; i < size; i++)
	{
		this->setElement(i, mt.getElement(i));
	}
	return *this;
}

template <class T> // сложение
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &mt)
{
	if (size != mt.size)
	{
		throw "Sizes are unequal";
	}
	TMatrix<T> matrix(*this);
	for (size_t i = 0; i < size; i++)
	{
		matrix.pVector[i] = matrix.pVector[i] + mt.pVector[i];
	}
	return matrix;
}

template <class T> // вычитание
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &mt)
{
	if (size != mt.size)
	{
		throw "Sizes are unequal";
	}
	TMatrix<T> matrix(*this);
	for (size_t i = 0; i < size; i++)
	{
		matrix.pVector[i] = matrix.pVector[i] - mt.pVector[i];
	}
		return matrix;
}