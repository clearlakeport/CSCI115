/* Lab 6
   Dong Lin */
   
#include <iostream>
#include <ctime>

const int SIZE = 2000000;

using namespace std;

void quicksort(int *arr, int left, int right);
void quicksortR(int *arr, int left, int right);
void quicksortM(int *arr, int left, int right);
int partitions(int *arr, int low, int high);
int randomPart(int *arr, int low, int high);
int medianPart(int *arr, int low, int high);
void swap(int &lhs, int &rhs);
int choosePivot();


int main()
{
    int *inputArr = new int[SIZE];
    int choice = 3;

    srand(time(NULL));

    choice = choosePivot();

    for (int i = 0; i < SIZE; i++)
    {
        inputArr[i] = rand() % INT_MAX;
    }


    /*cout << "Original Array: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << inputArr[i] << " ";
    }*/

    time_t t = clock();
    if (choice == 2)
        quicksortR(inputArr, 0, SIZE - 1);
    else if (choice == 3)
        quicksortM(inputArr,0, SIZE - 1);
    else
        quicksort(inputArr,0,SIZE - 1);
    t = clock() - t;


    cout << endl;
    /*cout << "Sorted Array: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << inputArr[i] << " ";
    }*/
    switch (choice)
    {
        case 1: cout << "Using first element on " << SIZE << " integers: ";
                cout << (float) t / CLOCKS_PER_SEC<< " seconds." << endl;
                break;
        case 2: cout << "Using random element on " << SIZE << " integers: ";
                cout << (float) t / CLOCKS_PER_SEC << " seconds." << endl;
                break;
        case 3: cout << "Using the median on " << SIZE << " integers: ";
                cout << (float) t / CLOCKS_PER_SEC << " seconds." << endl;
                break;
    }


    delete [] inputArr;

    return 0;
}

void quicksort(int *arr, int left, int right)
{
    int q;

    if (left < right)
    {
        q = partitions(arr, left, right);
        quicksort(arr, left, q-1);
        quicksort(arr, q + 1, right);
    }
}

void quicksortR(int *arr, int left, int right)
{
    int q;

    if (left < right)
    {
        q = randomPart(arr, left, right);
        quicksortR(arr, left, q-1);
        quicksortR(arr, q + 1, right);
    }
}

void quicksortM(int *arr, int left, int right)
{
    int q;

    if (left < right)
    {
        q = medianPart(arr, left, right);
        quicksortM(arr, left, q-1);
        quicksortM(arr, q + 1, right);
    }
}

int partitions(int *arr, int low, int high)
{

    int pivot = arr[low];

    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (arr[j] > pivot)
            j--;
        while (arr[i] < pivot)
            i++;

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++; j--;
        }

    }

    swap(arr[low], arr[j]);

    return j;
}

void swap(int &lhs, int &rhs)
{
    int temp;

    temp = lhs;
    lhs = rhs;
    rhs = temp;

}

int choosePivot()
{
    int pivotPos = 0, choice, median;

    cout << "Choose the Pivot for quicksort: " << endl;
    cout << "1. for first element" << endl;
    cout << "2. for a random element" << endl;
    cout << "3. for median of first, middle, and last element" << endl;


    cin >> choice;

    return choice;
}

int randomPart(int *arr, int low, int high)
{
    int rIndex = rand() % (high - low) + low;
    swap(arr[low], arr[rIndex]);

    return partitions(arr, low, high);

}

 int medianPart(int *arr, int low, int high)
{
    int median = (high - low) / 2 + low;
    swap(arr[low], arr[median]);

    return partitions(arr, low, high);
}
