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

#define INF 1000000000

int n;
int arr[25];
int memo[1048579];
                        // bitmask dp
                        // state 1 : current state killed are 1

int dp(int mask);

int dp(int mask)
{
    if(mask==(1<<n)-1)
    {
        return 0;
    }

    if(memo[mask]!=-1)
    {
        return memo[mask];
    }

    int minn=-1;
    int temp;
    int attack=0;
    int removee;
    int newMask;
    int i;

    for(i=0;i<n;i++)
    {
        if(!checkBit(mask,i))
        {
            //printf("mask %d bit %d\n",mask,i );
            attack+=arr[i];
        }
    }

        //printf("mask %d attack %d\n",mask,attack );

    for(i=0;i<n;i++)
    {
        if(!checkBit(mask,i))
        {
            removee = arr[i];

            if(!checkBit(mask,(i-1+n)%n))
                removee += arr[(i-1+n)%n];

            if(!checkBit(mask,(i+1)%n))
                removee += arr[(i+1)%n];

            newMask=mask;
            setBit(newMask,i);
            setBit(newMask, (i-1+n)%n );
            setBit(newMask, (i+1)%n );

            temp=attack-removee+dp(newMask);

            if(minn==-1)
            {
                minn=temp;
            }

            else
            {
                minn=SMALLER(minn,temp);
            }

        }
    }

    memo[mask]=minn;

    return minn;
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int i,j;

    //INPUT

    i=0;

    getInt(n)

    j=1<<n;

    for(i=0;i<n;i++)
    {
        getInt(arr[i])
    }

    for(i=0;i<=j;i++)
    {
        memo[i]=-1;
    }

    printf("%d\n",dp(0));


    return 0;
}
