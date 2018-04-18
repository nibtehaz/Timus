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

char inp[200005];
stack <char> steak;

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int i,j;

    scanf("%s",inp);

    for(i=0;inp[i]!=0;i++)
    {
        if(steak.size()!=0 && steak.top()==inp[i])
        {
            steak.pop();
        }

        else
        {
            steak.push(inp[i]);
        }
    }

    i=0;

    while(!steak.empty())
    {
        inp[i++]=steak.top();
        steak.pop();
    }

    for(j=i-1;j>=0;j--)
    {
        printf("%c",inp[j]);
    }

    printf("\n");



    return 0;
}
