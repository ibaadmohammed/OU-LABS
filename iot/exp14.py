import RPi_GPIO as GPIO
from time import sleep
LED_PIN=14
GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_PIN,GPIO.OUT)
try:
    while True:
        GPIO.output(LED_PIN,GPIO.HIGH)
        time.sleep(1)
        GPIO.output(LED_PIN,GPIO.LOW)
        time.sleep(1)
except KeyboardInterrupt:
    GPIO.cleanup()
