#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int val;
    node* link;
};
struct queue_
{
    node* i;
    node* o;
};

node* createnode(int val)
{
    node* newnode= (node*) malloc (sizeof(node));
    newnode->val=val;
    newnode->link=NULL;
    return newnode;
}
void createqueue(queue_ &q)
{
    q.i=NULL;
    q.o=NULL;
}

bool ktrarong(queue_ &q)
{
    if (q.o==NULL)
        return true;
    else return false;
}
void push(queue_ &q, int x)
{
    node* newnode=createnode(x);
    if (ktrarong(q))
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
void print_(queue_ &q)
{
    if (ktrarong(q))
    {
        cout<<"hang doi rong"<<endl;
    }
    else
    {
        node* n=q.o;
        cout<<"queue là:"<<endl;
        while (n!=NULL)
        {
            cout<< n->val<<" ";
            if (n->link==NULL) cout<< "'"<<endl;
            n=n->link;
        }

    }
}
int dem_ptu_queue(queue_ &q)
{
    int dem=0;
    if (!ktrarong(q))
    {
        node* p=q.o;
        while (p!=NULL)
        {
            dem++;
            p=p->link;
        }
        return dem;
    }
}
void xoa_ptu(queue_ &q,int index)
{
    if (index>=0&&index<=dem_ptu_queue(q))
    {
        node* p=q.o;
        for (int i=0;i<index-1;i++)
        {
            p=p->link;
        }
        node* index_delete=p->link;
        p->link=p->link->link;
        free(index_delete);
    }
    else cout<<"index < 0 or > max of queue"<<endl;
}
node* pop(queue_ &q)
{
        node* p=q.o;
        q.o=q.o->link;
        return p;
}
bool ktra_ton_tai(queue_ &q,int value)
{
    node* p=q.o;
    bool check=false;
    for (int i=0;i<dem_ptu_queue(q);i++)
    {
        if (p->val==value)
        {
            check=true;
            break;
        }
        p=p->link;
    }
    return check;
}
