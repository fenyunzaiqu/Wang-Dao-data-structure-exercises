//
//  main.cpp
//  fenyun
//
//  Created by 周南 on 2021/1/9.
//


#include <stdio.h>
#include <iostream>
using namespace::std;
typedef struct{
int data[100];
int length;
}Seqlist;//定义Seq这个新的数据类型

void creat(Seqlist &L);//建立线性表
void creattwo(Seqlist &M, Seqlist &N);
void show(Seqlist L);//显示线性表
bool deletemin(Seqlist &L, int &min);//删除顺序表中最小的元素2.1
bool change(Seqlist &L); //将顺序表中所有元素逆置2.2
bool deletevaluex(Seqlist &L, int &x);//删除顺序表中值为x的元素2.3
bool deletebetweenseq(Seqlist &L, int s, int t);//删除有序顺序表中值为s到t之间的元素2.4
bool deletebetween(Seqlist &L , int s, int t);//删除无序顺序表中值为s到t之间的元素2.5
bool deleterepaid(Seqlist &L);//删除顺序表中所有相同的元素，只留一个 2.6
bool seqsqlistmerge(Seqlist &L, Seqlist &M, Seqlist &N);//将两个有序顺序表合并 2.7
bool reverseseqlist(char A[], int left, int right,int arraysize);//将储存在数组里的顺序表逆置2.8
char *exchangearray(char A[], int m,int n, int arraysize);//2.8中的交换
bool findxinseq(Seqlist &L, int x);//在递增有序顺序表中找到值为x的元素 2.9
char *moveleftp(char A[], int p ,int n);//将一维数组中的数据左移p 2.10
int findmidnumber(int A[], int B[], int n);//找出两个等长升序数列的中位数 2.11
int majornumber(int A[],int n);//找出出现次数超过一半的元素 2.12
int findminmiss(int A[],int n);//找出未出现的最小正整数 2.13


int main()
{
Seqlist L;
//Seqlist M,N//
/*2.8交换数组中两个顺序表位置的测试
char A[]={'a','a','a','a','d','b','b','b','c'};
char *B=moveleftp(A, 2, 9);
    for (int i=0;i<9;i++)
    {
        cout<<B[i];
    }
    cout<<endl;
    delete []B;
*/
L.length=0;//初始化线性表的长度为0
/* 2.11题的测试数据
int A[]={1,3,4,5,6};
int B[]={2,5,7,8,10};
cout<<findmidnumber(A, B, 5)<<endl;
*/
/* 2.12题的测试数据
int A[]={1,2,1,1,4,1,1,1,2,3,1,1,2,3,2};
cout<<majornumber(A, 14)<<endl;
*/
/* 2.13题的测试数据
int A[]={-3,0,1,2,3,5};
findminmiss(A, 6);
cout<<findminmiss(A, 6)<<endl;
*/
creat(L);
cout<<"改变前的元素为："<<endl;
show(L);
    findxinseq(L, 10);
cout<<"改变后的元素为："<<endl;
show(L);
return 0;
}

void creat(Seqlist &L)
{
int a;
int test[]={1,2,3,4,5,6,7,9,13,14};
a=sizeof(test)/sizeof(int);//计算数组的大小
for(int i=0;i<a;i++)//将数组的元素一一写入顺序表中
{
L.data[i]=test[i];
L.length++;
}
}

void show(Seqlist L)
{
int i;
for(i=0;i<L.length;i++)
printf("%d\t",L.data[i]);
    cout<<endl;
}

//删除顺序表中最小的元素2.1
bool deletemin(Seqlist &L ,int &min)
{
    if(L.length==0) //如果是一个空的顺序表
    {
        return false; //返回
    }
    else{
    min=L.data[0];//从第一个元素开始比较
    int mark=0; //标记位置
    for(int i=1;i<L.length;i++)
    {
        if(L.data[i]<min)
        {
            min=L.data[i];//找最小的元素
            mark=i;
        }
    }
    L.data[mark]=L.data[L.length-1];//找到后交换位置
    L.length--;//表长度减一
        return true;
    }
}

