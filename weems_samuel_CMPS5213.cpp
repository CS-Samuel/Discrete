//------------------------------------------------------------------------------------------------------------
//
// Name:  Samuel Weems
//
// Course:  CMPS 5213, Spring 17, Dr. Passos
//
// Purpose:  This program receives a message of up to 40 bytes in ASCII format and a CRC-14 sequence of 15 bits
//           ones and zeros starting with a one. The input data ends with a carriage return.
//           The program then applies and appends this CR-12 (x^12 + x^11 + x^3 + x^2 + x + 1) to the message
//           followed by the CRC-14. The output is displayed in hexadecimal format.
//------------------------------------------------------------------------------------------------------------

#include<iostream>
#include<string>
#include<math.h>

using namespace std;

// Main Function

int main (){
    
    string message, finalMessage;               //String for input message and final message
    int crc12=0, crc14=0;                       //CRC remainder variables
    long int crc14Input;                        //CRC-14 Input
    int crc14Array[15];                         //Array for CRC-14 Input
    int inputBit=0, output;                     //Variable to hold input bit for Shift Registers and for output
    char inputChar;                             //Variable for character manipulation
    char crc12a = '@', crc12b = '@';            //Characters to append CRC12 remainder to message
    char crc14a = '@', crc14b = '@';            //Characters to append CRC14 remainder to message

    cin >> message;                             //Receive message input
    cin >> crc14Input;                          //Receive CRC-14 input
    
    finalMessage = message;                     //Copy initial message for final operations

    unsigned long int stringLength = message.length();        // Store length of input message
    
    for (int i = 0; i < stringLength; ++i)      // Loop to go through entire message
    {
        inputChar = message[i];                 // Set current character
       
        for (int j=0; j<8; ++j)                 // Loop to go through 8 bits of one character
        {
            inputBit = 128 & inputChar;         // Set input bit to leftmost bit of character
            inputBit = inputBit << 4;           // Move input bit to position C11 for operation
            
            inputBit = inputBit^crc12;          // XOR inputBit with current CRC12
            inputBit = inputBit >> 11;          // Move inputBit to rightmost position
            
            if (inputBit %2 == 0)               // Remove any other bits besides XORed input bit
                inputBit = 0;
            else inputBit = 1;
            
            crc12 = crc12 << 1;                 // Shift CRC bits left 1
            crc12 = crc12 + inputBit;           // Place input bit in C0 (first rightmost bit)
            
            inputBit = inputBit << 1;           // Shift input bit for positioning
            crc12 = crc12^inputBit;             // XOR
            
            inputBit = inputBit << 1;           // Continue positioning input bit and XOR
            crc12 = crc12^inputBit;
            
            inputBit = inputBit << 1;
            crc12 = crc12^inputBit;
            
            inputBit = inputBit << 8;
            crc12 = crc12^inputBit;
            
            inputChar = inputChar << 1;         // Shift bits left 1 to read the next bit
        }
    }
    
    crc12a = crc12a&0;                          // 0 out crc12 characters for appending
    crc12b = crc12a&0;
    crc12 = crc12 & 4095;                       // 0 out all bits left of CRC12 remainder
    crc12b = crc12b | crc12;                    // Place the last 8 bits of CRC12 remainder into CRC12b
    crc12b = crc12b << 4;                       // Shift bits left 4 of CRC12b - XXXX 0000
    crc12 = crc12 >> 4;                         // Shift CRC12 remainder right 4
    crc12a = crc12a | crc12;                    // Place the first 8 bits of CRC12 remainder into CRC12a
    
    message = message + crc12a;                 // Append message with CRC12 remainder
    message = message + crc12b;
    
    for (int i=0; i<15; ++i)                    // Put CRC-14 input into Array
    {
        crc14Array[i] = crc14Input%10;
        crc14Input = crc14Input/10;
        
    }
    
    stringLength = message.length();            // Store new length of input message
    
    for (int i = 0; i < stringLength; ++i)      // Loop to go through entire message
    {
        
        inputChar = message[i];                 // Set current character
 
        
        for (int j=0; j<8; ++j)                 // Loop to go through 8 bits of one character
        {
            if (i == (stringLength-1) && j == 4)               // Skip the last 4 bits of message (0000) from CRC12b;
                goto endCRC14;
            
            inputBit = 128 & inputChar;         // Set input bit to leftmost bit of character
            inputBit = inputBit << 6;           // Move input bit to position C13 for operation
            
            inputBit = inputBit^crc14;          // XOR inputBit with current CRC14
            inputBit = inputBit >> 13;          // Move inputBit to rightmost position
            
            if (inputBit %2 == 0)               // Remove any other bits besides XORed input bit
               inputBit = 0;
            else inputBit = 1;

            
            crc14 = crc14 << 1;                 // Shift CRC bits left 1
            crc14 = crc14 + inputBit;           // Place input bit in C0 (first rightmost bit)
        
            
            for (int k=1; k<14; ++k)
            {
                inputBit = inputBit << 1;       // Move input bit to next location (shift register)
                if (crc14Array[k] == 1)         // If CRC-14 location is a 1 then perform XOR operation
                    crc14 = crc14^inputBit;
            }
            
            inputChar = inputChar << 1;         // Shift bits left 1 to read the next bit
        }
    }
    
endCRC14:

    crc14a = crc14a&0;                          // 0 out crc14 characters for appending
    crc14b = crc14b&0;
    crc14 = crc14&16383;                        // 0 out all bits left of the CRC14 remainder
    
    crc14b = crc14b | crc14;                    // Place the last 8 bits of CRC14 remainder into CRC14b
    crc14b = crc14b << 6;                       // Shift bits left 6 of CRC14b - XX00 0000
    
    crc14 = crc14 >> 2;                         // Shift CRC14 remainder right 2
    crc14a = crc14a | crc14;                    // Place the next 8 bits into CRC 14a
    
    crc14 = crc14 >> 8;                         // Shift CRC14 remainder right 8
    crc12b = crc12b | crc14;                    // Place first 4 bits of CRC14 remainder into CRC12b
    
    finalMessage = finalMessage + crc12a;
    finalMessage = finalMessage + crc12b;
    finalMessage = finalMessage + crc14a;
    finalMessage = finalMessage + crc14b;
    
    stringLength = finalMessage.length();            // Store new length of input message
    
   for (int i=0; i<stringLength; ++i)               // Output message
   {
       
       output = static_cast<int>(finalMessage[i]);
       output = output & 255;                       // Message formatting for appended CRCs
       
      if (i == stringLength-1 && ((finalMessage[i] << 4) & 255) == 0) // formating for padding
           cout << hex << output / 0x10;
     else if (((finalMessage[i] >> 4) & 255) == 0)                        // formatting for 0 in message
           cout << 0 << hex << output;
       else cout << hex << output;
      
   }
}

    
  
    

    

    

  
    







