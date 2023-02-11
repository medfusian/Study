def city_country(city, country, population=''):
    """Форматирует название города и страны"""
    if population:
        return (city.title() + ', ' + country.title() + ' - population=' +
                str(population))
    else:
        return city.title() + ', ' + country.title()
