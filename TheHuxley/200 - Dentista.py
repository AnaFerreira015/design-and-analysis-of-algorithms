n = int(input())
matrix = []
for i in range(n):
    x_y = list(map(int, input().split()))
    matrix.append([x_y[1],x_y[0]])

matrix.sort()

total = 1; current = matrix[0][0]
for i in range(1, len(matrix), 1):
    if matrix[i][1] >= current:
        current = matrix[i][0]
        total += 1
print(total)
    