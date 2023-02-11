filename = r'Book\files\chislopi.txt'

with open(filename) as file:
    lines = file.readlines()

pi_string = ''
for line in lines:
    pi_string += line.strip()

print('Число пи: ' + str(pi_string))
print('Длина: ' + str(len(pi_string)))