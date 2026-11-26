import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
trigger = 14
echo = 15
GPIO.setup(trigger, GPIO.OUT)
GPIO.setup(echo, GPIO.IN)

def distance():
    GPIO.output(trigger, True)
    time.sleep(0.00001)
    GPIO.output(trigger, False)
    startTime = time.time()
    stopTime = time.time()
    while GPIO.input(echo) == 0:
        startTime = time.time()
    while GPIO.input(echo) == 1:
        stopTime = time.time()

    TimeElapsed = stopTime - startTime
    distance = (TimeElapsed * 34300) / 2
    return distance

try:
    while True:
        dist = distance()
        print("Measured Distance: ")
        print(dist)
        time.sleep(1)
except KeyboardInterrupt:
    GPIO.cleanup()