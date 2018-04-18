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

struct Person
{
    vector<int>parent;
    vector<int>child;
};

Person villegers[1005];

set<int>guilty;
set<int>::iterator it;

bool ancestorColor[2000]={0,};
bool decendentColor[2000]={0,};

char inp[100005];

void findAncestors(int i);
void findDecendent(int i);
void addRelation(int c,int p);
void linePerser(int &c , int &p);

void findAncestors(int i)
{
    //printf("ancestor %d\n",i+1);
    ancestorColor[i]=1;

    if(guilty.find(i)!=guilty.end())
    {
        guilty.erase(i);
    }

    for(int j=0;j<villegers[i].parent.size();j++)
    {
        if(ancestorColor[villegers[i].parent[j]])
        {
            ;
        }

        else
        {
            findAncestors(villegers[i].parent[j]);
        }
    }
}

void findDecendent(int i)
{
    decendentColor[i]=1;

    if(guilty.find(i)!=guilty.end())
    {
        guilty.erase(i);
    }

    for(int j=0;j<villegers[i].child.size();j++)
    {
        if(decendentColor[villegers[i].child[j]])
        {
            ;
        }

        else
        {
            findDecendent(villegers[i].child[j]);
        }
    }
}

void addRelation(int c,int p)
{
    villegers[p].child.pb(c);
    villegers[c].parent.pb(p);
}

void linePerser(int &c , int &p)
{
    int i=0;
    int len=strlen(inp);

    while(inp[i]==' ')
    {
        i++;
    }

    if(inp[i]=='B')
    {
        c=-1;
        p=-1;
        return;
    }

    else
    {
        c=0;
        p=0;

        for(;;i++)
        {
            if(inp[i]==' ')
            {
                break;
            }

            c = c*10 +(inp[i]-'0');
        }

        while(inp[i]==' ')
        {
            i++;
        }

        for(;i<len;i++)
        {
            p = p*10 +(inp[i]-'0');
        }

        c--;
        p--;

        return;
    }
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    //INPUT

    int N;
    int i;
    vector<int>dead;
    int c,p;

    getInt(N)

    for(i=0;i<N;i++)
    {
        guilty.insert(i);
    }

    gets(inp);

    while(1)
    {
        gets(inp);

        linePerser(c,p);

        if(c==-1)
        {
            break;
        }

        addRelation(c,p);
    }

    while(scanf("%d",&i)!=EOF)
    {
        i--;
        dead.pb(i);
    }

    for(i=0;i<dead.size();i++)
    {
        findDecendent(dead[i]);
        findAncestors(dead[i]);
    }

    if(guilty.size()==0)
    {
        printf("0\n");
    }

    else
    {
        it=guilty.begin();

        printf("%d",(*it)+1);

        it++;

        while(it!=guilty.end())
        {
            printf(" %d",(*it)+1);
            it++;
        }

        printf("\n");
    }

    return 0;
}
