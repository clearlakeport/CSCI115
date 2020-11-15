/*
   Dong Lin
   CSCI 115 - 1 PM Lab
   Lab 5 - Radix Sort
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

const int SIZE = 100000;
const int BASE = 10;

void radixSort(int* inArr, int size);
void display(int* arr, int size);
void initDisplay(int* arr, int size);

int main()
{
   int* input = new int[SIZE];

   srand(time(NULL));

   for (int i = 0; i < SIZE; i++)
   {
      input[i] = rand() % (SIZE + 1);
   }

   //int input[] = { 11, 5, 240 };
   //int size = sizeof(input) / sizeof(input[0]);
   //initDisplay(input, size);

   clock_t t = clock();

   radixSort(input, SIZE);

   t = clock() - t;

   //cout << endl;
   //display(input, size);

   cout << "Time to sort " << SIZE << " integers using radix sort: "
      << (float)t / CLOCKS_PER_SEC << " seconds." << endl;

   delete[] input;

   return 0;

}

void radixSort(int* inArr, int size)
{
   int max = *max_element(inArr, inArr + size);

   int numDigits = 1, tmp = 10;
   while (max / tmp > 0)
   {
      numDigits++;
      tmp *= 10;
   }

   int* outArr = new int[size];
   int pos = 1;

   for (int i = 1; i <= numDigits; i++)
   {
      /*cout << "iteration " << i << endl;
      cout << "Input Array= ";
      display(inArr, size);*/

      int auxArr[BASE] = { 0 };

      for (int j = 0; j < size; j++)
      {
         auxArr[inArr[j] / pos % 10]++;
      }

      //cout << "Auxiliary affary after adding the count of the units digits = ";
      //display(auxArr, 10);

      for (int j = 1; j < BASE; j++)
      {
         auxArr[j] += auxArr[j - 1];
      }

      //cout << "Auxiliary array after cumulation= ";
      //display(auxArr, 10);

      for (int j = size - 1; j >= 0; j--)
      {
         outArr[--auxArr[inArr[j] / pos % 10]] = inArr[j];
      }

      //cout << "Output array= ";
      //display(outArr, size);
      for (int i = 0; i < size; i++)
      {
         inArr[i] = outArr[i];
      }

      pos *= 10;
   }

   delete[] outArr;
}


void display(int* arr, int size)
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
   int tmpAux[BASE] = { 0 };
   display(tmpAux, BASE);

   cout << endl;
}