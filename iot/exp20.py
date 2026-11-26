import os, sys
import Adafruit_DHT
from time import sleep
import requests
import RPi.GPIO as GPIO

# GPIO.setmode(GPIO.BCM)
baseURL = 'https://api.thingspeak.com/update?api_key=INSERT_YOUR_API_KEY'
sensorPin = 23

while True:
    try:
        print("Program is running")
        humi, temp = Adafruit_DHT.read(Adafruit_DHT.DHT11, sensorPin)
        if (humi > 0) and (temp > 0):
            print(humi)
            print(temp)
            print("Data Received")
            x = '{}&field1={}&field2={}'.format(baseURL, temp, humi)
            y = requests.post(x)
            print(y.status_code)
            print(x)
            sleep(5)
    except:
        print("data not recieved")
        sleep(5)