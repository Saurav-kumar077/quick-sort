#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
  int pivot = arr[s];
  int count = 0;

  for (int i = s + 1; i <= e; i++)
  {
    if (arr[i] <= pivot)
    {
      count++;
    }
  }

  int pivotIndex = s + count;
  swap(arr[pivotIndex], arr[s]);

  int i = s, j = e;

  while (i < pivotIndex && j > pivotIndex)
  {
    while (i < pivotIndex && arr[i] <= pivot)
    {
      i++;
    }
    while (j > pivotIndex && arr[j] > pivot)
    {
      j--;
    }

    if (i < pivotIndex && j > pivotIndex)
    {
      swap(arr[i++], arr[j--]);
    }
  }

  return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
  if (s >= e)
  {
    return;
  }

  int p = partition(arr, s, e);
  quickSort(arr, s, p - 1);
  quickSort(arr, p + 1, e);
}

int main()
{
  int arr[10] = {3, 5, 1, 8, 8, 2, 4, 6, 6, 6};
  int size = 10;

  quickSort(arr, 0, size - 1);

  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}