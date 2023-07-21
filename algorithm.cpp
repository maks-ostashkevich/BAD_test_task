#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

int main() {
	string line;
	vector<string> v;

	while (getline(cin, line)) {
		if (line.empty()) {
			break;
		}
		v.push_back(line);
	}

	vector<char> firstUniqueWordSymbols;

	for (int i = 0; i < v.size(); ++i) {
		vector<string> words;
		string s;
		stringstream ss(v.at(i));

		while (getline(ss, s, ' ')) {
			words.push_back(s);
		}

		for (int j = 0; j < words.size(); ++j) {
			unordered_map<char, int> lettersCounts;
			for (int k = 0; k < words.at(j).size(); ++k) {
				if (lettersCounts.find(words.at(j).at(k)) != lettersCounts.end()) {
					++lettersCounts[words.at(j).at(k)];
				}
				else {
					lettersCounts.insert(pair<const char, int>(words.at(j).at(k), 1));
				}
			}
			for (int k = 0; k < words.at(j).size(); ++k) {
				if (lettersCounts[words.at(j).at(k)] == 1) {
					firstUniqueWordSymbols.push_back(words.at(j).at(k));
					break;
				}
			}
		}
	}

	unordered_map<char, int> firstUniqueWordSymbolsHashTable;
	for (int i = 0; i < firstUniqueWordSymbols.size(); ++i) {
		if (firstUniqueWordSymbolsHashTable.find(firstUniqueWordSymbols.at(i)) != firstUniqueWordSymbolsHashTable.end()) {
			++firstUniqueWordSymbolsHashTable[firstUniqueWordSymbols.at(i)];
		}
		else {
			firstUniqueWordSymbolsHashTable.insert(pair<const char, int>(firstUniqueWordSymbols.at(i), 1));
		}
	}
	bool uniqueExists = false;
	for (int i = 0; i < firstUniqueWordSymbols.size(); ++i) {
		if (firstUniqueWordSymbolsHashTable[firstUniqueWordSymbols.at(i)] == 1) {
			uniqueExists = true;
			cout << firstUniqueWordSymbols.at(i) << endl;
			break;
		}
	}
	if (!uniqueExists) {
		cout << -1 << endl;
	}
}
