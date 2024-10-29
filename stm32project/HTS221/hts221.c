/*
 * hts221.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Piwkova
 */

#include "hts221.h"

uint8_t HTS221_init(){

	LL_mDelay(100);

	uint8_t val = hts221_read_byte(LPS25HB_WHO_AM_I);

	if (val == WHO_AM_I_VALUE) {

		//to do
		uint8_t ctrl_reg1 = 0b10000011;
		hts221_write_byte(HTS221_CTRL_REG1, ctrl_reg1);

		return 1;
	}
	return 0;
}

uint8_t hts221_read_byte(uint8_t reg_address) {
	uint8_t val = 0;
	i2c_master_read(&val, 1, reg_address, HTS221_I2C_ADDRESS, 0);
	return val;
}

void hts221_write_byte(uint8_t reg_address, uint8_t val) {
	i2c_master_write(val, reg_address, HTS221_I2C_ADDRESS, 0);
}

//read humidity
float hts221_get_humidity() {
	//to do
}

//read temperature
float hts221_get_temperature() {
	//to do
}

