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

bool moduloCalculator (int base);

int num[1000005];
char inp[1000005];
int len;

bool moduloCalculator (int base)
{
    int modulo=0;
    int i;

    for(i=0;i<len;i++)
    {
        modulo=( (modulo*base)%(base-1) +num[i]) %(base-1);
    }

    return (modulo==0);
}


int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma


    int i,maxx;

    scanf("%s",inp);

    len=strlen(inp);

    maxx=0;

    for(i=0;i<len;i++)
    {
        if('0'<=inp[i] && inp[i]<='9')
        {
            num[i]=inp[i]-'0';
        }

        else
        {
            num[i]=inp[i]-'A'+10;
        }

        maxx=BIGGER(num[i]+1,maxx);
    }

    for(i=BIGGER(maxx,2);i<=36;i++)
    {
        if(moduloCalculator(i))
        {
            printf("%d\n",i);
            return 0;
        }
    }

    printf("No solution.\n");



    return 0;
}
