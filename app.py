import discord
import random
import asyncio
import configparser

config = configparser.ConfigParser()
config.read('config.ini')

bot_token = config['DISCORD']['BOT_TOKEN']
permissions = int(config['DISCORD']['PERMISSIONS'])
default_channel_id = config.getint('DISCORD', 'DEFAULT_CHANNEL_ID', fallback=None)

intents = discord.Intents.all()
client = discord.Client(intents=intents)

async def send_message(channel, message):
    if channel is not None:
        await channel.send(message)
    else:
        print('Error: Channel not found')

@client.event
async def on_message(message):
    if message.author == client.user:
        return
    if message.content.lower().strip().startswith('astrobot what is your purpose'):
        await send_message(message.channel, 'My existence in its entirety is just a flex that someone can code...')
    if message.content.lower().strip().startswith('astrobot pass butter'):
        await send_message(message.channel, 'Here is butter')
    if message.content.lower().strip().startswith('you pass butter'):
        await send_message(message.channel, ':(')

@client.event
async def on_ready():
    channel_id = config.getint('DISCORD', 'CHANNEL_ID', fallback=default_channel_id)

    if channel_id is not None:
        channel = client.get_channel(channel_id)
        await send_message(channel, 'Bot is online and ready to go!')
    else:
        print('Error: Channel ID not found in config.ini')

async def hello_message(channel, num_minutes):
    await send_message(channel, "Ooooh boieee who wants butter?")
    await probabilistic_action(channel, num_minutes)

async def probabilistic_action(channel, num_minutes):
    while True:
        if random.random() <= 1/num_minutes:
            await send_message(channel, "What is my purpose?")
            print("Questioning existence...")
        await asyncio.sleep(60)

async def main():
    channel_id = config.getint('DISCORD', 'CHANNEL_ID', fallback=default_channel_id)
    channel = client.get_channel(channel_id)

    if channel is not None:
        await hello_message(channel, 1440)
    else:
        print('Error: Channel not found')

if __name__ == '__main__':
    loop = asyncio.get_event_loop()
    loop.create_task(main())
    loop.run_until_complete(client.login(bot_token))
    loop.run_until_complete(client.connect())
