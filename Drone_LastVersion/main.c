///*
// * main.c
// *
// *  Created on: May 1, 2023
// *      Author: ElRuby
// */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MCAL/DIO_interface.h"
#include "MCAL/Timer_interface.h"
#include "MCAL/ADC_interface.h"
#include "MCAL/UART_interface.h"
#include "hal/BLTH_interface.h"
#include "hal/MPU6050_register.h"
#include <util/delay.h>
//
void main(){

	TIM1_voidInitialize();
	TIM3_voidInitialize();
	TIM1_voidSetTimerReg(20000);                         //SET FREQ=50HZ
	TIM3_voidSetTimerReg(20000);

	DIO_SetPortDirection(PORTB,PORT_OUTPUT);
	DIO_SetPortDirection(PORTA,PORT_INPUT);
	DIO_SetPortDirection(PORTE,PORT_OUTPUT);


	TIM1_A_voidSetCompareVal(1900);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
	TIM3_A_voidSetCompareVal(1900);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
	TIM1_B_voidSetCompareVal(1900);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
	TIM3_B_voidSetCompareVal(1900);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC



	UART_voidInit();

	DIO_SetPinDirection(PORTD,PIN2,PIN_INPUT);
	DIO_SetPinDirection(PORTD,PIN3,PIN_OUTPUT);



	u8 Reading,Speed;

while (1){

		Reading = BLTH_u8GetBluetoothReading();
		Speed=BLTH_u8GetBluetoothReading();

		if (Reading == FORWARD){

			if  (Speed < SPEED3){
				TIM1_A_voidSetCompareVal(2100);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
				TIM3_A_voidSetCompareVal(2100);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
				TIM1_B_voidSetCompareVal(2100);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
				TIM3_B_voidSetCompareVal(2100);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

					}
						else if ( (Speed >= SPEED3) &&  (Speed < SPEED5) ){

							TIM1_A_voidSetCompareVal(2800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM3_A_voidSetCompareVal(2800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM1_B_voidSetCompareVal(2800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM3_B_voidSetCompareVal(2800);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

						}

						else if ( (Speed >= SPEED5) &&  (Speed < SPEED8) ){

							TIM1_A_voidSetCompareVal(3200);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM3_A_voidSetCompareVal(3200);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM1_B_voidSetCompareVal(3200);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM3_B_voidSetCompareVal(3200);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

						}

						else if ( (Speed >= SPEED8) &&  (Speed < SPEED10) ){
							TIM1_A_voidSetCompareVal(3800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM3_A_voidSetCompareVal(3800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM1_B_voidSetCompareVal(3800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM3_B_voidSetCompareVal(3800);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

						}
		}

		else if (Reading == BACKWARD){

			if  (Speed < SPEED3){

				            TIM1_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM3_A_voidSetCompareVal(2100);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM1_B_voidSetCompareVal(2100);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM3_B_voidSetCompareVal(0000);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

								}
									else if ( (Speed >= SPEED3) &&  (Speed < SPEED5) ){

										TIM1_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_A_voidSetCompareVal(2800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM1_B_voidSetCompareVal(2800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_B_voidSetCompareVal(0000);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

									}

									else if ( (Speed >= SPEED5) &&  (Speed < SPEED8) ){

										TIM1_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_A_voidSetCompareVal(3200);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM1_B_voidSetCompareVal(3200);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_B_voidSetCompareVal(0000);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

									}

									else if ( (Speed >= SPEED8) &&  (Speed < SPEED10) ){
										TIM1_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_A_voidSetCompareVal(3800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM1_B_voidSetCompareVal(3800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_B_voidSetCompareVal(0000);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

									}

		}

		else if (Reading == LEFT){


			if  (Speed < SPEED3){

				            TIM1_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM3_A_voidSetCompareVal(2100);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM1_B_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM3_B_voidSetCompareVal(2100);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

								}
									else if ( (Speed >= SPEED3) &&  (Speed < SPEED5) ){

										TIM1_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_A_voidSetCompareVal(2800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM1_B_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_B_voidSetCompareVal(2800);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

									}

									else if ( (Speed >= SPEED5) &&  (Speed < SPEED8) ){

										TIM1_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_A_voidSetCompareVal(3200);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM1_B_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_B_voidSetCompareVal(3200);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

									}

									else if ( (Speed >= SPEED8) &&  (Speed < SPEED10) ){
										TIM1_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_A_voidSetCompareVal(3800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM1_B_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_B_voidSetCompareVal(3800);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

									}





		}

		else if (Reading == RIGHT){

			if  (Speed < SPEED3){

				            TIM1_A_voidSetCompareVal(2100);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM3_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM1_B_voidSetCompareVal(2100);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
							TIM3_B_voidSetCompareVal(0000);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

								}
									else if ( (Speed >= SPEED3) &&  (Speed < SPEED5) ){

										TIM1_A_voidSetCompareVal(2800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM1_B_voidSetCompareVal(2800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_B_voidSetCompareVal(0000);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

									}

									else if ( (Speed >= SPEED5) &&  (Speed < SPEED8) ){

										TIM1_A_voidSetCompareVal(3200);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM1_B_voidSetCompareVal(3200);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_B_voidSetCompareVal(0000);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

									}

									else if ( (Speed >= SPEED8) &&  (Speed < SPEED10) ){
										TIM1_A_voidSetCompareVal(3800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM1_B_voidSetCompareVal(3800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
										TIM3_B_voidSetCompareVal(0000);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

									}



		}

		else if (Reading == HOVER_ON){



					TIM1_A_voidSetCompareVal(2100);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
					TIM3_A_voidSetCompareVal(2100);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
					TIM1_B_voidSetCompareVal(2100);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
					TIM3_B_voidSetCompareVal(2100);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC





		}

		else if (Reading == HOVER_OFF){

			TIM1_A_voidSetCompareVal(1900);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
			TIM3_A_voidSetCompareVal(1900);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
			TIM1_B_voidSetCompareVal(1900);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
			TIM3_B_voidSetCompareVal(1900);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC




		}

		else if (Reading == STOP) {
			TIM1_A_voidSetCompareVal(1900);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
			TIM3_A_voidSetCompareVal(1900);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
			TIM1_B_voidSetCompareVal(1900);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
			TIM3_B_voidSetCompareVal(1900);                   //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

		}
}
}





/*
			else if (Reading == BACKWARD){
				TIM1_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
				TIM3_A_voidSetCompareVal(2500);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
				TIM1_B_voidSetCompareVal(2500);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
				TIM3_B_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC


			}

			else if (Reading == LEFT){
				TIM1_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
				TIM3_A_voidSetCompareVal(2500);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
				TIM1_B_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
				TIM3_B_voidSetCompareVal(2500);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

			}
			else if (Reading == RIGHT){
				TIM1_A_voidSetCompareVal(2500);
                TIM3_A_voidSetCompareVal(1000);
			    TIM1_B_voidSetCompareVal(2500);
                TIM3_B_voidSetCompareVal(0000);
			}
	        else {

				TIM1_A_voidSetCompareVal(1900);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
				TIM3_A_voidSetCompareVal(1900);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
				TIM1_B_voidSetCompareVal(1900);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
				TIM3_B_voidSetCompareVal(1900);                   //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

		}
}
	}





 {
	TIM1_A_voidSetCompareVal(2500);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
	TIM3_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
	TIM1_B_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
	TIM3_B_voidSetCompareVal(2500);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC


} */



// FORWARD DRONE

/*		if  (Speed < SPEED3){
			TIM1_A_voidSetCompareVal(2100);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
			TIM3_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
			TIM1_B_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
			TIM3_B_voidSetCompareVal(2100);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

				}
					else if ( (Speed >= SPEED3) &&  (Speed < SPEED5) ){

						TIM1_A_voidSetCompareVal(2800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
						TIM3_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
						TIM1_B_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
						TIM3_B_voidSetCompareVal(2800);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

					}

					else if ( (Speed >= SPEED5) &&  (Speed < SPEED8) ){

						TIM1_A_voidSetCompareVal(3200);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
						TIM3_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
						TIM1_B_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
						TIM3_B_voidSetCompareVal(3200);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

					}

					else if ( (Speed >= SPEED8) &&  (Speed < SPEED10) ){
						TIM1_A_voidSetCompareVal(3800);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
						TIM3_A_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
						TIM1_B_voidSetCompareVal(0000);                     //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC
						TIM3_B_voidSetCompareVal(3800);                    //OUTPUT FROM ADC READ TO BRUSHLESS MOTOR ESC

					} */









//
//		float Xa,Ya,Za,t;
//		float Xg=0,Yg=0,Zg=0;
//		I2C_Init();											/* Initialize I2C */
//		MPU6050_Init();										/* Initialize MPU6050 */
//		USART_Init(9600);									/* Initialize USART with 9600 baud rate */
//
//
//		while(1)
//		{
//			Read_RawValue();
//
//			Xa = Acc_x/16384.0;								/* Divide raw value by sensitivity scale factor to get real values */
//			Ya = Acc_y/16384.0;
//			Za = Acc_z/16384.0;
//
//			Xg = Gyro_x/16.4;
//			Yg = Gyro_y/16.4;
//			Zg = Gyro_z/16.4;
//
//			t = (Temperature/340.00)+36.53;					/* Convert temperature in �/c using formula */
//
//			motor1=settime(1000)+hagafn(-30+xg,yg,zg);
//
//
//
//			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//			//PID gain and limit settings
//			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//			float pid_p_gain_roll = 1.3;               //Gain setting for the roll P-controller
//			float pid_i_gain_roll = 0.04;              //Gain setting for the roll I-controller
//			float pid_d_gain_roll = 18.0;              //Gain setting for the roll D-controller
//			int pid_max_roll = 400;                    //Maximum output of the PID-controller (+/-)
//
//			float pid_p_gain_pitch = pid_p_gain_roll;  //Gain setting for the pitch P-controller.
//			float pid_i_gain_pitch = pid_i_gain_roll;  //Gain setting for the pitch I-controller.
//			float pid_d_gain_pitch = pid_d_gain_roll;  //Gain setting for the pitch D-controller.
//			int pid_max_pitch = pid_max_roll;          //Maximum output of the PID-controller (+/-)
//
//			float pid_p_gain_yaw = 4.0;                //Gain setting for the pitch P-controller. //4.0
//			float pid_i_gain_yaw = 0.02;               //Gain setting for the pitch I-controller. //0.02
//			float pid_d_gain_yaw = 0.0;                //Gain setting for the pitch D-controller.
//			int pid_max_yaw = 400;                     //Maximum output of the PID-controller (+/-)
//
//
//
//			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//			volatile int receiver_input_channel_1, receiver_input_channel_2, receiver_input_channel_3, receiver_input_channel_4;
//			int counter_channel_1, counter_channel_2, counter_channel_3, counter_channel_4, loop_counter;
//			int esc_1, esc_2, esc_3, esc_4;
//			int throttle, battery_voltage;
//			int cal_int, start, gyro_address;
//			int receiver_input[5];
//			int temperature;
//			int acc_axis[4], gyro_axis[4];
//			float roll_level_adjust, pitch_level_adjust;
//
//			long acc_x, acc_y, acc_z, acc_total_vector;
//			unsigned long timer_channel_1, timer_channel_2, timer_channel_3, timer_channel_4, esc_timer, esc_loop_timer;
//			unsigned long timer_1, timer_2, timer_3, timer_4, current_time;
//			unsigned long loop_timer;
//			double gyro_pitch, gyro_roll, gyro_yaw;
//			double gyro_axis_cal[4];
//			float pid_error_temp;
//			float pid_i_mem_roll, pid_roll_setpoint, gyro_roll_input, pid_output_roll, pid_last_roll_d_error;
//			float pid_i_mem_pitch, pid_pitch_setpoint, gyro_pitch_input, pid_output_pitch, pid_last_pitch_d_error;
//			float pid_i_mem_yaw, pid_yaw_setpoint, gyro_yaw_input, pid_output_yaw, pid_last_yaw_d_error;
//			float angle_roll_acc, angle_pitch_acc, angle_pitch, angle_roll;
//			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//			//Setup routine
//			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//			//Main program loop
//			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//			void loop(){
//
//			  //65.5 = 1 deg/sec (check the datasheet of the MPU-6050 for more information).
//			  gyro_roll_input = (gyro_roll_input * 0.7) + ((gyro_roll / 65.5) * 0.3);   //Gyro pid input is deg/sec.
//			  gyro_pitch_input = (gyro_pitch_input * 0.7) + ((gyro_pitch / 65.5) * 0.3);//Gyro pid input is deg/sec.
//			  gyro_yaw_input = (gyro_yaw_input * 0.7) + ((gyro_yaw / 65.5) * 0.3);      //Gyro pid input is deg/sec.
//
//
//			  ////////////////////////////////////////////////////////////////////////////////////////////////////
//			  //This is the added IMU code from the videos:
//			  //https://youtu.be/4BoIE8YQwM8
//			  //https://youtu.be/j-kE0AMEWy4
//			  ////////////////////////////////////////////////////////////////////////////////////////////////////
//
//			  //Gyro angle calculations
//			  //0.0000611 = 1 / (250Hz / 65.5)
//			  angle_pitch += gyro_pitch * 0.0000611;                                    //Calculate the traveled pitch angle and add this to the angle_pitch variable.
//			  angle_roll += gyro_roll * 0.0000611;                                      //Calculate the traveled roll angle and add this to the angle_roll variable.
//
//			  //0.000001066 = 0.0000611 * (3.142(PI) / 180degr) The Arduino sin function is in radians
//			  angle_pitch -= angle_roll * sin(gyro_yaw * 0.000001066);                  //If the IMU has yawed transfer the roll angle to the pitch angel.
//			  angle_roll += angle_pitch * sin(gyro_yaw * 0.000001066);                  //If the IMU has yawed transfer the pitch angle to the roll angel.
//
//			  //Accelerometer angle calculations
//			  acc_total_vector = sqrt((acc_x*acc_x)+(acc_y*acc_y)+(acc_z*acc_z));       //Calculate the total accelerometer vector.
//
//			  if(abs(acc_y) < acc_total_vector){                                        //Prevent the asin function to produce a NaN
//			    angle_pitch_acc = asin((float)acc_y/acc_total_vector)* 57.296;          //Calculate the pitch angle.
//			  }
//			  if(abs(acc_x) < acc_total_vector){                                        //Prevent the asin function to produce a NaN
//			    angle_roll_acc = asin((float)acc_x/acc_total_vector)* -57.296;          //Calculate the roll angle.
//			  }
//
//			  //Place the MPU-6050 spirit level and note the values in the following two lines for calibration.
//			  angle_pitch_acc -= 0.0;                                                   //Accelerometer calibration value for pitch.
//			  angle_roll_acc -= 0.0;                                                    //Accelerometer calibration value for roll.
//
//			  angle_pitch = angle_pitch * 0.9996 + angle_pitch_acc * 0.0004;            //Correct the drift of the gyro pitch angle with the accelerometer pitch angle.
//			  angle_roll = angle_roll * 0.9996 + angle_roll_acc * 0.0004;               //Correct the drift of the gyro roll angle with the accelerometer roll angle.
//
//			  pitch_level_adjust = angle_pitch * 15;                                    //Calculate the pitch angle correction
//			  roll_level_adjust = angle_roll * 15;                                      //Calculate the roll angle correction
//
//			  if(!auto_level){                                                          //If the quadcopter is not in auto-level mode
//			    pitch_level_adjust = 0;                                                 //Set the pitch angle correction to zero.
//			    roll_level_adjust = 0;                                                  //Set the roll angle correcion to zero.
//			  }
//
//
//			  //For starting the motors: throttle low and yaw left (step 1).
//			  if(receiver_input_channel_3 < 1050 && receiver_input_channel_4 < 1050)start = 1;
//			  //When yaw stick is back in the center position start the motors (step 2).
//			  if(start == 1 && receiver_input_channel_3 < 1050 && receiver_input_channel_4 > 1450){
//			    start = 2;
//
//			    angle_pitch = angle_pitch_acc;                                          //Set the gyro pitch angle equal to the accelerometer pitch angle when the quadcopter is started.
//			    angle_roll = angle_roll_acc;                                            //Set the gyro roll angle equal to the accelerometer roll angle when the quadcopter is started.
//			    gyro_angles_set = true;                                                 //Set the IMU started flag.
//
//			    //Reset the PID controllers for a bumpless start.
//			    pid_i_mem_roll = 0;
//			    pid_last_roll_d_error = 0;
//			    pid_i_mem_pitch = 0;
//			    pid_last_pitch_d_error = 0;
//			    pid_i_mem_yaw = 0;
//			    pid_last_yaw_d_error = 0;
//			  }
//			  //Stopping the motors: throttle low and yaw right.
//			  if(start == 2 && receiver_input_channel_3 < 1050 && receiver_input_channel_4 > 1950)start = 0;
//
//			  //The PID set point in degrees per second is determined by the roll receiver input.
//			  //In the case of deviding by 3 the max roll rate is aprox 164 degrees per second ( (500-8)/3 = 164d/s ).
//			  pid_roll_setpoint = 0;
//			  //We need a little dead band of 16us for better results.
//			  if(receiver_input_channel_1 > 1508)pid_roll_setpoint = receiver_input_channel_1 - 1508;
//			  else if(receiver_input_channel_1 < 1492)pid_roll_setpoint = receiver_input_channel_1 - 1492;
//
//			  pid_roll_setpoint -= roll_level_adjust;                                   //Subtract the angle correction from the standardized receiver roll input value.
//			  pid_roll_setpoint /= 3.0;                                                 //Divide the setpoint for the PID roll controller by 3 to get angles in degrees.
//
//
//			  //The PID set point in degrees per second is determined by the pitch receiver input.
//			  //In the case of deviding by 3 the max pitch rate is aprox 164 degrees per second ( (500-8)/3 = 164d/s ).
//			  pid_pitch_setpoint = 0;
//			  //We need a little dead band of 16us for better results.
//			  if(receiver_input_channel_2 > 1508)pid_pitch_setpoint = receiver_input_channel_2 - 1508;
//			  else if(receiver_input_channel_2 < 1492)pid_pitch_setpoint = receiver_input_channel_2 - 1492;
//
//			  pid_pitch_setpoint -= pitch_level_adjust;                                  //Subtract the angle correction from the standardized receiver pitch input value.
//			  pid_pitch_setpoint /= 3.0;                                                 //Divide the setpoint for the PID pitch controller by 3 to get angles in degrees.
//
//			  //The PID set point in degrees per second is determined by the yaw receiver input.
//			  //In the case of deviding by 3 the max yaw rate is aprox 164 degrees per second ( (500-8)/3 = 164d/s ).
//			  pid_yaw_setpoint = 0;
//			  //We need a little dead band of 16us for better results.
//			  if(receiver_input_channel_3 > 1050){ //Do not yaw when turning off the motors.
//			    if(receiver_input_channel_4 > 1508)pid_yaw_setpoint = (receiver_input_channel_4 - 1508)/3.0;
//			    else if(receiver_input_channel_4 < 1492)pid_yaw_setpoint = (receiver_input_channel_4 - 1492)/3.0;
//			  }
//
//			  calculate_pid();                                                            //PID inputs are known. So we can calculate the pid output.
//
//			  //The battery voltage is needed for compensation.
//			  //A complementary filter is used to reduce noise.
//			  //0.09853 = 0.08 * 1.2317.
//			  battery_voltage = battery_voltage * 0.92 + (analogRead(0) + 65) * 0.09853;
//
//			  //Turn on the led if battery voltage is to low.
//			  if(battery_voltage < 1000 && battery_voltage > 600)digitalWrite(12, HIGH);
//
//
//			  throttle = receiver_input_channel_3;                                      //We need the throttle signal as a base signal.
//
//			  if (start == 2){                                                          //The motors are started.
//			    if (throttle > 1800) throttle = 1800;                                   //We need some room to keep full control at full throttle.
//			    esc_1 = throttle - pid_output_pitch + pid_output_roll - pid_output_yaw; //Calculate the pulse for esc 1 (front-right - CCW)
//			    esc_2 = throttle + pid_output_pitch + pid_output_roll + pid_output_yaw; //Calculate the pulse for esc 2 (rear-right - CW)
//			    esc_3 = throttle + pid_output_pitch - pid_output_roll - pid_output_yaw; //Calculate the pulse for esc 3 (rear-left - CCW)
//			    esc_4 = throttle - pid_output_pitch - pid_output_roll + pid_output_yaw; //Calculate the pulse for esc 4 (front-left - CW)
//
//			    if (battery_voltage < 1240 && battery_voltage > 800){                   //Is the battery connected?
//			      esc_1 += esc_1 * ((1240 - battery_voltage)/(float)3500);              //Compensate the esc-1 pulse for voltage drop.
//			      esc_2 += esc_2 * ((1240 - battery_voltage)/(float)3500);              //Compensate the esc-2 pulse for voltage drop.
//			      esc_3 += esc_3 * ((1240 - battery_voltage)/(float)3500);              //Compensate the esc-3 pulse for voltage drop.
//			      esc_4 += esc_4 * ((1240 - battery_voltage)/(float)3500);              //Compensate the esc-4 pulse for voltage drop.
//			    }
//
//			    if (esc_1 < 1100) esc_1 = 1100;                                         //Keep the motors running.
//			    if (esc_2 < 1100) esc_2 = 1100;                                         //Keep the motors running.
//			    if (esc_3 < 1100) esc_3 = 1100;                                         //Keep the motors running.
//			    if (esc_4 < 1100) esc_4 = 1100;                                         //Keep the motors running.
//
//			    if(esc_1 > 2000)esc_1 = 2000;                                           //Limit the esc-1 pulse to 2000us.
//			    if(esc_2 > 2000)esc_2 = 2000;                                           //Limit the esc-2 pulse to 2000us.
//			    if(esc_3 > 2000)esc_3 = 2000;                                           //Limit the esc-3 pulse to 2000us.
//			    if(esc_4 > 2000)esc_4 = 2000;                                           //Limit the esc-4 pulse to 2000us.
//			  }
//
//			  else{
//			    esc_1 = 1000;                                                           //If start is not 2 keep a 1000us pulse for ess-1.
//			    esc_2 = 1000;                                                           //If start is not 2 keep a 1000us pulse for ess-2.
//			    esc_3 = 1000;                                                           //If start is not 2 keep a 1000us pulse for ess-3.
//			    esc_4 = 1000;                                                           //If start is not 2 keep a 1000us pulse for ess-4.
//			  }
//
//
//			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//			//Subroutine for calculating pid outputs
//			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//			//The PID controllers are explained in part 5 of the YMFC-3D video session:
//			//https://youtu.be/JBvnB0279-Q
//			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//			void calculate_pid(){
//			  //Roll calculations
//			  pid_error_temp = gyro_roll_input - pid_roll_setpoint;
//			  pid_i_mem_roll += pid_i_gain_roll * pid_error_temp;
//			  if(pid_i_mem_roll > pid_max_roll)pid_i_mem_roll = pid_max_roll;
//			  else if(pid_i_mem_roll < pid_max_roll * -1)pid_i_mem_roll = pid_max_roll * -1;
//
//			  pid_output_roll = pid_p_gain_roll * pid_error_temp + pid_i_mem_roll + pid_d_gain_roll * (pid_error_temp - pid_last_roll_d_error);
//			  if(pid_output_roll > pid_max_roll)pid_output_roll = pid_max_roll;
//			  else if(pid_output_roll < pid_max_roll * -1)pid_output_roll = pid_max_roll * -1;
//
//			  pid_last_roll_d_error = pid_error_temp;
//
//			  //Pitch calculations
//			  pid_error_temp = gyro_pitch_input - pid_pitch_setpoint;
//			  pid_i_mem_pitch += pid_i_gain_pitch * pid_error_temp;
//			  if(pid_i_mem_pitch > pid_max_pitch)pid_i_mem_pitch = pid_max_pitch;
//			  else if(pid_i_mem_pitch < pid_max_pitch * -1)pid_i_mem_pitch = pid_max_pitch * -1;
//
//			  pid_output_pitch = pid_p_gain_pitch * pid_error_temp + pid_i_mem_pitch + pid_d_gain_pitch * (pid_error_temp - pid_last_pitch_d_error);
//			  if(pid_output_pitch > pid_max_pitch)pid_output_pitch = pid_max_pitch;
//			  else if(pid_output_pitch < pid_max_pitch * -1)pid_output_pitch = pid_max_pitch * -1;
//
//			  pid_last_pitch_d_error = pid_error_temp;
//
//			  //Yaw calculations
//			  pid_error_temp = gyro_yaw_input - pid_yaw_setpoint;
//			  pid_i_mem_yaw += pid_i_gain_yaw * pid_error_temp;
//			  if(pid_i_mem_yaw > pid_max_yaw)pid_i_mem_yaw = pid_max_yaw;
//			  else if(pid_i_mem_yaw < pid_max_yaw * -1)pid_i_mem_yaw = pid_max_yaw * -1;
//
//			  pid_output_yaw = pid_p_gain_yaw * pid_error_temp + pid_i_mem_yaw + pid_d_gain_yaw * (pid_error_temp - pid_last_yaw_d_error);
//			  if(pid_output_yaw > pid_max_yaw)pid_output_yaw = pid_max_yaw;
//			  else if(pid_output_yaw < pid_max_yaw * -1)pid_output_yaw = pid_max_yaw * -1;
//
//			  pid_last_yaw_d_error = pid_error_temp;
//			}
//
//
