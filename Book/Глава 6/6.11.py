cities = {
    'Moscow': {
        'country': 'Russia',
        'population': 11.92,
        'fact': 'Very big city',
    },
    'Brest': {
        'country': 'Belarus',
        'population': 0.34,
        'fact': 'My hometown',
    } ,
    'Berlin': {
        'country': 'Germany',
        'population': 3.64,
        'fact': 'The capital of Germany'
    }
}

for city, information in cities.items():
    print(city + ':')
    print('country ' + information['country'])
    print('population ' + str(information['population']))
    print('fact ' + information['fact'])
    print()