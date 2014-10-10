//=========================HEADER=============================================================
/*
   CAN Example Code (Tx) for the TE-242-001 MCP2551 Breakout
   AUTHOR: Jason Traud
   DATE: October 10, 2014
   
   This is a simple test program to send arbitrary data (an incremental number)
   over CAN to a reciever using the MCP2551 Breakout, which is part number TE-242-001
                                                       
   Please see the link below for additional information and datasheets:
   http://www.superdroidrobots.com/shop/item.aspx/mcp2551-can-tranceiver-breakout/1841/
   
   Hardware: Arduino Mega R3      (MCU-049-000)
             MCP2551 CAN BReakout (TE-242-001)
           
   
   RS485 Breakout     -------------      Arduno Uno
   -----------------                    -------
            Tx     -------------------   Tx1 / D18   
            Rx     -------------------   Rx1 / D19 
            +5V    -------------------   Vcc (+5V)
            GND    -------------------   GND
			
   License: CCAv3.0 Attribution-ShareAlike (http://creativecommons.org/licenses/by-sa/3.0/)
   You're free to use this code for any venture. Attribution is greatly appreciated. 

//============================================================================================
*/


// Recieved data from the RS-485 transicever 
unsigned char rxByte;

// Timeout counter
unsigned int counter = 0;

void setup() {
  Serial.begin(57600);
  Serial1.begin(57600);
}

void loop() {
  
  // Check for available packets from serial port 1
  if (Serial1.available() > 0) {
    rxByte = Serial1.read();    // If we have a packet, read it and store it
    Serial.println(rxByte);     // Print the data to the serial monitor
    counter = 0;                // Reset our counter
  }
  
  // If we do not have data waiting in our buffer, then we need to
  // increment our timeout counter and display a prompt when we've
  // sufficiently timed out
  else {
    counter = counter + 1;
    if (counter > 100000) {
      Serial.println("[nd]");
      counter = 0;
    }
  }   
}
