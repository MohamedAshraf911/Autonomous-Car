/*
 * main.c
 *
 *  Created on: Oct 15, 2022
 *      Author: DELL
 */

#include "LIB/STD_TYPES.H"
#include "LIB/Bit_Math.h"
#include "MCAL/MDIO/MDIO_Interface.h"
#include "HAL/HCLCD/HCLCD_Interface.h"
#include "HAL/HKPD/HKPD_Interface.h"
#include "HAL/HSEVEN_SEG/HSEVEN_SEG_Interface.h"
#include "util/delay.h"
#include "HAL/HUS/HUS_Interface.h"
#include "HAL/HCLCD/HCLCD_Interface.h"
#include "HAL/HDCM/HDCM_Interface.h"
#include "MCAL/MEXTI/MEXTI_Interface.h"
#include "MCAL/MGIE/MGIE_Interface.h"
#include "HAL/HSERVO/HSERVO_Interface.h"

extern u16 GLOB_DIS;

enum state
{
	Forward,
	Right,
	Left,
	Back
}states;



int main()
{
	/*Initializing the Ultrasonic sensor, LCD, Servo motor and the DC motors
	 * Also enable the global interrupt for using external interrupt zero */
	u16 mid_distance;
	u16 left_distance;
	u16 right_distance;
	MGIE_Enable();
	US_INIT();
	HCLCD_Init4Bit();
	HSERVO_Init();
	HDCM_Init();
	/*Setting the initial state of the car as Forward to make it move forward first*/
	states = Forward;
	while(1)

	{
		switch(states)
		{
		case Forward:
			/*Display the direction on the LCD*/
			HCLCD_WriteCommand4Bit(0b00000001);
			HCLCD_WriteString("Dir: Forward");
			/*Rotate the servo motor to the middle to check if there is an obstacle on the way or not*/
			HSERVO_Rotate_Middle();
			/*Activating the trigger of the ultrasonic sensor to send an ultrasonic wave
			 * on the way that is reflected from objects in the direction of its propagation
			 * and then we calculate the distance using the time of its propagation while it is going back*/
			US_Trigger();
			_delay_ms(70);
			mid_distance = GLOB_DIS;
			/*We check if the distance calculated from the ultrasonic sensor is close to the car or not*/
			if(mid_distance <= 40 && mid_distance > 0)
			{
				/*If the the distance is close then we stop the car and turn the servo to the right
				 * and activate the ultrasonic sensor to check if there are obstacles on the way or not*/
				HDCM_Stop();
				HSERVO_Rotate_Right();
				_delay_ms(1000);
				US_Trigger();
				_delay_ms(70);
				right_distance = GLOB_DIS;
				_delay_ms(1000);
				/*we do the same as above but this time the servo turns to the left*/
				HSERVO_Rotate_Left();
				_delay_ms(1000);
				US_Trigger();
				_delay_ms(70);
				left_distance = GLOB_DIS;
				_delay_ms(1000);
				/*We check if the distance calculated from the ultrasonic sensor is close to the car or not
				 * if the right distance is not close then the car turns to the right
				 * if the right distance is close but the left distance is not close then the car turns to the left
				 * if both distances are close to the car then the car goes back*/
				if(right_distance > 40 || right_distance == 0)
				{
					states = Right;
				}
				else if(left_distance > 40 || left_distance == 0)
				{
					states = Left;
				}
				else
				{
					states = Back;
				}
			}
			else
			{
				HDCM_Forward();
			}

			break;
		case Right:
			/*We display the new direction of the car*/
			HCLCD_WriteCommand4Bit(0b00000001);
			HCLCD_WriteString("Dir: Right");
			/*Turn the car right*/
			HDCM_Right();
			_delay_ms(750);
			HDCM_Stop();
			_delay_ms(20);
			/*turn the servo motor to the middle and make the car move forward if there are no obstacles*/
			HSERVO_Rotate_Middle();
			_delay_ms(1000);
			states =Forward;
			break;
		case Left:
			/*We display the new direction of the car*/
			HCLCD_WriteCommand4Bit(0b00000001);
			HCLCD_WriteString("Dir: Left");
			/*Turn the car left*/
			HDCM_Left();
			_delay_ms(750);
			HDCM_Stop();
			_delay_ms(20);
			/*turn the servo motor to the middle and make the car move forward if there are no obstacles*/
			HSERVO_Rotate_Middle();
			_delay_ms(1000);
			states =Forward;
			break;
		case Back:
			/*We display the new direction of the car*/
			HCLCD_WriteCommand4Bit(0b00000001);
			HCLCD_WriteString("Dir: Backward");
			/*The car moves to the back*/
			HDCM_Back();
			_delay_ms(750);
			HDCM_Stop();
			_delay_ms(20);
			/*turn the servo to the right and activate the ultrasonic sensor to check if there are obstacles on the way or not*/
			HSERVO_Rotate_Right();
			_delay_ms(1000);
			US_Trigger();
			_delay_ms(70);
			right_distance = GLOB_DIS;
			_delay_ms(1000);
			/*turn the servo to the left and activate the ultrasonic sensor to check if there are obstacles on the way or not*/
			HSERVO_Rotate_Left();
			_delay_ms(1000);
			US_Trigger();
			_delay_ms(70);
			left_distance = GLOB_DIS;
			_delay_ms(1000);
			/*We check if the distance calculated from the ultrasonic sensor is close to the car or not
			 * if the right distance is not close then the car turns to the right
			 * if the right distance is close but the left distance is not close then the car turns to the left
			 * if both distances are close to the car then the car goes back*/
			if(right_distance > 40 || right_distance == 0)
			{
				states = Right;
			}
			else if(left_distance > 40 || left_distance == 0)
			{
				states = Left;
			}
			else
			{
				states = Back;
			}
			break;
		}
	}
}
