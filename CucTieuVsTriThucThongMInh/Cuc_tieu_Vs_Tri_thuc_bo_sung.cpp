#include "iostream"
#include <list>
using namespace std;
int a[100][100],n,c[100],b[100][100],h[100],f[100];
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
void getChildS(int s)
{
    for (int j=1; j<=n; j++)
    {
        if (a[s][j]>0)
        {
            int G,F;
            G=c[s]+a[s][j];
            F=G+h[s];
            if (checkValueInLList(Mo,j)&& checkValueInLList(Dong,j))
            {
                Mo.push_front(j);
                c[j]=G;
                f[j]=F;
            }
            else if (f[j]>F)
            {
                Mo.push_front(j);
                c[j]=G;
                f[j]=F;
            }
        }
    }
}
int getMo(list<int> &l)
{
    list <int> :: iterator it;
    int index=l.front();
    int minn=f[l.front()];
    for(it = l.begin(); it != l.end(); ++it)
    {
        if (minn>f[*it])
        {
            minn=f[*it];
            index=*it;
        }
    }
    return index;
}
int main()
{
    //nhap input
    cout<<"Nhap so dinh cua do thi: ";
    cin>>n;
    //tao gia tri mac dinh cho mang b va a
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            b[i][j]=0;
            c[i]=0;
        }
    }
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
        cout<<"Khoang cach tu dinh "<<l<<" den dinh "<<v<<" la: ";
        cin>>a[l][v];
        a[v][l]=a[l][v];
    }
    int t,z,s;
    cout<<"Dinh bat dau: ";
    cin>>t;
    cout<<"Dinh ket thuc: ";
    cin>>z;
    cout<<"Nhap tap h[n]:"<<endl;
    for (int i=1; i<=n; i++)
    {
        cout<<"Nhap h["<<i<<"]: ";
        cin>>h[i];
    }
    Mo.push_front(t);
    while (!Mo.empty())
    {
        s=getMo(Mo);
        Mo.remove(s);
        Dong.push_back(s);
        if (s==z)
        {
            cout<<"Tap dong:";
            showlist(Dong);
            cout<<"thanh cong";
            return 0;
        }
        getChildS(s);
    }
    cout<<"khong thanh cong";
    cout<<endl;
    showlist(Dong);
    return 0;
}

