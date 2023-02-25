import pyperclip
import time
import re

while True:
    buffer = pyperclip.paste()
    if re.search(r'[A-Za-z0-9]', buffer):
        f = open(
            u'C:\\Users\\vlads\\Documents\\Study\\xakep.ru\\buffer.txt',
            'a',
            encoding='UTF-8')
        f.write(buffer + '\n')
        f.close()
    time.sleep(10)