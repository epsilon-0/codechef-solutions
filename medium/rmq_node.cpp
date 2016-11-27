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

vector<int> v;

// n has range [i,j]
// left has range i,(i+j)/2 and right has (i+j)/2 +1 , j
struct node{
  li mn;
  int l,r;
  struct node *left;
  struct node *right;
};

// assume that the range i,j is in range of n and i<=j
// returns the  minimum number in range [i,j]
li query(node* n,int i,int j){
  li ans;
  int mid=(n->l+n->r)/2;
  if(i==n->l && j==n->r){
    ans=n->mn;
  }
  else if(j<=mid){
    ans=query(n->left,i,j);
  }
  else if(i>=mid+1){
    ans=query(n->right,i,j);
  }
  else{
    ans=min(query(n->left,i,mid),query(n->right,mid+1,j));
  }
  return ans;
}

// values stored in vector<int> v
void make_tree(node* n,int i,int j){
  // set the range of n
  n->l=i,n->r=j;
  // check if we are making a leaf
  if(i==j){
    n->mn=v[i];
  }
  else{
    int mid=(i+j)/2;
    n->left=new(struct node);
    n->right=new(struct node);
    // make left and right subtree
    make_tree(n->left,i,mid);
    make_tree(n->right,mid+1,j);
    // answer here is minimum of answers in left and right
    n->mn=min((n->left)->mn,(n->right)->mn);
  }
}

int main(){
  int t,tmp,n,q,a,b;
  scanf("%d",&t);
  f(i,1,t+1){
    printf("Scenario #%d:\n",i);
    scanf("%d %d",&n,&q);
    f(i,0,n){
      scanf("%d%",&tmp);
      v.pb(tmp);
    }
    node* root=new(struct node);
    make_tree(root,0,v.size()-1);
    f(i,0,q){
      scanf("%d %d",&a,&b);
      printf("%d\n",query(root,a-1,b-1));
    }
    v.clear();
  }
}
