# Bismillahir Rahmanir Rahim
# Rabbi Zidni Ilma 

global memo
                                # state 1 : position
                                # state 2 : sum so far

global N,S

def dp(position ,summ):

    global memo,N,S
    
    #print N,S

    if(position==N):

        if(summ==S):
            return 1
        else:
            return 0


    if(memo[position][summ]!=-1):
        return memo[position][summ]
    #print memo[position][summ]

    ans = 0 ;

    for i in range(10):

        if(summ+i>S):
            break

        else:
            ans+=dp(position+1,summ+i)
            
    memo[position][summ] = ans 

    return memo[position][summ]



li = raw_input().split(' ')

N=int(li[0])
S=int(li[1])

#sys.setrecursionlimit(1000)

memo=[]

if(S%2==0):

    S/=2
    #print

    for i in range(N+5):
        pii=[]
        for j in range(S+5):
            pii.append(-1)
        memo.append(pii)
    #print memo
#
    ans = dp(0,0)

    print ans*ans

else:

    print "0"
    
