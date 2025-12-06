import numpy as np

matrix = []

while True:
    try:
        line = input()
    except EOFError:
        break

    if line:
        matrix.append(list(line)[::-1])

transposed = np.transpose(matrix)

numbers = []
final_result = 0

for row in transposed:
    num_str = "".join(row[:-1]).strip()
    op = row[-1]

    if num_str == "":
        continue

    num = int(num_str)
    numbers.append(num)

    if op in ["+", "*"]:
        if op == "+":
            result = sum(numbers)
        else:
            result = 1
            for n in numbers:
                result *= n

        final_result += result
        numbers = []

print(final_result)
