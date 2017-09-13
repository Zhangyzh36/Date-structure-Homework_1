#include <iostream>
using namespace std;

void generateMagicSquare(int size);

int main()
{
	int size;
	cout << "Please enter the size of the magic square(odd):" << endl;
	cin >> size;
	
	while ( !(size & 1) || size <= 0 )
	{
		cout << "The size should be a positive odd number." << endl;
		cout << "Please enter again:" << endl;
		cin >> size; 
	}
	
	generateMagicSquare(size);
	
	return 0;
}

void generateMagicSquare(int size)
{
	int **arr = new int *[size];
	for (int i = 0; i < size; ++i)
	{	
		arr[i] = new int[size];
		for (int j = 0; j < size; ++j)
			arr[i][j] = 0;
	}
	
	for (int i = 1; i <= size * size; ++i )
	{
		int x = 0;
		int y = size / 2;
		
		int diagonalx = (x + size - 1) % size;
		int diagonaly = (y + 1) & size;
		
		if (arr[diagonalx][diagonaly])
		{
			
		}
		else
		{
			
		}
		
		
	}
	
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
			cout << arr[i][j]
		cout << endl;
	}		
	
	for (int i = 0; i < size; ++i)
		delete []arr[i];
	delete []arr;
}
