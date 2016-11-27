#include<cstdio>
#include<algorithm>

using namespace std;

int nums[100005];

long long sums(long long i, long long j){
  if(i>j){
    return 0;
  }
  long long sum = (j*(j+1)-i*(i-1))/2 ; 
  return sum;
}

long long fst(int n, int k){
  if(k==0) return sums(1,n);
  if(nums[0]==1) return 0;
  long long curr_max = sums(1,nums[0]-1);
  //  printf("%lld\n", curr_max);
  for(int i = 0; i < k; i++){
    if(nums[i] >= curr_max+1){
      break;
    }
    if(i!=k-1){
      curr_max += sums(nums[i]+1,nums[i+1]-1);
    }
    else{
      curr_max += sums(nums[i]+1, n);
    }
    //printf("%lld\n", curr_max);
  }
  return curr_max;
}

int main(){
  int t, n, k;
  long long maxposs;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++){
      scanf("%d", nums+i);
    }
    sort(nums,nums+k);
    maxposs = fst(n,k);
    maxposs++;
    //printf("%lld\n", maxposs);
    if(maxposs&1){
      printf("Chef\n");
    }
    else{
      printf("Mom\n");
    }
  }
}
