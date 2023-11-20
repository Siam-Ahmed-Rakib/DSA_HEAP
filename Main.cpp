#include "Heap.cpp"
int main()
{
    Priority_Queue<int> max_pq;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    while(cin>>t)
    {
        if(t==1)
        {
            int x;
            cin>>x;
            max_pq.Insert(x);
        }
        else if(t==2)
        {
            cout<<"Max: "<<max_pq.FindMax()<<endl;
        }
        else if(t==3)
        {
            cout<<"Max: "<<max_pq.ExtractMax()<<" has been extracted."<<endl;
        }
        else if(t==4)
        {
            int i,newkey;
            cin>>i>>newkey;
            max_pq.IncreaseKey(i,newkey);
        }
        else if(t==5)
        {
            int i,newkey;
            cin>>i>>newkey;
            max_pq.DecreaseKey(i,newkey);
        }
        else if(t==6)
        {
            max_pq.Print();
        }
        else if(t==7)
        {
            max_pq.Sort();
            break;
        }
    }
}