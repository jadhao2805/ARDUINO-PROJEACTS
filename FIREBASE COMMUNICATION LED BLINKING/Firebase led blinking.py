import firebase_admin
import RPi.GPIO as GPIO # Import Raspberry Pi GPIO library
from time import sleep # Import the sleep function from the time module
GPIO.setwarnings(False) # Ignore warning for now
GPIO.setmode(GPIO.BOARD) # Use physical pin numbering
GPIO.setup(8, GPIO.OUT, initial=GPIO.LOW) 

from firebase_admin import db
from firebase_admin import credentials
cred = credentials.Certificate("/Users/shubhamjadhao/Desktop/botproject-da8d0-firebase-adminsdk-ti4s3-2d3e62faf8.json") #your database json file
firebase_admin.initialize_app(cred,{'databaseURL': 'https://botproject-da8d0.firebaseio.com/'})  #your realtime database URL

def listener(event):
    x = event.data     #get value of x from firebase
    if x == 1:
        GPIO.output(8,1)
    elif x == 0:
        GPIO.output(8,0)
    
data = firebase_admin.db.reference('botOperation/c').listen(listener) #Listener for change in value
