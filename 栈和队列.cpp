//
//  main.cpp
//  栈和队列
//
//  Created by 周南 on 2021/2/7.
//
#define MaxSize 10
#include <iostream>
#include <vector>
using namespace::std;
typedef struct{
    int data [MaxSize];
    int top;
}SqStack;//顺序栈

typedef struct{
    int data [MaxSize];
    int top[2];//共享栈的前后两个指针
}sharestack;

typedef struct Node
{
    char data;
    Node *next;
}LNode,*Linklist;

typedef struct
{
    int tag;
    int data[MaxSize];
    int front,rear;
}tagSqQuence;

bool CreatStack(SqStack &S, vector<int>A);//创建一个顺序栈，容器vector传入要创建的数组
bool PopStack(SqStack &S,int x);//将元素入栈
bool PushStack(SqStack &S, int &x);//推栈顶元素出来
bool GetTop(SqStack S, int &x);//得到栈顶元素的值
bool IfStackLegal(char A[]);//3.1.3判断输入输出序列是否合法
Linklist CreatLinkListWithoutHead(Linklist &L,vector<char>A);
bool IfListCentreSymmetry(Linklist L,int n);//3.1.4判断链表是否中心对称
bool PushshareStack(int i, int x,sharestack &s);//3.1.5 共享栈的pop和push操作
bool PopshareStack(int i, sharestack &s);
int CreatetagSqQuence(tagSqQuence &Q,vector<int>A);//创造一个队列
bool DetagSqQuence(tagSqQuence &Q,int &x);//退队列操作
bool InverseSqQuence(tagSqQuence Q, SqStack S);//用栈将队列的元素逆置
bool StackOverflow(SqStack S);//判断栈是否溢出
int EnQueue(SqStack &S1,SqStack &S2, int x);//模拟队列的入队列
bool StackEmpty(SqStack S);//判断栈是否为空
void DeQueue(SqStack &S1,SqStack &S2, int x);//模拟队列出队列
bool ifQueueEmpty(SqStack S1,SqStack S2);//判断队列是否为空

int main()
{
    SqStack S;
    S.top=-1;
    /* 3.1.3测试数据与答案
     char A[]={'I','I','I','O','O','I','O','O'};
    IfStackLegal(A);
    */
    /*3.1.4
    vector<char>A={'x','x','y'};
    Linklist L;
    CreatLinkListWithoutHead(L, A);
    IfListCentreSymmetry(L, 3);
    */
    /*3.1.5
    sharestack B;
    B.top[0]=-1;
    B.top[1]=MaxSize;
    PushshareStack(0, 2, B);
    PopshareStack(0, B);
     */
    vector<int>A={1,2,3,4,5,6,7,8,9,10};
    tagSqQuence Q;
    Q.front=0;
    Q.rear=0;
    Q.tag=0;
    CreatetagSqQuence(Q, A);
    InverseSqQuence(Q, S);
    /*
    int x;
    for(int i=0;i<MaxSize;i++)
    {
        DetagSqQuence(Q, x);
        if(Q.tag==0)
            break;
    }
    */
    return 0;
}

bool CreatStack(SqStack &S, vector<int>A)
{
    S.top=-1;
    if(S.top==MaxSize-1)
        return false;
    for(int i=0;i<A.size();i++)
    {
        S.data[++S.top]=A[i];//top指针永远指向最新加进数组的元素，则加之前++top
    }
    return true;
}

bool PopStack(SqStack &S, int x)
{
    if(S.top==MaxSize-1)
        return false;
    else
    {
        S.data[++S.top]=x;
        return true;
    }
}

bool PushStack(SqStack &S,int &x)
{
    if(S.top==-1)
        return false;
    x=S.data[S.top--];//取出来后top指针--
    return true;
}

bool GetTop(SqStack S, int &x)
{
    if(S.top==-1)
        return false;
    x=S.data[S.top];
    return true;
}

bool StackOverflow(SqStack S)
{
    if(S.top>=MaxSize||S.top<-1)
    {
        cout<<"栈溢出了"<<endl;
        return 1;
    }
    else
    {
        cout<<"没有溢出"<<endl;
        return 0;
    }
}

bool StackEmpty(SqStack S)
{
    if(S.top==-1)
        return true;
    else
        return false;
}

bool IfStackLegal(char A[])
{
    int i=0;
    int j=0,k=0;//j代表in的次数，k代表out的次数
    while(A[i]!='\0')//通过数组来移动扫描的地方，并用结尾终止
    {
        switch (A[i]) {
            case 'I':
                j++;
                break;
                
            case 'O':
                k++;
                if(k>j){cout<<"序列非法"<<endl;exit(0);}
        }
        i++;
    }
    if(j==k)
    {
        cout<<"序列合法"<<endl;
        return true;
    }
    else
    {
        cout<<"序列非法"<<endl;
        return false;
    }
}

