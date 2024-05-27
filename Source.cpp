#include <iostream>
#include<vector>
#include<iomanip>
#include <cstdlib> 
#include "Header.h"

using namespace std;


void KeypadInitializationMatrix(vector<vector<int>>& matrix, int row, int col) // инициализация матрицы
{
	matrix.resize(row); // Создаем векторы для каждой строки матрицы
	for (int i = 0; i < row; i++)
	{
		matrix[i].resize(col); // Устанавливаем размер вектора 
		                       //для каждой строки             
		for (int j = 0; j < col; j++)
		{
			cin >> matrix[i][j];
		}
	}
}


void DisplayMatrix(vector<vector<int>>& matrix, int row, int col) // вывод матрицы
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


void RandomInitializationMatrix(vector<vector<int>>& matrix, int row, int col, int n)
{
	for (int i = 0; i < row; i++)
	{
		vector<int> rows;
		for (int j = 0; j < col; j++)
		{
			int randomNumber = rand() % n * 2 + 1;
			rows.push_back(randomNumber);
		}
		matrix.push_back(rows);
	}
}


int MinimumProductOfElements(vector<vector<int>>& matrix, int row, int col, int a)
{
	int min_product = INT_MAX;
	int product;
	int colIndex = -1;

	for (int i = 0; i < row; i++)
	{
		bool given_a = true;
		product = 1;
		for (int j = 0; j < col; j++)
		{
			if (matrix[j][i] >= a)
			{
				given_a = false;
				break;
			}
			product *= matrix[j][i];
		}
		if (given_a && product < min_product)
		{
			min_product = product;
			colIndex = i;
		}
	}




	
	return colIndex;
}