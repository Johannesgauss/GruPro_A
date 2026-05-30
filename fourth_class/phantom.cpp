#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int l, re;
typedef unsigned long long int ul, rea;
typedef struct er {
	re i, f;
} er;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	re n; cin>>n;
	vector<er> a;

	for (re i = 0; i < n; i++) {
		re h1, m1, h2, m2; cin>>h1>>m1>>h2>>m2;
		er h; h.i = h1*100 + m1; h.f = h2*100 + m2; 
		a.push_back(h);
	}

	sort(a.begin(), a.end(), [](er h1, er h2) {
		return h1.f < h2.f;
	});
	for (re i = 0; i < n; i++) {
//		cout << a[i].i << " " << a[i].f << endl;
	}

	re r = 1, at = 0;
	for (re i = 1; i < n; i++) {
		if (a[at].f > a[i].i)	{
			//cout << a[at].i << " " << a[i].f << endl;
			//cout << "isso" << endl;
			continue;
		}
		r++; at = i;
	}
	
	cout << r <<endl;

	return 0;
}
