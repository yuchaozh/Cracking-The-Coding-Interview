/*Question:
 *Given an image represented by an N*N matrix, where each pixel 
 *in the image is 4 bytes, write a method to rotate the iamge by
 *90 degrees. Can you do this in place?
 *
 *Author: Yuchao Zhou
 */
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void transfer(int matrix[][3])
{
	for (int layer = 0; layer < 3 / 2; layer++)
	{
		int first = layer;
		int last = 3 - 1 - layer;
		for (int i = first; i < last; i++)
		{
			int offset = i - first;
			//save top
			int top = matrix[first][i];
			//left->top
			matrix[first][i] = matrix[last - offset][first];
			//bottom->left
			matrix[last - offset][first] = matrix[last][last - offset];
			//right->bottom
			matrix[last][last - offset] = matrix[i][last];
			//top->right
			matrix[i][last] = top;
		}
	}
	cout<<"After transfer: "<<endl;
	for (int i = 0; i < 3; i++)
    {
    	for (int j = 0; j < 3; j++)
    	{
    		cout<<matrix[i][j]<<"  ";
    	}
    	cout<<endl;
    }
    cout<<endl;
}

int main(int argc, char* argv[])
{
	int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    for (int i = 0; i < 3; i++)
    {
    	for (int j = 0; j < 3; j++)
    	{
    		cout<<a[i][j]<<"  ";
    	}
    	cout<<endl;
    }
    cout<<endl;
    
    transfer(a);
	return 0;
}

