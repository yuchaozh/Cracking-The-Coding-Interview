/*Question:
 *implement an algorithm to determin if a string has all unique
 *characters. What if you can not use additional data strcutures
 *
 *Author: Yuchao Zhou
 */
 
#include <string>
#include <iostream>
using namespace std;
 
bool existCharactor(string s)
{
	//initate the array with 0 of each cell
	//the size of the whole ascii is 0-255
	int exist[256] = {0};
	int length = s.length();
	for (int i = 0; i < length; i++)
	{
		//change char into ascii code
		int index = (int)s[i];
		if (exist[index] == 1)
			return true;
		else
			exist[index] = 1;
	}
 	return false;
}
 
int main(int argc, char* argv[])
{
	string input = argv[1];
	if (existCharactor(input) == true)
		cout<<"exists same charactors."<<endl;
	else
		cout<<"no same charactors."<<endl;
}

 
