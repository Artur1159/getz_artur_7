#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string.h>
#include"Word.h"

using namespace std;

int main()
{
	Word word1;
	word1.print();

	Word word2("Hello");
	word2.print();

	Word word3(3, 'a');
	word3.print();

	Word word4("Programming", 3);
	word4.print();

	Word word5(word2);
	word5.print();

	Word word6 = move(word3);
	word6.print();

	Word swapWord(word4.swapLetters());
	swapWord.print();

	word3.print();
}