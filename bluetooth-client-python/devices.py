"""
This a file with classes that act as hardware drivers
"""
from abc import ABCMeta, abstractproperty
import time
from serial_custom import SerialCustom


class ArduinoDevice(object):
    __metaclass__ = ABCMeta

    def __init__(self, pin=-1, serial=SerialCustom()):
        self._pin = pin
        self._ser = serial

    def pin(self):
        return self._pin


class Light(ArduinoDevice):

    def on(self):
        self._ser.write(['p', self._pin, 'h'])

    def off(self):
        self._ser.write(['p', self._pin, 'l'])

class Car(ArduinoDevice):

    def turn_left(self):
        self._ser.write(['t', 'l'])

    def turn_right(self):
        self._ser.write(['t', 'r'])

    def turn_straight(self):
        self._ser.write(['t', 's'])

    def go(self):
        self._ser.write(['e', 'f'])

    def reverse(self):
        self._ser.write(['e', 'r'])

    def stop(self):
        self._ser.write(['e', 's'])


if __name__ == '__main__':
    # light = Light(13)
    motor = Car()
    while True:
        # light.on()
        motor.turn_left()
        time.sleep(1)
        # light.off()
        motor.turn_right()
        time.sleep(1)



