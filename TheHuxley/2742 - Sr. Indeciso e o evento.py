def binary_search(list, element):
    begin = 0; end = len(list) - 1
    while begin <= end:
        mid = (end + begin) // 2
        if list[mid] == element:
            return mid
        elif element > list[mid]:
            begin = mid + 1
        else:
            end = mid -1
    return mid


def search(x, numbers):
    i = binary_search(numbers, x)
    # print("index", i)
    j = k = i
    if numbers[i] == x:
        lo = hi = i
        while numbers[j - 1] == x:
            lo = j - 1
            j -= 1
        while numbers[k + 1] == x:
            hi = k + 1
            k += 1
        print(lo, hi)
        return
    else:
        if numbers[i] > x:
            print(i, i - 1)
        else:
            print(i, i + 1)
    

n = int(input())
numbers = []

numbers = list(map(int, input().split()))
# print(numbers)

q = int(input())
for i in range(q):
    x = int(input())
    search(x, numbers)

