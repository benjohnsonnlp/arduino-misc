import serial

if __name__ == "__main__":
    ser = serial.Serial('/dev/tty.HC-06-DevB', 9600)
    while True:
        print ser.readline()
