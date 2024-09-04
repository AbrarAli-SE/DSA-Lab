#include <iostream>
using namespace std;
int main()
{
	int arry[5] = { 10,20,30,40,50};
	int* ptr = &arry[0];
	for (int i = 0;i < 5;i++)
	{
		cout << ptr + i << endl;
	}
	cout << endl;
	for (int i = 0;i < 5;i++)
	{
		cout << arry[i] << endl;
	}
}