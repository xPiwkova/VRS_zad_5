/*
 * lps25hb.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Piwkova
 */

#include "lps25hb.h"

uint8_t adress = LPS25HB_I2C_ADDRESS_0;

uint8_t LPS25HB_init(){

	uint8_t status = 1;

	LL_mDelay(100);

	uint8_t val = lps25hb_read_byte(LPS25_HB_WHO_AM_I);

	if (val == WHO_AM_I_VALUE) {
		status = 1;
	} else {
		adress = LPS25HB_I2C_ADDRESS_1;
		val = lps25hb_read_byte(LPS25_HB_WHO_AM_I);
		if (val == WHO_AM_I_VALUE) {
			status = 1;
		}
		else {
			status = 0;
		}
	}
}

//read pressure
