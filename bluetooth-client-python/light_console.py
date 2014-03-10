"""
A file to control the LED on an arduino board via a little console app.
Typing 1 will turn on the light, typing 2 will turn off the light.
"""

import curses
from devices import Light

def end():
    curses.nocbreak()
    stdscr.keypad(0)
    curses.echo()
    curses.endwin()

# print "Press 1 to turn on the light, and 2 to turn it off.  q to exit"

light = Light(13)

stdscr = curses.initscr()
curses.noecho()

begin_x = 20
begin_y = 7
height = 5
width = 40
win = curses.newwin(height, width, begin_y, begin_x)
pad = curses.newpad(100, 100)
pad.addstr(1, 1, 'hi')

while 1:
    # c = sys.stdin.read(1)
    c = stdscr.getch()
    if c == ord('1'):
        light.on()
    elif c == ord('2'):
        light.off()
    elif c == ord('q'):
        end()
        break