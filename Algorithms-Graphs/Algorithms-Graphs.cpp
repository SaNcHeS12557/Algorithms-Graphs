// Algorythms-Graphs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void graphStep(unsigned int n, int** matrix) {
	int row = 0, column = 0; // row/column start indexes
	cout << "Start position: 0,0!\n";
	cout << "====================\n";
	for (column; column < n; column++) {
		if (matrix[row][column] == 1) {
			matrix[row][column]--;
			cout << "Moving to: " << row << ", " << column << "!\n";
			row = column;
			column = 0;
		}
		else if (matrix[row][column] == 2) {
			cout << "Moving to: " << row << ", " << column << "!\n";
			cout << "====================\n";
			cout << "Congratulations! The end point is on row: " << row << " and column: " << column;
		}
	}
}

int main()
{
	unsigned const int n = 9; // number of rows and columns 'square matrix'

	// Graph - tabular view
	int graph[n][n] = {
		{0,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,0},
		{0,0,0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0,1,0},
		{0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,0,2},
		{0,0,0,0,0,0,0,0,2},
		{0,0,0,0,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0},

	};
	//


	// Matrix pointer
	int** graphPtr = new int* [n]; // 2-dim matrix allocation (pointer to pointer)
	for (int row = 0; row < n; row++) {
		graphPtr[row] = new int[n]; // allocating 1-dim matrixes
		for (int column = 0; column < n; column++) {
			graphPtr[row][column] = graph[row][column]; // copying values from main matrix to allocated matrix
		}
	}
	//


	graphStep(n, graphPtr);


	// Freeing up memory allocated to the matrix
	for (int i = 0; i < n; ++i) {
		delete[] graphPtr[i];
	}
	delete[] graphPtr;
	//
}