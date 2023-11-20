#include <iostream>
using namespace std;
template <typename PQ>
class Priority_Queue
{
    PQ *pq;
    int len = 0, mem_size;
    int Parent(int i)
    {
        return i/2;
    }
    int Left(int i)
    {
        return 2*i;
    }
    int Right(int i)
    {
        return 2*i+1;
    }

public:
    Priority_Queue()
    {
        pq = new PQ[50];
        mem_size = 50;
    }
    void Insert(PQ x)
    {
        if (mem_size == len + 1)
        {
            PQ *tem;
            mem_size *= 2;
            tem = new PQ[mem_size];
            for (int i = 1; i <= len; i++)
            {
                tem[i] = pq[i];
            }
            delete[] pq;
            pq = tem;
        }
        pq[++len] = x;
        int i = len;
        while (i >= 1 && pq[i] > pq[Parent(i)])
        {
             swap(pq[i], pq[Parent(i)]);
             i = Parent(i);
        }
    }
    PQ FindMax()
    {
        return pq[1];
    }
    PQ ExtractMax()
    {
       // if (len == 0) return -999999;
        if (len == 1) return pq[--len];
        PQ m = pq[1];
        swap(pq[1],pq[len]);
        len--;
        MaxHeapify(1);
        return m;
    }
    void MaxHeapify(int i)
    {
        int l = Left(i);
        int r = Right(i);
        int largest = i;
        if (l <= len && pq[l] > pq[i]) largest = l;
        if (r <= len && pq[r] > pq[largest]) largest = r;
        if (largest != i)
        {
            swap(pq[i], pq[largest]);
            MaxHeapify(largest);
        }
    }
    void IncreaseKey(int i, PQ newKey)
    {
        if (pq[i] > newKey)
        {
            cout << "New key is not larger than the previous key" << endl;
            return;
        }
        pq[i] = newKey;
        cout<<"Key increased!"<<endl;
        while (i >= 1 && pq[i] > pq[Parent(i)])
        {
            PQ t = pq[i];
            pq[i] = pq[Parent(i)];
            pq[Parent(i)] = t;
            i = Parent(i);
        }
    }
    void DecreaseKey(int i, PQ newKey)
    {
        if (pq[i] < newKey)
        {
            cout << "New key is not smaller than the previous key" << endl;
            return;
        }
        pq[i]=newKey;
        cout<<"Key decreased!"<<endl;
        MaxHeapify(i);
    }
    void Print()
    {
        int c=0,d=1;
        cout<<"No of elements: "<<len<<endl;
        for(int i=1;i<=len;i++)
        {
            cout<<pq[i]<<"  ";
            c++;
            if(c==d)
            {
                d*=2;
                c=0;
                cout<<endl;
            }
        }
        cout<<endl;
    }
    void Sort()
    {
        int l=len;
        while(len)
        {
            ExtractMax();
        }
        int c=0,d=1;
        cout<<"No of elements: "<<l<<endl;
        for(int i=1;i<=l;i++)
        {
            cout<<pq[i]<<"  ";
            c++;
            if(c==d)
            {
                d*=2;
                c=0;
                cout<<endl;
            }
        }
        cout<<endl;
    }
    int size()
    {
        return len;
    }
};