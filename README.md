# PiBook_on_AcerTravelMate4001
A dead Acer Travelmate 4001 WLMI may become alive again with a "Raspberry Pi heart" in it

There are easier ways to get a so-called PiBook, but I want to figure it out how to do this.

My plan:

a) If possible use the housing of the TravelMate. But maybe there is not enough space.
  - Todo: measure the available space inside the housing and record it here.

## Details of a) can be found in folder \housing if the work is started

b) Use the existing keyboard matrix (german layout, 89 keys, curved)
  Using a bigger Arduino with many I/O to deal with 24 the pins.
  Currently in use is an full size Arduino Mega2560. Maybe a miniaturized version will be the final version.
  current state:
  - Working: It detects all 89 keys
  - Working: Temporary output of a detected key via UART (@9k6) 
  - ToDo: debouncing/dead time for key repeat (Timer triggered scan?)
  - ToDo: automatic key press acceleration
  - ToDo: Integrate PS/2 Library for becoming a "homemade PS/2 Keyboard" (Also: low/capital letter and all the Shift/Alt/Ctrl key stuff)
  - ToDo: Glue logic for PS/2 (Buffer gate, Pullup-resistors)
  - ToDo: Check signals with Oscilloskope / Digital Analyser, compare with other keyboard
  - Todo: The 3 LEDs of a usual keyboard
  - ToDo: Add a photo of the layout and the wiring
  
## Details of b) can be found in folder \keyboard
  
c) Use the existing Touchpad (TM42PUF), PS/2 out
  As this is already a PS/2 device, it is planned to use a PS/2 to USB converter, which shall handle the "homemade PS/2 keyboard", too.
  These converters look huge, but once pulled out of their housing, they are at the size of an SDCard.
  It is not expected to write any code for this task. The right wiring and maybe some glue logic shall do the job.
  I've opened such a converter, and it does not contain pullup-resistors for PS/2. Need to add this to the keyboard and the touchpad.
  Check with an Oscilloskope. Compare buyed Keyboard/Mouse signals with this homemmade stuff. 
  - ToDo: Wire Touchpad to PS/2 input of teh converter
  - ToDo: add Pullup resistor
  - ToDo: Check signals with Oscilloskope / Digital Analyser, compare with other Mouse
 
## Details od c) can be found in folder \Touchpad if the work is started

d) Use the existing screen (1280x1024(?), 15.x inches, "QDI N15W Rev4")
  I buyed a piece of electronic, called "M.NT68676.2" to convert VGA/HDMI/DVI to display signals, including the inverter to power up the CCFL backlight.
  The provided cable did not match, so I need to solder one new cable out of two.
  This needs no code if the keys of that PCB are used. But a samrter solution would be to replace these keys by some output lines of the arduino which is
  already used by the keyboard matrix. Maby Fn+Shift+whatever will trigger such a output line to emulate that keypress.
  Optocoupler to isolate? "Open collector output" with a bipolar transistor?
  The Raspberry Pi needs HDMI input. DVI and VGA left unused. They can be wired to externel plugs for using this
  - ToDo: Prepare 12V and 5V Power for the board 
  - ToDo: build data cable between display and board
  - ToDo: Test with existing Raspberry Pi zero
  - ToDo: Document what each button of this button-board can do.

## Details of d) can be found in folder \ScreenController if the work is started

e) Don't use the internal DVD-Writer
  This gives some more space for wiring.
  - ToDo: remove the front of teh drive and glue the front of the drive to the housing
  
f) At least add a headphone jack. Reuse internal speakers if possible 
  - ToDo: add headphone jack and wire it to the PCM sound output of the Raspberry pi (RPi Zero does not have this, but this could be added afaik)
  - Optional: Add the pcb of a USB-Soundcard and add a jack for the mike of the usb-soundcard
  - Optional: 5V-powered "class H" stereo amplifier
  - Optional: internal mic
 
g) Use a new 12V Power supply so there's no need to deal with the old one that provides 19V
  With this, only a 12V to 5V Step Down Converter is needed.
  - ToDo: estimate power consumption of all components and search for matching power converters
  - ToDo: make a plan how to wire this with thicker wires
  
h) If possible (room for cable), lead the inputs of the screen accessing board to the outside of this "PiBook", so the whole thing can be used as a monitor.
    Do the same for keyboard and touchpad (USB,PS/2, both?)

i) Temperatur and Voltage Monitoring, fan control and small extra Display? (2x16 char?)
  Temperatur measuring via DS18S20 (I need to check that character between the numbers...)
  Fan control via PWM?
  Voltage...How accurate can ADC be with an Arduino?
  
  
j) How to power on/off the Rapberry Pi? 
	Can the Keyboard-Arduino be of any help with this task?
	How to completely power off? This computer shall not boot on powering, but power on if the power button is pressed.
	- ToDo: Check if there is any prebuild hardware available for this.

h) Add a Realtime clock. There are tiny boards available for the Raspberry Pi, but most of them seem to deal with a capacitor.
	- ToDo: use existing RTC Board, get this working for the Pi Zero, and estimate the time span it can keep the clock alive. Maybe a CR2032 will work better?
	
## Details of e)...h) can be found in folder \additional if the work is started


