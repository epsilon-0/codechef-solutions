#ifndef LIS_
#define LIS_

#include<vector>
#include<algorithm>

using namespace std;

class LIS{
 private:
  vector<int> values;
  vector<int> seqs;
  vector<int> lengths;
  int lgt;

 public:
  LIS(vector<int> values){
    this->values = values;
    lengths.resize(values.size(), 0);
    seqs.clear();
    makeLIS();
  }
  void makeLIS(){
    lengths[0] = 1;
    seqs.push_back(values[0]);
    int pos;
    for(int i = 1; i < values.size(); i++){
      if(values[i] > seqs[seqs.size()-1]){
	seqs.push_back(values[i]);
	lengths[i] = seqs.size();
      }
      else{
	pos = lower_bound(seqs.begin(), seqs.end(), values[i]) - seqs.begin();
	lengths[i] = pos+1;
	seqs[pos] = values[i];
      }
    }
    lgt = *max_element(lengths.begin(), lengths.end());
  }
  int getLength(){    
    return lgt;
  }
  vector<int> getLengthVector(){
    return lengths;
  }
};

#endif
