import serial
from settings import SETTINGS


class SerialCustom(serial.Serial):
    def __init__(self):
        super(SerialCustom, self).__init__(SETTINGS['bluetooth-serial-port'], 9600)
