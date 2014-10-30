/*
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION 
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * 
 *
 * This file is a generated sample test application.
 *
 * This application is intended to test and/or illustrate some 
 * functionality of your system.  The contents of this file may
 * vary depending on the IP in your system and may use existing
 * IP driver functions.  These drivers will be generated in your
 * SDK application project when you run the "Generate Libraries" menu item.
 *
 */

#include <stdio.h>
#include "xparameters.h"
#include "xil_cache.h"
#include "xintc.h"
#include "intc_header.h"
#include "xtmrctr.h"
#include "tmrctr_header.h"
#include "tmrctr_intr_header.h"
#include "xgpio.h"
#include "gpio_header.h"

/* define a structure with bit fields */
typedef struct
{
  unsigned int rs : 1;
  unsigned int rw : 1;
  unsigned int en : 1;
  unsigned int db : 8 ;
} lcd;



void delay(numCycles){
	volatile int Delay;
	for (Delay = 0; Delay < numCycles; Delay++);
}


u32 outBits(lcd screen) {
//	xil_printf( "rs: 0x%01x\n", screen.rs );
//	xil_printf( "rw: 0x%01x\n", screen.rw );
//	xil_printf( "en: 0x%01x\n", screen.en );
//	xil_printf( "db: 0x%02x\n", screen.db );
	u32 allTogether = (screen.db<<3) | (screen.en<<2) | (screen.rw<<1) | screen.rs ;
	return  allTogether;
}

u32 read( XGpio Gpio ){
	XGpio_Initialize(&Gpio, XPAR_GPIO_0_DEVICE_ID);
	lcd commands;
	lcd pinDir;
	u32 gpioPinDir; // 0x0 is output, 0xFFF is input...
	u32 gpioOutput;
	commands.rs = 0;
	commands.rw = 0;
	commands.en = 0;
	commands.db = 0x00;

	pinDir.rs = 0;
	pinDir.rw = 0;
	pinDir.en = 0;
	pinDir.db = 0xFF;
	gpioPinDir = outBits(pinDir);
	XGpio_SetDataDirection(&Gpio, 1, gpioPinDir);
	gpioOutput = outBits(commands);
	XGpio_WriteReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET,gpioOutput);
	// commands.rs = 1;
	commands.rw = 1;
	gpioOutput = outBits(commands);
	XGpio_WriteReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET,gpioOutput);
	delay(3000);
	commands.en = 1;
	gpioOutput = outBits(commands);
	XGpio_WriteReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET,gpioOutput);
	delay(3000);
	// READ
	u32 readVal = 0;
	readVal = XGpio_ReadReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET);
	delay(1000);
	commands.en = 0;
	gpioOutput = outBits(commands);
	XGpio_WriteReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET,gpioOutput);
	delay(1000);
	commands.rs = 0;
	commands.rw = 0;
	gpioOutput = outBits(commands);
	XGpio_WriteReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET,gpioOutput);
	return readVal;
}

void write(lcd screen, XGpio Gpio){
	XGpio_Initialize(&Gpio, XPAR_GPIO_0_DEVICE_ID);
	lcd pinDir;
	u32 gpioOutput;
	u32 gpioPinDir; // 0x0 is output, 0xFFF is input...
	pinDir.rs = 0;
	pinDir.rw = 0;
	pinDir.en = 0;
	pinDir.db = 0xFF;
	gpioPinDir = outBits(pinDir);
	// screen arrives with the bits to be written already set.
	XGpio_SetDataDirection(&Gpio, 1, gpioPinDir);
	// Start of timing
	screen.rs = 0;
	screen.rw = 0;
	screen.en = 0;
	gpioOutput = outBits(screen);
	XGpio_WriteReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET,gpioOutput);
	delay(1000);
	screen.en = 1;
	gpioOutput = outBits(screen);
	XGpio_WriteReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET,gpioOutput);
	delay(3000);
	pinDir.db = 0x00;
	gpioPinDir = outBits(pinDir);
	XGpio_SetDataDirection(&Gpio, 1, gpioPinDir);
	XGpio_WriteReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET,gpioOutput);
	delay(3000);
	screen.en = 0;
	gpioOutput = outBits(screen);
	XGpio_WriteReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET,gpioOutput);
	pinDir.db = 0xFF;
	gpioPinDir = outBits(pinDir);
	XGpio_SetDataDirection(&Gpio, 1, gpioPinDir);
	screen.rs = 1;
	screen.rw = 1;
	gpioOutput = outBits(screen);
	XGpio_WriteReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET,gpioOutput);
}

