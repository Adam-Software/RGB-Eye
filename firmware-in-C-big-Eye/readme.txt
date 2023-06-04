BIGTEST
D:\Soft\Download\AVRDUDE\AVRDUDE\avrdude.exe
avrdude -p m8 -c usbasp -U lfuse:w:0xCE:m -U hfuse:w:0xD9:m avrdude -p m8 -c usbasp -U flash:w:testfw.hex
$(TargetDir)