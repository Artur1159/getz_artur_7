#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string.h>
#include"Word.h"

using namespace std;
const int N = 100;

void Word::print()
	{
		cout << word << endl;
	}

void Word::fieldFilling()
	{
		cout << "Enter word: ";
		cin >> word;
	}

	Word::Word() // конструктор без параметров
	{
		word[0] = '\0';
	}

	Word::Word(const char* InitialWord) // констуктор инициализации слова заданным словом-инициализатором
	{
		strcpy_s(word, InitialWord);
	}

	Word::Word(int repeat, char symbol) // конструктор инициализации слова заданным количеством повторов заданного символа
	{
		for (int i = 0; i < repeat; i++)
		{
			word[i] = symbol;
		}
		word[repeat] = '\0';
	}

	Word::Word(const char* initialWord, int n) // constructor to initialize a word with part of a given initial word
	{
		int len = strlen(initialWord);
		int count = 0;

		for (int i = 0; i < n && i < len; i++)
		{
			word[count] = initialWord[i];
			count++;
		}

		for (int i = len - n; i < len && i >= 0; i++)
		{
			word[count] = initialWord[i];
			count++;
		}
		word[count] = '\0';
	}

	Word::Word(const Word& str) // конструктор копирования
	{
		strncpy_s(word, str.word, sizeof(word));
	}

	Word::Word(Word&& other) noexcept // конструктор перемещения
	{
		strncpy_s(word, other.word, sizeof(word));
		other.word[0] = '\0';
	}

	char* Word::swapLetters()
	{
		int len = strlen(word);
		char* newWord = new char[len + 1];
		int j = 0;
		for (int i = 0; i < len; i += 2)
		{
			if (word[i + 1] != '\0')
			{
				newWord[j] = word[i + 1];
				newWord[j + 1] = word[i];
			}
			else
			{
				newWord[j] = word[i];
				newWord[j + 1] = ' ';
			}
			j += 2;
		}
		newWord[len] = '\0';
		return newWord;
	}

