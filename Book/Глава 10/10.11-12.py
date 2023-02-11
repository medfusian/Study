import json

file_name = 'Book\\files\\favnumber.json'


def get_stored_number():
    """Чтение любимого числа из файла"""
    try:
        with open(file_name) as file:
            num = json.load(file)
    except FileNotFoundError:
        get_new_number()
    else:
        return 'Я знаю ваше любимое число! Это ' + str(num)


def get_new_number():
    """Получение любимого числа пользователя"""
    with open(file_name, 'w') as file:
        num = input('Введите ваше любимое число: ')
        json.dump(num, file)


print(get_stored_number())