void writeInst(lcd screen, XGpio Gpio){
	XGpio_Initialize(&Gpio, XPAR_GPIO_0_DEVICE_ID);
	lcd pinDir;
	u32 gpioOutput;
	u32 gpioPinDir; // 0x0 is output, 0xFFF is input...
	pinDir.rs = 0;
	pinDir.rw = 0;
	pinDir.en = 0;
	pinDir.db = 0xFF;
	gpioPinDir = outBits(pinDir);
	// screen arrives with the bits to be written already set.
	XGpio_SetDataDirection(&Gpio, 1, gpioPinDir);
	// Start of timing
	screen.rs = 1;
	screen.rw = 0;
	screen.en = 0;
	gpioOutput = outBits(screen);
	XGpio_WriteReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET,gpioOutput);
	delay(1000);
	screen.en = 1;
	gpioOutput = outBits(screen);
	XGpio_WriteReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET,gpioOutput);
	delay(3000);
	pinDir.db = 0x00;
	gpioPinDir = outBits(pinDir);
	XGpio_SetDataDirection(&Gpio, 1, gpioPinDir);
	XGpio_WriteReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET,gpioOutput);
	delay(3000);
	screen.en = 0;
	gpioOutput = outBits(screen);
	XGpio_WriteReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET,gpioOutput);
	pinDir.db = 0xFF;
	gpioPinDir = outBits(pinDir);
	XGpio_SetDataDirection(&Gpio, 1, gpioPinDir);
	screen.rs = 1;
	screen.rw = 1;
	gpioOutput = outBits(screen);
	XGpio_WriteReg(Gpio.BaseAddress, XGPIO_DATA_OFFSET,gpioOutput);
}

