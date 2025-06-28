#include <iostream>
using namespace std;
int main()
{
    int a =5;
    int *p = &a;
    char b = 'g';
    char *po = &b; //pointer and variable data types must be same
    cout<<po<<endl;
    cout<<*po<<endl;
}