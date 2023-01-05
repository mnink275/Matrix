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
	~Matrix() = default;

	Matrix(Matrix<T, R, C>& mtx);
	Matrix<T, R, C>& operator=(Matrix<T, R, C>& mtx);
	
	void print();
	/*T findMinor(size_t row, size_t column);*/
	T det();
	std::array<T, C>& operator[](size_t idx);
	Matrix<T, R, C>& operator+(Matrix<T, R, C>& mtx);

	template<class T, class U, int M, int N, int K>
	friend Matrix<T, M, K>& operator*(Matrix<U, M, N>& mtx1, Matrix<T, N, K>& mtx2);
	

private:
	/*T detHelper(size_t row, size_t column);*/

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
Matrix<T, R, C>::Matrix(Matrix<T, R, C>& mtx)
{
	matrix = mtx.matrix;
}


template<class T, int R, int C>
Matrix<T, R, C>& Matrix<T, R, C>::operator=(Matrix<T, R, C>& mtx)
{
	matrix = mtx.matrix;
	return *this;
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


//template<class T, int R, int C>
//T Matrix<T, R, C>::findMinor(size_t row, size_t column)
//{
//	/*return pow(-1, i + j) * matrix[i][j] * minorHelper(i, j);*/
//}


template<class T, int R, int C>
T Matrix<T, R, C>::det()
{
	auto gauss = matrix;
	for (size_t k = 0; k < R - 1; k++)
	{
		for (size_t i = k + 1; i < R; i++)
		{
			double delta = -gauss[i][k] / gauss[k][k];
			for (size_t j = k; j < R; j++)
			{
				gauss[i][j] += gauss[k][j] * delta;
			}
		}
	}
	
	double ans = 1;
	for (size_t k = 0; k < C; k++)
	{
		ans *= gauss[k][k];
	}

	return ans;
}


//template<class T, int R, int C>
//T Matrix<T, R, C>::detHelper(size_t row, size_t skip_idx)
//{
//	T ans = 0;
//	for (size_t j = 0; j < C; j++)
//	{
//		if (j == skip_idx) continue;
//		ans += pow(-1, row + j) * matrix[row][j] * detHelper(row + 1, j);
//	}
//
//	return ans;
//}


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