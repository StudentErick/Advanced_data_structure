#include<cstdio>
#include<cstring>
const int MAXN=30005;
int par[MAXN],N,M;
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
    while(scanf("%d%d",&N,&M)&&N){
        memset(par,-1,sizeof(par));
        int k;
        for(int i=0;i<M;i++){
            scanf("%d",&k);        //输入组员人数
            for(int j=1;j<=k;j++){
                int n,m;
                scanf("%d",&n);
                if(j==1)m=n;
                else Union(m,n);   //合并组员
            }
        }
        int t=Find(0);
        printf("%d\n",-par[t]);
    }
    return 0;
}
