#pragma once
#include <iostream>
#include<vector>
#include<iomanip>
#include <cstdlib> 

using namespace std;

void KeypadInitializationMatrix(vector<vector<int>>&, int, int);

void DisplayMatrix(vector<vector<int>>&, int, int);

void RandomInitializationMatrix(vector<vector<int>>&, int, int, int);

int MinimumProductOfElements(vector<vector<int>>&, int, int, int a);