#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int	choice = 0;
	const char* pStudent[] = { "Muhammad Ahsan", "Kamzan Ahmed", "Asad Sana", "Noox Khan", "Adeel Shahzad", "UmexX�L��" };
	const char* pStr = "Your Favorite Student is";
	cout << endl << "Enter a number between 1 and 6" << endl;
	cin >> choice;
	if (choice >= 1 && choice <= 6)
	{
		cout << pStr << " " << pStudent[choice - 1] << endl;
	}
	return 0;
}