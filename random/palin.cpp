#include <cstdio>
#include <algorithm>

#define p(q) printf("%d\n", q)

using namespace std;

const int MAXN = 5000006;

int num[MAXN], palin[MAXN];
int nlength = 0;

void read_int(){
  nlength = 0;
  char digit;
  while(1){
    digit = getchar();
    if(digit == '\n') break;
    num[nlength] = digit-'0';
    nlength++;
  }
  reverse(num, num+nlength);
}

bool comp(){
  for(int i = nlength-1; i > -1; i--){
    if(num[i] < palin[i]){
      return true;
    }
    else if(num[i] > palin[i]){
      return false;
    }
  }
  return false;
}

bool all9(){
  for(int i = 0; i < nlength; i++){
    if(num[i] != 9){
      return false;
    }
  }
  return true;
}

int main(){
  int test;
  scanf("%d", &test);
  getchar();
  while(test--){
    read_int();
    //    for(int i = 0; i < number.size(); i++) p(number[i]);
    if(all9()){
      printf("1");
      for(int i = 0; i < nlength-1; i++){
	printf("0");
      }
      printf("1\n");
      continue;
    }
    for(int i = 0; i < nlength; i++){
      palin[i] = num[max(i, nlength-1-i)];
    }
    //    cout << comp(number, palin) << endl;
    if(!comp()){
      int pos = nlength/2;
      int carry = 1;
      while(carry != 0){
	if(palin[pos] == 9){ carry = 1; palin[pos] = 0;}
	else { carry = 0; palin[pos]++; }
	pos++;
      }
      for(int i = 0; i <= nlength/2; i++){
	palin[i] = palin[nlength-1-i];
      }
    }
    for(int i = 0; i < nlength; i++){
      printf("%d", palin[i]);
    }
    printf("\n");
  }
}
