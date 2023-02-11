import unittest
from employee import Employee


class TestEmployee(unittest.TestCase):
    """Тесты для класса Employee"""

    def setUp(self):
        """Создание опроса"""
        self.best_employee = Employee('Влад', 'Люстра', 10000)

    def test_give_default_raise(self):
        """Проверяет увеличение оклада по умолчанию"""
        result = self.best_employee.give_raise()
        self.assertEqual(result, 15000)

    def test_give_custom_raise(self):
        """Проверяет кастомное увеличение оклада"""
        self.assertEqual(self.best_employee.give_raise(2000), 12000)
        self.assertEqual(self.best_employee.give_raise(4000), 16000)


unittest.main()