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

using namespace std;

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("input.txt","r",stdin);
#define DEBUG(a) cout<<a<<endl;
#define PI acos(-1.0)
#define MAX 100005
#define MOD 100000007
#define EPS 1e-9
#define BIGGER(a,b) (a>=b ? a : b)
#define getInt(a) scanf("%d",&a);


int main()
{
    int N,array[MAX];
    int i;
    double ans;

    getInt(N)

    for(i=0;i<N;i++)
        getInt(array[i])

    sort(array,array+N);

    if(N==1)
    {
        printf("%.2lf\n",(double)array[0]);
    }

    else
    {
        ans=array[N-1]*array[N-2];
        ans=2*sqrt(ans);

        for(i=N-3;i>=0;i--)
        {
            ans=ans*array[i];
            ans=2.0*sqrt(ans);
        }

        printf("%.2lf\n",ans);
    }

    return 0;
 }
