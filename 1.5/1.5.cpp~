/*Question:
 *Write a method to replace all spaces in a string with '%20'
 *Caution:'%20' has 3 chars is a string
 *Author: Yuchao Zhou
 */
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void replaceSpace(string s)
{
	cout<<"input: "<<s<<endl;
	for (int i = 0; i < s.length(); i++)
	{
		//judge wether is a space
		if (s[i] == ' ')
		{	
			s.erase(i,1);
			s.insert(i, "%20");
		}
	}
	cout<<"After replace: "<<s<<endl;
}

int main(int argc, char* argv[])
{
	//judge NULL string, only 1 input but it is 2.
	if (argc!=1)
	{
		cout<<"Please input two strings"<<endl;
		exit(0);
	}
	string input1 = "Write a method to replace all spaces in a string with '%20'";
	replaceSpace(input1);
	return 0;
}

