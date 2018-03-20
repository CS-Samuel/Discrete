//------------------------------------------------------------------------------------------------------------
//
// Name:  Samuel Weems
//
// Course:  CS 2433, Spring 17, Cerise Wuthrich
//
// Purpose:  This program uses different versions of the Sieve of Eratosthenes to identify prime numbers.
//           Each version will find and display primes less than 500.
//           Then each version will find the primes up to 5,000, 50,000 and 100,000
//           displaying the amount of time (seconds with 4 decimal places) it took to complete each version
//           and displaying the number of primes.
//
//          Version 1: Check every value using Sieve process and replace composite numbers with 0's
//          Version 2: Beginning with prime X, skip X values and replace value with 0's
//          Version 3: Start replacing values with 0 starting at first replacement instead of beginning of list
//          Version 4: Use a counter to keep track of the number of composites to calculate total # of primes
//          Version 5:  Skip values based on patterns to minimize the number of repeat value replacements
//                     and stop checking for multiples of primes once reaching a certain point (square root of the list size)
//------------------------------------------------------------------------------------------------------------


#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

// Function prototypes

void fillArray (int Array[], int size);
void displayArray (int Array[], int size);

void Sieve1 (int Array[], int size, int &NumPrimes);
void Sieve2 (int Array[], int size, int &NumPrimes);
void Sieve3 (int Array[], int size, int &NumPrimes);
void Sieve4 (int Array[], int size, int &NumPrimes);
void Sieve5 (int Array[], int size, int &NumPrimes);


// Main Function

