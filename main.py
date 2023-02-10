# def sum(a, b):
#     return a + b


# numbers = (3, 6, 12, 3.14, 4)
# for number in numbers:
#     print(number - 1)

# print()

# nextNumbers = range(5)
# for number in nextNumbers:
#     print(number + 1)
#     if number == 4:
#         print('End')

# print()
# print(sum(numbers[0], nextNumbers[0]))


# def make_car(brand, model, **other):
#     car = {}
#     car['brand'] = brand
#     car['model'] = model
#     for key, value in other.items():
#         car[key] = value
#     return car


# КЛАССЫ


# class Snake():
#     """описание змеи"""

#     def __init__(self, name, length):
#         """свойсьва дома"""
#         self.name = name
#         self.length = length

#     def eat(self, value):
#         """увеличивает змею"""
#         print('исходный размер змеи: ' + str(self.length))
#         self.length += value
#         print('итоговый размер змеи: ' + str(self.length))

# Snake1 = Snake("Python", 14)
# Snake1.eat(12)


#ОБЪЕКТ-ГЕНЕРАТОР

# def skat(n):
#     """Функция, которая возвращает объект-генератор, способный предоставить нам 
#     элементы по запросу от 0 до n"""
#     cnt = 0
#     while cnt < n:
#         yield cnt
#         cnt += 1


# def first_eater(golod, skat):
#     """Первый подопытный"""
#     while golod > 0:
#         eda = next(skat)
#         print(f"Первый подопытный съел {eda} и в результате написал: ", eda)
#         golod -= 1


# def second_eater(golod, skat):
#     """Второй подопытный"""
#     while golod > 0:
#         eda = next(skat)
#         print(f"Второй подопытный съел {eda} и в результате написал: ", str(eda) * 4)
#         golod -= 1


# def third_eater(golod, skat):
#     """Третий подопытный"""
#     while golod > 0:
#         eda = next(skat)
#         print(f"Третий подопытный съел {eda} и в результате написал: ", str(eda) * 10)
#         golod -= 1


# skat_gen_obj = skat(100_000_000)
# golod_1 = 2
# golod_2 = 3
# golod_3 = 4

# try:
#     first_eater(golod_1, skat_gen_obj)
#     second_eater(golod_2, skat_gen_obj)
#     third_eater(golod_3, skat_gen_obj)
# except StopIteration:
#     print("Заряды в скатерти кончились!")


#АСИНХРОННОСТЬ
import asyncio
import time


async def fun1(x):
    print(x**2)
    await asyncio.sleep(3)
    print('fun1 завершена')


async def fun2(x):
    print(x**0.5)
    await asyncio.sleep(3)
    print('fun2 завершена')


async def main():
    task1 = asyncio.create_task(fun1(4))
    task2 = asyncio.create_task(fun2(4))

    await task1
    await task2


print(time.strftime('%X'))

asyncio.run(main())

print(time.strftime('%X'))