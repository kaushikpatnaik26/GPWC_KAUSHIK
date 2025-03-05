#include <iostream>
using namespace std;
int x[100];
int main()
{
    cout << x[99] << endl;
}

/*
OUTPUT : 0
Global variables in C++ are automatically initialized to zero.
Uninitialized local variables may have garbage values, but this does not apply to global ones.
Accessing x[99] is valid since the array is of size 100.
*/
