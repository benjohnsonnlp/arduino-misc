import serial
from settings import SETTINGS


class SerialCustom(serial.Serial):
    def __init__(self):
        super(SerialCustom, self).__init__('/dev/tty.HC-06-DevB', 9600)
