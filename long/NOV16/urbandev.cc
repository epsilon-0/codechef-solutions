#include <bits/stdc++.h>

using namespace std;

int lines[100005];
int sums[5*100005];

void insert(int bot, int top, int y){
  
}

void remove(int bot, int top, int y){
  
}

int query()



vector<pair<int, int> > horizontal;
vector<pair<int, pair<int, int> > > vertical;

set<pair<int, int> > horizontalEndPoints;

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, x2--, y1--, y2--;
    if(x1 == x2)
      vertical.push_back(make_pair(x1, make_pair(min(y1, y2), max(y1, y2))));
    else{
      horizontal.push_back(make_pair(min(x1, x2), y1)), horizontal.push_back(make_pair(max(x1, x2), -1 * y1));
      horizontalEndPoints.push_back(make_pair(x1, y1));
      horizontalEndPoints.push_back(make_pair(x2, y2));
    }
  }

  sort(horizontal.begin(), horizontal.end());
  sort(vertical.begin(), vertical.end());

}