#include <iostream>
#include "Sort/HeapSort.h"
using namespace std;
int main()
{
    vector<int> data = {1,4,3,2,6,8,9,230};
    HeapSort(data);
    for (auto x : data)
    {
        cout << x  << " " ;
    }
    return 0;
}