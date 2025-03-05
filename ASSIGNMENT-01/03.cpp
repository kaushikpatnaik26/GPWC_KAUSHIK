#include <iostream>
using namespace std;
int x = 1;
void fun()
{
    int x = 2;
    {
        int x = 3;
        cout << ::x << endl;
        //cout << x << endl;

    }
}
int main()
{
    fun();
    return 0;
}

//output: 1
// x is decalred as 1 globally before void fun() function.
// ::x accesses the global variable x, ignoring local variables.
// if it was cout << x << endl; The precedence to the inner local variable woul've been given and
// output would have been 3
