import discord
import configparser

# Read the configuration from config.ini
config = configparser.ConfigParser()
config.read('config.ini')

channel_id = config['DISCORD']['CHANNEL_ID']
permissions = discord.Permissions(int(config['DISCORD']['PERMISSIONS']))
bot_token = config['DISCORD']['BOT_TOKEN']

invite_link = discord.utils.oauth_url(channel_id, permissions=permissions)

print(f"Invite link: {invite_link}")