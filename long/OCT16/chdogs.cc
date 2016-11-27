#include <bits/stdc++.h>

using namespace std;

double COS_30 = 0.866025403784438646763723170752936183;
double SQRT_3 = 1.732050807568877293527446341505872366;

int main(){
	int t;
	cin >> t;
	while(t--){
		double s, v;
		cin >> s >> v;
		double distToCent = (double) s / SQRT_3;
		double speedToCent = (double) v * COS_30;
		double timeToCent = distToCent / speedToCent;
		printf("%.10f\n", timeToCent);
	}
}