#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr;
    // add element at the last
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);

    // size of the arr = number of elements
    cout << arr.size() << endl; // 9
    // The amount of space reserved in memory
    cout << arr.capacity() << endl; // 16

    // delete element from the last
    arr.pop_back();

    // print the arr
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    // clear the arr
    arr.clear();

    // size == capacity
    arr.shrink_to_fit();

    // add by index
    vector<int> arr2(2); // size of the arr
    arr2[0] = 10;
    arr2[1] = 20;

    for (auto x : arr2)
    {
        cout << x << " ";
    }
    cout << endl;

    // Modify the values
    arr2[1] = 30;

    for (auto x : arr2)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << *(arr2.begin()) << endl;     // Access to the first item = 10
    cout << *(arr2.begin() + 1) << endl; // Access to the next item = 30

    // add by index
    arr2.insert(arr2.begin() + 2, 20);
    for (auto x : arr2)
    {
        cout << x << " ";
    }
    cout << endl;


    // copy constructer
    vector<int> Test = arr2;
    for (auto x : Test)
    {
        cout << x << " ";
    }
    cout << endl;
    
    // iterator
    std ::vector<int>::iterator it;
    for (it = Test.begin(); it != Test.end(); it++)
    {
        cout<<*it<<" ";
    }
    
}