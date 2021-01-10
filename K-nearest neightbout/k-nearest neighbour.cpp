#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int square(const int x) {
	return x * x;
}

int get_dis(const pair <int, int> &first, const pair <int, int> &second) {
	return square(first.first - second.first) + square(second.second - first.second);
}

int main() {
	puts("Enter the number of items : ");
	int n;
	scanf("%d", &n);
	pair <int, int> items[n];
	string classifications[n];
	for(int i = 0; i < n; ++i) {
		scanf("%d %d", &items[i].first, &items[i].second);
		cin >> classifications[i];
	}
	puts("Enter the query instance : ");
	pair <int, int> query_Instance;
	scanf("%d %d", &query_Instance.first, &query_Instance.second);
	vector <pair<int, int>> new_items(n);
	for(int i = 0; i < n; ++i)
		new_items[i] = make_pair(get_dis(items[i], query_Instance), i);
	sort(new_items.begin(), new_items.end());
	puts("Enter the value of k : ");
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; ++i)
		cout << "The classification is " << ' ' <<  classifications[new_items[i].second] << '\n';
}
