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
	ulint max_score = 0;
	ulint left = 0, right = 0;

	lint hits = 0;
	while (left <= right) {
		while (right != fights_num - 1 && hits + fights[right+1] <= health) {
			hits += fights[right];
			right++;
		}
		if (right - left > max_score)
			max_score = right - left;
		hits -= fights[left];
		left++;
	}
	if (1 > max_score)
		max_score = 1;
	
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
