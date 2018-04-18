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

bool sieve[1000005]={0,};
vector<int>primo;

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int i,j;

    sieve[1]=1;

    for(i=2;i<1003;i++)
    {
        if(sieve[i]==0)
        {
            for(j=i*i;j<1000005;j+=i)
            {
                sieve[j]=1;
            }
        }
    }

    for(i=2;i<1000005;i++)
    {
        if(sieve[i]==0)
        {
            primo.pb(i);
        }
    }

    long long int L,R,Cnt;
    long long int i2,num,pum,tmp,divi;

    getLong(L)
    getLong(R)

    Cnt=R-L+1;

    num=sqrt(L);

    while(num*num<L)
    {
        num++;
    }

    //DEBUG(num)

    for(;;num++)
    {
        pum=num*num;

        //DEBUG(pum)

        if(pum>R)
        {
            break;
        }

        pum=num;

        divi=1;

        for(i=0;i<primo.size();i++)
        {
            if(primo[i]*primo[i]>pum)
            {
                break;
            }

            tmp=0;

            while(pum%primo[i]==0)
            {
                pum/=primo[i];
                tmp++;
            }

            divi*=(2*tmp+1);
        }

        if(pum!=1)
        {
            divi*=3;
        }

        if(sieve[divi]==0)
        {
            Cnt--;
        }
    }

    printf("%lld\n",Cnt);


    return 0;
}
