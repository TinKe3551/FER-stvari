#include <bits/stdc++.h>


using namespace std;


map<string, vector<string>> produkcije = {
    {"S", {"aAB", "bBA"}},
    {"A", {"bC", "a"}},
    {"B", {"ccSbc", ""}},
    {"C", {"AA"}}
};

deque<char> nezavrsni;
vector<string> rekreacija;


void rekreiraj(string &zadani) {
    
    

}


int main(void) {

    string zadani;
    cin >> zadani;

    rekreiraj(zadani);

    return 0;
}