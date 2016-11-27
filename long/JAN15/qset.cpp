#include<iostream>
#include<cstdio>

using namespace std;

int t1[300005],t2[300005],cnt[300005];

void update(int n,int bot,int top,int x,int y){
  if(x>top || y<bot){ // does not intersect with segment
    return;
  }
  int mid;
  // if segment contained inside the query
  if(x<=bot && y>=top){
    mid=t1[n];
    t1[n]=top-bot+1-t1[n]-t2[n];
    t2[n]=mid;
    cnt[n]=(cnt[n]+1)%3;
    return;
  }
  mid=(bot+top)>>1;
  update(2*n,bot,mid,x,y);
  update(2*n+1,mid+1,top,x,y);
  t1[n]=t1[2*n]+t1[2*n+1];
  t2[n]=t2[2*n]+t2[2*n+1];
  if(cnt[n]==1){
    mid=t1[n];
    t1[n]=top-bot+1-t1[n]-t2[n];
    t2[n]=mid;
  }
  else if(cnt[n]==2){
    mid=t2[n];
    t2[n]=top-bot+1-t1[n]-t2[n];
    t1[n]=mid;
  }
}

int query(int n,int bot,int top,int x,int y,int flag){
  if(x>top || y<bot) return 0;
  if(x<=bot && y>=top){
    if(flag==1){
      return t2[n];
    }
    else if(flag==2){
      return t1[n];
    }
    return top-bot+1-t1[n]-t2[n];
  }
  int mid=(bot+top)>>1,nf=(flag+cnt[n])%3;
  return query(2*n,bot,mid,x,y,nf)+query(2*n+1,mid+1,top,x,y,nf);
}

int arr[100005];

int main(){
  int n, q, t, a, b, times;
  long long c0, c1, c2, cnt;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; i++){
    scanf("%1d", &t);
    t%=3;
    arr[i] = t;
    if(t==1){
      update(1,1,n,i,n);
    }
    if(t==2){
      update(1,1,n,i,n);
      update(1,1,n,i,n);
    }
  }
  for(int i = 0; i < q; i++){
    scanf("%d %d %d", &t, &a, &b);
    if(t==1){
      b%=3;
      times = (b-arr[a]+3)%3;
      arr[a] = b;
      if(times==1){
	update(1,1,n,a,n);
      }
      if(times==2){
	update(1,1,n,a,n);
	update(1,1,n,a,n);
      }
    }
    else{
      c0 = query(1,1,n,a,b,0);
      c1 = query(1,1,n,a,b,1);
      c2 = query(1,1,n,a,b,2);
      //      cout << a << " " << b << " " << c0 << ' ' << c1 << ' ' << c2 << endl;
      cnt = c0*(c0-1)/2 + c1*(c1-1)/2 + c2*(c2-1)/2;
      if(a==1){
	cnt+=c0;
      }
      else{
	if(query(1,1,n,a-1,a-1,0)==1){
	  cnt+=c0;
	}
	else if(query(1,1,n,a-1,a-1,1)==1){
	  cnt+=c1;
	}
	else{
	  cnt+=c2;
	}
      }
      printf("%lld\n", cnt);
    }
  }
}
