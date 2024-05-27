#include <iostream>
#include<vector>
#include<iomanip>
#include <cstdlib> 
#include "Header.h"

using namespace std;

int main() 
{
    srand(time(NULL));

    int row;
    cout << "Enter count rows: ";
    cin >> row;

    int col;
    cout << "Enter count column: ";
    cin >> col;

    int n;
    cout << "Enter the number up to which the numbers will be generated: ";
    cin >> n;

    vector<vector<int>> matrix;

    int selection;
    cout << endl << "Select the method of matrix initialisation: " << endl;
    cout << "1. Random numbers" << endl;
    cout << "2. Keypad initialisation" << endl;

    cout << "Our selection: ";
    cin >> selection;

    switch (selection)
    {
    case 1:
        RandomInitializationMatrix(matrix, row, col, n);
        break;
    case 2:
        KeypadInitializationMatrix(matrix, row, col);

    }

    cout << endl << "Initial matrix: " << endl << endl;
    DisplayMatrix(matrix, row, col);

    int a;
    cout << endl << "Enter a: ";
    cin >> a;

    int col_minimum_product_index = MinimumProductOfElements(matrix, row, col, a);
    cout << endl << "Column with minimum elements product: " << col_minimum_product_index<< endl;
    
    return 0;
}