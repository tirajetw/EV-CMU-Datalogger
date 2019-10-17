import serial
import time


ser = serial.Serial('COM17',9600)
ser.write('Y'.encode())
