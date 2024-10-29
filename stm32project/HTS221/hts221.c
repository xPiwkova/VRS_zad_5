/*
 * hts221.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Piwkova
 */

#include "hts221.h"

uint8_t HTS221_init(){

	uint8_t status = 1;

	LL_mDelay(100);

	uint8_t val = hts221_read_byte(LPS25HB_WHO_AM_I);

	if (val == WHO_AM_I_VALUE) {
		//to do
		status = 1;
	} else {
		status = 0;
	}
}


//read humidity

//read temperature
