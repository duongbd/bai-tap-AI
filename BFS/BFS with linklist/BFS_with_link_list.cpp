#include<iostream>
#include<stdlib.h>
#include"queue_library.h"
using namespace std;

queue_ q[100];
queue_ qq,ss;

void bfs()
{
    node* h=pop(qq);
    node* p=q[h->val].o;
    for (int i=0;i<dem_ptu_queue(q[h->val]);i++)
    {
        if (!ktra_ton_tai(ss,p->val))
        {
            push(qq,p->val);
            push(ss,p->val);
        }
        p=p->link;
    }
    if (!ktrarong(qq)) bfs();
}
void start(int a)
{
    createqueue(qq);
    createqueue(ss);
    push(qq,a);
    push(ss,a);
    bfs();
}
int main()
{
    for (int i=1;i<=10;i++)
        createqueue(q[i]);
    /*push(q[1],1);
    push(q[1],2);
    push(q[1],3);
    push(q[2],2);
    push(q[2],4);
    push(q[2],5);
    push(q[3],3);
    push(q[3],6);
    push(q[3],7);
    push(q[4],4);
    push(q[4],9);
    push(q[5],5);
    push(q[6],6);
    push(q[6],8);
    push(q[7],7);*/
    push(q[1],2);
    push(q[1],3);
    push(q[2],1);
    push(q[2],4);
    push(q[2],5);
    start(2);
    print_(ss);
    return 0;
}
