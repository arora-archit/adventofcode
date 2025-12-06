matrix = []

while True:
    try:
        line = input().strip()
    except EOFError:
        break

    if line:
        matrix.append(list(map(str, line.split())))


index = 0
result = 0

for op in matrix[-1]:
    if op == "*":
        res = 1
        for row in matrix[:-1]:
            res = res * int(row[index])
        index += 1
    elif op == "+":
        res = 0
        for row in matrix[:-1]:
            res = res + int(row[index])
        index += 1
    result += res

print(result)
