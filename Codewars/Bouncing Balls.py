def bouncing_ball(h, bounce, window):
    if not (h > 0 and bounce < 1 and bounce > 0 and window < h):
        return -1

    count = 1
    h *= bounce
    while h > window:
        count += 2
        h *= bounce
    return count