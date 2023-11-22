#include <iostream>
using namespace std;
template<typename T>
struct X
{
    int t;
    T val;
};

template<typename T>
class Priority_Queue
{
    X<T> *pq;
    int len = 0, mem_size;

    int Parent(int i)
    {
        return i / 2;
    }

    int Left(int i)
    {
        return 2 * i;
    }

    int Right(int i)
    {
        return 2 * i + 1;
    }

public:
    Priority_Queue()
    {
        pq = new X<T>[50];
        mem_size = 50;
    }

    void Insert(X<T> x)
    {
        if (mem_size == len + 1)
        {
            X<T> *tem;
            mem_size *= 2;
            tem = new X<T>[mem_size];
            for (int i = 1; i <= len; i++)
            {
                tem[i] = pq[i];
            }
            delete[] pq;
            pq = tem;
        }
        pq[++len] = x;
        int i = len;
        while (i >= 1 && pq[i].t > pq[Parent(i)].t)
        {
            swap(pq[i], pq[Parent(i)]);
            i = Parent(i);
        }
    }

    X<T> FindMax()
    {
        return pq[1];
    }

    X<T> ExtractMax()
    {
        if (len == 1) return pq[--len];
        X<T> m = pq[1];
        swap(pq[1], pq[len]);
        len--;
        MaxHeapify(1);
        return m;
    }

    void MaxHeapify(int i)
    {
        int l = Left(i);
        int r = Right(i);
        int largest = i;
        if (l <= len && pq[l].t > pq[i].t) largest = l;
        if (r <= len && pq[r].t > pq[largest].t) largest = r;
        if (largest != i)
        {
            swap(pq[i], pq[largest]);
            MaxHeapify(largest);
        }
    }

    void IncreaseKey(int i, X<T> newKey)
    {
        if (pq[i].t > newKey.t)
        {
            cout << "New key is not larger than the previous key" << endl;
            return;
        }
        pq[i] = newKey;
        cout << "Key increased!" << endl;
        while (i >= 1 && pq[i].t > pq[Parent(i)].t)
        {
            X<T> t = pq[i];
            pq[i] = pq[Parent(i)];
            pq[Parent(i)] = t;
            i = Parent(i);
        }
    }

    void DecreaseKey(int i, X<T> newKey)
    {
        if (pq[i].t < newKey.t)
        {
            cout << "New key is not smaller than the previous key" << endl;
            return;
        }
        pq[i] = newKey;
        cout << "Key decreased!" << endl;
        MaxHeapify(i);
    }

    void Print()
    {
        int c = 0, d = 1;
        cout << "No of elements: " << len << endl;
        for (int i = 1; i <= len; i++)
        {
            cout << pq[i].val << "  ";
            c++;
            if (c == d)
            {
                d *= 2;
                c = 0;
                cout << endl;
            }
        }
        cout << endl;
    }

    void Sort()
    {
        int l = len;
        while (len)
        {
            ExtractMax();
        }
        int c = 0, d = 1;
        cout << "No of elements: " << l << endl;
        for (int i = 1; i <= l; i++)
        {
            cout << pq[i].val<< "  "; 
            c++;
            if (c == d)
            {
                d *= 2;
                c = 0;
                cout << endl;
            }
        }
        cout << endl;
    }
};

template<typename T>
class Stack
{
    int l = 0;
    Priority_Queue<T> a;

public:
    void push(T x)
    {
        X<T> p;
        p.val = x;
        p.t = l;
        a.Insert(p);
        l++;
    }

    T pop()
    {
        X<T> p= a.ExtractMax();
        l--;
        return p.val;
    }

    int size()
    {
        return l;
    }
};


int main()
{
    Stack<int> stk;
    while(true)
    {
        cout<<"1.push\n2.pop\n3.size\n4.exit."<<endl;
        int c;
        cout<<"Enter your choice : ";
        cin>>c;
        if(c==1)
        {
            int d;
            cout<<"Enter the element : ";
            cin>>d;
            stk.push(d);
        }
        else if(c==2)
        {
            if(stk.size())
            {
                cout<<"The popped element : "<<stk.pop()<<endl;
            }
            else 
                cout<<"The stack is empty ."<<endl;
        }
        else if(c==3)
        {
            cout<<"The size of the stack : "<<stk.size()<<endl;
        }
        else if(c==4)
        {
            break;
        }
        else 
        {
            cout<<"Wrong option! Try again ."<<endl;
        }
    }
    return 0;
}