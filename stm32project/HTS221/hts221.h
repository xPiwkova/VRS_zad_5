/*
 * hts221.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Piwkova
 */

#ifndef HTS221_H_
#define HTS221_H_

#define HTS221_I2C_ADDRESS 0xBE

#define HTS221_WHO_AM_I 0x0F
#define HTS221_CTRL_REG1 0x20
#define HTS221_CTRL_REG2 0x21
#define HTS221_CTRL_REG3 0x22

//temperature
#define HTS221_TEMP_OUT_L 0x2A
#define HTS221_TEMP_OUT_H 0x2B

//humidity
#define HTS221_REG_HUMIDITY_OUT_L 0x28
#define HTS221_REG_HUMIDITY_OUT_H 0x29

#define WHO_AM_I_VALUE 0b10111100

//calibration registers
#define H0_rH_x2  0x32
#define H1_rH_x2  0x33
#define T0_degC_x8  0x32
#define T1_degC_x8  0x33
#define T1_T0msb    0x35

#define T0_OUT_1    0x3C
#define T0_OUT_2    0x3D
#define T1_OUT_1    0x3E
#define T1_OUT_2    0x3F

#define H0_T0_OUT_1    0x36
#define H0_T0_OUT_2    0x37
#define H1_T0_OUT_1    0x3A
#define H1_T0_OUT_2    0x3B

//init function
uint8_t HTS221_init();

#endif /* HTS221_H_ */
