// Ryan
#include <iostream>
#include <map>
using namespace std;

int N;
map<string, pair<int, string>> loudests;

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string person;
		int loudness, numSports;
		cin >> person >> loudness >> numSports;
		for (int j = 0; j < numSports; ++j) {
			string sport;
			cin >> sport;
			if (loudness >= loudests[sport].first) {
				loudests[sport] = {loudness, person};
			}
		}
	}

	for (auto val  : loudests) {
		cout << "In " << val.first << ", " << val.second.second << " is the loudest!\n";
	}
}