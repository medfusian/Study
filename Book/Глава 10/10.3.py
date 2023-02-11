file_name = 'Book\\files\\guest.txt'

with open(file_name, 'w', encoding='utf8') as file:
    name = input('Введите имя пользователя: ')
    file.write(name)
    