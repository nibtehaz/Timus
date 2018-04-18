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

int N,M;
bool diagonally[1005][1005]={0,};
double memo[1005][1005];
bool done[1005][1005];

                        // state 1 : e-w coordinate
                        // state 2 : n-s coordinate

double dp(int x,int y);

double dp(int x,int y)
{
    if(x==N && y==M)
    {
        return 0.0;
    }

    if(done[x][y]!=0)
    {
        return memo[x][y];
    }

    double temp,pre;
    bool fnd=0;

    if(x<N)
    {
        pre=100.0+dp(x+1,y);
        fnd=1;
    }

    if(y<M)
    {
        temp=100.0+dp(x,y+1);

        if(fnd==0)
        {
            pre=temp;
            fnd=1;
        }

        else
        {
            if((pre-temp)>=EPS)
            {
                pre=temp;
            }
        }
    }

    if(diagonally[x+1][y+1])
    {
        temp=100.00*sqrt(2.0) + dp(x+1,y+1);

        if(fnd==0)
        {
            pre=temp;
            fnd=1;
        }

        else
        {
            if((pre-temp)>=EPS)
            {
                pre=temp;
            }
        }
    }

    done[x][y]=1;
    memo[x][y]=pre;

    return memo[x][y];


}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int i,j,k;

    getInt(N)
    getInt(M)

    for(i=0;i<=N;i++)
    {
        for(j=0;j<=M;j++)
        {
            done[i][j]=0;
        }
    }

    getInt(k)

    while(k--)
    {
        getInt(i)
        getInt(j)

        diagonally[i][j]=1;
    }

    printf("%d\n",int(round(dp(0,0))));

    return 0;
}
