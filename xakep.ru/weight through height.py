height = input('Введите свой рост: ')
sex = input('Введите свой пол (Male or Female): ')
if sex == 'Male':
    weigth = (int(height) - 100) * 1.15
    print('Ваш идеальный вес: ' + str(round(weigth)))
elif sex == 'Female':
    weigth = (int(height) - 110) * 1.15
    print('Ваш идеальный вес: ' + str(round(weigth)))
else:
    print('Error')