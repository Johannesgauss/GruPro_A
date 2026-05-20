#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int l, lint;
typedef unsigned long long int ul, ulint;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	lint restaurants_num; cin>>restaurants_num;
	vector<lint>restaurants;

	for (lint i = 0; i < restaurants_num; i++) {
		lint each_restaurant; cin>>each_restaurant;
		lint new_element = each_restaurant * (1 - 2 * (i%2));
		restaurants.push_back(new_element);
	}
	vector<lint> r_sum; r_sum.push_back(restaurants[0]);
	vector<lint>rcp; rcp.push_back(restaurants[0]);
	for (ulint i = 1; i < restaurants_num; i++) {
		lint new_element = r_sum[i-1] + restaurants[i];
		r_sum.push_back(new_element);
		rcp.push_back(new_element);
	}

	sort(rcp.begin(), rcp.end());
	ulint i = 0; 
	while (i <= restaurants_num - 2 && rcp[i] != rcp[i+1] && rcp[i] != 0) {
		cout << i << endl;
		cout << rcp[i] << endl;
		i++; 
	}
	if (i == restaurants_num) {
		cout << -1 << endl;
		return 0;
	} else if (rcp[restaurants_num-1] == 0) {
		i = restaurants_num - 1;
	}
	ulint j = 0; while (j <= restaurants_num - 1 && r_sum[j] != rcp[i]) {
		cout << r_sum[i] << endl;
		j++;
	}
	cout << j+1 << " ";
	j++; while (j <= restaurants_num - 1 && r_sum[j] != rcp[i]) j++;
	cout << j+1;

	return 0;
}
