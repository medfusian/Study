import unittest
from city_function import city_country


class CityTestCase(unittest.TestCase):
    """Тесты для 'city_function.py'"""

    def test_city_country(self):
        """Проверка значений типа: 'santiago' и 'chile'"""
        result = city_country('santiago', 'chile')
        self.assertEqual(result, 'Santiago, Chile')

    def test_city_country_population(self):
        """Проверка значений типа: 'santiago', 'chile' и '50000'"""
        result = city_country('santiago', 'chile', 50000)
        self.assertEqual(result, 'Santiago, Chile - population=50000')


unittest.main()