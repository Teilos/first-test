//DISPLAY 9.5 A Dynamic Array
//Sorts a list of numbers entered at the keyboard.
#include <iostream>
#include <cstdlib>
#include <cstddef>

typedef int* IntArrayPtr;

void fill_array(int a[], int size);
//Precondition: size is the size of the array a.
//Postcondition: a[0] through a[size-1] have been
//filled with values read from the keyboard.

void sort(int a[], int size);
//Precondition: size is the size of the array a.
//The array elements a[0] through a[size-1] have values.
//Postcondition: The values of a[0] through a[size-1] have been rearranged
//so that a[0] <= a[1] <= ... <= a[size-1].
void swap(int &v1, int &v2);
int small(const int a[],int start, int used);
int main( )
{
    using namespace std;
    cout << "This program sorts numbers from lowest to highest.\n";

    int array_size;
    cout << "How many numbers will be sorted? ";
    cin >> array_size;

    IntArrayPtr a;
    // sets a array pointer a for the wew array of array size only pointed to by a t
    a = new int[array_size];// allocates size dynamicly to what ever you want under a pointer
    // this aray is limited only by hardware they are continous 
    //'\t' is a space
/*
    fill_array(a, array_size);
    sort(a, array_size);
*/
    cout << "In sorted order the numbers are:\n";
    for (int index = 0; index < array_size; index++)
    {
    if (index%1000==0 )
        cout << a[index] << " ";
    }
    cout << endl;

    delete [] a;

    return 0;
}

//Uses the library iostream:
void fill_array(int a[], int size)
{
    using namespace std;
    cout << "Enter " << size << " integers.\n";
    for (int index = 0; index < size; index++)
        cin >> a[index];
}

void sort(int a[], int size)
{
	int next;
	for (int index = 0; index < size - 1; index++)
	{
	next = small(a, index, size);
	swap(a[index], a[next]);
	}
}
void swap(int& v1, int& v2)
{
	int temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}
int small(const int a[],int start, int used)
{
	int min = a[start], minindex = start;
	for(int index = start+1; index < used; index++)
	if(a[index] < min)
	{
		min = a[index];
		minindex = index;
	}
	return minindex;
}
     //Any implementation of sort may be used. This may or may not require some 
     //additional function definitions. The implementation need not even know that 
     //sort will be called with a dynamic array. For example, you can use the 
     //implementation in Display 7.12 (with suitable adjustments to parameter names).

