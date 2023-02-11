import tkinter as Tk
from tkinter import *
from tkinter import messagebox


def calculate_nalog():
    nalog = 0
    mas = int(weight_tf.get())
    per = person_tf.curselection()
    bike = bike_var.get()

    if not (bike):
        if per[0]:
            if mas < 1000:
                nalog = 162
            elif mas >= 1000 and mas < 2000:
                nalog = 209
            elif mas >= 2000 and mas < 3000:
                nalog = 255
            else:
                nalog = 325
        else:
            if mas < 1500:
                nalog = 61
            elif mas >= 1500 and mas < 1750:
                nalog = 81
            elif mas >= 1750 and mas < 2000:
                nalog = 102
            elif mas >= 2000 and mas < 2250:
                nalog = 122
            elif mas >= 2250 and mas < 2500:
                nalog = 142
            elif mas >= 2500 and mas < 3000:
                nalog = 162
            else:
                nalog = 223
    else:
        if per[0]:
            nalog = 70
        else:
            nalog = 41

    nalog_lb = Label(frame,
                     text="Налог: " + str(nalog) + " бел.руб.",
                     font='Arial 11 bold',
                     fg='#EB4C42')
    nalog_lb.grid(row=7, column=3, sticky='w')


window = Tk()
window.title("Калькулятор налога")
window.geometry('600x300')

frame = Frame(window, padx=10, pady=10)
frame.pack(expand=True)
frame.rowconfigure(99, weight=5)

weight_lb = Label(frame,
                  text="Введите массу автомобиля: ",
                  font='Arial 10 bold',
                  fg='#474A51')
weight_lb.grid(row=3, column=1, sticky='w')

weight_tf = Entry(frame, bg='#C7D0CC')
weight_tf.grid(row=3, column=2)

person_lb = Label(frame,
                  text="Владелец (выбрать): ",
                  font='Arial 10 bold',
                  fg='#474A51')
person_lb.grid(row=4, column=1, sticky='w')

person_tf = Listbox(frame, bg='#C7D0CC', height=2)
person_tf.insert(END, 'Физическое лицо', 'Юридическое лицо')
person_tf.grid(row=4, column=2)

bike_var = BooleanVar()
bike_btn = Checkbutton(frame, variable=bike_var, text="Мотоцикл")
bike_btn.grid(row=5, column=1)

cal_btn = Button(frame, text="Рассчитать налог")
cal_btn.grid(row=5, column=2)
cal_btn.configure(command=calculate_nalog)

window.mainloop()