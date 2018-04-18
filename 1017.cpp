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

long long int memo[502][502]={0,};

int main()
{
    // Bismillahir Rahmanir Rahim
    // Rabbi Zidni Ilma

    int N,len,lev,tot,rest;


    getInt(N)

   

    for(tot=3;tot<=N;tot++)
    {
        //char ch=getchar();
        //printf("total %d\n",tot );
        for(lev=0;lev<=N;lev++)
        {
            //printf("level %d\n",lev );
           // DEBUG(memo[tot][0])

            if(tot<lev)
                break;

            for(len=1;len<=N;len++)
            {
                //printf("len %d\n",len );
                rest=tot-(len+1)*(lev+1);

                if(rest<=0)
                    break;

                if(len==1)
                {
                    memo[tot][len]++;
                    memo[tot][0]++;
                }

                else
                {
                    memo[tot][len] += memo[rest][len-1];
                    memo[tot][0] += memo[rest][len-1];
                }
            }
        }
    }

    //while(1)
    //{
        
        printf("%lld\n",memo[N][0]);
   // }



    return 0;
}
