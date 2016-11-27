#include <cstdio>  
#include <cstring>  
  
using namespace std;  
  
const long long MAXINT=(1ll<<60);  
const int N=5010;  
const int M=30010;  
  
struct NetWorkFlow {  
    struct Edge {  
        int t;  
        long long f;  
        Edge *ne,*p;  
        Edge () {}  
        Edge (int tt,int ff,Edge *nee) {  
            t=tt;f=ff;ne=nee;  
        }  
        void *operator new(size_t,void *p) {  
            return p;  
        }  
    };  
    Edge b[M*2];  
    Edge *p,*fe[N],*cur[N];  
    int n,s,t;  
    int h[N],vh[N];  
    void clear(int nn,int ss,int tt) {  
        n=nn;s=ss;t=tt;  
        for (int i=0;i<=n;i++) fe[i]=NULL;  
        p=b;  
    }  
    void putedge(int x,int y,int f) {  
        fe[x]=new(p++)Edge(y,f,fe[x]);  
        fe[y]=new(p++)Edge(x,f,fe[y]);  
        fe[x]->p=fe[y];  
        fe[y]->p=fe[x];  
    }  
    long long aug(int i,long long f) {  
        if (i==t) return f;  
        long long l=f;  
        for (Edge *&j=cur[i];j;j=j->ne) {  
            if (j->f&&h[j->t]+1==h[i]) {  
                long long tmp=aug(j->t,l<j->f?l:j->f);  
                j->f-=tmp;  
                j->p->f+=tmp;  
                l-=tmp;  
                if (h[s]==n||!l) return f-l;  
  
            }  
        }  
        int minh=n-1;  
        for (Edge *j=cur[i]=fe[i];j;j=j->ne) {  
            if (j->f&&h[j->t]<minh) minh=h[j->t];  
        }  
        minh++;  
        if (!--vh[h[i]]) h[s]=n;  
        else ++vh[h[i]=minh];  
        return f-l;  
    }  
    long long flow() {  
        long long ans=0;  
        vh[0]=n;  
        for (int i=0;i<=n;i++) {  
            cur[i]=fe[i];  
            h[i]=vh[i]=0;  
        }  
        while (h[s]<n) ans+=aug(s,MAXINT);  
        return ans;  
    }  
};  
  
NetWorkFlow c;  
int n,m;  
  
int main() {  
    int i,x,y,z;  
    scanf("%d%d",&n,&m);  
    c.clear(n,1,n);  
    for (i=0;i<m;i++) {  
        scanf("%d%d%d",&x,&y,&z);  
        c.putedge(x,y,z);  
    }  
    printf("%lld\n",c.flow());  
    return 0;  
}  
