#include<iostream>
#include"queue_library.h"
using namespace std;
int a[1000][1000],n;
queue_ q,ss;

void bfs()
{
    node* p=pop(q);
    for (int j=1;j<=n;j++)
        if(!ktra_ton_tai(ss,j) && a[p->val][j]!=-1)
    {
        push(q,j);
        push(ss,j);
    }
    if (!ktrarong(q)) bfs();
}
void start()
{
    createqueue(q);
    createqueue(ss);
    push(q,2);
    push(ss,2);
    bfs();
}
int main()
{
    cout<<"Nhap so dinh cua do thi: ";
    cin>>n;
    cout<<"Neu khong co khoan cach giua 2 dinh vui long nhap -1"<<endl;
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
    {
        if (i!=j)
        {
            cout<<"Khoang cach tu dinh "<<i<<" den dinh "<<j<<" la: ";
            cin>>a[i][j];
            a[j][i]=a[i][j];
        }
        else
            a[i][j]=0;
    }
    /*n=9;
    for (int i=1;i<=n;i++)
    {
        a[i][i]=0;
    }
    a[1][2]=1;  a[1][3]=1;  a[1][4]=-1; a[1][5]=-1; a[1][6]=-1; a[1][7]=-1; a[1][8]=-1; a[1][9]=-1;
                a[2][3]=-1; a[2][4]=1;  a[2][5]=1;  a[2][6]=-1; a[2][7]=-1; a[2][8]=-1; a[2][9]=-1;
                            a[3][4]=-1; a[3][5]=-1; a[3][6]=1;  a[3][7]=1;  a[3][8]=-1; a[3][9]=-1;
                                        a[4][5]=-1; a[4][6]=-1; a[4][7]=-1; a[4][8]=-1; a[4][9]=1;
                                                    a[5][6]=-1; a[5][7]=-1; a[5][8]=-1; a[5][9]=-1;
                                                                a[6][7]=-1; a[6][8]=1;  a[6][9]=-1;
                                                                            a[7][8]=-1; a[7][9]=-1;
                                                                                        a[8][9]=-1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=i;j++)
    {
        a[i][j]=a[j][i];
    }*/
    start();
    print_(ss);
    return 0;
}
