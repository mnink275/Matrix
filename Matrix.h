#pragma once

#include <iostream>
#include <array>

// class template with non-type template parameters (int, size_t, long long, ...)
template<class T, int Row, int Column>
class Matrix
{
public:
	Matrix();
	Matrix(T);
	void print();

	std::array<T, Column>& operator[](size_t idx);

	template<class T, class U, int M, int N, int K>
	friend Matrix<T, M, K> operator*(Matrix<U, M, N>&, Matrix<T, N, K>&);

private:
	std::array<std::array<T, Column>, Row> matrix;
};


template<class T, int Row, int Column>
Matrix<T, Row, Column>::Matrix()
{
	for (size_t i = 0; i < Row; i++)
	{
		for (size_t j = 0; j < Column; j++)
		{
			matrix[i][j] = 0;
		}
	}
}


template<class T, int Row, int Column>
Matrix<T, Row, Column>::Matrix(T value)
{
	for (size_t i = 0; i < Row; i++)
	{
		for (size_t j = 0; j < Column; j++)
		{
			matrix[i][j] = value;
		}
	}
}


template<class T, int Row, int Column>
void Matrix<T, Row, Column>::print()
{
	for (size_t i = 0; i < Row; i++)
	{
		for (size_t j = 0; j < Column; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}


template<class T, int Row, int Column>
std::array<T, Column>& Matrix<T, Row, Column>::operator[](size_t idx)
{
	return matrix[idx];
}


template<class T, class U, int M, int N, int K>
Matrix<T, M, K> operator*(Matrix<U, M, N>& mtx1, Matrix<T, N, K>& mtx2)
{
	Matrix<T, M, K> product;
	// each element in product of mtx1 and mtx2
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < K; j++)
		{
			// Row-Column rule
			for (size_t k = 0; k < N; k++)
			{
				product[i][j] += mtx1[i][k] * mtx2[k][j];
			}
		}
	}

	return product;
}