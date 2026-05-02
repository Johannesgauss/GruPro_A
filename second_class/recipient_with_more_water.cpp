#include <iostream>
//#include <algorithm>
#include <vector>
using namespace std;
typedef long long int l, lint;
typedef unsigned long long int ul, ulint;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	lint logs_num; cin>>logs_num;
	vector<lint> logs;
	for (lint i = 0; i < logs_num; i++) {
		lint each_log; cin>>each_log;
		logs.push_back(each_log);
	}
	
	lint left = 0, right = logs_num - 1;
	lint max_water = 0;
	while (right > left) {
		lint shorter_log_pos = (logs[left] <= logs[right]) ? left : right;
		lint tmp_max_water = logs[shorter_log_pos] * (right - left);
		if (tmp_max_water > max_water)
			max_water = tmp_max_water;

		lint tmp_left = left, tmp_right = right;
		while (tmp_left < right && logs[tmp_left] <= logs[shorter_log_pos]) tmp_left++;
		while (left < tmp_right && logs[tmp_right] <= logs[shorter_log_pos]) tmp_right--;
		left = tmp_left;
		right = tmp_right;
	}
	cout<<max_water<<endl;

	return 0;
}
