/*
 * hts221.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Piwkova
 */
#include "hts221.h"

//initialisation of sensor
uint8_t HTS221_init() {
	uint8_t val = hts221_read_byte(HTS221_WHO_AM_I);

	if(val == HTS221_WHO_AM_I_VALUE) {
		//control register setup
		uint8_t ctrl_reg1 = 0b10000011;
		hts221_write_byte(HTS221_CTRL_REG1, ctrl_reg1);

		return 1;
	}
	return 0;
}

void hts221_write_byte(uint8_t reg_addr, uint8_t value) {
	i2c_master_write(value, reg_addr, HTS221_I2C_ADDRESS);
}

uint8_t hts221_read_byte(uint8_t reg_addr) {
	uint8_t val = 0;
	i2c_master_read(&val, 1, reg_addr, HTS221_I2C_ADDRESS);
	return val;
}

float hts221_get_temperature() {

	float temp;

	uint8_t msb = hts221_read_byte(MSB);

	uint8_t t0_x8 = hts221_read_byte(T0_degC_x8);
	uint16_t t0_out = (hts221_read_byte(T0_OUT_1) << 8) | hts221_read_byte(T0_OUT_2);

	uint8_t t1_x8 = hts221_read_byte(T1_degC_x8);
    uint16_t t1_out = (hts221_read_byte(T1_OUT_1) << 8) | hts221_read_byte(T1_OUT_2);

    uint16_t t_out = (hts221_read_byte(HTS221_TEMP_OUT_L) << 8) | hts221_read_byte(HTS221_TEMP_OUT_H);

    float T0_degC = (float) (t0_x8+(1 << 6)*(msb & 0x03))/8.0;
    float T1_degC = (float) (t1_x8+(1 << 6)*(msb & 0x0C))/8.0;

    //calculate temperature
    temp = (T1_degC + (((float)t_out-(float)t1_out) * (T1_degC - T0_degC)/((float)t1_out-(float)t0_out)));

	return temp;
}


float hts221_get_humidity() {

	float hum;

    uint8_t h0_x2 = hts221_read_byte(H0_rH_x2);
    uint16_t h0_t0_out = (hts221_read_byte(H0_OUT_1) << 8) | hts221_read_byte(H0_OUT_2);

    uint8_t h1_x2 = hts221_read_byte(H1_rH_x2);
    uint16_t h1_t0_out = (hts221_read_byte(H1_OUT_1) << 8) | hts221_read_byte(H1_OUT_2);

    uint16_t h_out = (hts221_read_byte(HTS221_HUM_OUT_L) << 8) | hts221_read_byte(HTS221_HUM_OUT_H);

    float h0_rh = (float) h0_x2/2.0;
    float h1_rh = (float) h1_x2/2.0;

    //calculate humidity
    hum = (h0_rh + ((h1_rh-h0_rh) * ((float)h_out - (float)h0_t0_out)/((float)h1_t0_out-(float)h0_t0_out)));

    return hum;
}
