import serial
from settings import SETTINGS

if __name__ == "__main__":
    ser = serial.Serial(SETTINGS['bluetooth-serial-port'], 9600)
    print ser.write('response')

    while True:
        print ser.readline()
