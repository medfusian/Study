file_name = 'Book\\files\\guest_book.txt'

with open(file_name, 'w', encoding='utf8') as file:
    while True:
        name = input('Введите имя пользователя: ')
        if not (name == ''):
            print('Здравствуйте ' + name + '\n')
            file.write(name + '\n')
        else:
            break
