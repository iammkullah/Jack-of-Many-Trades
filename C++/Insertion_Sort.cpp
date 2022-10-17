#include <iostream>
using namespace std;

int main()
{
    int arr[7] = {32, 30, 39, 34, 37, 35, 33};

    for(int i = 0; i < 7; i++)
    {
        cout << arr[i];
        if(i < 6)
        cout << ", ";
    }
    cout << endl;

    int temp;
    int j;
    for( int i = 0; i < 7; i++)
    {
        temp = arr[i];
        for(j = i; j>0 &&temp < arr[j-1]; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }

    for(int i = 0; i < 7; i++)
    {
        cout << arr[i];
        if(i < 6)
        cout << ", ";
    }
    cout << endl;
}