import RPi.GPIO as GPIO
import time

sensor = 14

GPIO.setmode(GPIO.BCM)
GPIO.setup(sensor, GPIO.IN)

print("IR Sensor Ready.....")
print(" ")

try:
    while True:
        if GPIO.input(sensor):
            print("Object NOT Detected")
            while GPIO.input(sensor):
                time.sleep(0.2)
        else:
            print("Object Detected")
except KeyboardInterrupt:
    GPIO.cleanup()