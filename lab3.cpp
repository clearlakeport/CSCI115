/* Dong Lin
   Lab 3 - 1 PM
*/
#include <iostream>
#include <ctime>
#include <limits>
#include <algorithm>

using namespace std;

const int SIZE = 150000;

void selectionSort(int arr[], int size);
void mergeSort(int *arr, int left, int right);
void merge(int *arr, int l, int m, int r);


int main()
{
    int randomArr1[SIZE], randomArr2[SIZE], msArr[SIZE];
    clock_t t;

    srand(time(NULL));

    for(int i = 0; i < SIZE; i++)
    {
        randomArr1[i] = rand() % INT_MAX;
        randomArr2[i] = rand() % INT_MAX;
    }
/*
    cout << "Randomized array 1:" << endl;
    for (int i = 0; i < SIZE; i++ )
        cout << randomArr1[i] << ' ';
    cout << endl; 
*/


    // selection sort randomized array
    cout << ">> Selection Sort <<: " << endl;
    t = clock();
    selectionSort(randomArr1, SIZE);
    t = clock() - t;
/*
    cout << "Sorted randomized array: " << endl;
    for (int i = 0; i < SIZE; i++ )
        cout << randomArr1[i] << ' ';
    cout << endl; 
*/
    cout << "Selection Sort of " << SIZE << " randomized int takes: " 
         << (double)t / CLOCKS_PER_SEC << " seconds" << endl; 

    // selection sort sorted array
    t = clock();
    selectionSort(randomArr1, SIZE);
    t = clock() - t;
    cout << "Selection Sort of " << SIZE << " sorted int takes: " 
         << (double)t / CLOCKS_PER_SEC << " seconds" << endl; 

    // selection sort half sorted array
    for (int i = SIZE / 2 + 1, j = SIZE - 1 ; i < j; i++, j--)
    {
        int tmp = randomArr1[i];
        randomArr1[i] = randomArr1[j];
        randomArr1[j] = tmp; 
    }

    t = clock();
    selectionSort(randomArr1, SIZE);
    t = clock() - t;
    cout << "Selection Sort of " << SIZE << " half sorted int takes: " 
         << (double)t / CLOCKS_PER_SEC << " seconds" << endl; 
  

    // selection sort reversed array
    int size = sizeof(randomArr1) / sizeof(randomArr1[0]);
    reverse(randomArr1, randomArr1 + size);

    t = clock();
    selectionSort(randomArr1, SIZE);
    t = clock() - t;
    cout << "Selection Sort of " << SIZE << " reversed int takes: " 
         << (double)t / CLOCKS_PER_SEC << " seconds" << endl; 

/*
    for (int i = 0; i < SIZE; i++ )
        cout << randomArr1[i] << ' ';
    cout << endl; 
*/

/*
    cout << "Randomized array 2:" << endl;
    for (int i = 0; i < SIZE; i++ )
        cout << randomArr2[i] << ' ';
    cout << endl; 
*/
    cout << ">> Merge Sort <<: " << endl;
    // merge sort randomized array
    t = clock();
    mergeSort(randomArr2, 0, SIZE - 1);
    t = clock() - t;
/*
    cout << "Sorted randomized array: " << endl;
    for (int i = 0; i < SIZE; i++ )
        cout << randomArr2[i] << ' ';
    cout << endl; 
*/
    cout << "Merge Sort of " << SIZE << " randomized int takes: " 
         << (double)t / CLOCKS_PER_SEC << " seconds" << endl; 


    // merge sort sorted array
    t = clock();
    mergeSort(randomArr2, 0, SIZE - 1);
    t = clock() - t;
    cout << "Merge Sort of " << SIZE << " sorted int takes: " 
         << (double)t / CLOCKS_PER_SEC << " seconds" << endl; 

    // merge sort half sorted array
    for (int i = SIZE / 2 + 1, j = SIZE - 1 ; i < j; i++, j--)
    {
        int tmp = randomArr2[i];
        randomArr2[i] = randomArr2[j];
        randomArr2[j] = tmp; 
    }
    t = clock();
    mergeSort(randomArr2, 0, SIZE -1);
    t = clock() - t;
    cout << "Merge Sort of " << SIZE << " half sorted int takes: " 
         << (double)t / CLOCKS_PER_SEC << " seconds" << endl; 

    // sort reversed array
    size = sizeof(randomArr2) / sizeof(randomArr2[0]);
    reverse(randomArr2, randomArr2 + size);

    t = clock();
    mergeSort(randomArr2, 0, SIZE - 1);
    t = clock() - t;
    cout << "Merge Sort of " << SIZE << " reversed int takes: " 
         << (double)t / CLOCKS_PER_SEC << " seconds" << endl; 

/*
    for (int i = 0; i < SIZE; i++ )
        cout << randomArr2[i] << ' ';
    cout << endl;  
*/
    
    return 0;
}

void selectionSort(int arr[], int size)
{
    int i, j, MIN, index, temp;
    for (i = 0; i < size - 1; i++)
    {
        MIN = arr[i];
        index = i;
        for (j = i + 1; j < size; j++)
        {
            if (MIN > arr[j])
            {
                MIN = arr[j];
                index = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

void mergeSort(int arr[], int left, int right)
{
    int middle; 

    if (left < right)
    {
        middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1,right);
        merge(arr, left, middle, right);
    }
}

void merge(int original[], int left, int middle, int right)
{
    int i,j,k;

    int arr1 = middle - left + 1;
    int arr2 = right - middle;

    int *fPtr = new int[arr1];
    int *sPtr = new int[arr2];


    for (i = 0; i < arr1; i++)
        fPtr[i] = original[left+i];
    
    for (j = 0; j < arr2; j++)
        sPtr[j] = original[middle + 1 + j];

    i = j = 0;
    k = left;

    while (i < arr1 && j < arr2)
    {
        if (fPtr[i] <= sPtr[j])
        {
            original[k] = fPtr[i];
            i++;
        }
        else
        {
            original[k] = sPtr[j];
            j++;
        }
        k++;
    }

    while (i < arr1)
    {
        original[k] = fPtr[i];
        k++;
        i++;
    }

    while (j < arr2)
    {
        original[k] = sPtr[j];
        k++;
        j++;
    }

    delete [] fPtr;
    delete [] sPtr;
}