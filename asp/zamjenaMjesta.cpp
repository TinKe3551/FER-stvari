#include <iostream>


using namespace std;


int zamjenaMjesta(int n) {

	if (n < 10) return n;

	int z2 = n % 10;
	n /= 10;
	int z1 = n % 10;
	n /= 10;
	
	return z1 + 10 * z2 + 100 * zamjenaMjesta(n);

}


int main(void) {
	
	int n;
	cin >> n;

	int m = zamjenaMjesta(n);

	cout << m << endl;

	return 0;

}
