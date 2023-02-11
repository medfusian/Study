def make_car(brand, model, **other):
    car = {}
    car['brand'] = brand
    car['model'] = model
    for key, value in other.items():
        car[key] = value
    return car


car = make_car('subaru', 'outback', color='red')
print(car)