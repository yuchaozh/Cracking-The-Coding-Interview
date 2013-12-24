/*Question:
 *Write a method to decide if two strings are anagrams or not
 *anagram is not as same as Palindrome
 *Author: Yuchao Zhou
 */
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void isAnagrams1(string s, string t)
{
	bool isAnagram = true;
	int input1[256] = {0};
	int input2[256] = {0};
	int index = 0;
	if (s.length() != s.length())
		isAnagram = false;
	else
	{
		for (int i = 0; i < s.length(); i++)
		{
			index = (int)s[i];
			input1[index]++;
			index = (int)t[i];
			input2[index]++;
		}
		for (int i = 0; i < 256; i++)
		{
			if (input1[i] != input2[i])
			{
				isAnagram = false;
			}
		}
	}
	if (isAnagram == true)
		cout<<s<<" "<<t<<" is anagrams."<<endl;
	else
		cout<<s<<" "<<t<<" is not anagrams."<<endl;
}

int main(int argc, char* argv[])
{
	bool exitSame = false;
	//judge NULL string, only 1 input but it is 2.
	if (argc!=3)
	{
		cout<<"Please input two strings"<<endl;
		exit(0);
	}
	string input1 = argv[1];
	string input2 = argv[2];
	isAnagrams1(input1, input2);
	return 0;
}

