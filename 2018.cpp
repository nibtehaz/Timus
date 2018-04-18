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

int memo[50003][2];
                    // state 1 : begining of the new interval
                    // stage 2 : want to fill this index with

int N,A,B;

int dp(int index,int type);

int dp(int index,int type)
{
    if(index==N)
    {
        return 1;
    }

    if(memo[index][type]!=-1)
    {
        return memo[index][type];
    }

    int i;
    long long int summ=0;

    if(type==0)
    {
        for(i=0;i<A;i++)
        {
            if(index+i>=N)
                break;

            summ= (summ + dp(index+i+1,1) )%MOD ;
        }
    }

    else
    {
        for(i=0;i<B;i++)
        {
            if(index+i>=N)
                break;

            summ= (summ + dp(index+i+1,0) )%MOD ;
        }
    }

    memo[index][type]=summ;

    return summ;

}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int i,j;

    getInt(N)
    getInt(A)
    getInt(B)

    for(i=0;i<=N;i++)
    {
        memo[i][0]=-1;
        memo[i][1]=-1;
    }

    printf("%d\n",(dp(0,0)+dp(0,1))%MOD);


    return 0;
}
