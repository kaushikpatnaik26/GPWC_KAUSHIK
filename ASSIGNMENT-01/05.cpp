#include <iostream>
using namespace std;
void Cube(double &y)
{
    y = y * y * y;
}
int main()
{
    double g = 4.0;
    Cube(g);
    cout << g << endl;
    return (0);
}

 
/*
output: 64

g is initialized as 4.0.
Cube(g); is called, and since g is passed by reference, y refers directly to g.
Inside Cube(), y = 4.0 * 4.0 * 4.0 = 64.0, which updates g to 64.0.
cout << g << endl; prints 64.

*/