#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int l, re;
typedef unsigned long long int ul, rea;
typedef struct er {
	re p, d;
} er;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	re n, t, m, x; cin>>n>>t>>m>>x;
	vector<er> a;

	for (re i = 0; i < n; i++) {
		re p, d; cin>>p>>d;
		er e; e.p = p; e.d = d;
		a.push_back(e);
	}

	sort(a.begin(), a.end(), [](er e1, er e2) {
		return (double) e1.p/e1.d > (double) e2.p/e2.d;
	});

	double tpoints = 0; 
	double ttime = t;
	for (re i = 0; i < n && ttime > 0; i++) {
		if (ttime >= a[i].d) {
			tpoints += a[i].p;
			ttime -= a[i].d;
		} else {
			tpoints += (double)(ttime * a[i].p) / a[i].d;
			break;
		}
	}
	
	double hpoints = 0;
	double htime = m;
	for (re i = 0; i < n && htime > 0; i++) {
		if (htime >= (double)a[i].d/x) {
			hpoints += a[i].p;
			htime -= (double)a[i].d/x;
		} else {
			hpoints += (double)(htime * a[i].p) / ((double)a[i].d/x);
			break;
		}
	};

	if (tpoints > hpoints) {
		cout << "TARTARUGA" << endl;
	} else if (tpoints < hpoints) {
		cout << "LEBRE" << endl;
	} else {
		cout << "EMPATE" << endl;
	}

	return 0;
}
