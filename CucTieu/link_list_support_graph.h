#include<iostream>
#include<stdlib.h>
using namespace std;

struct nodde
{
    int val;
    int index;
    nodde* link;
    bool check;
};
struct queue__
{
    nodde* i;
    nodde* o;
};

nodde* createnode_(int val,int index)
{
    nodde* newnode= (nodde*) malloc (sizeof(nodde));
    newnode->val=val;
    newnode->index=index;
    newnode->link=NULL;
    newnode->check=false;
    return newnode;
}
void createqueue_(queue__ &q)
{
    q.i=NULL;
    q.o=NULL;
}

bool ktrarong_(queue__ &q)
{
    if (q.o==NULL)
        return true;
    else return false;
}
void push_(queue__ &q, int x, int index)
{
    nodde* newnode=createnode_(x,index);
    if (ktrarong_(q))
    {
        q.i=newnode;
        q.o=newnode;
    }
    else
    {
        q.i->link=newnode;
        q.i=newnode;
    }
}
void print_val_(queue__ &q)
{
    if (ktrarong_(q))
    {
        cout<<"hang doi rong"<<endl;
    }
    else
    {
        nodde* n=q.o;
        cout<<"queue là:"<<endl;
        while (n!=NULL)
        {
            cout<< n->val<<" ";
            if (n->link==NULL) cout<< "'"<<endl;
            n=n->link;
        }

    }
}
void print_index_(queue__ &q)
{
    if (ktrarong_(q))
    {
        cout<<"hang doi rong"<<endl;
    }
    else
    {
        nodde* n=q.o;
        cout<<"queue là:"<<endl;
        while (n!=NULL)
        {
            cout<< n->index<<" ";
            if (n->link==NULL) cout<< "'"<<endl;
            n=n->link;
        }

    }
}
int dem_ptu_queue_(queue__ &q)
{
    int dem=0;
    if (!ktrarong_(q))
    {
        nodde* p=q.o;
        while (p!=NULL)
        {
            dem++;
            p=p->link;
        }
        return dem;
    }
}
void xoa_ptu_(queue__ &q,int index)
{
    if (index>=0&&index<=dem_ptu_queue_(q))
    {
        nodde* p=q.o;
        for (int i=0;i<index-1;i++)
        {
            p=p->link;
        }
        nodde* index_delete=p->link;
        p->link=p->link->link;
        free(index_delete);
    }
    else cout<<"index < 0 or > max of queue"<<endl;
}
nodde* pop_(queue__ &q)
{
        nodde* p=q.o;
        q.o=q.o->link;
        return p;
}
bool ktra_ton_tai_(queue__ &q,int index)
{
    nodde* p=q.o;
    bool check=false;
    for (int i=0;i<dem_ptu_queue_(q);i++)
    {
        if (p->index==index)
        {
            check=true;
            break;
        }
        p=p->link;
    }
    return check;
}
