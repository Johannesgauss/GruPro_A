#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int l, lint;
typedef unsigned long long int ul, ulint;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	lint restaurants_num; lint health; cin>>restaurants_num>>health;
	vector<lint> restaurants;
	vector<lint> restaurants_prefix_sum;
	for (lint i = 0; i < restaurants_num; i++) {
		lint each_restaurant; cin>>each_restaurant;
		lint new_element = each_restaurant * (1 - 2 * (i%2));
		restaurants.push_back(new_element);
	}

	restaurants_prefix_sum[0] = restaurants[0];
	for (lint i = 1; i < restaurants_num; i++) {
		restaurants_prefix_sum[i] = restaurants_prefix_sum[i-1] + restaurants[i];
	}
	sort(restaurants_prefix_sum.begin(), restaurants_prefix_sum.end());
	for (lint i = 0; i < restaurants_num && restaurants[i] == restaurants[i+1]; i++);
	sort(restaurants_prefix_sum.begin(), restaurants_prefix_sum.end());

	return 0;
}
