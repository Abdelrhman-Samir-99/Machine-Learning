#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;


int square(const int x) {
	return x * x;
}


void new_weight(vector <vector <int>> &items, vector <vector <double>> &weights, const double &lambda,
															bool are_equal, int current_w, int current_item) {
	
	int factor = are_equal ? 1 : -1;
	int row_cnt = items[1].size() - 1;
	assert(row_cnt > 0);
	for(int r = 1; r <= row_cnt; ++r) {
		weights[r][current_w] = weights[r][current_w] + lambda * factor * (items[current_item][r] - weights[r][current_w]);
	}
}


void print(const vector <vector<double>> &weights, int current_row, int n, int c) {
	cout << "The weights after the " << current_row << ' ' << "Iterations look like this : \n";
	for(int i = 1; i <= c; ++i) {
		for(int j = 1; j <= n; ++j)
			printf("%lf ", weights[i][j]);
		puts("");
	}
	puts("");
}

int main() {
	puts("Enter the number of rows : ");
	int r;
	scanf("%d", &r);
	puts("Enter the number of columns : ");
	int c;
	scanf("%d", &c);
	vector <vector <int>> items(r + 1, vector <int> (c + 1));
	assert(r > 0 && c > 0);
	puts("Enter the values : ");
	for(int i = 1; i <= r; ++i)
		for(int j = 1; j <= c; ++j)
			scanf("%d", &items[i][j]);
	puts("Enter the target values : ");
	vector <int> T(r + 1);
	for(int i = 1; i <= r; ++i)
		scanf("%d", &T[i]);
	puts("Enter the number of weights : ");
	int n;
	scanf("%d", &n);
	vector <vector <double>> weights(c + 1, vector <double> (n + 1));
	for(int i = 1; i <= c; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%lf", &weights[i][j]);
	puts("Enter the value of lambda : ");
	double lambda;
	scanf("%lf", &lambda);

	for(int current_row = 1; current_row <= r; ++current_row) {
		int best = 1e9;
		
		// getting the best weight for each item.
		vector <int> all_w;
		for(int current_w = 1; current_w <= n; ++current_w) {
			int total_w = 0;
			for(int current_col = 1; current_col <= c; ++current_col)
				total_w += square(items[current_row][current_col] - weights[current_col][current_w]);
			all_w.push_back(total_w);
			best = min(best, total_w);
		}
		assert(best != 1e9);
		// modifying the weights, including the case when multiple weights are equal to the minimum.
		for(int current_w = 0; current_w < n; ++current_w) {
			if(all_w[current_w] == best)
				new_weight(items, weights, lambda, current_w + 1 == T[current_row], current_w + 1, current_row);
		}
		print(weights, current_row, n, c);
	}
}
