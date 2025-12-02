data = input()
parts = data.split(",")


def checkRepeat(start, end):
    total = 0
    for i in range(start, end):
        s = str(i)
        L = len(s)

        repeated = False

        for size in range(1, L // 2 + 1):
            if L % size != 0:
                continue

            block = s[:size]
            if block * (L // size) == s:
                repeated = True
                break

        if repeated:
            total += i

    return total


result = 0

for p in parts:
    start, end = p.split("-")
    start = int(start)
    end = int(end)
    result += checkRepeat(start, end + 1)

print(result)
