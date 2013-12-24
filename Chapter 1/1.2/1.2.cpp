/*Question:
 *Write code to reverse a C-Style String.(C-String means that 
 *"abcd" is represented as fice characters, including the null
 *character.)
 *
 *Author: Yuchao Zhou
 */
 
#include <string>
#include <iostream>

using namespace std;

string reverse(string str)
{	
	string outcome = "";
	string temp;
	for (int i = 1; i <= str.length(); i ++)
	{
		temp = str[i - 1];
		outcome.insert(0, temp);
	}
	
	return outcome;
}

int main(int argc, char* argv[])
{
	string input = argv[1];
	cout<<"input:  "<<input<<endl;
	cout<<"output:  "<<reverse(input)<<endl;
}
