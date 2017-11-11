#include<cstdio>
#include<cstring>
const int MAXN=2*(10e5+10);
int N,M,par[MAXN];
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
bool same(int x,int y){
    return (Find(x)==Find(y))?true:false;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(par,-1,sizeof(par));
        scanf("%d%d",&N,&M);
        int c,x,y;
        for(int i=0;i<M;i++){
            getchar();
            scanf("%c%d%d",&c,&x,&y);
            if(c=='D'){
                Union(x,y+N);
                Union(x+N,y);
            }
            else if(c=='A'){
                if(same(x,y+N)||same(x+N,y))
                    puts("In different gangs.");
                else if(same(x,y))
                    puts("In the same gang.");
                else
                    puts("Not sure yet.");
            }
        }
    }
}
