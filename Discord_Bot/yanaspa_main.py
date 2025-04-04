import discord 
from discord.ext.commands import Bot 
from Token_yanaspa import Token 

client = discord.Client()

client = commands.Bot(command_prefix = './')

@client.event
async def on_ready():
    print('Login...')
    print(f'{client.user}에 로그인했습니다.')
    print(f'ID : {client.user.name}')
    await client.change_presence(status=discord.Status.online, activity=discord.Game('VS Code로 개발'))

@client.event
async def on_message(message) : 
    if message.content.startswith('테스트')  :
        await message.channel.send("{} | {}. 안녕!".format(message.author, message.author.mention))
    if message.content == '테스트' : 
        await message.channel.send("{} | {}, 어서오세요!".format(message.author, message.author.mention))

    await message.author.send("{} | {} 유저님, 환영합니다.".format(message.author, message.author.mention))     

@client.command(aliases=['hi'])
async def hello(ctx) : 
    await ctx.send("안녕하세요!!!")

@client.command(aliases=['로그인', '접속하기'])
async def login(ctx) : 
    await ctx.channel.send("{} | {}님, 어서오세요!!".format(ctx.author, ctx.author.mention)) 

client.run(Token)
