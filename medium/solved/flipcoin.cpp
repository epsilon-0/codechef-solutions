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

using namespace std;

#define inf 1000000007
#define eps 1e-19
#define rev(s,e) reverse(s,e)
#define set(s,i) memset(s,i,sizeof(s))
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
  int ans;
  int l,r;
  int flag; // indicates whether there is a need to update after this point
  struct node *left;
  struct node *right;
};

// in the start every node will have zero answer
void make_tree(node *n,int i,int j){
  //set range of n
  n->l=i;
  n->r=j;
  n->flag=0;
  n->ans=0;
  // check if we are making a leaf
  if(i!=j){
    int mid=(i+j)/2;
    n->left=new(struct node);
    n->right=new(struct node);
    // make left and right subtree
    make_tree(n->left,i,mid);
    make_tree(n->right,mid+1,j);
  }
}

int query(node *n,int i,int j){
  int answer=0;
  int mid=((n->l)+(n->r))/2;
  // we have yet to update this node
  if(n->flag){
    // we are not at a leaf, hence we need to push the update to the children
    if(n->l!=n->r){
      (n->left)->flag=1-((n->left)->flag);
      (n->right)->flag=1-((n->right)->flag);
    }
    n->flag=0;
    (n->ans)=((n->r)-(n->l)+1)-(n->ans);
  }
  if(n->l==i && n->r==j){
    answer=n->ans;
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

// we want to flip the coins between i and j inclusive
void update(node *n,int i,int j){
  // we check if there is a pending update, if so we update this node and push the pending update downwards
  if(n->flag){
    if(n->l!=n->r){
      (n->left)->flag=1-((n->left)->flag);
      (n->right)->flag=1-((n->right)->flag);
    }
    n->ans=(n->r)-(n->l)+1-(n->ans);
  }
  // now we have no pending updates
  n->flag=0;
  int temp,mid=(n->r+n->l)/2;

  // now starting to flip coins lazily

  //in this case i==j==n->l==n->r
  if(n->l==n->r){
    n->ans=1-(n->ans);
  }
  else if(n->l==i && n->r==j){
    (n->left)->flag=1-((n->left)->flag);
    (n->right)->flag=1-((n->right)->flag);
    n->ans=j-i+1-(n->ans);
  }
  else if(j<=mid){
    update(n->left,i,j);
    if((n->right)->flag){
      temp=(n->r)-mid-((n->right)->ans);
    }
    else{
      temp=(n->right)->ans;
    }
    n->ans=(n->left)->ans + temp;
  }
  else if(i>mid){
    update(n->right,i,j);
    if((n->left)->flag){
      temp=mid-(n->l)+1-((n->left)->ans);
    }
    else{
      temp=(n->left)->ans;
    }
    n->ans=(n->right)->ans + temp;
  }
  else{
    update(n->left,i,mid);
    update(n->right,mid+1,j);
    n->ans=(n->left)->ans +(n->right)->ans;
  }
}

int main(){
  int n,q,t,a,b;
  scanf("%d %d",&n,&q);
  node* root=new(struct node);
  make_tree(root,0,n-1);
  f(i,0,q){
    scanf("%d %d %d",&t,&a,&b);
    if(t){
      printf("%d\n",query(root,a,b));
    }
    else{
      update(root,a,b);
    }
  }
}
