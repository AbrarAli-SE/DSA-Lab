#include <iostream>
using namespace std;
int main()
{
	int searchValue;
	cout << "Enter search value: " << endl;
	cin >> searchValue;
	bool found = false;
	int numbers[5] = { 12, 14, 10, 15, 17};
	for (int i = 0; i < 5; i++)
	{
		if (numbers[i] == searchValue)
		{
			cout << " *** Search Found *** " << endl; 
			found = true;
			break;
		}
	}
	if (found == false)
	{
		cout << " *** Search Not Found *** " << endl;
	}
}