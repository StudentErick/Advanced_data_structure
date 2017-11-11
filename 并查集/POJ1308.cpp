#include<cstdio>     //顶点的个数==边的个数+1
#include<cstring>
const int MAXN=1000000;
int par[MAXN];
int main()
{
    int m,n;
    int t=1;
    while(scanf("%d%d",&m,&n)&&m>=0&&n>=0){
        memset(par,0,sizeof(par));
        int e=1;
        if((m==0&&n==0)){   //空树
            printf("Case %d is a tree.\n",t++);
            continue;
        }
        par[m]=par[n]=1;
        while(scanf("%d%d",&m,&n)&&m>0&&n>0){
            e++;
            par[m]=par[n]=1;
        }
        int v=0;
        for(int i=0;i<MAXN;i++)
            v+=par[i];
        int flag=(v==e+1);
        printf("Case %d ",t++);
        if(flag)
            puts("is a tree.");
        else
            puts("is not a tree.");
    }
    return 0;
}