int main() 
{
   static XIntc intc;
   static XTmrCtr axi_timer_0_Timer;
   XGpio Gpio; /* The Instance of the GPIO Driver  */

   Xil_ICacheEnable();
   Xil_DCacheEnable();
   print("---Entering main---\n\r");
   xil_printf( "Memory size occupied by status2 : %d\n", sizeof(lcd) );

   lcd myLCD;
   myLCD.rs = 0;
   myLCD.rw = 0;
   myLCD.en = 0;
   myLCD.db = 0x30;

   u32 gpioOutput = outBits(myLCD);
   xil_printf( "gpioOut 0x%04x\n", gpioOutput );
   write(myLCD, Gpio);
   u32 readOut = read(Gpio);
   xil_printf( "readOut 0x%04x\n", readOut );
   write(myLCD, Gpio);
   delay(1000000);
   write(myLCD, Gpio);
   delay(1000000);
   write(myLCD, Gpio);
   delay(1000000);
   myLCD.rs = 0;
   myLCD.rw = 0;
   myLCD.en = 0;
   myLCD.db = 0x3C;
   gpioOutput = outBits(myLCD);
   write(myLCD, Gpio);
   delay(1000000);
   readOut = read(Gpio);
   xil_printf( "readOut 0x%04x\n", readOut );
   myLCD.db = 0x08;
   gpioOutput = outBits(myLCD);
   write(myLCD, Gpio);
   delay(1000000);
   readOut = read(Gpio);
   xil_printf( "readOut 0x%04x\n", readOut );

   myLCD.db = 0x01;
   gpioOutput = outBits(myLCD);
   write(myLCD, Gpio);
   delay(1000000);
   readOut = read(Gpio);
   xil_printf( "readOut 0x%04x\n", readOut );

   myLCD.db = 0x06;
   gpioOutput = outBits(myLCD);
   write(myLCD, Gpio);
   readOut = read(Gpio);
   xil_printf( "readOut 0x%04x\n", readOut );

   myLCD.db = 0x0F;
   gpioOutput = outBits(myLCD);
   write(myLCD, Gpio);
   readOut = read(Gpio);
   xil_printf( "readOut 0x%04x\n", readOut );

   // Blinking Cursor

   myLCD.db = 0xCF;
   gpioOutput = outBits(myLCD);
   write(myLCD, Gpio);
   readOut = read(Gpio);
   xil_printf( "readOut 0x%04x\n", readOut );

   myLCD.db = 0x30;
   gpioOutput = outBits(myLCD);
   writeInst(myLCD, Gpio);
   readOut = read(Gpio);
   xil_printf( "readOut 0x%04x\n", readOut );

   myLCD.db = 0x8B;
   gpioOutput = outBits(myLCD);
   write(myLCD, Gpio);
   readOut = read(Gpio);
   xil_printf( "readOut 0x%04x\n", readOut );

   myLCD.db = 0x48;
   gpioOutput = outBits(myLCD);
   writeInst(myLCD, Gpio);
   readOut = read(Gpio);
   xil_printf( "readOut 0x%04x\n", readOut );

   myLCD.db = 0x8C;
  gpioOutput = outBits(myLCD);
  write(myLCD, Gpio);
  readOut = read(Gpio);
  xil_printf( "readOut 0x%04x\n", readOut );

  myLCD.db = 0x45;
  gpioOutput = outBits(myLCD);
  writeInst(myLCD, Gpio);
  readOut = read(Gpio);
  xil_printf( "readOut 0x%04x\n", readOut );

  myLCD.db = 0x8D;
	gpioOutput = outBits(myLCD);
	write(myLCD, Gpio);
	readOut = read(Gpio);
	xil_printf( "readOut 0x%04x\n", readOut );

	myLCD.db = 0x4C;
	gpioOutput = outBits(myLCD);
	writeInst(myLCD, Gpio);
	readOut = read(Gpio);
	xil_printf( "readOut 0x%04x\n", readOut );

	myLCD.db = 0x8E;
	gpioOutput = outBits(myLCD);
	write(myLCD, Gpio);
	readOut = read(Gpio);
	xil_printf( "readOut 0x%04x\n", readOut );

	myLCD.db = 0x4C;
	gpioOutput = outBits(myLCD);
	writeInst(myLCD, Gpio);
	readOut = read(Gpio);
	xil_printf( "readOut 0x%04x\n", readOut );

	myLCD.db = 0x8F;
	gpioOutput = outBits(myLCD);
	write(myLCD, Gpio);
	readOut = read(Gpio);
	xil_printf( "readOut 0x%04x\n", readOut );

	myLCD.db = 0x4F;
	gpioOutput = outBits(myLCD);
	writeInst(myLCD, Gpio);
	readOut = read(Gpio);
	xil_printf( "readOut 0x%04x\n", readOut );

	myLCD.db = 0x80;
	gpioOutput = outBits(myLCD);
	write(myLCD, Gpio);
	readOut = read(Gpio);
	xil_printf( "readOut 0x%04x\n", readOut );

	// Blinky
	myLCD.db = 0xCF;
	gpioOutput = outBits(myLCD);
	write(myLCD, Gpio);
	readOut = read(Gpio);
	xil_printf( "readOut 0x%04x\n", readOut );

   print("---Exiting main---\n\r");
   Xil_DCacheDisable();
   Xil_ICacheDisable();
   return 0;
}
