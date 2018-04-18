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

int memo[10005][100][2];
                            // state 1 : current index
                            // state 2 : first 2 digits
                            // state 3 : have we found a prime

int sieve[1000]={0,};

int n;

int dp(int index, int first2, int isPrime);

int dp(int index, int first2, int isPrime)
{
    //printf("Index %d\n",index);

    if(index==n)
    {
        return isPrime;
    }

    //printf("Memo %d\n",memo[index][first2][isPrime]);

    if(memo[index][first2][isPrime] != -1)
    {
        return memo[index][first2][isPrime];
    }

    int i;
    int temp;


    long long int ans=0;

    //DEBUG("********************")

    //DEBUG(first2);

    for(i=0;i<10;i++)
    {

        temp = first2*10 + i ;

        //if(sieve[temp]==1)
        //DEBUG(temp);

        //DEBUG(temp);



        ans = ( ans + dp(index+1,temp%100, isPrime & sieve[temp] ) )  % 1000000009;

    }

    memo[index][first2][isPrime]=int(ans);

    return memo[index][first2][isPrime] ;


}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int i,j;

    //OUTPUT

    for(i=2;i<100;i++)
    {
        if(sieve[i]==0)
        {
            for(j=i*i;j<1000;j+=i)
            {
                sieve[j]=1;
            }
        }
    }

    for(i=0;i<=99;i++)
    {
        sieve[i]=0;
    }

    for(i=100;i<=999;i++)
    {
        sieve[i]=1-sieve[i];
    }


    getInt(n)

    memset(memo,-1,sizeof(memo));

    long long int ans=0;

    for(i=10;i<100;i++)
    {
        ans=(ans+dp(2,i,1))%1000000009;
    }

    printf("%lld\n",ans );


    return 0;
}
