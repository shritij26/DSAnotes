#include <iostream>
using namespace std;
int main()
{
    /*
    1D ARRAY CREATIONNN
    
    int n;int i;
    cout<<"enter size";
    cin>>n;
    int* arr = new int [n]; //declare n size array like this, it is stored in heap
    for (i =0; i<n; i++)
    {   cout<<"enter "<<i+1<<" element"<<endl;
        cin>>arr[i];
    }    
    for(i =0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }    
    delete []arr; //always need to delete the data stored in heap
    */
   int r,c;
   cin>>r>>c;
   int** arr = new int* [r]; //2D array creation of and n size
   for(int i = 0; i<r;i++)
   {
    arr[i] = new int [c];
   }

   //erasing data
   for(int i =0; i<r; i++)
   {
    delete [] arr[i];
   }
   delete []arr;
}