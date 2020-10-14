#include "iostream"
#include <list>
using namespace std;
int a[100][100],n,c[100];
list<int> Mo,Dong,ChildS;
void showlist(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}
bool checkValueInLList(list<int> g, int value)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
    {
        if (*it==value)
        {
            return false;
            break;
        }
    }
    return true;
}
list<int> getChildS(list <int> &g,int s)
{
    g.clear();
    for (int j=1; j<=n; j++)
    {
        if (a[s][j]>0 && checkValueInLList(Mo,j)&& checkValueInLList(Dong,j))
        {
            g.push_back(j);
            c[j]=c[s]+1;
        }
    }
    return g;
}
void appendToFrontList(list<int> a, list<int> &b)
{
    list <int> :: iterator it;
    for(it = a.begin(); it != a.end(); ++it)
    {
        b.push_front(*it);
    }
}
void appendToBackList(list<int> a, list<int> &b)
{
    list <int> :: iterator it;
    for(it = a.begin(); it != a.end(); ++it)
    {
        b.push_back(*it);
    }
}
int main()
{
    //nhap input
    cout<<"Nhap so dinh cua do thi: ";
    cin>>n;
    //tao gia tri mac dinh cho mang va a
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            if (i!=j)
            {
                a[i][j]=-1;
            }
            else
                a[i][j]=0;
        }
    int k;
    cout<<"Do thi co may canh: ";
    cin>>k;
    for (int i=1; i<=k; i++)
    {
        int l,v;
        cout<<"Nhap cap thu "<<i<<": ";
        cin>>l>>v;
        a[l][v]=1;
        //a[v][l]=a[l][v];
    }
    int t,z,ds,s;
    cout<<"Dinh bat dau: ";
    cin>>t;
    c[t]=0;
    cout<<"Dinh ket thuc: ";
    cin>>z;
    cout<<"Do sau ban dau:";
    cin>>ds;
    Mo.push_front(t);
    while (!Mo.empty())
    {
        s=Mo.front();
        Mo.pop_front();
        Dong.push_back(s);
        if (s==z)
        {
            cout<<"Tap dong:";
            showlist(Dong);
            cout<<"thanh cong";
            return 0;
        }
        if (!getChildS(ChildS,s).empty())
        {
            if (c[s]<=ds-1 && c[s]>=0)
            {
                appendToFrontList(ChildS,Mo);
            }
            if (c[s]==ds)
            {
                appendToFrontList(ChildS,Mo);
            }
            if (c[s]==ds+1)
            {
                ds=ds+ds;
                if (ds==1)
                {
                    appendToBackList(ChildS,Mo);
                }
                else
                {
                    appendToFrontList(ChildS,Mo);
                }
            }
        }
    }
    cout<<"khong thanh cong";
    cout<<endl;
    showlist(Dong);
    return 0;
}
