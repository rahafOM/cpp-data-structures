#include <iostream>
using namespace std;

class MyArrayList
{
    // attributes
    int *arr;
    int size;
    int capacity;

    // expand the array
    void expand()
    {
        capacity *= 2;
        int *arr2 = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            arr2[i] = arr[i];
        }
        delete[] arr;
        arr = arr2;
    }

public:
    // default constructer
    MyArrayList()
    {
        size = 0;
        capacity = 10;
        arr = new int[capacity];
    }
    // add to last
    void addToLast(int element)
    {
        if (isFull())
            expand();
        arr[size] = element;
        size++;
    }
    // add to First
    void addToFirst(int element)
    {
        if (isFull())
            expand();
        for (int i = size; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = element;
        size++;
    }
    // remove first  element
    void removeFirstElement()
    {
        if (isEmpty())
        {
            cout << "array is empty !!";
            return;
        }
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    // remove last element
    void removeLastElement()
    {
        if (isEmpty())
        {
            cout << "array is empty !!";
            return;
        }
        size--;
    }
    // add to index
    void addToIndex(int index, int element)
    {
        if (isFull())
            expand();
        if (index < 0 || index > size)
        {
            cout << "invalid index :(";
            return;
        }
        for (int i = size; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        size++;
    }
    // capacity == size
    void shrinkToFit()
    {
        capacity = size;
        int *arr2 = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            arr2[i] = arr[i];
        }
        delete arr;
        arr = arr2;
    }
    // clear array
    void clear()
    {
        size = 0;
    }
    // get size
    int getSize()
    {
        return size;
    }
    // get capacity
    int getCapacity()
    {
        return capacity;
    }
    // is full ?
    bool isFull()
    {
        return capacity == size;
    }
    // is empty ?
    bool isEmpty()
    {
        return size == 0;
    }
    // print arrayList
    void printArray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // destructer
    ~MyArrayList()
    {
        delete[] arr;
    }
};

int main()
{

    MyArrayList arr;
    arr.addToLast(10);
    arr.addToLast(20);
    arr.addToLast(30);
    arr.addToLast(40);

    cout << arr.isEmpty();
    cout<<endl;
    cout << arr.isFull();
    cout<<endl;

    arr.addToIndex(2, 25);
    arr.shrinkToFit();

    cout << "the size is : " << arr.getSize() << endl;
    cout << "the capacity is : " << arr.getCapacity() << endl;
    cout << "print elements : ";

    arr.printArray();
}