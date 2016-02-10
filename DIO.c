﻿/*
 * DIO.c
 *
 * Created: 25/01/2015 10:00:35 م
 *  Author: Ahmed Abdel-Kader
 */ 

#include "DIO.h"

/******************************************************************************************************************/
void DIO_Set_Direction(const DIO_Config *s_Config_Msg )
{
	volatile uint8 * DDR_Ptr;
	/* point to the required DDR Register */
	switch(s_Config_Msg->port)
	{
		case 'A': DDR_Ptr = &DDRA;
		break;
		case 'B': DDR_Ptr = &DDRB;
		break;
		case 'C': DDR_Ptr = &DDRC;
		break;
		case 'D': DDR_Ptr = &DDRD;
		break;
	}
	if(s_Config_Msg->direction == OUTPUT)
	{
		SET_BIT(*DDR_Ptr,s_Config_Msg->pin_num); // set the corresponding bit in the DDR register to configure it as output pin
	}
	else if(s_Config_Msg->direction == INPUT)
	{
		CLEAR_BIT(*DDR_Ptr,s_Config_Msg->pin_num); // clear the corresponding bit in the DDR register to configure it as input pin
	}
}
/*******************************************************************************************************************/

void DIO_Set_Direction_Port(const DIO_Config *s_Config_Msg )
{
	volatile uint8 * DDR_Ptr;
	/* point to the required DDR Register */
	switch(s_Config_Msg->port)
	{
		case 'A': DDR_Ptr = &DDRA;
		break;
		case 'B': DDR_Ptr = &DDRB;
		break;
		case 'C': DDR_Ptr = &DDRC;
		break;
		case 'D': DDR_Ptr = &DDRD;
		break;
	}
	if(s_Config_Msg->direction == OUTPUT)
	{
		*DDR_Ptr=0xFF; // set the corresponding bit in the DDR register to configure it as output pin
	}
	else if(s_Config_Msg->direction == INPUT)
	{
		*DDR_Ptr=0x00; // clear the corresponding bit in the DDR register to configure it as input pin
	}
}
/************************************************************************************************************************************/
void DIO_Write_Pin(const DIO_Config * s_State)
{
	volatile uint8 * PORT_Ptr;
	/* point to the required PORT Register */
	switch(s_State->port)
	{
		case 'A': PORT_Ptr = &PORTA;
		break;
		case 'B': PORT_Ptr = &PORTB;
		break;
		case 'C': PORT_Ptr = &PORTC;
		break;
		case 'D': PORT_Ptr = &PORTD;
		break;
	}
	if(s_State->value == LOGIC_HIGH)
	{
		SET_BIT(*PORT_Ptr,s_State->pin_num); //set the corresponding pin in the PORT register
	}
	else if(s_State->value == LOGIC_LOW)
	{
		CLEAR_BIT(*PORT_Ptr,s_State->pin_num); //clear the corresponding pin in the PORT register
	}
}
/*******************************************************************************************************************/
void DIO_Write_Port(const DIO_Config * s_State)
{
	volatile uint8 * PORT_Ptr;
	/* point to the required PORT Register */
	switch(s_State->port)
	{
		case 'A': PORT_Ptr = &PORTA;
		break;
		case 'B': PORT_Ptr = &PORTB;
		break;
		case 'C': PORT_Ptr = &PORTC;
		break;
		case 'D': PORT_Ptr = &PORTD;
		break;
	}
	*PORT_Ptr=s_State->value;
}
/***********************************************************************************************************************************/




uint8 DIO_Read_Pin(const DIO_Config * s_State)
{
	volatile uint8 * PIN_Ptr;
	uint8 output;
	/* point to the required PIN Register */
	switch(s_State->port)
	{
		case 'A': PIN_Ptr = &PINA;
		break;
		case 'B': PIN_Ptr = &PINB;
		break;
		case 'C': PIN_Ptr = &PINC;
		break;
		case 'D': PIN_Ptr = &PIND;
		break;
	}
	if(BIT_IS_SET(*PIN_Ptr,s_State->pin_num)) //check if the corresponding bit is set in the PIN register
	{
		output =  LOGIC_HIGH;
	}
	else if(BIT_IS_CLEAR(*PIN_Ptr,s_State->pin_num)) //check if the corresponding bit is clear in the PIN register
	{
		output = LOGIC_LOW;
	}
	return output;
}
/********************************************************************************************************************/