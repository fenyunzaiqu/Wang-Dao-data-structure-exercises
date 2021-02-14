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
    char data [MaxSize];
    int top;
}Stack;//顺序栈

typedef struct{
    int data [MaxSize];
    int top[2];//共享栈的前后两个指针
}sharestack;

typedef struct Node
{
    char data;
    Node *next;
}LNode,*Linklist;

typedef struct{
    LNode *front,*rear;
}LinkQueue;

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
bool EntagSqQuence(tagSqQuence &Q,int x);//入队操作
bool InverseSqQuence(tagSqQuence Q, SqStack S);//用栈将队列的元素逆置
bool StackOverflow(SqStack S);//判断栈是否溢出
int EnQueue(SqStack &S1,SqStack &S2, int x);//模拟队列的入队列
bool StackEmpty(SqStack S);//判断栈是否为空
void DeQueue(SqStack &S1,SqStack &S2, int x);//模拟队列出队列
bool ifQueueEmpty(SqStack S1,SqStack S2);//判断队列是否为空
bool ifLinkQueueEmpty(LinkQueue LQ);//判断链式队列是否为空
void EnLinkQueue(LinkQueue &LQ,int x);//链式队列入队
bool DeLinkQueue(LinkQueue &LQ,int &x);//链式队列出队
bool IfBracketsSymmerty(Stack &S,vector<char>A);//3.3.1 判断括号是否对称
bool charPopStack(Stack &S,char &x);//推出栈
bool charPushStack(Stack &S, char x);//推进栈
void Train_Arrange(char *train);//3.3.2 火车安排
void Train_Arrange2(char *train);//3.3.2 火车安排第二种写法
double Calculate(int n,double x);//3.3.3 用栈实现递归函数的非递归运算


