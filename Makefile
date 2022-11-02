default: build

build:
	avr-gcc -Os -mmcu=atmega328p blink.c -o blink
burn:
	avr-objcopy -O ihex -R .eeprom blink blink.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:blink.hex
