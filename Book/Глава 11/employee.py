class Employee():
    """Работник и изменение его оклада"""

    def __init__(self, name, surname, salary):
        """Получает имя, фамилию и оклад"""
        self.name = name
        self.surname = surname
        self.salary = salary

    def give_raise(self, value = 5000):
        """Увеличивает ежегодный оклад"""
        self.salary += value
        return self.salary