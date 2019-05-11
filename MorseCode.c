/*
 * GccApplication10.c
 *
 * Created: 3/4/2019 9:15:19 PM
 * Author : Achuthan Panikath & Ayan Sengupta
Program Name:
*  MorseCode.c
*
* Purpose:
*	 To display the message 'Washington - July 2, 1862.' in Morse code by blinking the LED as per standard Morse Code.
*
* Test environment:
*   Atmel Studio
*
* Authors: Ayan Sengupta, Achuthan Panikath
*
* Course: ECE231, UMass Amherst
*
* Usage:
*	 Run the program.
*	 
*	 
*	 
*
* Revision history:
*      1.0  5 March 2019,  Achuthan Panikath, Ayan Sengupta
*           Initial Version.
*
*      1.1  7 March 2019,  Ayan Sengupta, Achuthan Panikath.
*           fixed times for dots from 1 seconds to 500 ms and dashes from 3 seconds to 1.5 seconds
*           fixed variable name for dot_delay.
*
* Note: 7th March 2019 - tested and ready for demo
*
*
* References: ECE231 Class Recording
*             
*
*******************************************************
*/

#include <avr/io.h>

void delay(float s) //function to cause delay
{
	RTC.CNT = 0;
	while(RTC.CNT<=s)
	{
		
		}
}
int main(void)
{
	PORTB.DIR = 0xFF;// to set the LED port
	RTC.CLKSEL = RTC.CLKSEL & 0b11111100;
	//RTC selects the ULP Clock
	RTC.CTRLA = RTC.CTRLA | 0b00101001;//101=5 is the prescaler mask for factor 32 and LSB of 1 enables RTC
	int dot_delay = 500; //1000 micro seconds for the dot delay
	int dash_delay = 3*dot_delay; //dashes are 3 times the delay of dots
	int inletter_sp = dot_delay; //space between same letters is 1000 microseconds
	int bwletter_sp = 3*dot_delay; //space between different letters is 3000 microseconds
	int word_sp = 7*dot_delay; //space between words is 7 microseconds
	
	
    while (1)
    {	//start by leaving light off for two seconds
		PORTB.OUT = 0xFF;
		delay(2000);
		
		//Morse for W is .--
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for a in letter 
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for a between letter period
		delay(bwletter_sp);
		
		//Morse for a is .-
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for a between letter period
		delay(bwletter_sp);
		
		//Morse for s is ...
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for a between letter period
		delay(bwletter_sp);
		
		//Morse for h is ....
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for a between letter period
		delay(bwletter_sp);
		
		//Morse for i is ..
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for a between letter period
		delay(bwletter_sp);
		
		//Morse for n is _.
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for a between letter period
		delay(bwletter_sp);
		
		//Morse for g is _ _ .
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for a between letter period
		delay(bwletter_sp);
		
		//Morse for t is _
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for a between letter period
		delay(bwletter_sp);
		
		//Morse for o is _ _ _
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for a between letter period
		delay(bwletter_sp);
		
		//Morse for n is _ .
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for word period
		delay(word_sp);
		
		//Morse for - is _...._
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for word period
		delay(word_sp);
		
		//Morse for J is ._ _ _
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for a between letter period
		delay(bwletter_sp);
		
		//Morse for u is .._
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for a between letter period
		delay(bwletter_sp);
		
		//Morse for l is . _ ..
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for a between letter period
		delay(bwletter_sp);
		
		//Morse for y is _. _ _
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for word period
		delay(word_sp);
		
		//Morse for 2 is .._ _ _
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for word period
		delay(word_sp);
		
		//Morse for comma is _ _ .. _ _
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for word period
		delay(word_sp);
		
		//Morse for 1 is . _ _ _ _
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for a between letter period
		delay(bwletter_sp);
		
		//Morse for 8 is _ _ _ ..
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for a between letter period
		delay(bwletter_sp);
		
		//Morse for 6 is _....
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for a between letter period
		delay(bwletter_sp);
		
		//Morse for 2 is .._ _ _
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for word period
		delay(word_sp);
		
		//Morse for period is ._._._
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dot period
		delay(dot_delay);
		PORTB.OUT = 0xFF;//off for in letter period
		delay(inletter_sp);
		PORTB.OUT = 0x00;//on for a dash period
		delay(dash_delay);
		PORTB.OUT = 0xFF;//off for word period
		delay(word_sp);
		
	}
}

