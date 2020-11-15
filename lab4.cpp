/*
    Dong Lin
    Lab 4
*/

#include <iostream>
#include <vector>

using namespace std;

class Heap
{
    public:
    vector<int> Arr, outVec;
    Heap();
    Heap(vector<int> arr, int c);

    void printArray();

    //Max heap
    void modifyKeyMax (int n, int i); //Modify index value
    void insert_value_maxHeap (int val); //Adds value at the end of array and calls max_heapify
    void max_heapify(int i); //Maintains the max heap property
    int extract_maximum (); //Return the maximum element in heap and swap last element with first element
    void ascendingHeapSort(); //Prints the array in ascending order 
    void buildMaxHeap(); //Heapifies entire list

    //Min Heap
    void modifyKeyMin (int n, int i); //Modify Index value
    void insert_value_minHeap (int val); // Adds value at the end of array and calls min_heapify
    void min_heapify(int i); //Maintains min heap property
    int extract_minimum (); //Return the minimum element in heap and swap last element with first element
    void descendingHeapSort(); //Prints the array in descending order 
    void buildMinHeap(); //Heapifies entire list

private:
   int choice = 0;

};


int main()
{

   int choice, num, num2;
   vector<int> vec;
   //Heap maxHeap, minHeap;

   cout << "Enter 0 for ascending and 1 for descending order" << endl;
   cin >> choice;
   
   if (choice == 0)
   {
      cout << "input array (-111 to stop): ";
      cin >> num;
      while (num != -111)
      {
         vec.push_back(num);
         cout << "input array (-111 to stop): ";
         cin >> num;
      }
      Heap maxHeap(vec,0);
      cout << "Input element: ";
      cin >> num2;
      maxHeap.insert_value_maxHeap(num2);
      cout << "sorted heap: ";
      maxHeap.ascendingHeapSort();
      maxHeap.printArray();
      cout << "On calling extract maximum: " << maxHeap.extract_maximum() << endl;
      cout << "Sorted heap is" << endl;
      maxHeap.ascendingHeapSort();
      maxHeap.printArray();
   }
   else
   {
      cout << "input array (-111 to stop): ";
      cin >> num;
      while (num != -111)
      {
         vec.push_back(num);
         cout << "input array (-111 to stop): ";
         cin >> num;
      }
      Heap minHeap(vec, 1);
      cout << "Input element: ";
      cin >> num2;
      minHeap.insert_value_maxHeap(num2);
      cout << "sorted heap: ";
      minHeap.descendingHeapSort();
      minHeap.printArray();
      cout << "On calling extract minimum: " << minHeap.extract_minimum() << endl;
      cout << "Sorted heap is" << endl;
      minHeap.descendingHeapSort();
      minHeap.printArray();
   }

    return 0;
}


Heap::Heap()
{
   choice = 0;
}

Heap::Heap(vector<int> original, int choice)
{
   if (choice == 0)
   {
      while (!original.empty())
      {
         Arr.push_back(original.back());
         original.pop_back();
      }
   }
   else if (choice == 1)
   {
      while (!original.empty())
      {
         Arr.push_back(original.back());
         original.pop_back();
      }
   }
   else
      cerr << "Wrong choice!" << endl;
   this->choice = choice;
}

void Heap::printArray()
{
    for (int i = outVec.size() - 1; i >= 0; i--)
    {

        cout << outVec[i] << ' ';
    }
    cout << endl;
}

void Heap::modifyKeyMax(int index, int val)
{
   int tmp;

   Arr[index] = val;
   while ((index > 0) && Arr[index] > Arr[(index - 1) / 2])
   {
      tmp = Arr[index];
      Arr[index] = Arr[(index - 1) / 2];
      Arr[(index - 1) / 2] = tmp;
      index = (index - 1) / 2;
   }
}

void Heap::insert_value_maxHeap(int val)
{
   int n, tmp;

   Arr.push_back(val);
   n = Arr.size() - 1;
   while ((n > 0) && (Arr[n] > Arr[(n - 1) / 2]))
   {
      tmp = Arr[n];
      Arr[n] = Arr[(n - 1) / 2];
      Arr[(n - 1) / 2] = tmp;
      n = (n - 1) / 2;
   }
}

