#include <bits/stdc++.h>
using namespace std;
// Using 1 base indexing

class heap
{
public:
    vector<int> arr;
    int size;
    heap()
    {
        size = 0;
        arr.push_back(-1);
    }
    void insert(int x)
    {
        arr.push_back(x);
        size++;
        int i = size;
        while (i > 1)
        {
            int parent = i / 2;
            if (arr[parent] < arr[i])
            {
                swap(arr[parent], arr[i]);
                i = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deletelast()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (2 * i <= size)
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;
            if (left <= size && arr[left] > arr[largest])
            {
                largest = left;
            }
            if (right <= size && arr[right] > arr[largest])
            {
                largest = right;
            }
            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
            {
                return;
            }
        }
    }

    int deleteKey(int key)
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return -1;
        }
        if (key > size)
        {
            cout << "Key not found" << endl;
            return -1;
        }
        int deleted = arr[key];
        arr[key] = arr[size];
        size--;
        int i = key;
        while (2 * i <= size)
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;
            if (left <= size && arr[left] > arr[largest])
            {
                largest = left;
            }
            if (right <= size && arr[right] > arr[largest])
            {
                largest = right;
            }
            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
            {
                return deleted;
            }
        }
    }
};

void heapify(int arr[], int i, int n)
{
    int largest = i;
    int right = 2 * i + 1;
    int left = 2 * i;
    if (left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

void Heapsort(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, i, n);
    }
    for (int i = n; i >= 1; i--)
    {
        swap(arr[1], arr[i]);
        heapify(arr, 1, i - 1);
    }
}

int main()
{
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.deletelast();
    h.deleteKey(2);
    for (int i = 1; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;
    int arr[] = {0, 10, 20, 30, 40, 50};
    Heapsort(arr, 5);
    for (int i = 1; i <= 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}