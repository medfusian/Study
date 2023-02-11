names_magicians = ['mile', 'niop', 'klop']

def show_magicians(names):
    """Выводит список фокусников"""
    for name in names:
        print(name)

def make_great(names):
    """Добавляет к имени каждого фокусника 'Great'"""
    for key, value in enumerate(names):
        names[key] = 'Great ' + value
    return names

show_magicians(make_great(names_magicians[:]))
show_magicians(names_magicians)