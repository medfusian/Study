cars = ['bmw', 'opel', 'reno', 'audi', 'lexus', 'volvo', 'jeep', 'dodge']

print('The first item three item in the list are: ')
print(cars[:3])

print('Three item from the midle of the list are: ')
midle_cars = len(cars) / 2
print(cars[int(midle_cars):int(midle_cars + 3)])

print('The last three item from the list are: ')
print(cars[-3:])