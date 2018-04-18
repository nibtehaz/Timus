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

struct Point
{
    long long int x;
    long long int y;
};

vector <Point> originalPoints;
vector <Point> sortedPoints;
Point minn,wanted;

long long int area2 (Point A , Point B , Point C)
{
    return ( A.x*B.y + B.x*C.y + C.x*A.y - A.y*B.x - B.y*C.x - C.y*A.x );
}

bool isFirstSmaller(Point A , Point B )
{
    return area2(A,minn,B)<=0;
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int N;
    int i;
    long long int xx,yy;
    int indexMinn,indexWanted;

    getInt(N)

    for(i=0;i<N;i++)
    {
        getLong(xx)
        getLong(yy)

        originalPoints.pb({xx,yy});
    }

    minn=originalPoints[0];

    for(i=1;i<N;i++)
    {
        if( (minn.y>originalPoints[i].y) || ( (minn.y==originalPoints[i].y) && (minn.x>originalPoints[i].x) ) )
        {
            minn=originalPoints[i];
        }
    }

    for(i=0;i<N;i++)
    {
        if(minn.x==originalPoints[i].x && minn.y==originalPoints[i].y)
        {
            continue;
        }

        else
        {
            sortedPoints.pb(originalPoints[i]);
        }
    }

    sort(sortedPoints.begin(),sortedPoints.end(),isFirstSmaller);

    wanted = sortedPoints[sortedPoints.size()/2];

    //printf("%lld %lld\n",minn.x,minn.y);
    //printf("%lld %lld\n",wanted.x,wanted.y);

    for(i=0;i<N;i++)
    {
        if(minn.x==originalPoints[i].x && minn.y==originalPoints[i].y)
        {
            indexMinn=i;
        }

        else if(wanted.x==originalPoints[i].x && wanted.y==originalPoints[i].y)
        {
            indexWanted=i;
        }
    }

    printf("%d %d\n",indexMinn+1,indexWanted+1);

    return 0;
}
