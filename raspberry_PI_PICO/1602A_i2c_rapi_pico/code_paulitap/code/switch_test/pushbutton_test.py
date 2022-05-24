from machine import Pin
import time

PUSHBUTTON_1 = Pin(4, Pin.IN)

def main():
    print(PUSHBUTTON_1.value())
    
    if (PUSHBUTTON_1.value() == 0):
        print('On\n')
    elif (PUSHBUTTON_1.value() == 1):
        print('Off\n')


for x in range(5):
    main()
    time.sleep(1)
    