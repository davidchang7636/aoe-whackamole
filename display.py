import serial  
import tkinter as tk
import threading
import time

serial_port = '/dev/cu.usbmodem2101' #Bluetooth.Incoming.Port usbmodem2101
baud_rate = 9600
ser = serial.Serial(serial_port, baud_rate)
highScore = 3700
currScore = 0

start = time.time()
mins = 0
seconds = 2

root = tk.Tk()
root.title = ("Clock")
root.resizable(0, 0)  # disable resizing
root.attributes('-fullscreen', True)
root.configure(background='black')

string_variable = tk.StringVar(root, "High: {0:05d}\nCurr: {1:05d}\n{2:01d}:{3:02d}".format(highScore, currScore, mins, seconds))

def updateScore():
    global currScore
    string_variable.set("High: {0:05d}\nCurr: {1:05d}\n{2:01d}:{3:02d}".format(highScore, currScore, mins, seconds))

def updateTime():
    global mins, seconds, start
    print(time.time() - start)
    if(time.time() - start >= 1):
        if(seconds == 0):
            mins -= 1
            seconds = 59
        else:
            seconds -= 1
        if(mins == 0 and seconds < 1):
            string_variable.set("High: {0:05d}\nCurr: {1:05d}\nFINISH".format(highScore, currScore))
            exit(1)
        string_variable.set("High: {0:05d}\nCurr: {1:05d}\n{2:01d}:{3:02d}".format(highScore, currScore, mins, seconds))
        start = time.time()

def serialHandler():
    global currScore
    while True:
        if (ser.inWaiting() > 0):
            line = ser.readline()
            line = line.decode("utf-8") #ser.readline returns a binary, convert to string
            currScore = int(line)
        updateScore()
        updateTime()

label = tk.Label(root, font=("ds-digital", 250), background = "black", foreground="red", textvariable=string_variable)
label.pack(anchor="center", expand=True)

threading.Thread(target=serialHandler, daemon=True).start()

tk.mainloop()


