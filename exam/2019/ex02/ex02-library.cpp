#include "ex02-library.h"
#include <iostream>

//Exercise 2 (a) Implement this function
string reverse(string s, int n)
{
	//put your code here
	if (s == "" || n < 0)
	{
		return s;
	}

	// Get the first letter in the string.
	string first = s.substr(0, 1);
	// Reverse the remaining.
	string reversed = reverse(s.substr(1, n), n - 1);
	// Build the reverse string.
	return reversed + first;
}

//Exercise 2 (b) Implement this function
bool isPalindrome(string s, int n1, int n2)
{
	// n1 == n2 if there is only one character.
	// A single character is its own palindrome.
	// or if n1 is greater than or equal to the half of the string, then all characters
	// up to that point have been the same.
	if (n1 == n2 || n1 >= (int)(s.length() / 2))
	{
		return true;
	}

	// If the first and last character is not the same, it is not an palindrome.
	if (s[n1] == s[n2])
	{
		return isPalindrome(s, n1 + 1, n2 - 1);
	}

	// If we reach here then a two characters are not the same.
	return false;
}

//Exercise 2 (c) Implement this function
int distancePalindrome(string s, int n1, int n2)
{
	// If n1 == n2 then there is only one character, which have zero distance.
	// or if n1 is greater than or equal to the half of the string, then all characters
	// up to that point have been checked.
	if (n1 == n2 || n1 >= (int)(s.length() / 2))
	{
		return 0;
	}

	// If two characters are the same then add 0 and recurse.
	if (s[n1] == s[n2])
	{
		return 0 + distancePalindrome(s, n1 + 1, n2 - 1);
	}

	// Two characters have not been the same, add 1 distance and recurse.
	return 1 + distancePalindrome(s, n1 + 1, n2 - 1);
}