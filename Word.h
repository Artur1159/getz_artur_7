#pragma once
#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
const int N = 100;
class Word
{
	char word[N];
public:
	void print();

	void fieldFilling();
	Word(); // конструктор без параметров
	

	Word(const char* InitialWord); // констуктор инициализации слова заданным словом-инициализатором
	

	Word(int repeat, char symbol); // конструктор инициализации слова заданным количеством повторов заданного символа
	

	Word(const char* initialWord, int n); // constructor to initialize a word with part of a given initial word
	

	Word(const Word& str); // конструктор копирования
	

	Word(Word&& other) noexcept;// конструктор перемещения
	

	char* swapLetters();
	
};