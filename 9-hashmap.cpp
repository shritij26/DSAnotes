#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    //creation
    unordered_map<string, int> m;

    //insertion
    pair<string, int> p = make_pair("Virat", 18);
    m.insert(p);
    m.insert(make_pair("Dhoni", 7));
    m.insert(make_pair("Rohit", 45));

    //searching
    cout << m["Virat"] << endl; 

    //erasing
    m.erase("Dhoni");
    cout << m["Dhoni"] << endl; // This will return 0 since "Raman" is erased

    m.insert(make_pair("Bumrah", 93));

    //iterator
    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end()) 
    {
        cout << it->first << " " << it->second << endl; //no specific order
        it++;
    }
}

//                  YEH PHIR SE REVISE WITH LOVE BABBAR ND REFER OTHER RESOURCES TOO

