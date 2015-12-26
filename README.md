# Universal-RS485
CAD files and software for my Universal RS-485/DMX transceiver

This universal RS-485/DMX transceiver is based on the fully isolated MAX1480ACPI RS-485 driver IC from Maxim as well as a few carefully chosen 74 series CMOS logic ICs. This module allows for bidirectional, half duplex conversion of either 5v or 3.3v TTL serial signals to differential RS-485 compliant signals. Since DMX operates over RS-485, this can easily be used for controlling DMX devices or reading a DMX data stream using a software implementation of the DMX protocol and a UART capable of operating at 250k baud. This device has been tested to work with the OLA UART Native DMX plugin as well as the DMXSimple Arduino library.


Known Issues (to be fixed in next PCB revision):

Pad spacing for C1 is too large.
    Mitigation: Bend leads of C1 to accomodate.

Unused inputs on the 74LVC245 are floating and may oscillate, increasing power consumption and potentially causing receive bit errors.
    Mitigation: Solder thin wire on back of board connecting all pins between GND and A2 on the 74LVC245 if using the 3.3v output.