Linklist CreatLinkListWithoutHead(Linklist &L,vector<char>A)
{
    LNode *s;
    L=(Linklist)malloc(sizeof(Node));
    L->next=NULL;
    for(int i=0;i<A.size();i++)
    {
        s=(LNode*)malloc(sizeof(Node));
        s->data=A[i];
        s->next=L;
        L=s;
    }
    return L;
}

//3.1.4
bool IfListCentreSymmetry(Linklist L,int n)
{
    int i;
    char s[n/2];
    LNode *p=L;
    for(i=0;i<n/2;i++)
    {
        s[i]=p->data;
        p=p->next;
    }
    i--;//因为出循环时并没有写入，所以-1恢复之前的i值
    if(n%2==1) //若n是奇数，则中间有一个不对称的中间点,就要向后移一位
        p=p->next;
    while(p->data!='\0'&&p->data==s[i])
    {
        i--;
        p=p->next;
    }
    if(i==-1)
    {
        cout<<"是对称链表"<<endl;
        return true;
    }
    else
    {
        cout<<"不是对称链表"<<endl;
        return false;
    }
}

//3.1.5
bool PushshareStack(int i, int x, sharestack &s)
{
    if(i<0||i>1)
    {
        cout<<"输入序号不对"<<endl;
        return false;
    }
    if(s.top[1]-s.top[0]==1)
    {
        cout<<"栈已满"<<endl;
        return false;
    }
    switch (i) {//先移指针，再放数据进去
        case 0:
            s.data[++s.top[0]]=x;
            return true;
        case 1:
            s.data[--s.top[1]]=x;
            return true;
        default:
            return false;
    }
}

bool PopshareStack(int i, sharestack &s)
{
    /*不能在这里判断，要在case里判断
     if(s.top[0]==-1&&s.top[1]==MaxSize)
    {
        cout<<"栈空"<<endl;
        return false;
    }
    */
    switch (i) {
        case 0:
            if(s.top[0]==-1)
            {
                cout<<"栈已空"<<endl;
                return false;
            }
            else
            {
            cout<<s.data[s.top[0]--]<<endl;
            return true;
            }
        case 1:
            if(s.top[1]==MaxSize)
            {
                cout<<"栈已空"<<endl;
                return false;
            }
            else
            {
            cout<<s.data[s.top[1]++]<<endl;
            return true;
            }
        default:
            cout<<"输入错误"<<endl;
            return false;
    }
}

int CreatetagSqQuence(tagSqQuence &Q,vector<int>A)
{
    for(int i=0;i<A.size();i++)
    {
        if(Q.front==Q.rear&&Q.tag==1)
            return 0;
        else
        {
            Q.data[Q.rear]=A[i];
            Q.rear=(Q.rear+1)%MaxSize;//
            Q.tag=1;
        }
    }
    return 1;
}

bool DetagSqQuence(tagSqQuence &Q,int &x)
{
    if(Q.front==Q.rear&&Q.tag==0)
        return false;
    x=Q.data[Q.front];
    //cout<<Q.data[Q.front]<<" ";
    Q.front=(Q.front+1)%MaxSize;
    Q.tag=0;
    return true;
}

bool InverseSqQuence(tagSqQuence Q, SqStack S)
{
    int x;
    for(int i=0;i<MaxSize;i++)//如果小于最高容量
    {
        DetagSqQuence(Q, x);//队列出
        PopStack(S, x);//栈入
        if(Q.tag==0&&Q.front==Q.rear)//如果队列为空，退出循环
            break;
    }
    for(int i=0;i<MaxSize;i++)
    {
        PushStack(S, x);//出栈完成反向输出
        cout<<x<<" ";
        if(S.top==-1)//如果S为空
            break;
    }
    return true;
}

int EnQueue(SqStack &S1,SqStack &S2, int x)
{
    if(!StackOverflow(S1))
    {
        PushStack(S1, x);
        return 1;
    }
    if(StackOverflow(S1)&&!StackEmpty(S2))
    {
        cout<<"队列满"<<endl;
        return 0;
    }
    if(StackOverflow(S1)&&StackEmpty(S2))
    {
        while(!StackEmpty(S1))
        {
            PushStack(S1, x);
            PopStack(S2, x);
        }
    }
    PopStack(S1, x);
    return 1;
}

void DeQueue(SqStack &S1,SqStack &S2,int x)
{
    if(!StackEmpty(S2))
    {
        PushStack(S2, x);
    }
    else if(StackEmpty(S2))
        cout<<"队列为空"<<endl;
    else
    {
        while(!StackEmpty(S1))
        {
            PushStack(S1, x);
            PopStack(S2, x);
        }
        PushStack(S2, x);
    }
}

bool ifQueueEmpty(SqStack S1,SqStack S2)
{
    if(StackEmpty(S1)&&StackEmpty(S2))
    {
        cout<<"队列为空"<<endl;
        return true;
    }
    else
    {
        cout<<"队列不为空"<<endl;
        return false;
    }
}
