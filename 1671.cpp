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

int components;
int parent[100005];
int rankk[100005];

set <int> edgesLeft;
set<int>::iterator it;
vector<int> edgesID;
vector<int>ans;

struct Edge
{
    int u;
    int v;
};

vector <Edge>edgeList;

void init(int N);
int getParent(int x);
void unionn(int x,int y);

void init(int N)
{
    components=N;

    for(int i=0;i<N;i++)
    {
        parent[i]=i;
        rankk[i]=0;
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
        parent[x]=getParent(parent[x]);
        return parent[x];
    }
}

void unionn(int x,int y)
{
    int px = getParent(x);
    int py = getParent(y);

    if(px==py)
    {
        return;
    }

    else
    {
        components--;

        if(rankk[px]>rankk[py])
        {
            parent[py]=px;
        }

        else if(rankk[px]<rankk[py])
        {
            parent[px]=py;
        }

        else
        {
            parent[px]=py;
            rankk[py]++;
        }
    }
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int N,M,Q;
    int u,v,i,j;

    getInt(N)
    getInt(M)

    init(N);


    for(i=0;i<M;i++)
    {
        getInt(u)
        getInt(v)

        u--;
        v--;

        edgeList.pb({u,v});
        edgesLeft.insert(i);
    }


    getInt(Q)

    while(Q--)
    {
        getInt(i)
        i--;
        edgesID.pb(i);

        edgesLeft.erase(i);
    }

    for(it=edgesLeft.begin();it!=edgesLeft.end();it++)
    {
        unionn(edgeList[*it].u,edgeList[*it].v);
    }

    ans.pb(components);

    for(i=edgesID.size()-1;i>0;i--)
    {
        unionn(edgeList[edgesID[i]].u,edgeList[edgesID[i]].v);
        ans.pb(components);
    }

    printf("%d",ans[ans.size()-1]);

    for(i=ans.size()-2;i>=0;i--)
    {
        printf(" %d",ans[i]);
    }

    printf("\n");


    return 0;
}
