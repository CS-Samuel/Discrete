//------------------------------------------------------------------------------------------------------------
//
// Name:  Samuel Weems
//
// Course:  CS 2433, Spring 17, Cerise Wuthrich
//
// Purpose:  This program supposes there are 8 dipswitches representing these options:
//      0. Sensor Enter (There is a sensor that will automatically open the gate and allow visitors onto the property.)
//      1. Soft Open (The gate opening speed will gradually diminish as it opens.)
//      2. Soft Close (The gate opening speed will gradually diminish as it closes.)
//      3. Automatic Close (The gate will close automatically after a visitor enters/exits.)
//      4. Sensor Exit (There is a sensor that will automatically open the gate and allow visitors to exit the property.)
//      5. Intercom keypad (The intercom is enabled allowing visitors to signal the base station in the house.)
//      6. Pin Lock (When on, disables the ability to manually operate the gate.)
//      7. Photo Beam (When on, senses objects in the way of gate open/close and automatically reverses.)
//  The program takes input from a file named "on_off.dat" which contains exactly ten lines of data.
//  Based on these values the program uses bitwise operators to appropriately set the bits of the single variable.
//  The resulting base ten number is sent to the output file along with the gate number.
//------------------------------------------------------------------------------------------------------------


#include<iostream>
#include<fstream>
#include<math.h>
#include<string>

using namespace std;

// Main Function

int main (){
    
    int pointer;        // Variable that points to target bit
    string input;       // Variable to receive "on" "off" input from file
    unsigned short dipSwitchStates[10] {};  // Array to store 10 different lines of dipswitch state data
    
// Opening data file
    
    ifstream inputFile;
    inputFile.open ("on_off.dat");
    
    
// Reading file information about dipswitch states and storing information in dipswitchState array

    
    for (int i = 0; i < 10; i++) {          // Loop for each array element (10 lines of data)
        
        for (int j = 1; j < 9; j++) {       // Loop for each bit value per array element
        
            pointer = pow (2,8-j);          // increases by powers of 2 to target appropriate bit starting with leftmost bit
            inputFile >> input;             // Reads next entry from data file into temporary input variable
            
        if ((input == "on"))
            dipSwitchStates[i] = dipSwitchStates[i]^(pointer);    // uses bit operator to toggle target bit from 0 to 1 if "on"
   
        }
    }
    
// Closing Input File
    
    inputFile.close();
    
// Creating Output File Weems_Samuel_GateB.out
    
    ofstream outputFile;
    outputFile.open ("Weems_Samuel_GateB.out");
    
// Outputting Gate #1
    
    outputFile << "Samuel Weems" << endl << endl;
    outputFile << "Gate #1 FLAG is " << dipSwitchStates[0]<< endl;
    
// Toggle the Photo Beam bit and send output to outputFile
    
    dipSwitchStates[0] =  dipSwitchStates[0]^128;
    
    outputFile << "If the PHOTO BEAM bit is toggled, the flag would be " << dipSwitchStates[0] << "." << endl << endl;
    
// Output Gates #2-10
    
    for (int i=1; i<10; i++) {
        
        outputFile << "Gate #" << i+1 << " FLAG is " << dipSwitchStates[i] << endl << endl;
        
        }
    
// Closing Output File
    
    outputFile.close();
    
    return 0;
    
}
