# PiBook_on_AcerTravelMate4001
A dead Acer Travelmate 4001WLMI may become alive again with a "Raspberry Pi heart" in it

There ar eeasier wys to get a PiBook, but I want to figure it out how to do this.
My plan:

a) If possible use the housing of the TravelMate.

b) Use the existing keyboard matrix (german layout, 89 keys)
  Using a bigger Arduino with many I/O to deal with 24 the pins
  Currently in use is an Arduino Mega2560
  Details can be found in folder \keyboard
  Add a way to control the Displayboard (d) via Fn+Key (or similar)

c) Use the existing Touchpad (TM42PUF), PS/2 out
  As this is already a PS/2 device, it is planned to use a PS/2 to USB converter, whcih shall handle the keyboard, too.

d) Use the existing screen (1280x1024(?) 15.x inches, QDI N15W Rev4)
  I buyed a piece of elctronic, called M.NT68676.2 to convert VGA/HDMI/DVI to LCD signals,including the inverter for the backlight.
  The provided cable does not match, so I need to solder a new cable out of two. 

e) Don't use the internal DVD-Writer

f) At least add a headphone jack. Reuse internal speakers if possible 

g) Use a new 12V Power supply so there's no need to deal with the old one

h) If possible, lead the inputs of the screen adaption to the outside of the laptop, so it can be used as a monitor.
    Do the same for keyboard and touchpad.



