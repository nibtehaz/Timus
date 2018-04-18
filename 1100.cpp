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

struct Team
{
    int index;
    int ID;
    int M;
};

vector <Team> teams;

bool isFirstSmaller(Team a , Team b);

bool isFirstSmaller(Team a , Team b)
{
    return ( (a.M>b.M) || ( (a.M==b.M) && (a.index<b.index) ) );
}

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int N,i;
    int a,b;

    getInt(N)

    for(i=0;i<N;i++)
    {
        getInt(a)
        getInt(b)

        teams.pb({i,a,b});
    }

    sort(teams.begin(), teams.end(), isFirstSmaller);

    for(i=0;i<N;i++)
    {
        printf("%d %d\n",teams[i].ID,teams[i].M);
    }

    return 0;
}
