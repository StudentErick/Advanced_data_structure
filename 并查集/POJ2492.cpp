#include<cstdio>
#include<cstring>
const int MAXN=2005;
int par[2*MAXN],N,M;
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
bool same(int i,int j){
    return (Find(i)==Find(j))?true:false;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int w=1;w<=t;w++){
        scanf("%d%d",&N,&M);
        memset(par,-1,sizeof(par));
        bool flag=false;
        int t1,t2;
        for(int i=0;i<M;i++){
            scanf("%d%d",&t1,&t2);
            if(flag)continue;
            if(same(t1,t2)||same(t1+N,t2+N))
                flag=true;
            else{
                Union(t1,t2+N);
                Union(t2,t1+N);
            }
        }
        printf("Scenario #%d:\n", w);
        if(flag)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
        if(w!=t)
            printf("\n");
    }
    return 0;
}
