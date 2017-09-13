#include <iostream>
#include <iomanip>
using namespace std;

void generateMagicSquare(int size);
int width(int size);

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
	
	cout << "The magic square of size " << size << ":" << endl;
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
	
	int x = 0;
	int y = size / 2;
		
	for (int i = 1; i <= size * size; ++i )
	{
		
		arr[x][y] = i;
		
		int diagonalx = (x + size - 1) % size;
		int diagonaly = (y + 1) % size;
		
		if (arr[diagonalx][diagonaly])
			x = (x + 1) % size;
		else
		{
			x = diagonalx;
			y = diagonaly;
		}
		
	}
	
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
			cout << setw(width(size)) << right << arr[i][j];
		cout << endl;
	}		
	
	for (int i = 0; i < size; ++i)
		delete []arr[i];
	delete []arr;
}

int width(int size)
{
	int num = size * size;
	int count = 0;
	while (num)
	{
		num /= 10;
		count++;
	}
	
	return ++count;
}
