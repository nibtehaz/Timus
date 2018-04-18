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

int memo[12][90][12][12];
                                // Digit dp
int y[12]={0,};
int S;

int dp(int index,int summ,int leftmostLo,int leftmostHi)
{
    if(index==10)
    {
        if(summ==S && leftmostLo<=leftmostHi)
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }

    if(memo[index][summ][leftmostLo][leftmostHi]!=-1)
    {
        return memo[index][summ][leftmostLo][leftmostHi];
    }

    int digit;
    int newLo=leftmostLo;
    int newHi=leftmostHi;
    int result=0;

    for(digit=0;digit<10;digit++)
    {
        newLo=leftmostLo;
        newHi=leftmostHi;

        if(digit<y[index] && index<leftmostLo)
            newLo=index;

        if(digit>y[index] && index<leftmostHi)
            newHi=index;

        if(digit+summ<=S)
        {
            result += dp(index+1,summ+digit,newLo,newHi);
        }

    }

    memo[index][summ][leftmostLo][leftmostHi]=result;

    return result;
}



int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int i,j,k,k2;
    getInt(S)

    y[0]=1;

    memset(memo,-1,sizeof(memo));

    printf("%d\n",dp(0,0,10,10) );

    return 0;
}
