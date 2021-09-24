#press the butto

import time
import board
import displayio
from adafruit_display_shapes.rect import Rect
from digitalio import DigitalInOut, Direction, Pull

button1 = DigitalInOut(board.BUTTON_1)
button1.direction = Direction.INPUT

# wio display x = 0-320 y = 0-240

rectgreen = Rect(220, 100, 80, 40, fill=0x000000, outline=0x00FF00, stroke=1)
rectyellow = Rect(120, 100, 80, 40, fill=0x000000, outline=0xffee00, stroke=1)
rectred = Rect(20, 100, 80, 40, fill=0x000000, outline=0Xff0000, stroke=1)

group = displayio.Group()
group.append(rectgreen)
group.append(rectred)
group.append(rectyellow)

display = board.DISPLAY
display.show(group)

tnum = 0

while True:
    if (button1.value == False):
        time.sleep(0.5)
        if (button1.value == True):
            tnum+=1
    elif tnum%4 == 0:
        rectred.fill = 0Xff0000
        rectyellow.fill = 0X000000
        time.sleep(0.1)
    elif tnum%4 == 1:
        rectred.fill = 0X000000
        rectyellow.fill = 0xffee00
        time.sleep(0.1)
    elif tnum%4 == 2:
        rectyellow.fill = 0x000000
        rectgreen.fill = 0x00FF00
        time.sleep(0.1)
    elif tnum%4 == 3:
        rectyellow.fill = 0xffee00
        rectgreen.fill = 0x000000
        time.sleep(0.1)