import os

import openai
import telebot

openai.api_key = os.getenv("OPEN_API_KEY")
bot = telebot.TeleBot("BOT_API_KEY")


@bot.message_handler(func=lambda _: True)
def handle_message(message):
    response = openai.Completion.create(model="text-davinci-003",
                                        prompt=message.text,
                                        temperature=0.5,
                                        max_tokens=1000,
                                        top_p=1.0,
                                        frequency_penalty=0.5,
                                        presence_penalty=0.0)
    bot.send_message(message.from_user.id, response['choices'][0]['text'])


bot.polling()
