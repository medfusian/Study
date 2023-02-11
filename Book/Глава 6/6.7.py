first_human = {
    'first_name': 'Vlad',
    'last_name': 'Lisov',
    'age': 19,
    'city': 'Minsk',
}

second_human = {
    'first_name': 'Maks',
    'last_name': 'Pupkin',
    'age': 21,
    'city': 'Minsk',
}

third_human = {
    'first_name': 'Alina',
    'last_name': 'Novarskaya',
    'age': 18,
    'city': 'Brest',
}

humans = [first_human, second_human, third_human]

for human in humans:
    print(human['first_name'])
    print(human['last_name'])
    print(human['age'])
    print(human['city'])
    print()