int main (){

// Variables for total number of primes in each array and timer
    
    int numPrime;
    double t1, t2;
    
// Define and fill arrays for each case, 500, 5,000, 50,0000, and 100,000
    
    int Array500[499], Array5k[4999], Array50k[49999], Array100k[99999];
    
    fillArray (Array500, 499);
    fillArray (Array5k, 4999);
    fillArray (Array50k, 49999);
    fillArray (Array100k, 99999);
    
// Display Prime Numbers less than 500
    
    cout << "Displaying Prime numbers less than 500:" << endl << endl;
    
// Version 1
    
    Sieve1 (Array500, 499, numPrime);
    
    cout << "Version 1:" << endl << endl;
    displayArray (Array500, 499);
    

// Resetting Array500
    
    fillArray (Array500, 499);
    

// Version 2
    
    Sieve2 (Array500, 499, numPrime);
    
    cout << endl << endl << "Version 2:" << endl << endl;
    displayArray (Array500, 499);

// Resetting Array500
    
    fillArray (Array500, 499);

// Version 3 
    
    Sieve3 (Array500, 499, numPrime);
    
    cout << endl << endl << "Version 3:" << endl << endl;
    displayArray (Array500, 499);

// Resetting Array500
    
    fillArray (Array500, 499);
    
// Version 4
    
    Sieve4 (Array500, 499, numPrime);
    
    cout << endl << endl << "Version 4:" << endl << endl;
    displayArray (Array500, 499);
    
// Resetting Array500
    
    fillArray (Array500, 499);

// Version 5
    
    Sieve5 (Array500, 499, numPrime);
    
    cout << endl << endl << "Version 5:" << endl << endl;
    displayArray (Array500, 499);
    cout << endl << endl;
    
// Primes up to 5,000
    
    cout << "Primes up to 5,000:" << endl << endl;
    
// Version 1
    
    
    t1 = clock();
    Sieve1 (Array5k, 4999, numPrime);
    t2 = clock();
    
    cout << "Version 1" << endl << "Number of Primes:" << fixed << setprecision(4) << numPrime << endl;
    cout << "Time: " << (t2-t1) / CLK_TCK << " sec" << endl << endl;
    
// Version 2
    
    t1 = clock();
    Sieve2 (Array5k, 4999, numPrime);
    t2 = clock();
    
    cout << "Version 2" << endl << "Number of Primes:" << numPrime << endl;
    cout << "Time: " << (t2-t1) / CLK_TCK << " sec" << endl << endl;

// Version 3
    
    t1 = clock();
    Sieve3 (Array5k, 4999, numPrime);
    t2 = clock();
    
    cout << "Version 3" << endl << "Number of Primes:" << numPrime << endl;
    cout << "Time: " << (t2-t1) / CLK_TCK << " sec" << endl << endl;
    
// Version 4
    
    t1 = clock();
    Sieve2 (Array5k, 4999, numPrime);
    t2 = clock();
    
    cout << "Version 4" << endl << "Number of Primes:" << numPrime << endl;
    cout << "Time: " << (t2-t1) / CLK_TCK << " sec" << endl << endl;
    
// Version 5
    
    t1 = clock();
    Sieve5 (Array5k, 4999, numPrime);
    t2 = clock();
    
    cout << "Version 5" << endl << "Number of Primes:" << numPrime << endl;
    cout << "Time: " << (t2-t1) / CLK_TCK << " sec" << endl << endl;

// Primes up to 50,000
    
      cout << "Primes up to 50,000:" << endl << endl;
    
// Version 1
    
    t1 = clock();
    Sieve1 (Array50k, 49999, numPrime);
    t2 = clock();
    
    cout << "Version 1" << endl << "Number of Primes:" << numPrime << endl;
    cout << "Time: " << (t2-t1) / CLK_TCK << " sec" << endl << endl;
    
// Version 2
    
    t1 = clock();
    Sieve2 (Array50k, 49999, numPrime);
    t2 = clock();
    
    cout << "Version 2" << endl << "Number of Primes:" << numPrime << endl;
    cout << "Time: " << (t2-t1) / CLK_TCK << " sec" << endl << endl;
    
// Version 3
    
    t1 = clock();
    Sieve3 (Array50k, 49999, numPrime);
    t2 = clock();
    
    cout << "Version 3" << endl << "Number of Primes:" << numPrime << endl;
    cout << "Time: " << (t2-t1) / CLK_TCK << " sec" << endl << endl;
    
// Version 4
    
    t1 = clock();
    Sieve4 (Array50k, 49999, numPrime);
    t2 = clock();
    
    cout << "Version 4" << endl << "Number of Primes:" << numPrime << endl;
    cout << "Time: " << (t2-t1) / CLK_TCK << " sec" << endl << endl;
    
// Version 5
    
    t1 = clock();
    Sieve5 (Array50k, 49999, numPrime);
    t2 = clock();
    
    cout << "Version 5" << endl << "Number of Primes:" << numPrime << endl;
    cout << "Time: " << (t2-t1) / CLK_TCK << " sec" << endl << endl;
    
// Primes up to 100,000
    
    cout << "Primes up to 100,000:" << endl << endl;
    
// Version 1
    
    
    t1 = clock();
    Sieve1 (Array100k, 99999, numPrime);
    t2 = clock();
    
    cout << "Version 1" << endl << "Number of Primes:" << numPrime << endl;
    cout << "Time: " << (t2-t1) / CLK_TCK << " sec" << endl << endl;
    
// Version 2
    
    
    t1 = clock();
    Sieve2 (Array100k, 99999, numPrime);
    t2 = clock();
    
    cout << "Version 2" << endl << "Number of Primes:" << numPrime << endl;
    cout << "Time: " << (t2-t1) / CLK_TCK << " sec" << endl << endl;
    
// Version 3
    
    
    t1 = clock();
    Sieve3 (Array100k, 99999, numPrime);
    t2 = clock();
    
    cout << "Version 3" << endl << "Number of Primes:" << numPrime << endl;
    cout << "Time: " << (t2-t1) / CLK_TCK << " sec" << endl << endl;
    
// Version 4
    
    
    t1 = clock();
    Sieve4 (Array100k, 99999, numPrime);
    t2 = clock();
    
    cout << "Version 4" << endl << "Number of Primes:" << numPrime << endl;
    cout << "Time: " << (t2-t1) / CLK_TCK << " sec" << endl << endl;
    
// Version 5
    
    
    t1 = clock();
    Sieve5 (Array100k, 99999, numPrime);
    t2 = clock();
    
    cout << "Version 5" << endl << "Number of Primes:" << numPrime << endl;
    cout << "Time: " << (t2-t1) / CLK_TCK << " sec" << endl << endl;
}

    
// Array Filling Function

void fillArray (int Array[], int size)
{
    int j=2;
    
    for (int i=0; i<size; i++)
    {
        Array[i]=j;
        ++j;
    }
   
}

// Display Prime Numbers in Array Function

void displayArray (int Array[], int size)
{
    for (int i=0; i<size; i++)
        if (Array[i] != 0)
            cout << Array[i]  << " ";
}

// Version 1 Function: Check every value using Sieve process and replace composite numbers with 0's

void Sieve1 (int Array[], int size, int &NumPrimes)
{
    NumPrimes=0;
    int currentPrime;
    
    for (int i=0; i<size; i++)
    {

// If Array Element has not been set to 0 (composite) then make this the current prime to check with
        
        if (Array[i] != 0)
        {
            currentPrime = Array[i];
            
// Using the current prime check each array element and if it is divisible (composite) set value to 0
        
            for (int j=0; j<size; j++)
            {
                if ((Array[j] != currentPrime) && (Array[j] % currentPrime == 0))
                    Array[j] = 0;
            }
        }
    }

// Go through the Array to count the total number of prime numbers
    
    
    for (int i=0; i<size; i++)
    {
        if (Array[i] != 0)
            ++NumPrimes;
    }
    
}

// Version 2 Function: Beginning with prime X, skip X values and replace value with 0's without checking

