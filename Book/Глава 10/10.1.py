file_name = 'Book\\files\\10.1.txt'

with open(file_name, 'r', encoding='utf8') as file:
    lines = file.readlines()

for i in range(3):
    for line in lines:
        print(line.rstrip())
    print('\n')