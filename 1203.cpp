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

#define INF 1000000000

struct Range
{
    int startt;
    int endd;
};

vector <Range> range;

int memo[MAX];
                        // state 1 : index

int N;

bool isFirstSmaller(Range a , Range b);
int BS(int val);
int dp(int index);

bool isFirstSmaller(Range a , Range b)
{
    return ( (a.startt<b.startt) || ( (a.startt==b.startt) && (a.endd<b.endd) ) ) ;
}

int BS(int val)
{
    int lo=0;
    int hi=N-1;
    int mid;

    if(val>=range[hi].startt)
        return N;

    while(lo<hi)
    {
        mid=(lo+hi)/2;

        if(range[mid].startt<=val)
        {
            lo=mid+1;
        }

        else
        {
            hi=mid;
        }
    }

    return lo;
}

int dp(int index)
{
    if(index==N)
    {
        return 0;
    }

    if(memo[index]!=-1)
    {
        return memo[index];
    }

    int take,notTake,next;

    // taking
    next=BS(range[index].endd);

    take=1+dp(next);

    // not taking
    notTake=dp(index+1);

    memo[index]=BIGGER(take,notTake);

    return memo[index];
}



int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int i,j,a,b;

    //INPUT

    getInt(N)

    for(i=0;i<N;i++)
    {
        getInt(a)
        getInt(b)

        range.pb({a,b});
    }

    sort(range.begin(),range.end(),isFirstSmaller);

    for(i=0;i<=N;i++)
        memo[i]=-1;

    printf("%d\n",dp(0));



    return 0;
}
