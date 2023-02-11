def array_diff(a, b):
    for currentNumber in b:
        for number in a:
            if currentNumber in a:
                a.remove(currentNumber)
    return (a)

print(array_diff([2, 4, 3, 2], [2]))