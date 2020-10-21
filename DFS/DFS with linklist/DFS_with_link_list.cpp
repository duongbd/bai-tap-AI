#include<iostream>
#include"stack_library.h"
#include"queue_library.h"
using namespace std;
queue_ q[100],ss;
stack_ s;
void dfs()
{
    node* p=q[s.top->val].o;
    for (int i=0;i<dem_ptu_queue(q[s.top->val]);i++)
    {
        if (!ktra_ton_tai(ss,p->val))
        {
            insert_(s,p->val);
            push(ss,p->val);
            dfs();
        }
        p=p->link;
    }
    get_stack(s);
}
void start()
{
    create_stack(s);
    createqueue(ss);
    insert_(s,1);
    push(ss,1);
    dfs();
}
int main()
{
    for (int i=1;i<=10;i++)
        createqueue(q[i]);
    push(q[1],1);
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
    push(q[7],7);
    start();
    print_(ss);
    return 0;
}
