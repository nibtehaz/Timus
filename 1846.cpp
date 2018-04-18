/* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
/* رَّبِّ زِدْنِى عِلْمًا */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <stack>
#include <set>
#include <deque>

using namespace std;

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("myInput.in","r",stdin);
#define DEBUG(a) cout<<a<<endl;
#define PI acos(-1.0)
#define MAX 100005
#define MOD 1000000007
#define EPS 1e-9
#define BIGGER(a,b) (a>=b ? a : b)
#define SMALLER(a,b) (a<=b ? a : b)
#define getInt(a) scanf("%d",&a);
#define getLong(a) scanf("%lld",&a);
#define pb push_back
#define ppb pop_back
#define setBit(a,n) a|=1<<n;
#define resetBit(a,n) a&=~(1<<n);
#define checkBit(a,n) ((a&(1<<n))!=0)
#define toggleBit(a,n) a^=1<<n;
#define floatingEqual(a,b) (fabs(a-b)<=EPS)
#define floatingLess(a,b) ((b-a)>=EPS)
#define floatingGreater(a,b) ((a-b)>=EPS)

#define INF 1000000000

int tree[400100]={0,};

map< int,queue<int> >occurance;

int getGcd(int x,int y);
void update(int node,int lo,int hi,int index,int value);

int getGcd(int x,int y)
{
    int z;

    if(y>x)
    {
        z=x;
        x=y;
        y=z;
    }

    while(1)
    {
        if(y==0)
        {
            return x;
        }

        z=y;
        y=x%y;
        x=z;
    }
}

void update(int node,int lo,int hi,int index,int value)
{
    if(lo==hi && lo==index)
    {
        tree[node]=value;
        return;
    }

    if(index<lo || index>hi)
    {
        return;
    }

    int mid=(lo+hi)>>1;
    int leftChild = node<<1;
    int rightChild = leftChild + 1;

    update(leftChild,lo,mid,index,value);
    update(rightChild,mid+1,hi,index,value);

    tree[node] = getGcd(tree[leftChild],tree[rightChild]);

}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int Q,index=0;
    char inp[50];
    int x,t;

    getInt(Q)

    while(index<Q)
    {
        scanf("%s",inp);
        getInt(x)

        if(inp[0]=='+')
        {
            occurance[x].push(index);

            update(1,0,Q,index,x);

            //printf("%d %d\n",x,index);

            printf("%d\n",BIGGER(1,tree[1]));
        }

        else
        {
            t=occurance[x].front();
            occurance[x].pop();

            update(1,0,Q,t,0);

            //printf("%d %d\n",x,t);

            printf("%d\n",BIGGER(1,tree[1]));
        }

        index++;
    }

    return 0;
}
