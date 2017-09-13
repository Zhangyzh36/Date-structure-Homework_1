#include <iostream>
#include <vector>
using namespace std;

bool isMagicSquare(int **a, int size);

int main()
{
	int **arr;
	int size;
	cout << "Please enter the size of the square:" << endl;
	cin >> size;
	arr = new int *[size];
	for (int i = 0; i < size; ++i )
		arr[i] = new int[size];	
	
	cout << "Please enter the data of the square(row by row):" << endl;
	
	for (int i = 0; i < size; ++i )
		for (int j = 0; j < size; ++j)
			cin >> arr[i][j];
			
	cout << (isMagicSquare(arr, size) ? "It is a magic square." : "It is not a magic square." ) << endl;
	
	for (int i = 0; i < size; ++i )
		delete []arr[i];
	delete []arr;
	
	return 0;
}

bool isMagicSquare(int **a, int size)
{
	
	vector<int> allSum;
	int diagonalSum1 = 0;
	int diagonalSum2 = 0;
	
	for (int i = 0; i < size; ++i )
	{
		diagonalSum1 += a[i][i];
		diagonalSum2 += a[i][size - i - 1];
	
		int rowSum = 0;
		int colSum = 0;
		
		for (int j = 0; j < size; ++j )
		{
			rowSum += a[i][j];
			colSum += a[j][i];
		}
		
		allSum.push_back(rowSum);
		allSum.push_back(colSum);
	}
	
	allSum.push_back(diagonalSum1);
	allSum.push_back(diagonalSum2);
	
	for (int i = 0; i < allSum.size() - 1; ++i )
		if (allSum[i] != allSum[i + 1])
			return false;
			
	return true;
}