int main()
{
    SqStack S;
    S.top=-1;
    Stack b;
    b.top=-1;
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
    /*tag队列Q
    vector<int>A={1,2,3,4,5,6,7,8,9,10};
    tagSqQuence Q;
    Q.front=0;
    Q.rear=0;
    Q.tag=0;
    CreatetagSqQuence(Q, A);
    InverseSqQuence(Q, S);
     */
    LinkQueue LQ;
    LQ.rear=LQ.front=(LNode*)malloc(sizeof(LNode));//初始化链式队列
    LQ.front->next=NULL;
    /*括号匹配的测试程序
    vector<char>B={'[','{','}',']','{'};
    IfBracketsSymmerty(b, B);
    */
    
    /*
    int x;
    for(int i=0;i<MaxSize;i++)
    {
        DetagSqQuence(Q, x);
        if(Q.tag==0)
            break;
    }
    */
    //char train[]={'H','S','H'};测试数据
    //Train_Arrange2(train); 还有trainArrange2 两种写法
    cout<<Calculate(4, 1);
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

//bool PopStack(SqStack &S, int x)
bool charPushStack(Stack &S, char x)
{
    if(S.top==MaxSize-1)
        return false;
    else
    {
        S.data[++S.top]=x;
        return true;
    }
}
bool PopStack(SqStack &S, int x)
{
    if(S.top==-1)
        return false;
    x=S.data[S.top--];//取出来后top指针--
    return true;
}
    
bool PushStack(SqStack &S,int &x)
{
    if(S.top==-1)
        return false;
    x=S.data[S.top--];//取出来后top指针--
    return true;
}

//bool PushStack(SqStack &S,int &x)
bool charPopStack(Stack &S,char &x)
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
bool EntagSqQuence(tagSqQuence &Q,int x)
{
    if(Q.front==Q.rear&&Q.tag==1)
    {
        cout<<"队列已满"<<endl;
        return false;
    }
    Q.data[Q.rear%MaxSize]=x;
    Q.rear++;
    if(Q.rear==Q.front)
        Q.tag=1;
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

bool ifLinkQueueEmpty(LinkQueue LQ)
{
    if(LQ.front==LQ.rear)
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

void EnLinkQueue(LinkQueue &LQ,int x)
{
    if(LQ.front==LQ.rear->next)
    {
        LNode *s=(LNode*)malloc(sizeof(LNode));//申请空间
        s->data=x;//输入数值
        s->next=LQ.rear->next;//将新节点与要插入的节点的后继连接起来
        LQ.rear->next=s;//将新节点与前节点连接起来
        LQ.rear=s;//将rear往后移
    }
    else
    {
        LQ.rear->data=x;//如果队列没满，则将数据写入x的新数据
        LQ.rear=LQ.rear->next;//
    }
}

bool DeLinkQueue(LinkQueue &LQ,int &x)
{
    if(LQ.front==LQ.rear)
    {
        cout<<"队列为空"<<endl;
        return false;
    }
    else
    {
        x=LQ.front->data;
        LQ.front=LQ.front->next;
        return true;
    }
}

bool IfBracketsSymmerty(Stack &S,vector<char>A)
{
    char e;
    for(int i=0;A[i]!='\0';i++)//用case替代各种if来判断各种括号
    {
        switch (A[i]) {//左括号进栈
            case '(':
                charPushStack(S, '(');
                break;
            case '{':
                charPushStack(S, '{');
                break;
            case '[':
                charPushStack(S, '[');
                break;
            case ')'://遇到右括号，就把栈里的左括号pop出来看是否匹配
                charPopStack(S, e);
                if(e!='(')
                    return false;
                break;
            case '}':
                charPopStack(S, e);
                if(e!='{')
                    return false;
                break;
            case ']':
                charPopStack(S, e);
                if(e!='[')
                    return false;
                break;
            default:
                break;
        }
    }
    if(S.top!=-1)
    {
        cout<<"括号不匹配"<<endl;
        return false;
    }
    else
    {
        cout<<"括号匹配"<<endl;
        return true;
    }
}

void Train_Arrange(char *train)
{
    char *p=train,*q=train,c;
    Stack b;
    b.top=-1;
    while(*p)
    {
        if(*p=='H')
            charPushStack(b, 'H');
        else
            *(q++)=*p;//用指针q将值为s的指到一起，即S都放在前面
        p++;
    }
    while(b.top!=-1)
    {
        charPopStack(b, c);
        *(q++)=c;//然后用指针q将值为h的接到后面
    }
    cout<<train<<endl;//train头指针地址没变 一切ok
}

void Train_Arrange2(char *train)
{
    char c;
    Stack b;
    b.top=-1;
    int j=0;
    for(int i=0;train[i]!='\0';i++)//通过访问数组遍历
    {
        if(train[i]=='H')
        {
            charPushStack(b, 'H');
        }
        else
            train[j]=train[i];//重写数组
    }
    while(j!='\0')
    {
        charPopStack(b, c);
        train[j]=c;//重写数组后面
        j++;
    }
    cout<<train<<endl;
}

double Calculate(int n,double x)
{
    struct calstack{
        int no;//存n的值
        double val;//存Pn（x)的值
    }st[MaxSize];
    int top=-1,i;
    double fv1=1,fv2=2*x;//n=0,n=1时的初值
    for(i=n;i>=2;i--)//用来存栈里放的n值
    {
        top++;
        st[top].no=i;
    }
    while(top>-1)//从p1,p2,p3,p4一直往上递归
    {
        st[top].val=2*x*fv2-2*(st[top].no-1)*fv1;//递归公式,pn=f(pn-1,pn-2)
        fv1=fv2;//然后把pn-2赋给pn-1
        fv2=st[top].val;//
        top--;
    }
    if(n==0)
        return fv1;
    else
        return fv2;
}

tagSqQuence q,q1,q2;
void manager()
{
    int x;
    int i=0,j=0;
    while(j<10)
    {
        if(q.front!=q.rear&&q.tag!=1&&i<4)
        {
            DetagSqQuence(q1, x);
            EntagSqQuence(q, x);
            i++;//用来计数客车
            j++;//用来计数船上总数
        }
        else if(i==4&&q2.front!=q2.rear&&q2.tag!=1)
        {
            DetagSqQuence(q2, x);
            EntagSqQuence(q, x);
            j++;//船上加
            i=0;
        }
        else
        {
            while(j<10&&i<4&&q2.rear!=q2.front&&q2.tag!=1)//客车队列空（有货车）且客车没上够4辆，用货车代替
            {
                DetagSqQuence(q2, x);
                EntagSqQuence(q, x);
                i++;
                j++;
            }
            i=0;//等待，客车全上船
        }
        if(q1.front==q1.rear&&q1.tag==0&&q2.front==q2.rear&&q2.tag==0)
            j=11;//如果两个队列都为空了，则j=11跳出循环
    }
}
