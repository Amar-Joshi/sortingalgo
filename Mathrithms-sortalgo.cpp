/* I am going to use a divide and conquer aproach.
partition is an important part of this algorithm.
Target of partitions is, given an array and an 
element z of array as pivot, put z at its correct
 position in sorted array and put all smaller elements
(smaller than z) before z, and put all greater elements
(greater than z) after z
In an Array I am going to pivote the last element of 
an array and shift all the numbers smaller than pivoted 
number into its left and bigger numbers into its right.
Then I'll use partition.

swap() function is used to swap two elements during partition.

part() function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivoted number)
to left of pivot and all greater elements to right
of pivot.

algorithm() is the main function that implements QuickSort
arr[] --> Array which is to be sorted,
small --> Starting index,
big--> Ending index

pin is partitioning index.
 
 printArray() unction to print an array 

*/
#include <bits/stdc++.h>
using namespace std;

//swapping numbers
void swapping(int* x, int* y)
{
	int a = *x;
	*x = *y;
	*y = a;
}

int part (int arr[], int small, int big)
{
	int pivot = arr[big];
	int i = (small - 1); 

	for (int j = small; j <= big- 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swapping(&arr[i], &arr[j]);
		}
	}
	swapping(&arr[i + 1], &arr[big]);
	return (i + 1);
}

void algorithm(int arr[], int small, int big)
{
	if (small < big)
	{
		
		int pin = part(arr, small, big);

		// sorting of elements before and after partition
		algorithm(arr, small, pin - 1);
		algorithm(arr, pin + 1, big);
	}
}


void printArray(int arr[], int length)
{
	
	for (int i = 0; i < length; i++)
		cout << arr[i] << " "; // space between elements
	cout << endl;
}

// Driver Code
int main()
{
	int arr[] = {6,8,1,10,27,97,45};
	int n = sizeof(arr) / sizeof(arr[0]);
	algorithm(arr, 0, n - 1);
	cout << "This is the sorted array: \n";
	printArray(arr, n);
	return 0;
}