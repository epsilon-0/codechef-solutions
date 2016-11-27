#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<numeric>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<list>
#include<climits>
#include<cstdlib>
#include<string>
#include<cmath>

using namespace std;

#define inf 1000000007
#define eps 1e-19
#define rev(s,e) reverse(s,e)
#define mset(s,i) memset(s,i,sizeof(s))
#define cpy(i,j) memset(i,j,sizeof(j))
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define ld long double
#define li long int
#define lli long long int
#define pb(x) push_back(x)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>b;i--)

struct node{
  int r0,r1,r2;
  int l,r;
  int flag;
  struct node *left,*right;
};


//makes tree given correct values
void make_tree(node *n,int i,int j){
  n->l=i;
  n->r=j;
  n->flag=0;
  n->r0=j-i+1;
  n->r1=0;
  n->r2=0;
  int mid=(i+j)/2;
  if(i!=j){
    n->left=new(struct node);
    n->right=new(struct node);
    make_tree(n->left,i,mid);
    make_tree(n->right,mid+1,j);
  }
}

void update(node* n,int i,int j){
  // pending update, push it to the children
  if(n->flag){
    if(n->l!=n->r){
      (n->left)->flag= ((n->left)->flag + n->flag)%3;
      (n->right)->flag= ((n->right)->flag + n->flag)%3;
    }
    //correctly adds the flag to the answers
    if(n->flag==1){
      swap(n->r0,n->r2);
      swap(n->r2,n->r1);
    }
    else{
      swap(n->r0,n->r2);
      swap(n->r0,n->r1);
    }
  }
  // pending updates on this node are finished and have the correct values here, now onto the next
  n->flag=0;
  int temp0,temp1,temp2,mid=(n->r+n->l)/2;

  //now adding lazily
  if(n->l==n->r){
    swap(n->r0,n->r2);
    swap(n->r2,n->r1);
  }
  else if(n->l==i && n->r==j){
    (n->left)->flag=((n->left)->flag+1)%3;
    (n->right)->flag=((n->right)->flag+1)%3;
    swap(n->r0,n->r2);
     swap(n->r2,n->r1);
  }
  else if(j<=mid){
    update(n->left,i,j);
    if((n->right)->flag==0){
      temp0=(n->right)->r0;
      temp1=(n->right)->r1;
      temp2=(n->right)->r2;
    }
    else if((n->right)->flag==1){
	temp0=(n->right)->r2;
	temp1=(n->right)->r0;
	temp2=(n->right)->r1;
    }
    else{// if((n->right)->flag==2){
	temp0=(n->right)->r1;
	temp1=(n->right)->r2;
	temp2=(n->right)->r0;
    }
    n->r0=temp0+(n->left)->r0;
    n->r1=temp1+(n->left)->r1;
    n->r2=temp2+(n->left)->r2;
  }
  else if(i>mid){
    update(n->right,i,j);
    if((n->left)->flag==0){
      temp0=(n->left)->r0;
      temp1=(n->left)->r1;
      temp2=(n->left)->r2;
    }
    else if((n->left)->flag==1){
	temp0=(n->left)->r2;
	temp1=(n->left)->r0;
	temp2=(n->left)->r1;
    }
    else{//if((n->left)->flag==2){
	temp0=(n->left)->r1;
	temp1=(n->left)->r2;
	temp2=(n->left)->r0;
    }
    n->r0=temp0+(n->right)->r0;
    n->r1=temp1+(n->right)->r1;
    n->r2=temp2+(n->right)->r2;
  }
  else{
    update(n->left,i,mid);
    update(n->right,mid+1,j);
    n->r0=(n->left)->r0 + (n->right)->r0;
    n->r1=(n->left)->r1 + (n->right)->r1;
    n->r2=(n->left)->r2 + (n->right)->r2;
  }
}

int query(node *n,int i,int j){
  int answer=0;
  int mid=(n->l+n->r)/2;
  if(n->flag){
    if(n->l!=n->r){
      (n->left)->flag= ((n->left)->flag + n->flag)%3;
      (n->right)->flag= ((n->right)->flag + n->flag)%3;
    }
    //correctly adds the flag to the answers
    if(n->flag==1){
      swap(n->r0,n->r2);
      swap(n->r2,n->r1);
    }
    else{
      swap(n->r0,n->r2);
      swap(n->r0,n->r1);
    }
  }
  n->flag=0;
  if(n->l==i && n->r==j){
    answer=n->r0;
  }
  else if(j<=mid){
    answer=query(n->left,i,j);
  }
  else if(i>mid){
    answer=query(n->right,i,j);
  }
  else{
    answer=query(n->left,i,mid);
    answer+=query(n->right,mid+1,j);
  }
  return answer;
}

int main(){
  int n,q,t,a,b;
  scanf("%d %d",&n,&q);
  node *root;
  root=new(struct node);
  make_tree(root,0,n-1);
  while(q--){
    scanf("%d %d %d",&t,&a,&b);
    if(t){
      printf("%d\n",query(root,a,b));
    }
    else{
      update(root,a,b);
    }
  }
}
