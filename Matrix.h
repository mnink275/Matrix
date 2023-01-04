#pragma once

#include <iostream>
#include <array>

// class template with non-type template parameters (int, size_t, long long, ...)
template<class T, int R, int C>
class Matrix
{
public:
	Matrix();
	Matrix(T);
	
	
	void print();

	std::array<T, C>& operator[](size_t idx);
	Matrix<T, R, C>& operator+(Matrix<T, R, C>&);

	template<class T, class U, int M, int N, int K>
	friend Matrix<T, M, K>& operator*(Matrix<U, M, N>&, Matrix<T, N, K>&);
	

private:
	std::array<std::array<T, C>, R> matrix;
};


template<class T, int R, int C>
Matrix<T, R, C>::Matrix()
{
	for (size_t i = 0; i < R; i++)
	{
		for (size_t j = 0; j < C; j++)
		{
			matrix[i][j] = 0;
		}
	}
}


template<class T, int R, int C>
Matrix<T, R, C>::Matrix(T value)
{
	for (size_t i = 0; i < R; i++)
	{
		for (size_t j = 0; j < C; j++)
		{
			matrix[i][j] = value;
		}
	}
}


template<class T, int R, int C>
void Matrix<T, R, C>::print()
{
	for (size_t i = 0; i < R; i++)
	{
		for (size_t j = 0; j < C; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}


template<class T, int R, int C>
std::array<T, C>& Matrix<T, R, C>::operator[](size_t idx)
{
	// operator[] overloads a first square bracket,
	// a second square bracket refer to std::array
	return matrix[idx];
}


template<class T, int R, int C>
Matrix<T, R, C>& Matrix<T, R, C>::operator+(Matrix<T, R, C>& mtx)
{
	// there is only 1 arg in operator+(arg)
	Matrix<T, R, C> sum;
	for (size_t i = 0; i < R; i++)
	{
		for (size_t j = 0; j < C; j++)
		{
			sum[i][j] = matrix[i][j] + mtx[i][j];
		}
	}

	return sum;
}


template<class T, class U, int M, int N, int K>
Matrix<T, M, K>& operator*(Matrix<U, M, N>& mtx1, Matrix<T, N, K>& mtx2)
{
	Matrix<T, M, K> product;
	// each element for-loop
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