from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
import numpy as np
import sys
 
sys.stdin = open(r'test_case.txt', 'r')

x = int(raw_input("Enter the number of centroids: "))

# Reading the centroids.
# centroids = []
# for i in range(x):
	# ls = list(map(int, raw_input("Enter the co-ordinate of a centroid: ").split()))
	# centroids.append(ls)

y = int(raw_input("Enter the number of points you want to culuster: "))
points = []
for i in range(y):
	ls = list(map(int, raw_input("Enter the co-ordinate of the point: ").split()))
	points.append(ls)

kmeans = KMeans(n_clusters = 2).fit(points)
print(kmeans.cluster_centers_) # Showing the random centroids.
print(kmeans.labels_) # Showing the centroid of each point.
