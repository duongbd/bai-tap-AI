#include<iostream>
#include"queue_library.h"
#include"link_list_support_graph.h"
#include"stack_library.h"
using namespace std;
int a[1000][1000],n,b[1000][1000];
queue_ q;
queue__ qq;
stack_ s;
void bfs()
{
    node* p=pop(q);
    for (int j=1;j<=n;j++)
        if(!ktra_ton_tai_(qq,j) && a[p->val][j]!=-1)
    {
        push(q,j);
        push_(qq,999999,j);
    }
    if (!ktrarong(q)) bfs();
}
int get_val(int index_)
{
    bool ck=true;
    nodde* p=qq.o;
    while(p!=NULL && ck)
    {
        if (p->index==index_)
        {
            int w=p->val;
            ck=false;
            return w;
        }
        p=p->link;
    }
    if (ck) return -1;
}
void start(int index)
{
    createqueue(q);
    push(q,index);
    push_(qq,0,index);
    bfs();
}
void search_way(int col)
{
    int tg=get_val(col);
    if (tg>0)
    {
        for (int i=n;i>=1;i--)
        {
            if (b[i][col]==tg)
            {
                insert_(s,i);
                search_way(i);
                break;
            }
        }
    }
}
nodde* min_()
{
    nodde* p=qq.o;
    nodde* tg=NULL;
    while (p!=NULL)
    {
        if (!p->check)
        {
            if (tg==NULL || p->val < tg->val)
            {
                tg=p;
            }
        }
        p=p->link;
    }
    return tg;
}
void search_min(int x)
{
    nodde* k=qq.o;
    while (k!=NULL && k->index!=x)
    {
        k->check=true;
        nodde* p=qq.o->link;
        while (p!=NULL)
        {
            if (k->val + a[k->index][p->index] < p->val && a[k->index][p->index] > 0)
            {
                p->val=k->val + a[k->index][p->index];
                b[k->index][p->index]=p->val;
            }
            p=p->link;
        }
        k=min_();
    }
    if (get_val(x)>=0)
    {
        insert_(s,x);
        search_way(x);
        cout<<"Do dai duong di tu "<<qq.o->index<<" den "<<x<<" la: "<<get_val(x)<<endl;
        print(s);
    }
    else
        cout<<"Khong co duong di tu "<<qq.o->index<<" den "<<x;
}
int main()
{
    //nhap input
    cout<<"Nhap so dinh cua do thi: ";
    cin>>n;
    //tao gia tri mac dinh cho mang b va a
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            b[i][j]=0;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
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
    for (int i=1;i<=k;i++)
    {
        int l,v;
        cout<<"Nhap cap thu "<<i<<": ";
        cin>>l>>v;
        cout<<"Khoang cach tu dinh "<<l<<" den dinh "<<v<<" la: ";
        cin>>a[l][v];
        //a[v][l]=a[l][v];
    }
    int t,z;
    cout<<"Dinh bat dau: ";
    cin>>t;
    cout<<"Dinh ket thuc: ";
    cin>>z;
    start(t);
    search_min(z);
    print_index_(qq);
    print_val_(qq);
    cout<<endl;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
