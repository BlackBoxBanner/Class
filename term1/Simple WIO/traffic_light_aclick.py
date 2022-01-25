# one click for colore rotate and left with red in the end.
import time
import board
import displayio
from digitalio import DigitalInOut, Direction, Pull
from adafruit_display_shapes.rect import Rect

button1 = DigitalInOut(board.BUTTON_1)
button1.direction = Direction.INPUT

rect3 = Rect(220, 100, 80, 40, fill=0x000000, outline=0x00FF00, stroke=1) #green
rect2 = Rect(120, 100, 80, 40, fill=0x000000, outline=0xffee00, stroke=1) #yellow
rect1 = Rect(20, 100, 80, 40, fill=0Xff0000, outline=0Xff0000, stroke=1) #red

group = displayio.Group()
group.append(rect1)
group.append(rect2)
group.append(rect3)

display = board.DISPLAY
display.show(group)


while True:
        if button1.value:
            time.sleep(0.001)
        count=0
        if button1.value == False:
            time.sleep(0.001)
            for count in range(5):
                count+=1
                if count==1:
                    rect1.fill = 0xFF0000
                    time.sleep(2)
                elif count==2:
                    rect1.fill = 0x000000
                    rect2.fill = 0xFFFF00
                    time.sleep(2)
                elif count==3:
                    rect2.fill = 0x000000
                    rect3.fill = 0x00FF00
                    time.sleep(2)
                elif count==4:
                    rect2.fill = 0xFFFF00     
                    rect3.fill = 0x000000 
                    time.sleep(2)
                elif count==5:
                    rect1.fill = 0xFF0000
                    rect2.fill = 0x000000
                else:
                    count=0