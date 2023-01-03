#pragma once

#include <iostream>
#include <array>

// class template with non-type template parameters (int, size_t, long long, ...)
template<class T, int Row, int Column>
class Matrix
{
public:
	Matrix();
	void print();
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