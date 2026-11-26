import RPi.GPIO as GPIO
import time

sensor = 14

GPIO.setmode(GPIO.BCM)
GPIO.setup(sensor, GPIO.IN)

print("LDR Sensor Ready.....")
print(" ")

try:
    while True:
        if GPIO.input(sensor):
            print("LIGHT NOT Detected")
        else:
            print("LIGHT Detected")
except KeyboardInterrupt:
    GPIO.cleanup()