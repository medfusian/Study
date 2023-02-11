import socket
# Список портов для сканирования
ports = [
    20, 21, 22, 23, 25, 42, 43, 53, 67, 69, 80, 110, 115, 123, 137, 138, 139,
    143, 161, 179, 443, 445, 514, 515, 993, 995, 1080, 1194, 1433, 1702, 1723,
    3128, 3268, 3306, 3389, 5432, 5060, 5900, 5938, 8080, 10000, 20000
]
# Открываем файл со списком IP
f = open(
    u'C:\\Users\\vlads\\Documents\\Python\\Test1\\xakep.ru\\Список IP.txt',
    'r',
    encoding='UTF-8')
# Открываем файл с отчетом
fl = open(
    u'C:\\Users\\vlads\\Documents\\Python\\Test1\\xakep.ru\\Отчет IP.txt',
    'a',
    encoding='UTF-8')
for ip in f:
    host = ip
    print("Ожидай, идет сканирование портов!")
    # В цикле перебираем порты из списка
    for port in ports:
        # Создаем сокет
        s = socket.socket()
        # Ставим тайм-аут в одну cекунду
        s.settimeout(1)
        # Ловим ошибки
        try:
            # Пробуем соединиться, хост и порт передаем как список
            s.connect((host, port))
        # Если соединение вызвало ошибку
        except socket.error:
            # тогда ничего не делаем
            pass
        else:
            fl.write(f"{host}: {port} порт активен")
            # Закрываем соединение
            s.close
    print("Сканирование завершено!")
f.close()
fl.close()