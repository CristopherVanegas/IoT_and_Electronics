from machine import I2C, Pin
from esp8266_i2c_lcd import I2cLcd
from time import sleep_ms, sleep

# 1602A i2c address 0x27 || 0x20

PUSHBUTTON = Pin(4, Pin.IN)
I2C_ADDRESS = 0x27
count = 0

def main_paulitap():
    PUSHBUTTON = Pin(4, Pin.IN)
    I2C_ADDRESS = 0x27
    count = 0
    
    print("Everything it's setting up... \n")
    
    i2c = I2C(1, scl=Pin(3), sda = Pin(2), freq = 100000)
    lcd = I2cLcd(i2c, I2C_ADDRESS, 2, 16)
    lcd.putstr("Everything it's setup!")
    sleep_ms(1000) # 1sec
    lcd.clear()
    
    while True:
        count += 1
        lcd.putstr("Hi Paulitap :3")
        
        if (PUSHBUTTON.value() == 0):
            lcd.clear()
            lcd.move_to(4, 0)
            lcd.putstr("I love u")
            lcd.move_to(3, 1)
            lcd.putstr("so much! <3")
            sleep_ms(5000)
         
        sleep_ms(1000)
        lcd.clear()
        

main_paulitap()