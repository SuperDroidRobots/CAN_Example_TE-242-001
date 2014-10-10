//=========================HEADER=============================================================
/*
   CAN Example Code (Tx) for the TE-242-001 MCP2551 Breakout
   AUTHOR: Jason Traud
   DATE: October 10, 2014
   
   This is a simple test program to send arbitrary data (an incremental number)
   over CAN to a reciever using the MCP2551 Breakout, which is part number TE-242-001
                                                       
   Please see the link below for additional information and datasheets:
   http://www.superdroidrobots.com/shop/item.aspx/mcp2551-can-tranceiver-breakout/1841/
   
   Hardware: Arduino Uno R3       (MCU-050-000)
             MCP2551 CAN BReakout (TE-242-001)
           
   
   CAN  Breakout      -------------      Arduno Uno
   -----------------                    -------
            Tx     -------------------   Tx / D1   
            Rx     -------------------   Rx / D0 
            +5V    -------------------   Vcc (+5V)
            GND    -------------------   GND
                                                   
 			
   License: CCAv3.0 Attribution-ShareAlike (http://creativecommons.org/licenses/by-sa/3.0/)
   You're free to use this code for any venture. Attribution is greatly appreciated. 

//============================================================================================
*/


// Our counter that we're using as our dummy data to send
unsigned char counter = 0;


void setup() {
  Serial.begin(57600);            // We're communicating over the hardware UART
}

void loop() {
  
  Serial.write(counter);         // Send our data
  
  // Slow ourselves down a bit
  delay(900);
  
  // Increment our data and loop it back to 0 before an
  // overflow occurs
  counter = counter + 1;
  if (counter > 250)
    counter = 0;
}
