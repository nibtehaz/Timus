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


int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int n;
    int matrix[105][105];
    int rowSum[105];
    long long int sum,maxx=0;
    int nega=1;
    int i,j,k,colStart,colEnd;

    getInt(n)

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            getInt(matrix[i][j])

            if(matrix[i][j]>=0)
            {
                nega=0;
            }

            if(nega==1)
            {
                if(maxx==0)
                {
                    maxx=matrix[i][j];
                }

                else
                {
                    maxx=BIGGER(maxx,matrix[i][j]);
                }
            }
        }
    }

    if(nega==1)
    {
        printf("%lld\n",maxx );
    }

    else
    {
        maxx=0;

        for(colStart=0;colStart<n;colStart++)
        {
            for(i=0;i<n;i++)
            {
                rowSum[i]=0;
            }

            for(colEnd=colStart;colEnd<n;colEnd++)
            {
                for(i=0;i<n;i++)
                {
                    rowSum[i] += matrix[i][colEnd];
                }

                sum=0;

                for(i=0;i<n;i++)
                {
                    sum+=rowSum[i];

                    maxx=BIGGER(maxx,sum);

                    if(sum<0)
                    {
                        sum=0;
                    }
                }
            }
        }

        printf("%lld\n",maxx);
    }




    return 0;
}
