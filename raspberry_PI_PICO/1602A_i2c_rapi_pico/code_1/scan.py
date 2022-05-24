from machine import Pin
from machine import I2C

sda = Pin(8)
scl = Pin(9)

i2c = I2C(0, sda=sda, scl=scl, freq=400000)
print(i2c.scan())