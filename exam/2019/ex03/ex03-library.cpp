#include "ex03-library.h"
#include <iostream>

//Do not modify
WordsList::WordsList()
{
	allWords.push_back("121");
	wordsToPalindromeDistance["121"] = 0;
	allWords.push_back("122");
	wordsToPalindromeDistance["122"] = 1;
}

//Exercise 3 (a) implement this method
void WordsList::print()
{
	std::cout << allWords.size() << " words:";
	for (auto word : allWords)
	{
		std::cout << " "
				  << word
				  << " "
				  << "("
				  << wordsToPalindromeDistance[word]
				  << ")";
	}
}

//Exercise 3 (b) implement this method
int WordsList::distancePalindrome(string s)
{
	int distance = 0;
	for (int i = 0, j = s.length() - 1; i < j; i++, j--)
	{
		if (s[i] != s[j])
		{
			distance += 1;
		}
	}

	return distance;
}

//Exercise 3 (c) implement this method
void WordsList::addWord(string word)
{
	allWords.push_back(word);
	auto pair = std::pair<string, int>(word, distancePalindrome(word));
	wordsToPalindromeDistance.insert(pair);
}

//Exercise 3 (d) implement this method
int WordsList::palindromeWords()
{
	int palindromes = 0;
	for (auto word : wordsToPalindromeDistance)
	{
		if (word.second == 0)
		{
			palindromes += 1;
		}
	}

	return palindromes;
}