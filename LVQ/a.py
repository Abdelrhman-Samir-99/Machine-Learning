import sys

sys.stdin = open(r'test_case.txt', 'r')

r = int(raw_input("Enter the number of rows for items: "))
c = int(raw_input("Enter the number of columns for items: "))


items = []
for i in range(r):
	current_row2 = list(map(int, raw_input().split()))
	items.append(current_row2)

target = list(map(int, raw_input("Now Enter the target value for each item: ").split()))

rw = int(raw_input("Enter the number of rows for weights: "))
cw = int(raw_input("Enter the number of columns for weights: "))

weights = []
for i in range(rw):
	current_row2 = list(map(int, raw_input().split()))
	weights.append(current_row2)

lambda_v = float(raw_input("Enter the value of lambda: "))

def printing_func(current_iteration):
	print("The weights array after iteration number " + str(current_iteration) + " like this: ")
	for current_row2 in weights:
		print(current_row2)

def new_weight(current_w, target_w, current_item):
	factor = 1
	if(current_w + 1 != target_w):
		factor = -1
	for i in range(rw):
		weights[i][current_w] = weights[i][current_w] + lambda_v * factor * (items[current_item][i] - weights[i][current_w])

print("")
for current_row in range(r):
	best = 100000000009
	all_w = [] # the distance between the current item and all the weights. (like a simple graph)
	for current_w in range(cw):
		total_w = 0
		for current_col in range(c):
			total_w += (items[current_row][current_col] - weights[current_col][current_w])**2
		all_w.append(total_w)
		best = min(best, total_w)
	for current_w in range(cw):
		if(all_w[current_w] == best):
			new_weight(current_w, target[current_row], current_row)
	printing_func(current_row + 1)

