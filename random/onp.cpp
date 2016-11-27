#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    string expr;
    cin >> expr;
    stack<char> operators;
    for(int i = 0; i < expr.length(); i++){
      if(isalpha(expr[i])){
	cout << expr[i];
      }
      else if(expr[i] == ')'){
	cout << operators.top();
	operators.pop();
      }
      else if(expr[i] != '('){
	operators.push(expr[i]);
      }
    }
    cout << endl;
  }
}
