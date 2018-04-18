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

int parent[10005];
int rrank[10005];

int used;

void init(int N);
int getParent(int x);
void unionn(int x,int y);


void init(int N)
{
    for(int i=0;i<N;i++)
    {
        parent[i]=i;
        rrank[i]=0;
    }
}

int getParent(int x)
{
    if(parent[x]==x)
    {
        return x;
    }

    else
    {
        parent[x] = getParent(parent[x]);
        return parent[x];
    }
}

void unionn(int x,int y)
{
    int px = getParent(x);
    int py = getParent(y);

    if(py==px)
    {
        return;
    }

    else
    {
        used++;

        if(rrank[px]>rrank[py])
        {
            parent[py]=px;
        }

        else if(rrank[px]<rrank[py])
        {
            parent[px]=py;
        }

        else
        {
            parent[py]=px;
            rrank[px]++;
        }
    }
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int N,K,M;
    int u,v,i,j;

    getInt(N)
    getInt(K)
    getInt(M)

    init(N);

    while(K--)
    {
        getInt(u)
        getInt(v)

        u--;
        v--;

        unionn(u,v);
    }

    used=0;

    while(M--)
    {
        getInt(u)
        getInt(v)

        u--;
        v--;

        unionn(u,v);
    }

    printf("%d\n",used);

    return 0;
}
