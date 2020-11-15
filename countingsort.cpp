/* 
   Dong Lin
   CSCI 115 - 1 PM Lab
   Lab 5 - Counting Sort
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

const int SIZE = 100000;

void countingSort(int *inArr, int size);
void display(int *arr, int size);
void initDisplay(int* arr, int size);

int main()
{
   int* input = new int[SIZE];

   //int input[] = { 2,0,1,0 };
   //int size = sizeof(input) / sizeof(input[0]);

   //initDisplay(input, size);

   srand(time(NULL));

   for (int i = 0; i < SIZE; i++)
   {
      input[i] = rand() % (SIZE);
   }

   //display(input, SIZE);

   clock_t t = clock();

   countingSort(input, SIZE);

   t = clock() - t;

   //display(input, SIZE);

   cout << "Time to sort " << SIZE << " integers using counting sort: " 
        << (float) t / CLOCKS_PER_SEC << " seconds." << endl;

   delete[] input;

   return 0;

}

void countingSort(int *inArr, int size)
{
   int max = *max_element(inArr, inArr + size);
   int* outArr = new int[size];
   int* auxArr = new int[max + 1];

   for (int i = 0; i <= max; i++)
   {
      auxArr[i] = 0;
   }


   for (int i = 0; i < size; i++)
   {
      auxArr[inArr[i]]++;
   }

   for (int i = 1; i <= max; i++)
   {
      auxArr[i] += auxArr[i - 1];
   }

   for (int i = size - 1; i >= 0; i--)
   {
      outArr[--auxArr[inArr[i]]] = inArr[i];
   }

   for (int i = 0; i < size; i++)
   {
      inArr[i] = outArr[i];
   }

   delete[] outArr;
   delete[] auxArr;
}

void display(int *arr, int size)
{
   cout << "[ ";
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << ' ';
   }
   cout << ']';

   cout << endl;
}

void initDisplay(int* arr, int size)
{
   vector<int> tmpVec(arr, arr + size);

   cout << "Input Array = ";
   display(arr, size);

   cout << "Expected Output = ";
   sort(tmpVec.begin(), tmpVec.end());

   cout << "[ ";
   for (vector<int>::iterator itr = tmpVec.begin(); itr != tmpVec.end(); itr++)
   {
      cout << *itr << ' ';
   }
   cout << "]" << endl;

   cout << "Initial Auxiliary array= ";
   int max = *max_element(arr, arr + size);
   int auxSize = max + 1;
   int *tmpAux = new int[auxSize];
   for (int i = 0; i < auxSize; i++)
   {
      tmpAux[i] = 0;
   }
   display(tmpAux, auxSize);

   cout << "Auxiliary array after adding the count of each element= ";
   for (int i = 0; i < size; i++)
   {
      tmpAux[arr[i]]++;
   }
   display(tmpAux, auxSize);

   cout << "Auxiliary array after cumulation= ";
   for (int i = 1; i < auxSize; i++)
   {
      tmpAux[i] += tmpAux[i - 1];
   }
   display(tmpAux, auxSize);

   cout << "\nBuilding output array:" << endl;
   int* outArr = new int[size];
   vector<char> cVec(size, 'x');

   for (int i = size - 1; i >= 0; i--)
   {
      static int count = 1;

      cout << "Iteration " << count++ << ':' << endl;
      cVec[tmpAux[arr[i]] - 1] = '0' + arr[i];
      outArr[--tmpAux[arr[i]]] = arr[i];

      cout << "Output array= ";
      cout << "[ ";
      for (vector<char>::iterator itr = cVec.begin(); itr != cVec.end(); itr++)
      {
         cout << *itr << ' ';
      }
      cout << "]" << endl;

      cout << "Auxiliary array=";
      display(tmpAux, auxSize);
   }

   delete[] tmpAux;
   delete[] outArr;

   cout << endl;
}