void Heap::max_heapify(int i)
{
   int size = Arr.size();

   if (i > size / 2 - 1 )
      return;

   int largest, lCIndex, rCIndex;


   lCIndex = 2 * i + 1;
   rCIndex = 2 * i + 2;

   largest = i;


   if (lCIndex <= size - 1 && Arr[lCIndex] > Arr[i])
   {
      largest = lCIndex;
   }
   if (rCIndex <= size - 1 && Arr[rCIndex] > Arr[largest])
   {
      largest = rCIndex;
   }
   if (largest != i)
   {

      int tmp = Arr[largest];
      Arr[largest] = Arr[i];
      Arr[i] = tmp;

      max_heapify(largest);
   }


}

int Heap::extract_maximum()
{
   int retVal = Arr[0], tmp;

   tmp = Arr.back();
   Arr.pop_back();
   Arr[0] = tmp;
   max_heapify(0);

   return retVal;
}

void Heap::buildMaxHeap()
{
   for (int lastIndex = Arr.size() / 2 - 1; lastIndex >= 0; lastIndex--)
      max_heapify(lastIndex);
}

void Heap::ascendingHeapSort()
{
   int tmp;
   vector<int> tmpVec;

   tmpVec = Arr;
   outVec.clear();

   buildMaxHeap();

   while (!Arr.empty())
   {
      outVec.push_back(Arr[0]);
      tmp = Arr.back();
      Arr[0] = tmp;
      Arr.pop_back();
      buildMaxHeap();
   }

   Arr = tmpVec;
}

// --- minHeap

void Heap::modifyKeyMin(int index, int val)
{
   int tmp;

   Arr[index] = val;

   while ((index > 0) && Arr[index] < Arr[(index - 1) / 2])
   {
      tmp = Arr[index];
      Arr[index] = Arr[(index - 1) / 2];
      Arr[(index - 1) / 2] = tmp;
      index = (index - 1) / 2;
   }

}
void Heap::insert_value_minHeap(int val)
{
   int n, tmp;

   Arr.push_back(val);
   n = Arr.size() - 1;
   while ((n > 0) && (Arr[n] < Arr[(n - 1) / 2]))
   {
      tmp = Arr[n];
      Arr[n] = Arr[(n - 1) / 2];
      Arr[(n - 1) / 2] = tmp;
      n = (n -1) / 2;
   }  
}

void Heap::min_heapify(int i)
{
   int size = Arr.size();

   if (i < 0)
      return;

   int smallest, lIndex, rIndex;

   lIndex = 2 * i + 1;
   rIndex = 2 * i + 2;

   smallest = i;


   if (lIndex <= size - 1 && Arr[lIndex] < Arr[i])
   {
      smallest = lIndex;
   }
   if (rIndex <= size - 1 && Arr[rIndex] < Arr[smallest])
   {
      smallest = rIndex;
   }
   if (smallest != i)
   {

      int tmp = Arr[smallest];
      Arr[smallest] = Arr[i];
      Arr[i] = tmp;

      min_heapify(smallest);
   }


}

int Heap::extract_minimum()
{
   int retVal = Arr[0];


   Arr[0] = Arr.back();
   Arr.pop_back();
   buildMinHeap();

   return retVal;
}

void Heap::buildMinHeap()
{

   for (int lastIndex = Arr.size() / 2 - 1; lastIndex >= 0; lastIndex--)
      min_heapify(lastIndex);
}

void Heap::descendingHeapSort()
{
   int tmp;
   vector<int> tmpVec;

   buildMinHeap();
   tmpVec = Arr;
   outVec.clear();

   while (!Arr.empty())
   {
      outVec.push_back(Arr[0]);
      tmp = Arr.back();
      Arr[0] = tmp;
      Arr.pop_back();
      buildMinHeap();
   }

   Arr = tmpVec;
}