//将顺序表中所有元素逆置2.2
bool change(Seqlist &L)
{
    int temp;//中间变量
    for(int i=0;i<int(L.length/2);i++)//前后部分交换位置
    {
        temp=L.data[i];
        L.data[i]=L.data[L.length-i-1];
        L.data[L.length-i-1]=temp;
    }
    return true;
}

//删除顺序表中值为x的元素2.3
bool deletevaluex(Seqlist &L, int &x)
{
    int count=0;//统计有多少个值为x的元素
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i]==x)//当有值为x的元素时计数
        {
            count++;
        }
        else
        {
            L.data[i-count]=L.data[i];//若碰到有连续的持续计数，然后把后面的元素后移k位
        }
    }
    L.length=L.length-count;//最后再减去顺序表的长度，因为该移位的都移位了，只需要输出的时候改变就行
    return true;
}

//删除有序顺序表中值为s到t之间的元素2.4
bool deletebetweenseq(Seqlist &L, int s, int t)
{
    int mark1=0,mark2=0,k;//k其实是多余的，mark1是标记比s小的元素，mark2标记比t大的元素的位置
    if(L.length==0||s>=t)
    {
        return false;
    }
    else
    {
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i]<=s)//范围外最大的比s小，范围内最小的比s大
            mark1=i;
        else if(L.data[i]<=t)//范围内最大的比t小，范围外最小的比t大
            mark2=i;
    }
        k=mark2-mark1;//范围大小
        for(int i=mark2;i<L.length;i++)
        {
            L.data[i-k+1]=L.data[i+1];//把t（mark2）右边的移到左边去
        }
        L.length=L.length-k;
        return true;
    }
}

//删除无序顺序表中值为s到t之间的元素2.5
bool deletebetween(Seqlist &L , int s, int t)//与2.3的删除算法相同，故此不再赘述
{
    int k=0;
    if(s>=t||L.length==0)
        return false;
    else
    {
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i]>=s&&L.data[i]<=t)
            k++;
        else
        {
            L.data[i-k]=L.data[i];
        }
    }
    L.length=L.length-k;
    return true;
    }
}

//删除有序顺序表中所有相同的元素，只留一个 2.6
bool deleterepaid(Seqlist &L)
{
    int i,j;//要在后面当长度的量，所以不能为临时变量
    for(i=0,j=1;j<L.length;j++)
    {
        if(L.data[i]!=L.data[j])//当被选元素和遍历到后面的元素不同的时候
            L.data[++i]=L.data[j];//被选元素后面的元素依次接上
    }
    L.length=i+1;//最后长度是最后一位元素位置+1
    return true;
}

//将两个顺序表合并为一张顺序表 2.7
bool seqsqlistmerge(Seqlist &L, Seqlist &M, Seqlist &N)
{
    int i,j,k;//i,j,k分别标记顺序表M,N,L元素的位置
    for(i=0,j=0,k=0;i<M.length&&j<N.length;k++)//当其中一个顺序表比完后（标记到末尾后），停止比较
    {
        if(M.data[i]<=N.data[j])//“表头”互相对比，小的那个顺序表表头向后移一位，并把小的赋值给表L
        {
            L.data[k]=M.data[i];
            i++;
        }
        else
        {
            L.data[k]=N.data[j];
            j++;
        }
    }
    while(i<M.length)//把还剩下的那个表的后面接在L的末尾
        L.data[k++]=M.data[i++];
    while(j<N.length)
        L.data[k++]=N.data[j++];
    L.length=k;
    return true;
}

