//this program find leader element in array
#include<iostream>
using namespace std;
int main()
{
	int x;
	cout << "Enter size of array: ";
	cin >> x;
	int* p = new int[x];
	cout << "Enter elment of array\n";
	for (int i = 0; i < x; i++)
	{
		cin >> p[i];
	}
	int k = 0;
	for (int i = 0; i < x - 1; i++)
	{
		k = 0;
		for (int j = 0; j < x; j++)
		{
			if (p[i] > p[j])
				k++;
		}
		if (k == (x - 1) - i)
			cout << "Leader is " << p[i] << endl;
	}
	delete[] p;
}