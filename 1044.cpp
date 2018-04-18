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

long long int bank[5][100]={0,};

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int N;
    int dig,summ;
    long long int ans=0;

    getInt(N)

    // 1 place

    for(dig=0;dig<10;dig++)
    {
        bank[0][dig]=1;
    }

    // 2 place

    for(dig=0;dig<10;dig++)
    {
        for(summ=0;summ<100;summ++)
        {
            bank[1][summ+dig] += bank[0][summ] ;
        }
    }

    // 3 place

    for(dig=0;dig<10;dig++)
    {
        for(summ=0;summ<100;summ++)
        {
            bank[2][summ+dig] += bank[1][summ] ;
        }
    }

    // 4 place

    for(dig=0;dig<10;dig++)
    {
        for(summ=0;summ<100;summ++)
        {
            bank[3][summ+dig] += bank[2][summ] ;
        }
    }

    N/=2;
    N--;

    for(summ=0;summ<100;summ++)
    {
        ans += bank[N][summ]*bank[N][summ];
    }

    printf("%lld\n",ans);


    return 0;
}
