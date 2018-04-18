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

int cntWhite[505]={0,};
int cntBlack[505]={0,};
int memo[503][503];
                         // state 1 : current index
                         // state 2 : options left
int N,K,N_;
bool horse[505];

int countt(int lo,int hi);
int dp(int index , int left);

int countt(int lo,int hi)
{
    int black=cntBlack[hi];
    int white=cntWhite[hi];

    if(lo!=0)
    {
        black-=cntBlack[lo-1];
        white-=cntWhite[lo-1];
    }

    return black*white;
}

int dp(int index , int left)
{
    if(index>=N)
    {
        return 0;
    }


    if(left==0)
    {
        return countt(index,N-1);
    }

    if(memo[index][left]!=-1)
    {
        return memo[index][left];
    }

    int minn=-1;
    int i;
    int j=0;

    for(i=index;i<N;i++)
    {
        if(i+left>=N||left==0)
        {
            break;
        }

        if(minn==-1)
        {
            minn=countt(index,i)+dp(i+1,left-1);
        }

        else
        {
            minn=SMALLER(minn,countt(index,i)+dp(i+1,left-1));
        }
    }

    memo[index][left]=minn;

    return memo[index][left];
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int i,j,k,t;

    //INPUT

    getInt(N)
    getInt(K)

    N_=N-1;

    for(i=0;i<=N;i++)
            for(k=0;k<=K;k++)
                memo[i][k]=-1;

    getInt(t)

    horse[0]=bool(t);

    cntBlack[0]=0;
    cntWhite[0]=0;

    if(horse[0]==1)
    {
        cntWhite[0]=1;
    }

    else
    {
        cntBlack[0]=1;
    }

    for(i=1;i<N;i++)
    {
        getInt(t)

        horse[i]=bool(t);

        cntBlack[i]=cntBlack[i-1];
        cntWhite[i]=cntWhite[i-1];

        if(horse[i]==1)
        {
            cntWhite[i]++;
        }

        else
        {
            cntBlack[i]++;
        }
    }

   /* while(1)
    {
        getInt(i)
        getInt(j)

        if(i<0||j<0)
            break;

        DEBUG(countt(i,j))


    }*/

    printf("%d\n",dp(0,K-1));




    return 0;
}
