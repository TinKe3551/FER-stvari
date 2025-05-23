#include <iostream>
#include <bits/stdc++.h>


using namespace std;


void unesi_duzinu(stack<pair<int, int>> &duzine, int l, int d) {

	if (duzine.empty()) {
		duzine.emplace(pair<int, int>(l, d));
		return;
	}

	stack<pair<int, int>> duzine2;

	while (!duzine.empty()) {

		if (duzine.top().first > d) break;

		if (duzine.top().second < l) {

			duzine2.emplace(duzine.top());
			duzine.pop();
			continue;

		}

		d = max(d, duzine.top().second);
		l = min(l, duzine.top().first);
		duzine.pop();

	}

	duzine.emplace(pair<int, int>(l, d));
	
	while (!duzine2.empty()) {

		duzine.emplace(duzine2.top());
		duzine2.pop();

	}

}


int main(void) {

	map<int, stack<pair<int, int>>> duzine;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		
		int x1, y1, x2, y2;
		cin >> x1;
		cin >> y1;
		cin >> x2;
		cin >> y2;

		for (int y = y1; y <= y2; y++) {

			if (duzine.count(y) < 1) duzine[y] = stack<pair<int, int>>();
			unesi_duzinu(duzine[y], x1, x2);

		}

	}

	long long A;
	cin >> A;

	long long P;
	P = 0;

	for (auto i: duzine) {

		#ifdef debug
		cout << "> " << i.first << '\n';
		#endif

		while (!i.second.empty()) {

			#ifdef debug
			cout << i.second.top().first << ' ' << i.second.top().second << '\n';
			#endif

			P += i.second.top().second - i.second.top().first + 1;
			i.second.pop();

		}

	}

	cout << P << '\n';
	

	
	return 0;

}
