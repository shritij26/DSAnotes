#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool sort(int *a /*could also write a[]*/, int size)//check whether array is sorted
{
    if((size==0)||(size==1))
    return true;
    if(a[0]>a[1])
    return false;
    return sort(a+1, size-1);
}
int sumofarray(int *a, int s)
{
    if(s==1)
    return a[0];
    return a[0]+ sumofarray(a+1,s-1);
}
/*void arrayinput()
{
    int n;
    cin>>n;
    int* arr = new int [n]; 
    for (int i =0; i<n; i++)
    {   
        cout<<"enter "<<i+1<<" element"<<endl;
        cin>>arr[i];
    }    
}*/
int power(int a, int b)//to calculate a^b
{
    if(b==0)
      return 1;
    if(b==1)
      return a;
    int ans = power(a, b/2);
    if(b&1)          //shortcut to check number is odd
      return a*ans*ans;
    else
      return ans*ans;
}
int main()
{
    double a; int b;
    cin>>a>>b;
    cout<<power(a,b);
}
void solve(vector<int> nums, vector<vector<int>>&ans, int index)
{
  if(index >= nums.size())
  {
    ans.push_back(nums);
    return;
  }
  for(int j=index; j<nums.size(); j++)
  {
    swap(nums[index],nums[j]);
    solve(nums, ans, index+1);
    //backtrack
    swap(nums[index],nums[j]);
  }
}