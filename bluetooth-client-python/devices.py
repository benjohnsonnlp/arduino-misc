"""
This a file with classes that act as hardware drivers
"""
from abc import ABCMeta, abstractproperty
import time
from serial_custom import SerialCustom


class ArduinoDevice(object):
    __metaclass__ = ABCMeta

    def __init__(self, pin, serial=SerialCustom()):
        self._pin = pin
        self._ser = serial

    def pin(self):
        return self._pin


class Light(ArduinoDevice):

    def on(self):
        self._ser.write(['p', self._pin, 'h'])

    def off(self):
        self._ser.write(['p', self._pin, 'l'])


if __name__ == '__main__':
    light = Light(13)
    while True:
        light.on()
        time.sleep(0.1)
        light.off()
        time.sleep(0.1)



