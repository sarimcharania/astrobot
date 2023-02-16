import discord
import random
import asyncio

client = discord.Client(intents=discord.Intents.all())

@client.event
async def on_message(message):
    if message.author == client.user:
        return
    if message.content.lower().strip().startswith('astrobot what is your purpose'):
        await message.channel.send('My existence in its entirety is just a flex that someone can code...')
    if message.content.lower().strip().startswith('astrobot pass butter'):
        await message.channel.send('Here is butter')
    if message.content.lower().strip().startswith('you pass butter'):
        await message.channel.send(':(')

@client.event
async def on_ready():
    await hello_message()

async def hello_message():
    channel = client.get_channel(1068665849268944946)
    await channel.send("Ooooh boieee who wants butter?")
    await probabilistic_action(1440)

async def probabilistic_action(num_minutes):
    while True:
        if random.random() <= 1/num_minutes:
            channel = client.get_channel(1068665849268944946)
            await channel.send("What is my purpose? ")
            print("Questioning existence...")
        await asyncio.sleep(60)


print ("")
client.run("MTA2ODY2MDk0MzE1MzgxMTQ4Ng.GPPyoM.r8QaMufUXB55cmVNCeJnfvnLWuu1WclC-iscIo")