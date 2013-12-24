/*Question:
 *Design an algorithm and write code to remove the duplicate   *characters in a string without using any additional buffer.  *NOTE: One or two additional variables are fine. An extra copy *of the array is not.
 *
 *Author: Yuchao Zhou
 */
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	bool exitSame = false;
	//judge NULL string, only 1 input but it is 2.
	if (argc!=2)
	{
		cout<<"Please input a string"<<endl;
		exit(0);
	}
	string input = argv[1];
	cout<<"input:  "<<input<<endl;
	for (int i = 0; i < input.size(); i++)
	{
		exitSame = false;
		for (int j = i + 1; j < input.size(); j++)
		{
			if (input[i] == input[j])
			{
				exitSame = true;
				input.erase(j, 1);
				j--;
			}
		}
		if (exitSame == true)
		{
			input.erase(i, 1);
			i--;
		}
	}
	cout<<"output: "<<input<<endl;
	return 0;
}