/*两张表合并的函数
void creattwo(Seqlist &M, Seqlist &N)
{
    M.length=0;N.length=0;
    int a,b;
    int test1[]={1,2,3};
    int test2[]={1,3,4,5,5};
    a=sizeof(test1)/sizeof(int);//计算数组的大小
    for(int i=0;i<a;i++)//将数组的元素一一写入顺序表中
    {
    M.data[i]=test1[i];
    M.length++;
    }
    b=sizeof(test2)/sizeof(int);
    for(int i=0;i<b;i++)//将数组的元素一一写入顺序表中
    {
    N.data[i]=test2[i];
    N.length++;
    }
}
*/

//将储存在数组中的两个顺序表逆置2.8
bool reverseseqlist(char A[], int left, int right,int arraysize)
//其中left标志开始的元素位置，right标记结束的元素位置，arraysize为数组的长度
{
    if(left>=right||right>=arraysize)
        return false;
    int mid=(left+right)/2;//找出mid的位置，一半交换从left到mid为止
    int temp;
    for(int i=left;i<=mid;i++)
    {
        temp=A[i];
        A[i]=A[right+left-i];//相当于交换的元素位置序号相加为left+right（2mid）
        A[right+left-i]=temp;
    }
    return true;
}

char *exchangearray(char A[], int m,int n, int arraysize)
{
    reverseseqlist(A, 0, m+n-1, arraysize);
    reverseseqlist(A, 0, n-1, arraysize);
    reverseseqlist(A, n, m+n-1, arraysize);
    char *B=new char[9];
    for(int i=0;i<9;i++)
    {
        B[i]=A[i];
    }
    return B;
}

//在递增有序顺序表中找值为x的元素并进行与后继元素交换或插入的操作 2.9
bool findxinseq(Seqlist &L, int x)
{
    int left=0,right=L.length-1,temp;
    int mid=0;
    while(L.data[mid]!=x)
    {
        mid=(left+right)/2;//二分查找
        if(left>right) //一定要先判读右界（标记）是不是在左界（左标记）左边了，后面判断的话left和right的值又更新了，会陷入死循环。
            break;
        else if(L.data[mid]<x)
        {
            left=mid+1;
        }
        else
            right=mid-1;
    }
    if(L.data[mid]==x&&mid!=L.length-1)//找到且不是顺序表的最后时，和后续元素交换位置
    {
        temp=L.data[mid];
        L.data[mid]=L.data[mid+1];
        L.data[mid+1]=temp;
    }
    if(left>right)//如果没找到，那么先把right+1后面的元素后移一位，再插入right+1这个位置
    {
        for(int i=L.length-1;i>right;i--)
        {
        L.data[i+1]=L.data[i];
        }
        L.data[right+1]=x;
        L.length++;
    }
    return true;
}

//将一维数组中的数据左移p 2.10
char *moveleftp(char A[], int p, int n)
{
    reverseseqlist(A, 0, n-1, n); //详见草稿图，先整体逆置，然后两个局部逆置
    reverseseqlist(A, 0, n-p-1, n);
    reverseseqlist(A, n-p , n-1, n);
    char *B=new char[9];//通过输出头部的地址来保存改变后的数组
    for(int i=0;i<9;i++)
    {
        B[i]=A[i];
    }
    return B;
}

