pizzas = ['pigeon', 'Owl', 'Tomtit', 'Hen']
print(pizzas)

friend_pizzas = pizzas[:]
print(friend_pizzas)

pizzas.append('crow')
friend_pizzas.append('duck')

print('My favorite pizzas are: ')
for pizza in pizzas:
    print(pizza)

print('My favorite friend pizzas are: ')
for friend_pizza in friend_pizzas:
    print(friend_pizza)