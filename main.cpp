#include <iostream>
#include "Sort/BubbleSort.h"
#include "Sort/SelectSort.h"
#include "Sort/InsertSort.h"
#include "Sort/QuickSort.h"
#include "Sort/HeapSort.h"
#include "Sort/BinarySearch.h"
using namespace std;
int main1()
{
    vector<int> data = {4,3,2,1,8,9};
    cout << BinarySearch(data,3) ;
}