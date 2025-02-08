#include <iostream>
#include <bits/stdc++.h>


using namespace std;


int main(void) {

	map<int, set<pair<int, int>>> duzine;
	set<int> x_razine;
	set<int> y_razine;
	map<int, set<int>> tocke; // tocke[x_i] = {y_j, y_(j+1), ...}
	map<pair<int, int>, int> donje_t;
	map<pair<int, pair<int, int>>, int> donje_d;
	int n;
	long long A;

	cin >> n;

	for (int i = 0; i < n; i++) {

		int x[2];
		int y[2];

		cin >> x[0];
		cin >> y[0];
		cin >> x[1];
		cin >> y[1];

		for (int j = 0; j < 2; j++) {

			x_razine.insert(x[j]);
			y_razine.insert(y[j]);

			for (int k = 0; k < 2; k++) {

				tocke[x[j]].insert(y[k]);

				pair<int, int> t = pair<int, int>(x[j], y[k]);
				if (donje_t.count(t) == 0) donje_t[t] = 0;
				donje_t[t] -= 2 * k - 1;

			}

		}

		for (int k = 0; k < 2; k++) {

			pair<int, pair<int, int>> d = pair<int, pair<int, int>>(y[k], pair<int, int>(x[0], x[1]));
			duzine[d.first].insert(d.second);
			if (donje_d.count(d) == 0) donje_d[d] = 0;
			donje_d[d] -= 2 * k - 1;

		}

	}

	cin >> A;

	long long P = 0;

	while (!x_razine.empty()) {

		int x = *(x_razine.begin());
		int m = 0;
		int y0 = 0;
		int f = 0;

		#ifdef debug
		cout << "----------------\n";
		cout << "pravac x = " << x << '\n';
		cout << "y: ";
		#endif

		for (int y: y_razine) {

			for (auto d: duzine[y]) {

				if (d.first > x || d.second < x) continue;

				tocke[x].insert(y);
				pair<int, int> t = pair<int, int>(x, y);
				if (donje_t.count(t) == 0) donje_t[t] = 0;
				donje_t[t] += donje_d[pair<int, pair<int, int>>(y, d)];

			}
		}

		for (int y: tocke[x]) {

			#ifdef debug
			cout << y << ' ';
			#endif
			
			pair<int, int> tocka = pair<int, int>(x, y);

			if (m == 0) y0 = y;

			m += donje_t[tocka];
			if (m == 0) {
				f += y - y0 + 1;
				y0 = y;
			}

		}

		P += f;

		#ifdef debug
		cout << '\n';
		cout << "površina na ovom pravcu: " << f << '\n';
		cout << "ukupna površina dosad: " << P << '\n';
		#endif

		x_razine.erase(x);
		if (x_razine.empty()) break;

		int x2 = *(x_razine.begin());
		m = 0;
		f = 0;
		y0 = 0;

		#ifdef debug
		cout << "----------------\n";
		cout << "prostor između pravaca x = " << x << " i x = " << x2 << '\n';
		cout << "duzine (y, x1, x2): ";
		#endif

		for (int y: y_razine) {

			if (m == 0) y0 = y;
			bool aaa = false;

			for (auto d: duzine[y]) {

				if (d.first > x || d.second < x2) continue;
				aaa = true;

				#ifdef debug
				printf("(%d, %d, %d) ", y, d.first, d.second);
				#endif

				pair<int, pair<int, int>> duzina = pair<int, pair<int, int>>(y, d);

				m += donje_d[duzina];

			}

			#ifdef debug
			cout << aaa << '\n';
			#endif

			if (m == 0 && aaa) {
				f += y - y0 + 1;
				y0 = y;
			}

		}

		P += f * (x2 - x - 1);

		#ifdef debug
		cout << '\n';
		cout << "faktor za površinu na ovom prostoru: " << f << '\n';
		cout << "ukupna površina dosad: " << P << '\n';
		#endif

	}

	if (A == P) cout << "YES\n";
	else cout << "NO\n";

	//cout << P << endl;

	return 0;

}
