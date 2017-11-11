#include<cstdio>
#include<cstring>    //并查集在这里维护的是物种的关系，把元素之间的关系作为维护的对象；不再是之前那种直接给元素本身进行分类了
const int MAXN=3*50005;
int K,N,T[MAXN],X[MAXN],Y[MAXN],par[MAXN];
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
bool same(int x,int y){
    return (Find(x)==Find(y))?true:false;
}
void Union(int x,int y){
    int r1=Find(x),r2=Find(y);
    if(r1==r2)return;                 ///并查集一定要进行元素判重，为了数据安全性
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
void solve(){
    memset(par,-1,sizeof(par));
    int ans=0;
    for(int i=0;i<K;i++){
        int t=T[i];
        int x=X[i]-1,y=Y[i]-1;
        if(x<0||x>=N||y<0||y>=N){
            ans++;continue;
        }
        if(t==1){    //属于同一个种群
            if(same(x,y+N)||same(x,y+2*N))
                ans++;
            else{
                Union(x,y);
                Union(x+N,y+N);
                Union(x+2*N,y+2*N);
            }
        }
        else{       //x吃y
            if(same(x,y)||same(x,y+2*N))
                ans++;
            else{
                Union(x,y+N);
                Union(x+N,y+2*N);
                Union(x+2*N,y);
            }
        }
    }
    printf("%d\n",ans);
}
int main()
{
    scanf("%d%d",&N,&K);
    for(int i=0;i<K;i++)
        scanf("%d%d%d",&T[i],&X[i],&Y[i]);
    solve();
    return 0;
}
