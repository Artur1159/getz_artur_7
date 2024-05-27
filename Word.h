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
	Word(); // ����������� ��� ����������
	

	Word(const char* InitialWord); // ���������� ������������� ����� �������� ������-���������������
	

	Word(int repeat, char symbol); // ����������� ������������� ����� �������� ����������� �������� ��������� �������
	

	Word(const char* initialWord, int n); // constructor to initialize a word with part of a given initial word
	

	Word(const Word& str); // ����������� �����������
	

	Word(Word&& other) noexcept;// ����������� �����������
	

	char* swapLetters();
	
};