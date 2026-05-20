#include <iostream>
//#include <algorithm>
#include <vector>
using namespace std;
typedef long long int l, lint;
typedef unsigned long long int ul, ulint;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	ulint fights_num; ulint health; cin>>fights_num>>health;
	vector<ulint> fights;
	for (ulint i = 0; i < fights_num; i++) {
		lint each_fight; cin>>each_fight;
		fights.push_back(each_fight);
	}
	vector<ulint> fights_sum; fights_sum.push_back(0);
	for (ulint i = 1; i < fights_num+1; i++) {
		fights_sum.push_back(fights_sum[i-1] + fights[i-1]);
	}
	ulint max_score = 0;

	lint hits = 0;
	for (ulint i = 0; i < fights_num+1; i++) {
		ulint left = i, right = fights_num;
		ulint current = (left+right)/2;
		while (left <= right) {
			//cout << fights_sum[current] << " " << fights_sum[i]<<endl;
			if (fights_sum[current] - fights_sum[i] <= health) {
				left = current + 1;
				//puts("here0");
			} else {
				right = current-1;
			}
			current = (left+right)/2;
		}
		//cerr << i << " " << left <<" "<< right <<" "<< current <<" "<< endl;
		//puts("left and right");
				
		if (current - i > max_score) {
				max_score = current - i;
		}
	}
	
	cout<<max_score<<endl;

	return 0;
}
/*	
	cout<<"left "<<left<<endl;
	cout<<"right "<<right<<endl;
	cout<<"hit "<<fights[right]<<endl;
cout<<hits<<endl;
	cout<<"hits "<<hits<<endl;
*/
