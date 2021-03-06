#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> hash_map;
vector<int> one_bit;
vector<int> two_bit;
void display(void) {
	cout << "hash_map: " << endl;
	for(auto it = hash_map.begin(); it != hash_map.end(); ++it)
		cout << it->first << "  " << it->second << endl;
	cout << "one_bit: " << endl;
	for (auto it = one_bit.begin(); it != one_bit.end(); ++it)
		cout << *it << endl;
	cout << "two_bit: " << endl;
	for (auto it = two_bit.begin(); it != two_bit.end(); ++it)
		cout << *it << endl;
}
void generate(int bits) {
	for (int i = 0; i < bits; ++i) {
		int val = pow(2, i);
		one_bit.push_back(val);
	}
	for (int i = 0; i < bits; ++i) {
		int val = pow(2, i);
		for (int j = i + 1; j < bits; ++j) {
			int val_1 = val + pow(2, j);
			two_bit.push_back(val_1);
		}
	}
}
int clustering(void) {
	int num_of_ver = hash_map.size();
	int* id = new int[num_of_ver];
	int i;
	for (i = 0; i < num_of_ver; ++i)
		id[i] = i;
	int count = num_of_ver;
	for (auto it = hash_map.begin(); it != hash_map.end(); ++it) {
		for (int k = 0; k < one_bit.size(); ++k) {
			int seek = it->first ^ one_bit[k];
			if (hash_map.find(seek) != hash_map.end()) {
				if (!connected(id, hash_map[seek], it->second))
					union_1(id, hash_map[seek], it->second, count);
				if (count % 100 == 0)
					cout << count << endl;
			}
		}
	}
	for (auto it = hash_map.begin(); it != hash_map.end(); ++it) {
		for (int k = 0; k < two_bit.size(); ++k) {
			int seek = it->first ^ two_bit[k];
			if (hash_map.find(seek) != hash_map.end()) {
				if (!connected(id, hash_map[seek], it->second))
					union_1(id, hash_map[seek], it->second, count);
				if (count % 100 == 0)
					cout << count << endl;
			}
		}
	}
	return count;
}
bool connected(int* id, int u, int v) {
	return find(id, u) == find(id, v);
}
void union_1(int* id, int u, int v, int& count) {
	int u_id = find(id, u);
	int v_id = find(id, v);
	if (u_id == v_id)
		return;
	for (int i = 0; i <= hash_map.size(); ++i) {
		if (id[i] == u_id)
			id[i] = v_id;
	}
	--count;
}
int find(int* id, int u) {
	return id[u];
}

int main(int argc, char** argv) {
	int line = 1;
	int num, bits;
	ifstream myfile;
	myfile.open("clustering_big.txt");
	string input;
	getline(myfile, input);
	istringstream iss(input);
	iss >> num >> bits;
	generate(bits);
	while (line <= num) {
		string str;
		getline(myfile, str);
		istringstream iss(str);
		int i = 0;
		int val = 0;
		while (i < bits) {
			int n;
			iss >> n;
			val = val * 2 + n;
			++i;
		}
		if (hash_map.find(val) == hash_map.end())
			hash_map.insert(pair<int, int>(val, hash_map.size()));
		++line;
	}
	myfile.close();
	cout << "cluster: " << clustering() << endl;
	return 0;
}
