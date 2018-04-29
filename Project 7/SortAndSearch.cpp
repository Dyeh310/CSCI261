/*
	CSCI 261: PROJECT 7
	Different sort and search methods
	Author: Nicholas Heyd

*/

void fill_array (int arr[], int size);
//pre-condition: The arr has actual size that is greater than or equal to size
//post-condition: arr[0], ..., arr[size-1] is filled from keyboard

void print_array(int arr[], int size);
//pre-condition: The arr has actual size that is greater than or equal to size
//post-condition: arr[0], ..., arr[size-1] is printed to screen with 5 elements per line

int linear_search (int arr[], int size, int key);
//pre condition: arr has given size
//post-condition: The index of first occurrence of key in arr is returned. If the key cannot be found in arr, -1 is returned

void select_sort(int arr[], int size);
//pre-condition: arr has given size
//post-condition: the elements in arr are rearranged from least to largest.

void insert_sort (int arr[], int size);
//pre-condition: arr has given size
//post-condition: the elements in arr are rearranged from least to largest

void bubble_sort(int arr[], int size);
//pre-condition: arr has given size
//post-condition: the elements in arr are rearranged from least to largest

void menu ();
//pre-condition: takes no arguments
//post-condition: prints a menu for the user to select which method from

#include <iostream>

using namespace std;


int main() 
{
	int choice;
	int a[9];
	
	do
	{
		menu();
		cout << "Enter you choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
			{
				fill_array(a,9);
				cout << "Enter the key you want to search: ";
				int key;
				cin >> key;
				int index = linear_search(a, 9, key);
				if (index == -1)
					cout << "The key " << key << " is not in array\n";
				else
					//possible error
					cout << "The key " << key << " is #" << (index + 1) << " element in array\n";
				break;
			}
			case 2:
				{
					fill_array(a,9);
					select_sort(a,9);
					cout << "After sort, the array is:\n";
					print_array(a,9);
					break;
				}
			case 3:
				{
					fill_array(a,9);
					insert_sort(a,9);
					cout << "After sort, the array is :\n";
					print_array(a,9);
					break;
				}
			case 4:
				{
					fill_array(a,9);
					bubble_sort(a,9);
					cout << "After sort< the array is:\n";
					print_array(a,9);
					break;
				}
			case 5:
				{
					cout << "Thank you for using the array functions\n";
					break;
				}
			default:
				{
					cout << "Wrong choice. Please choose from menu: ";
					break;
				}
		}
	} while (choice != 5);
	
	return 0;
}



void fill_array (int arr[], int size)
{
	cout << "Please enter " << size << " digits to add into the array"  << endl; 
	for (int i = 0; i < size; i++) 
	{
		cin >> arr[i]; //takes user input till the array reaches its limit.
	}
}

void print_array(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " " << endl; //loop through array printing its elements
	}

}

int linear_search (int arr[], int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		//if the key is found in the array return it.
		if (arr[i] == key)
		{
			return i;
		}
	}
	//in the event the key is not found, -1 is returned.
	return -1;

}

void select_sort(int arr[], int size)
{
	int minimal;
	int i;
	int j;
	int temp;


	for (i = 0; i < size-1; i++)
	{
		//current minimal value being evaluated
		minimal = i;
		for (j = i+1; j < size; j++)
		{
			if (arr[j] < arr[minimal])
			{
				minimal = j;
			}
		}
		//used to swap values
		if (minimal != i) 
		{
			temp = arr[i];
			arr[i] = arr[minimal];
			arr[minimal] = temp;
		}
	}
}

void insert_sort (int arr[], int size)
{
	int j;
	int temp;

	for (int i = 0; i < size; i++)
	{
		j = i;

		while (j > 0 && arr[j] < arr[j-1])
		{
			//swaps values 
			temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
	}

}

void bubble_sort(int arr[], int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			// iv the previous element is greater than the next
			if (arr[j] > arr[j+1])
			{
				//swaps values
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void menu ()
{
	cout << "*******************************" << endl;
	cout << "SORT AND SEARCH\n" << endl;
	cout << "1) Linear Search" << endl;
	cout << "2) Select Sort" << endl;
	cout << "3) Insert Sort" << endl;
	cout << "4) Bubble Sort" << endl;
	cout << "5) Exit" << endl;

}
