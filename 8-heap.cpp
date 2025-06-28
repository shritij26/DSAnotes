#include <iostream>
#include <queue> //for STL priority queue
using namespace std;

class heap
{
    public:
    int arr[100];
    int size;

    heap() //constructor
    {
        arr[0] = -1; //to make the index start from 1
        size = 0;
    }

    //in max heap, the parent node is always greater than or equal to its child nodes
    void insert(int val) //max heap insertion with O(log n) time complexity
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletion()
    {
        if (size == 0) //if heap is empty
        {
            cout << "Heap is empty" << endl;
            return;
        }
        //step 1: put the last element at the root
        arr[1] = arr[size];
        //step 2: remove the last element
        size--;

        //step 3: take the root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftChildIndex = 2 * i;
            int rightChildIndex = 2 * i + 1;
            if( leftChildIndex < size && arr[i] < arr[leftChildIndex])
            {
                swap(arr[i], arr[leftChildIndex]);
                i = leftChildIndex;
            }
            else if (rightChildIndex < size && arr[i] < arr[rightChildIndex])
            {
                swap(arr[i], arr[rightChildIndex]);
                i = rightChildIndex;
            }
            else
            {
                return; 
            }
        }
    }


    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";  
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i ) //to convert an array into a max heap (HEAPIFY ALGO.)
{
    int largest = i; 
    int leftChild = 2 * i; //had there be no -1 at index 0, it would have been 2*i + 1
    int rightChild = 2 * i + 1; //had there be no -1 at index 0, it would have been 2*i + 2
    if (leftChild < n && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }
    if (rightChild < n && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); //recursive call to heapify the affected subtree
    }
}

/* heap sort is a method where we first convert the array into a max heap and 
then extract the maximum element from the heap and then give it
its position, repeat this step repeatedly to sort the array*/

void heapsort(int arr[], int n) //this is for max heap only and time complexity is O(n log n)
{
    int size = n;
    while(size > 1)
    {
        swap(arr[1], arr[size]); //swap the root with the last element
        size--; //reduce the size of the heap
        heapify(arr, size + 1, 1); //heapify the reduced heap
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    // Output: 55 54 53 50 52
    h.deletion();
    h.print();
    // Output: 54 52 53 50 
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n =5;
    heapify(arr, 6, 1); 
    for (int i = n/2; i > 0; i--) //heapify the array from the last non-leaf node to the root
    {
        heapify(arr, 6, i);
    }
    cout << "Array after heapify: ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    heapsort(arr, n);
    cout << "\nArray after heapsort: "; 
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    /* SUPRISE SUPRISE, instead of implemnting, we can use heap directly as it present in queue STL */

    cout << endl << endl << "Using STL priority queue: " << endl;
    priority_queue<int> pq; //max heap by default
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "Element at Top: " << pq.top() << endl; //returns the maximum element

    //min heap using STL
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(2);        
    minHeap.push(5);
    minHeap.push(3);

    cout << "Element at Top : " << minHeap.top() << endl; //returns the minimum element
}

  
    