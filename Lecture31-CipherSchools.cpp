#include<bits/stdc++.h>
using namespace std;

class SegmentTree
{
    int *arr;
    int arrSize;
    int *tree;
    int N;

    int getLeftChild(int index)
    {
        retunr 2 * index +1;
    }

    int getRightChild(int index)
    {
        return 2 * index +2;
    }

    void builtTree(int nodeindex, int start, int end)
    {
         if(start == end)
         {
            tree[nodeindex] = arr[start];
         }
         else{
            int mid = start + (end-start)/2;
            int li = getLeftChild(nodeindex);
            int ri = getRightChild(nodeindex);
            builtTree(li, start, mid);
            builtTree(ri, mid+1, end);
         }
    }



    void updateTree(int nodeIndex, int start, int end, int indextoupdate, int delta)
    {
        if(indextoupdate < start || indextoupdate > end)
            return;
        tree[indextoupdate] += delta;
        if(start < end)
        {
            int mid = (start + end)/2;
            int l = getLeftChild(nodeIndex), r = getRightChild(nodeIndex);
            if(start <= indextoupdate && indextoupdate <= mid)
            {
                updateTree(l, start, mid, indextoupdate, delta);
            }
            else{
                updateTree(r, mid +1, end, indextoupdate, delta);
            }
        }
    }



    int getsum(int nodeIndex, int start, int end, const int &qstart, const int &qend)
    {
        if(qstart > end || qend < start)
        {
            return 0;
        }
        else if(qstart <= start && end <= qend)
        {
            return tree[nodeIndex];
        }
        else{
            int mid = (start+end)/2;
            int l = getLeftChild(nodeIndex), r = getRightChild(nodeIndex);
            return getsum(l, start, mid, qstart, qend) + getsum(r, mid +1, end, qstart, qend);
        }
    }



    public:

    SegmentTree(int *a, int size)
    {
        arrSize = size;
        N = 4 * arrSize;

        arr = a;
        tree = new int[N];
        for(int i = 0; i < N; i++)
        {
            tree[i] = 0;
        }
        builtTree(a, 0, 0, arrSize-1);
    }


    void PrintSegmenttree()
    {
        for(int i = 0; i < N; i++)
        {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};
