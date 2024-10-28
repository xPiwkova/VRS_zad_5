/*
 * lps25hb.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Piwkova
 */

#ifndef LPS25HB_H_
#define LPS25HB_H_

#define LPS25HB_I2C_ADDRESS_0 0xB8
#define LPS25HB_I2C_ADDRESS_1 0xBA

#define LPS25HB_WHO_AM_I 0x0F
#define LPS25HB_CTRL_REG1 0x20
#define LPS25HB_CTRL_REG2 0x21
#define LPS25HB_CTRL_REG3 0x22
#define LPS25HB_CTRL_REG4 0x23

//pressure
#define LPS25HB_REG_PRESS_OUT_XL 0x28
#define LPS25HB_REG_PRESS_OUT_L 0x29
#define LPS25HB_REG_PRESS_OUT_H 0x2A

#define WHO_AM_I_VALUE 0b10111101

//init function
uint8_t lps25hb_init();

#endif /* LPS25HB_H_ */