print('Для выхода введите "q q"')

while True:

    x, y = input('Введите два числа через пробел: ').split()

    if not (x == 'q' and y == 'q'):

        try:
            sum = int(x) + int(y)
        except ValueError:
            print('Введен текст!')
        else:
            print('Сумма: ' + str(sum))

    else:
        break