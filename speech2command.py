import speech_recognition as sr
import serial
import os

def say(cmd):
    os.system(f'say "{cmd}"')

def perform(cmd):
    '''
    Few more commands are to be implemented
    Because this is a rule based kind of a model, Would love to make it with NLP.
    '''
    if 'open' in cmd:
        hand.write(b'ooooo')
    if 'close' in cmd:
        hand.write(b'ccccc')
    if 'horns' in cmd:
        hand.write(b'occoc')
    if 'bye' in cmd:
        hand.write(b'bbbbb')
        say("Bye Bye")
        exit()
    else:
        hand.write(b'ooooo')
    say('OK!')

#Modify with your device and Baudrate
device = '/dev/cu.usbmodem1421'
baudrate = 115200

#Initializing the Speech Recognition Module and Serial Hand
print("Initializing Program....")
r=sr.Recognizer()
say("Initializing program")
hand = serial.Serial('/dev/cu.usbmodem1421',115200)
say("My hand is connected and command mode activated")

#Listening Starts
while(True):
    with sr.Microphone() as source:
        audio = r.listen(source)
    try:
        text = str(r.recognize_google(audio,language='en-IN'))
        perform(text)
    except Exception as e:
        print(e)
