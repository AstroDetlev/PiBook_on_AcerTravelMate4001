# PiBook_on_AcerTravelMate4001
A dead Acer Travelmate 4001WLMI may become alive again with a "Raspberry Pi heart" in it

There ar eeasier wys to get a PiBook, but I want to figure it out how to do this.
My plan:

a) If possible use the housing of the TravelMate. Maybe there is not enough space.

b) Use the existing keyboard matrix (german layout, 89 keys)
  Using a bigger Arduino with many I/O to deal with 24 the pins.
  Currently in use is an full size Arduino Mega2560. Maybe a miniaturized version will be the final version.
  current state:
  - Working: It detects all 89 keys
  - Working: Temporary output of a detected key via UART (9k6) 
  - ToDo: debouncing/dead time for key repeat
  - ToDo: automatic key press acceleration
  - ToDo: Integrate PS" Library for becoming a "homemmade PS/2 Keyboard" (Also: low/capital letter and all the Shift/Alt/Ctrl key stuff)
  - Todo: The 3 LEDs of a keybaord
Details can be found in folder \keyboard
  
c) Use the existing Touchpad (TM42PUF), PS/2 out
  As this is already a PS/2 device, it is planned to use a PS/2 to USB converter, which shall handle the "homemade PS/2 keyboard", too.
  These converters look huge, but once pulled out of their housing, they are at the size of an SDCard.
  It is not expected to write any code for this task. The right wiring and maybe some glue logic shall do the job.
 Details can be found in folder \Touchpad if the work is started

d) Use the existing screen (1280x1024(?), 15.x inches, "QDI N15W Rev4")
  I buyed a piece of electronic, called "M.NT68676.2" to convert VGA/HDMI/DVI to display signals, including the inverter to power up the CCFL backlight.
  The provided cable does not match, so I need to solder one new cable out of two.
  This needs no code if the keys of that PCB are used. But a samrter solution would be to repace these keys by some output lines of the arduino which is
  already used by the keyboard matrix. Maby Fn+Shift+whatever will trigger such a output line to emulate that keypress.
  Optocoupler to isolate? "Open collector output" with a bipolar transistor? 
Details can be found in folder \ScreenController if the work is started

e) Don't use the internal DVD-Writer
  This gives some more space for wiring.

f) At least add a headphone jack. Reuse internal speakers if possible 
  
g) Use a new 12V Power supply so there's no need to deal with the old one that provides 19V
  With this, only a 12V to 5V Step Down Converter is needed.

h) If possible, lead the inputs of the screen accessing board to the outside of the laptop, so it can be used as a monitor.
    Do the same for keyboard and touchpad (USB or PS/2?)

i) Temperatur and Voltage Monitoring and small extra Display (2x16 char?)
  Temperatur measuring via DS18S20 (I need to check that character between the numbers...)
  Voltage...How often will I need this?
  Details can be found in folder \Measuring if the work is started


