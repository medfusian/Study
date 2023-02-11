def make_car(brand, model, **other):
    car = {}
    car['brand'] = brand
    car['model'] = model
    for key, value in other.items():
        car[key] = value
    return car