void Sieve2 (int Array[], int size, int &NumPrimes)
{
    NumPrimes=0;
    int currentPrime;
    
    for (int i=0; i<size; i++)
    {
        
// If Array Element has not been set to 0 (composite) then make this the current prime to check with
        
        if (Array[i] != 0)
        {
            currentPrime = Array[i];
            
// Using the current prime, and beginning at its location, set every multiple of that number in the array to 0
            
            for (int j= currentPrime-2; j<size; j += currentPrime)
            {
                if (Array[j] != currentPrime)
                    Array[j] = 0;
            }
        }
    }
    
    // Go through the Array to count the total number of prime numbers
    
    
    for (int i=0; i<size; i++)
    {
        if (Array[i] != 0)
            ++NumPrimes;
    }
    
}
    
// Version 3 Function: Start replacing values with 0 starting at first replacement instead of beginning of list

void Sieve3 (int Array[], int size, int &NumPrimes)
{
    NumPrimes=0;
    int currentPrime;
    
    for (int i=0; i<size; i++)
    {
        
// If Array Element has not been set to 0 (composite) then make this the current prime to check with
        
        if (Array[i] != 0)
        {
            currentPrime = Array[i];
            
// Using the current prime set every multiple of that number in the array to 0
// In this version begin with the first replacement which is the current prime value squared
            
            if (pow(currentPrime,2)<size-2)
                for (int j= pow(currentPrime,2)-2; j<size; j += currentPrime)
                    Array[j] = 0;
        }
    }
    
// Go through the Array to count the total number of prime numbers
    
    
    for (int i=0; i<size; i++)
    {
        if (Array[i] != 0)
            ++NumPrimes;
    }
    
}

// Version 4 Function: Use a counter to keep track of the number of composites to calculate total # of primes

void Sieve4 (int Array[], int size, int &NumPrimes)
{
    NumPrimes=0;
    int currentPrime;
    
    for (int i=0; i<size; i++)
    {
        
// If Array Element has not been set to 0 (composite) then make this the current prime to check with
// In this version increment the total number of primes counter by 1 each time a current prime is found
        
        if (Array[i] != 0)
        {
            currentPrime = Array[i];
            ++NumPrimes;
            
// Using the current prime set every multiple of that number in the array to 0
// Begin with the first replacement which is the current prime value squared

            if (pow(currentPrime,2)<size-2)
                for (int j= pow(currentPrime,2)-2; j<size; j += currentPrime)
                    Array[j] = 0;
        }
    }
}

// Version 5 Function: Skip values based on patterns to minimize the number of repeat value replacements
//                     and stop checking for multiples of primes once reaching a certain point (square root of the list size)
// In this version replace multiples of 2 as before, for multiples of 3 replace every 6 values instead of every 3
// Beginning with prime number 5 alternate between the follwoing two patterns:
// Pattern 1: To find composites to replace with 0, alternate between skipping the Prime Value * 2 and the Prime Value * 4 number of values
// Pattern 2: To find composites to replace with 0, alternate between skipping the Prime Value * 4 and the Prime Value * 2 number of values

void Sieve5 (int Array[], int size, int &NumPrimes)
{
    NumPrimes=2;
    int currentPrime;

// Pattern Counter to alternate between patterns and internal counters for alternating inside each pattern

    int patternCounter = 0, internalCounter;
    
// Prime 2- Replace 2 multiples every 2 values
    
    for (int i=2; i<size; i+=2)
        Array[i] = 0;
    
// Prime 3- Replace 3 multiples every 6 values (Prime Value * 2)
    
    for(int i=7; i<size; i+=6)
        Array[i] = 0;

// Prime 5 and above
// Stop looking for multiples of primes once reaching the square root of the list size
    
    for (int i=3; i<sqrt(size+1)-2; i++)
    {
        
// If Array Element has not been set to 0 (composite) then make this the current prime to check with
        
        if (Array[i] != 0)
        {
            currentPrime = Array[i];
            ++NumPrimes;
            ++patternCounter;
            internalCounter = 0;

// Pattern 1
            
            if (patternCounter % 2 !=0)
                for (int j= pow(currentPrime,2)-2; j<size; j += currentPrime*2+currentPrime*2*(internalCounter % 2 ==0))
                {
                    ++internalCounter;
                    Array[j]=0;
                }
                    
// Pattern 2
            
            else
                for (int k=pow(currentPrime,2)-2; k<size; k += currentPrime*2+currentPrime*2*(internalCounter % 2 !=0))
                {
                    ++internalCounter;
                    Array[k]=0;
                }

        }
    }

// Find remaining primes in list and increment the numPrime counter
    
    for (int i=sqrt(size+1)-1; i<size; ++i)
    {
        if (Array[i]!=0)
            ++NumPrimes;
    }
}







