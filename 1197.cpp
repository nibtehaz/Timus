﻿/* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
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

    int N;
    char inp[200];
    int r,c;
    int ans;

    getInt(N)

    while(N--)
    {
        scanf("%s",inp);

        r=inp[0]-'a'+1;
        c=inp[1]-'0';

        ans = 0 ;

        if( (1<=r+2) && (r+2<=8) && (1<=c+1) && (c+1<=8) )
        {
            ans++;
        }

        if( (1<=r+2) && (r+2<=8) && (1<=c-1) && (c-1<=8) )
        {
            ans++;
        }

        if( (1<=r-2) && (r-2<=8) && (1<=c+1) && (c+1<=8) )
        {
            ans++;
        }

        if( (1<=r-2) && (r-2<=8) && (1<=c-1) && (c-1<=8) )
        {
            ans++;
        }

        if( (1<=r+1) && (r+1<=8) && (1<=c+2) && (c+2<=8) )
        {
            ans++;
        }

        if( (1<=r+1) && (r+1<=8) && (1<=c-2) && (c-2<=8) )
        {
            ans++;
        }

        if( (1<=r-1) && (r-1<=8) && (1<=c+2) && (c+2<=8) )
        {
            ans++;
        }

        if( (1<=r-1) && (r-1<=8) && (1<=c-2) && (c-2<=8) )
        {
            ans++;
        }

        printf("%d\n",ans);
    }

    return 0;
}
