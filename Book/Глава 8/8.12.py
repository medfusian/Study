def make_sandvich(*components):
    """Выводит описание заданного сэндвича"""
    for component in components:
        print(f'Сэндвич содержит: {component}')

make_sandvich('carrot', 'apple')
print('-------------------------')
make_sandvich('Ham', 'Cheese', 'Lettuce')