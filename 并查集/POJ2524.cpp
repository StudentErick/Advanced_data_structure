#include<cstdio>
#include<cstring>
const int MAXN=50005;
int par[MAXN],N;
long M;
int Find(int x){
    int s;
    for(s=x;par[s]>=0;s=par[s]);
    while(s!=x){
        int tmp=par[x];
        par[x]=s;
        x=tmp;
    }
    return s;
}
void Union(int x,int y){
    int r1=Find(x),r2=Find(y);
    if(r1==r2)return;
    int sum=par[r1]+par[r2];
    if(par[r1]<par[r2]){
        par[r1]=sum;
        par[r2]=r1;
    }
    else{
        par[r2]=sum;
        par[r1]=r2;
    }
}
int main()
{
    int t=0;
    while(scanf("%d%ld",&N,&M)&&N&&M){
        memset(par,-1,sizeof(par));
        int i,j;
        for(long k=0;k<M;k++){
            scanf("%d%d",&i,&j);
            Union(i,j);
        }
        long ans=0;
        for(long k=1;k<=N;k++)
            if(par[k]<=0)
                ans++;
        printf("Case %d: %d\n",++t,ans);
    }
    return 0;
}
