#include<iostream>
#include<stdlib.h>
using namespace std;
struct nodes
{
    int val;
    nodes* link;
};
struct stack_
{
    nodes* top;
};
nodes* create_node(int val)
{
    nodes* new_node= (nodes*) malloc (sizeof(nodes));
    new_node->val=val;
    new_node->link=NULL;
    return new_node;
}
void create_stack(stack_ &s)
{
    s.top=NULL;
}
bool stack_empty(stack_ &s)
{
    if (s.top==NULL) return true;
    else return false;
}
void insert_(stack_ &s,int val)
{
    nodes* new_node=create_node(val);
    if (stack_empty(s))
    {
        s.top=new_node;
    }
    else
    {
        new_node->link=s.top;
        s.top=new_node;
    }
}
void print(stack_ &s)
{
    nodes* p=s.top;
    cout<<"stack la:"<<endl;
    while (p!=NULL)
    {
        cout<<p->val<<" ";
        if (p->link==NULL) cout<<"."<<endl;
        p=p->link;
    }
}
int count_stack(stack_ &s)
{
    int dem=0;
    nodes* p=s.top;
    while (p!=NULL)
    {
        dem++;
        p=p->link;
    }
    return dem;
}
int get_stack(stack_ &s)
{
    int val=s.top->val;
    nodes* p=s.top;
    s.top=s.top->link;
    free(p);
   return val;
}
