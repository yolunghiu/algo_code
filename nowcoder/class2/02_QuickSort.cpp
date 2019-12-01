#include <iostream>

using namespace std;

class QuickSort
{
public:
    static void quickSort(int *arr, int l, int r)
    {
        if (arr == nullptr)
            return;
        if (l < r)
        {
            int res[2];
            partition(arr, l, r, arr[r], res);
            quickSort(arr, l, res[0] - 1);
            quickSort(arr, res[1] + 1, r);
        }
    }

    static void partition(int *arr, int l, int r, int num, int *res)
    {
        int min = l - 1, max = r + 1, cur = l;
        while (cur < max)
        {
            if (arr[cur] < num)
                swap(arr, ++min, cur++);
            else if (arr[cur] == num)
                cur++;
            else
                swap(arr, --max, cur);
        }

        res[0] = min + 1, res[1] = max - 1;
    }

    static void swap(int *arr, int i, int j)
    {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
};

int main()
{
    int arr[] = {3, 2, 1, 5, 6, 4, 3, 9};
    QuickSort::quickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}