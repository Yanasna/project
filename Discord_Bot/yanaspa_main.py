import discord 
from Token_yanaspa import Token 
from discord.ext import commands

intents = discord.Intents.default()

intents.message_content = True

client = commands.Bot(command_prefix = '!', intents=intents)

@client.event
async def on_ready():
    print('Login...')
    print(f'{client.user}에 로그인했습니다.')
    print(f'ID : {client.user.name}')
    await client.change_presence(status=discord.Status.online, activity=discord.Game('VS Code로 개발'))

@client.event
async def on_message(message) : 
    if message.content.startswith('테스트')  :
        await message.channel.send("{} | {}. 안녕하냐!".format(message.author, message.author.mention))
    if message.content == '테스트' : 
        await message.channel.send("{} | {}, 테스트 제발 그만좀.. ".format(message.author, message.author.mention))
        await message.channel.send("{} | {} 야, 그만좀 불러다오.".format(message.author, message.author.mention))     

    await client.process_commands(message)

@client.command(aliases=['hi'])
async def hello(ctx) : 
    await ctx.send("안녕하세요!!!")

@client.command(aliases=['로그인', '접속하기'])
async def login(ctx) : 
    await ctx.channel.send("{} | {}님, 어서오세요!!".format(ctx.author, ctx.author.mention)) 

client.run(Token)
