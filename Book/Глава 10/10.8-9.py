def Rfile(file_name):

    try:
        with open(file_name, encoding='utf8') as file:
            animals = file.readlines()
    except FileNotFoundError:
        pass
    else:
        for animal in animals:
            print(animal.rstrip())


Rfile('Book\\files\\cats.txt')
print('\n')
Rfile('Book\\files\\dogs.txt')