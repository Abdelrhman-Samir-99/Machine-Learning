#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
using namespace std;


double square(const double x) {
	return x * x;
}


double get_dis(const pair <double, double> &first, const pair <double, double> &second) {
	return sqrt(square(abs(first.first - second.first)) + square(abs(second.second - first.second)));
}

int main() {
	puts("Enter the number of centroids : ");
	int n;
	scanf("%d", &n);
	vector <pair<double, double>> centroid(n);
	puts("Enter the centroids co-ordinates : ");
	for(int i = 0; i < n; ++i)
		scanf("%lf %lf", &centroid[i].first, &centroid[i].second);
	puts("Enter the number of nodes : ");
	int m;
	scanf("%d", &m);
	puts("Enter the co-ordinates of each node : ");
	vector <pair<double, double>> points;
	for(int i = 0; i < m; ++i) {
		double x, y;
		scanf("%lf %lf", &x, &y);
		points.emplace_back(x, y);
	}
	vector <int> cur(m), prev(m);
	while(true) {
		for(int p = 0; p < m; ++p) {
			double best = int(1e9);
			int best_c = -1;
			for(int c = 0; c < n; ++c) {
				double current = get_dis(centroid[c], points[p]);
				if(current < best) {
					best = current;
					best_c = c;
				}
			}
			assert(best_c != -1);
			cur[p] = best_c;
		}
		if(prev == cur)
			break;
		prev = cur;
		for(int i = 0; i < n; ++i) {
			double new_x = 0;
			double new_y = 0;
			int cnt = 0;
			for(int p = 0; p < m; ++p) {
				if(prev[p] == i) {
					new_x += points[p].first;
					new_y += points[p].second;
					++cnt;
				}
			}
			centroid[i] = make_pair(new_x / cnt, new_y / cnt);
		}
	}
	for(int i = 0; i < m; ++i)
		printf("The point (%lf , %lf) belongs to the centroid %d.\n", points[i].first, points[i].second, cur[i] + 1);
}
