#include <bits/stdc++.h>
using namespace std;
vector<string> words;
string make_unused_word(int num_letters, mt19937 &rng, vector<pair<string, string> > guesses = {}) {
	string s;
	while (s.size() < 5) {
		bool done = false;
		for (auto g : guesses) {
			if (g.second[s.size()] == 'G') {
				done = true;
				s.push_back(g.first[s.size()]);
				break;
			}
		}
		if (done) continue;

		char c = 'A' + uniform_int_distribution<int>(0, num_letters-1)(rng);
		if (s.find(c) == std::string::npos) {
			s.push_back(c);
		}
	}
	if (find(words.begin(), words.end(), s) != words.end()) {
		return make_unused_word(num_letters, rng);
	} else {
		return s;
	}
}
string make_word(int num_letters, mt19937 &rng) {
	string s = make_unused_word(num_letters, rng);
	words.push_back(s);
	return s;
}

string do_guess(string ans, string guess) {
	string res;
	for (int i = 0; i < 5; i++) {
		if (guess[i] == ans[i]) res.push_back('G');
		else if (ans.find(guess[i]) != std::string::npos) res.push_back('Y');
		else res.push_back('.');
	}
	return res;
}

vector<pair<string, string> > guesses;

string make_extra_word(int num_letters, mt19937 &rng) {
	string s = make_unused_word(num_letters, rng, guesses);
	for (auto g : guesses) {
		if (do_guess(s, g.first) != g.second) {
			return make_extra_word(num_letters, rng);
		}
	}
	words.push_back(s);
	return s;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n, k, num_letters, extra;
	scanf("%d%d%d%d", &n, &k, &num_letters, &extra);

	for (int i = 0; i < n; i++) {
		make_word(num_letters, rng);
	}

	string ans = words[uniform_int_distribution<int>(0, n-1)(rng)];

	for (int i = 0; i < k; i++) {
		string guess = words[uniform_int_distribution<int>(0, n-1)(rng)];
		guesses.push_back({guess, do_guess(ans, guess)});
	}

	for (int i = 0; i < extra; i++) {
		make_extra_word(num_letters, rng);
	}

	shuffle(words.begin(), words.end(), rng);

	printf("%lu\n", words.size());
	for (auto s : words) printf("%s\n", s.c_str());

	printf("%d\n", k);

	for (int i = 0; i < k; i++) {
		printf("%s\n%s\n", guesses[i].first.c_str(), guesses[i].second.c_str());
	}
}