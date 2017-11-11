#include<cstdio>
#include<cstring>
#include<cmath>
const int MAXN=10000;
int par[MAXN],ok[MAXN],X[MAXN],Y[MAXN],N,D;
inline double dis(int i,int j){
    return  sqrt(1.0*(X[i]-X[j])*(X[i]-X[j])+1.0*(Y[i]-Y[j])*(Y[i]-Y[j]));
}
int Find(int x){
    int s=x;
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
    int sum=par[r1]+par[r2];
    if(par[r1]<par[r2]){
        par[r2]=r1;
        par[r1]=sum;
    }
    else{
        par[r1]=r2;
        par[r2]=sum;
    }
}
int main()
{
    while(scanf("%d%d",&N,&D)!=EOF){
        memset(par,-1,sizeof(par));
        memset(ok,0,sizeof(ok));
        for(int i=1;i<=N;i++)
            scanf("%d%d",&X[i],&Y[i]);
        char c;
        getchar();
        while(scanf("%c",&c)!=EOF){
            if(c=='O'){
                int n;
                scanf("%d",&n);
                getchar();
                ok[n]=1;
                for(int i=1;i<=N;i++){
                    if(ok[i]&&i!=n&&dis(i,n)<=double(1.0*D))  //距离满足而且本来就没有连接
                        Union(i,n);
                }
            }
            else if(c=='S'){
                int n,m;
                scanf("%d%d",&n,&m);
                getchar();
                if(Find(m)==Find(n))
                    puts("SUCCESS");
                else puts("FAIL");
            }
        }
    }
    return 0;
}
