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

struct Fraction
{
    long long int num;
    long long int den;

    bool operator < ( Fraction B)
    {
        return (num*B.den<=den*B.num);
    }
};

bool sieve[1000006]={0,};
vector <int> primo;

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int i,j;
    int L,R;
    long long int minnNum,pp,nn;
    long long int sum;
    Fraction minn,temp;


    sieve[1]=1;

    for(i=2;i<1000;i++)
    {
        if(sieve[i]==0)
        {
            for(j=i*i;j<1000006;j+=i)
            {
                sieve[j]=1;
            }
        }
    }

    for(i=2;i<1000006;i++)
    {
        if(sieve[i]==0)
        {
            primo.pb(i);
        }
    }


    getInt(L)
    getInt(R)

    minnNum=-1;

    for(i=L;i<=R;i++)
    {
        pp=i;
        sum=1;

        for(j=0;j<primo.size();j++)
        {
            if(primo[j]*primo[j]>pp)
            {
                break;
            }

            nn=1;

            while(pp%primo[j]==0)
            {
                nn*=primo[j];
                pp/=primo[j];
            }

            if(nn!=1)
            {
                nn*=primo[j];
                sum*=(nn-1)/(primo[j]-1);
            }

        }

        if(pp!=1)
        {
            sum*=(pp*pp-1)/(pp-1);
        }

        sum-=i;

        temp.num=sum;
        temp.den=i;

        if(minnNum==-1)
        {
            minn=temp;
            minnNum=i;
        }

        else
        {
            if(temp<minn)
            {
                minn=temp;
                minnNum=i;
            }
        }

        //if(sum<0)printf("%lld %lld\n",i,sum);

    }

    printf("%d\n",minnNum);

    return 0;
}
