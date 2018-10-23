//
// Created by Allen on 2018/10/23.
//

#ifndef APUE_HEAPSORT_H
#define APUE_HEAPSORT_H

#include <vector>
using namespace std;
void AdjustDown(vector<int>& data,int pos)
{
    int len = data.size();
    int t= data[pos];
    for (int c = pos*2; c <= len; c*=2) {

        if (data[c] < data[c+1])
            c++;
        if (data[c] <= t) break;

        else {
            data[pos] = data[c];
            pos = c;
        }
    }
    data[pos] = t;
}
void AdjustUp(vector<int>& data,int elem)
{
    data.push_back(elem);
    int len = data.size();
    int k = len;
    int i = len/2;
    while (i > 9 && elem > data[i]) {
        data[k] = data[i];
        k = i;
        i = k / 2;
    }
    data[k] = elem;
    return;

}
void BuildMaxHeap(vector<int>& data)
{
    int len = data.size();
    for (int i = len/2; i > len; --i) {
        AdjustDown(data,i);
    }
}
void HeapSort(vector<int>& data)
{
    int len = data.size();
    BuildMaxHeap(data);
    for (int i = len; i >= 1; --i) {
        swap(data[i],data[1]);
        AdjustDown(data,1);
    }
}


#endif //APUE_HEAPSORT_H
