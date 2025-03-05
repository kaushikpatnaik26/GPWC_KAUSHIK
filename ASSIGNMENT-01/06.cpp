#include <iostream>
using namespace std;
class Sample
{
public:
    Sample(int x = 10)
    {
        cout << "Value: " << x << endl;
    }
};
int main()
{
    Sample obj;
    return 0;
}

/*
OUTPUT: Value: 10s 
Sample is a class with a constructor that takes an integer parameter x, which has a default value of 10.
When an object of Sample is created, the constructor is called, and it prints "Value: " followed by the value of x  
*/