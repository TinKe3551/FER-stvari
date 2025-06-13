#include <iostream>
#include <set>

using namespace std;

int mat_sus[15][15];
set<int> incidentni[15];
set<int> posjeceni;

void trazi(int &pocetni, int v, int l, int &k, bool &postoji) {

  if (postoji)
    return;

  if (l == k && incidentni[v].count(pocetni) > 0) {
    postoji = true;
    return;
  }

  else if (l == k) {
    return;
  }

  posjeceni.insert(v);

  for (int i : incidentni[v]) {

    if (posjeceni.count(i) > 0)
      continue;

    trazi(pocetni, i, l + 1, k, postoji);
  }

  posjeceni.erase(v);
}

int main(void) {

  string dat;
  // cout << "Unesite ime datoteke: ";
  // cin >> dat;
  dat = "graf.txt";

  freopen(dat.c_str(), "r", stdin);

  int n;
  cin >> n;

  int k;
  cin >> k;

  if (k > n) {
    cout << 0 << '\n';
    return 0;
  }

  // matrica susjedstva

  for (int i = 0; i < n; i++) {

    string redak;
    cin >> redak;

    for (int j = 0; j < n; j++) {

      if (redak[j] == '1')
        mat_sus[i][j] = 1;
      else
        mat_sus[i][j] = 0;
    }
  }

  // incidentni vrhovi

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {

      if (mat_sus[i][j] == 1)
        incidentni[i].emplace(j);
    }
  }

  bool postoji = false;

  // trazenje ciklusa

  for (int i = 0; i < n; i++) {

    trazi(i, i, 1, k, postoji);
  }

  // konacni rezultat
  cout << postoji << '\n';
}
