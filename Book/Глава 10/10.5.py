file_name = 'Book\\files\\10.5.txt'

with open(file_name, 'w', encoding='utf8') as file:
    while True:
        cause = input('Почему вам нравится програмировать: ')
        if not (cause == ''):
            file.write(cause + '\n')
        else:
            break