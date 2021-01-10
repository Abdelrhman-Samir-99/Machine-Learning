import numpy as np
import sys
 
sys.stdin = open(r'test_case.txt', 'r')

#Reading input section.
max_depth = int(raw_input("Enter the maximum depth: "))
n = int(raw_input("Enter the number of nodes: "))
m = int(raw_input("Etner the number of edges: "))

adj_matrix = []
rev_adj_matrix = []
n = n + 1 # so we can work 1-based.

#initializing the adjacency matrix.
for i in range(n):
	ls = [0] * n
	ls2 = [0] * n #python is a TRASH languge. this can make a serious bug with references.
	adj_matrix.append(ls)
	rev_adj_matrix.append(ls2)

print("Now enter information about every edge.")
for i in range(m):
	ls = list(map(int, raw_input("Enter from to: ").split()))
	u = ls[0]
	v = ls[1]
	w = float(raw_input("Enter the weight: "))
	rev_adj_matrix[v][u] = w
	adj_matrix[u][v] = w

all_depth = []
for i in range(0, max_depth + 1):
	print("Enter the nodes at depth ", i)
	ls = list(map(int, raw_input().split()))
	all_depth.append(ls)

all_v = [0] * n
print("Now enter the input values of all the nodes in depth 0: ")
for i in range(len(all_depth[0])):
	ls = list(map(int, raw_input("Enter the node and it's input value: ").split()))
	u = ls[0]
	v = ls[1]
	all_v[u] = v

expected = float(raw_input("Enter the expected output to calculate the error: "))
LR = float(raw_input("Enter the learning rate value: "))
# The end of reading input section.


# Some AI functions i believe :3.
def sigmoid(x):
	return 1 / (1 + np.log(x)**(-x))

def Linear_activation_function(x):
	if(x > 1):
		return 1
	else:
		return 0
def Linear_function(x):
	return x

def Printing_function():
	for i in range(1, n):
		print(all_v[i])

# Calculating the value of each node.
for current_depth in range(1, max_depth + 1):
	for current_node in all_depth[current_depth]:
		total = 0
		for parent in range(n):
			total += (all_v[parent] * rev_adj_matrix[current_node][parent])
		all_v[current_node] = total
 
Printing_function()

error = 0.5 * (all_v[n - 1] - expected)**2
delta = all_v[n - 1] - expected
#Calculattions end here.

#Reducing the error section.
for current_depth in range(max_depth, -1, -1):
	for current_node in all_depth[current_depth]:
		output = 0
		for to in range(n):
			output += adj_matrix[current_node][to]
			if(output == 0):
				output = 1
		for current_child in range(n):
			if(rev_adj_matrix[current_node][current_child] == 0):
				continue
			new_weight = rev_adj_matrix[current_node][current_child] - LR * delta * output * all_v[current_child]
			rev_adj_matrix[current_node][current_child] = adj_matrix[current_child][current_node] = new_weight

for i in range(n):
	print(adj_matrix[i])
