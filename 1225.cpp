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

long long int memo[50][3];
                            // state 1 : number
                            // state 2 : color
                                        // red -> 0
                                        // blue -> 1
                                        // white -> 2
int N;

long long int dp(int number,int color);

long long int dp(int number,int color)
{
    if(number==N)
    {
        return 1;
    }

    if(memo[number][color]!=-1)
    {
        return memo[number][color];
    }

    long long int summ=0;

    // for red
    if(color==0)
    {
        // place white
        summ = summ + dp(number+1,2);

        // place blue
        if(number+2<N)
        {
            summ += dp(number+2,2);
        }
    }

    // for white
    else 
    {
        // place red
        summ = summ + dp(number+1,0);

        // place blue
        if(number+2<N)
        {
            summ += dp(number+2,0);
        }
    }

    memo[number][color]=summ;

    return summ;
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma 

    int i;

    getInt(N)

    for(i=0;i<=N;i++)
    {
        memo[i][0]=-1;
        memo[i][2]=-1;
    }

    printf("%lld\n",dp(0,0)+dp(0,2));
     
    return 0;
}
