def nb_year(p0, percent, aug, p):
    n = 0
    while p0 < p:
        p0 += int(p0 * (percent / 100) + aug)
        n += 1
    return n

print(nb_year(1500000, 0.25, 1000, 2000000))