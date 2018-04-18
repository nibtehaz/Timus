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

int adjMat[105][105];

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int N,M;
    int minA,minB,minSet=-1;
    int setA,setB,setC,setD,setM;
    int i,j,k;

    getInt(N)
    getInt(M)

    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            getInt(adjMat[i][j])
        }
    }

    for(i=0;i<M;i++)
    {
        for(j=i+1;j<M;j++)
        {
            setA=0;
            setB=0;
            setC=0;
            setD=0;

            for(k=0;k<N;k++)
            {
                if(adjMat[k][i]==0 && adjMat[k][j]==0)
                {
                    setA++;
                }

                else if(adjMat[k][i]==0 && adjMat[k][j]==1)
                {
                    setB++;
                }

                else if(adjMat[k][i]==1 && adjMat[k][j]==0)
                {
                    setC++;
                }

                else
                {
                    setD++;
                }
            }

            setM = BIGGER(BIGGER(setA,setB),BIGGER(setC,setD));

            if(minSet==-1)
            {
                minSet=setM;
                minA=i;
                minB=j;
            }

            else
            {
                if(minSet>setM)
                {
                    minSet=setM;
                    minA=i;
                    minB=j;
                }
            }

        }
    }


    printf("%d\n%d %d\n",minSet,minA+1,minB+1);

    return 0;
}
