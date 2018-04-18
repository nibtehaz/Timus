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
 
 

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma 

    int lck1,lck2,thief=0,i;

    getInt(lck1)
    getInt(lck2)

    for(i=0;i<10000;i++)
    {
        if(i%2==0)
        {
            if(lck1==i)
            {
                thief=1;
                break;
            }
        }

        else
        {
            if(lck2==i)
            {
                thief=1;
                break;
            }
        }
    }

    printf("%s\n",(thief==1 ? "yes" : "no") );



    return 0;
}
