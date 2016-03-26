/*
 * ECET279_Lab1_S_2015_LED_Test.c
 *
 * Description:
 * This is a simple program with which to create a project to be run on the Atmel ATmega2560
 *
 *
 * Execution results:
 * The LEDs are initialized into a pattern with each of the even numbered LEDs only being illuminated.
 * Pressing any of the 8 push-buttons on the STK600 causes the odd numbered LEDs only to light for 0.5 seconds.
 * The LED display then reverts back to the original pattern.
 * The process may be repeated any number of times.
 *
 * Hardware:
 *		Outputs: 	PORTB 0~7 connected to STK600 LEDs 0~7 (active low)
 *		Inputs: 	PORTD 0~7 connected to STK600 pushbuttons 0~7 (active low)
 *
 * Created: 1/10/2015 12:40:29 PM
 * Author: Cameron Wade Burford
 * Ver: 1.0
 */

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
   // Set up ports B and D
   DDRB = 0b11111111;                   // PORTB all outputs connected to LEDs. Note LEDs are active LOW
   PORTB = 0b10101010;                  // Even PORT bits set to 0V i.e. all even numbered LEDs initially ON
   DDRD = 0b00000000;                   // PORTD all inputs. */
                                        // Push buttons are active LOW i.e. press = 0, release = 1
   PORTD = 0b11111111;                  // Set pull-ups to ON. All inputs default to logic 1
   uint8_t	check;

    while(1)
    {
      check = ~PIND;                    // Read state of push-buttons
	  if(check)                         // Implement only if any PB pressed
	  {
	  PORTB = 0b01010101;               // Odd PORT bits set to 0V i.e. all odd numbered LEDs ON
	  _delay_ms(500);

	  PORTB = ~PINB;                    // Revert back to original LED pattern
	  _delay_ms(500);

	  while(check)	check = ~PIND;      // Read PIND until all PBs released
	  } // End of if(check)

	}   //End of while(1)

} //End of main()

