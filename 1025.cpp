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
    int k,array[MAX];
    int i,cnt;

    while(scanf("%d",&k)!=EOF)
    {
        for(i=0;i<k;i++)
            getInt(array[i])

        sort(array,array+k);

        int half=(k/2)+1;

        cnt=0;

        for(i=0;i<half;i++)
            cnt+=(array[i]/2)+1;

        printf("%d\n",cnt);
    }


    return 0;
 }
