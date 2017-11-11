#include<cstdio>
#include<cstring>
const int MAXN=30006;
int par[MAXN],high[MAXN],N,P;    //双并查集操作
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
    while(scanf("%d",&P)!=EOF){
        memset(par,-1,sizeof(par));
        memset(high,0,sizeof(high));
        for(int i=0;i<P;i++){
            char c;
            int x,y;
            getchar();   //读取前边的换行
            scanf("%c",&c);
            if(c=='M'){
                scanf("%d%d",&x,&y);
                par[x]=y;
                high[x]+=(high[y]+1);   //高度累加
                int dis=high[x],t=x;
                while(par[t]!=y){
                    high[t]=dis--;
                    t=par[t];
                }
            }
            else if(c=='C'){
                scanf("%d",&x);
                printf("%d\n",high[x]);
            }
        }
    }
    return 0;
}