//找出两个等长升序数列的中位数 2.11
int findmidnumber(int A[], int B[], int n)
{
    int Aleft=0,Bleft=0,Aright=n-1,Bright=n-1,Amid=0,Bmid=0;
    while(Aleft!=Aright||Bleft!=Bright)//这道题重要的一点是这个循环终止条件，即查找的左界和右界相同（即折半到最后唯一一个数）后停止查找
    {
        Amid=(Aleft+Aright)/2;
        Bmid=(Bleft+Bright)/2;
        if(A[Amid]==B[Bmid])//这个很好理解，即A的中位数和B的中位数相同，那么即位他们两个序列一起的中位数
            return A[Amid];
        if(A[Amid]>B[Bmid])
            //另一个重点就是这个的舍弃流程。如果用这个算法看一下循环的流程，这个折半查找的核心思想是，最后一次折半找到的最后一个数，即左界等于右界的时候，舍弃的比他小的和舍弃的比他大的数目相同（尽管实际上不会计数），当A的“中位数”比B的中位数大的时候，这个中位数只是取比较大小的作用，不会是真正他的中位数。
        {
            if((Bright+Bleft)%2==0)//如果剩下的元素个数是奇数，那么舍弃掉比A中位数大的，和比B中位数小的。这里有个点很难理解，即：虽然都是升序序列，但比A中位数大的不一定比B中位数小，那么这样取出来的中位数还可信吗？这个问题很好解答：以A{1,3,7} B{2,4,6}为例，第一次循环后丢掉了1和6，确实6比7小，但我们只要保证丢掉的比4大，那么他就一定是比最后求得中位数大的元素，且1也一定比求的最后的中位数小，那么此次丢弃就丢掉了x个比中位数大的和x个比中位数小的，又是新的等长升序序列继续比，比到到各剩2个为止
            {
                Aright=Amid;
                Bleft=Bmid;
            }
            else
            {
                Aright=Amid;
                Bleft=Bmid+1;//这个加1很关键，其一就是用于丢掉到只剩两个元素的情形，因为int取整的缘故，如果没有加一，那么在剩下最后两个数的时候，永远达不到左界和右界重合（即只剩一个数）如4和5，mid也永远是4，需要+1才能到5，其二就是 当元素为偶数个的时候，mid是取剩下序列中位数中，偏0近的那一方，那么要丢掉相同个数保持等长序列，就需要其中一个序列在mid位置的基础上往右取一位，才能保证丢掉相同长度的序列。
            }
        }
        else
        {
            if((Aright+Aleft)%2==0)
            {
                Aleft=Amid;
                Bright=Bmid;
            }
            else
            {
                Bright=Bmid;
                Aleft=Amid+1;
            }
        }
    }
    return A[Aleft]<B[Bleft]?A[Aleft]:B[Bleft];//这个千万不能取成中位数，因为他是在循环的才开始更新，所以应该取left或right的位置
}

//找出出现次数超过一半的主元素 2.12
int majornumber(int A[],int n)
{
    int count=0,temp=A[0];
    //用计数的方法时间复杂度在2n，即位O(n),空间复杂度为O(1)，因为只用了temp和count这两个内存空间，也可以通过排序后直接输出中间元素，然后数一遍有没有超过一半（实现简单，时间复杂度更高）
    for(int i=0;i<n;i++)
    //本质上是抽屉原理，即用一个计数器计数1，0，到-1就换上temp重新计数。即用一半的抽屉来装元素，如果元素超过一半，那么肯定有一个抽屉有两个元素，那么这个计数器就不会为-1，temp也不会装不为超过一半的元素。
    {
        if(A[i]==temp)
            count++;
        else
        {
            count--;
            if(count==-1)
            {
                temp=A[i];
                count=0;
            }
        }
    }
    count=0;//当没有超过一半元素的时候，需要数一遍确认一下有没有超过一半就解决了
    for(int i=0;i<n;i++)
    {
        if(A[i]==temp)
        {
            count++;
        }
    }
    if(count>(n/2))
        cout<<"主元素是"<<temp<<endl;
    else
        cout<<"没有主元素"<<endl;
    return temp;
}

//找到最小未出现的正整数2.13
int findminmiss(int A[],int n)//给出的空间换时间的算法答案我不太满意，但也想不到更好的办法
{
    int j=0,B[n];
    for(int i=0;i<n;i++)//也可以用memeset的方法来初始长度为n的全为0的数组
    {
        B[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(A[i]>0&&A[i]<=n)
            B[A[i]-1]=1;//用B的位置来标记有没有出现过值=B位置的最下正整数
    }
    for(int i=0;i<n;i++)
    {
    if(B[i]==0)//最后输出第一个没有被标记的位置，也即为A没有出现的最小正整数的值
    {
        j=i;
        cout<<"最小正整数为"<<i+1<<endl;
        break;
    }
    }
    return j;
}


