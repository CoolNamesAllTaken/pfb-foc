/*
 * as5048a_test.cc
 *
 *  Created on: Nov 23, 2020
 *      Author: jkailimcnelly
 */

#include "test_framework.hh"
#include "test_encoder.hh"

#define private public // where is your god now (use this to test private utility functions)
#define protected public
#include "as5048a.hh"

//#define TEST_SPI // run actual SPI test on the honest to god SPI port (use logic analyzer to debug)
#ifdef TEST_SPI
#include "main.h" // gives access to encoder_spi global handle
#endif

bool TestEncoderCreate() {
	TEST_PRINT("Create Encoder.\r\n");
	SPI_HandleTypeDef * dummy_spi = NULL;
	GPIO_TypeDef * dummy_cs_port = NULL;
	uint16_t dummy_cs_pin = 0;
	AS5048A enc(dummy_spi, dummy_cs_port, dummy_cs_pin);

	uint16_t enc_angle = enc.get_angle();
	if (enc_angle != 0) {
		FAIL_PRINT("Initialized with nonzero encoder angle: got %d but expected %d.\r\n", enc_angle, 0);
		return false;
	}

	return true;
}

bool TestEncoderZero() {
	TEST_PRINT("Zero Encoder.\r\n");
	SPI_HandleTypeDef * dummy_spi = NULL;
	GPIO_TypeDef * dummy_cs_port = NULL;
	uint16_t dummy_cs_pin = 0;
	AS5048A enc(dummy_spi, dummy_cs_port, dummy_cs_pin);

	T_TEST_PRINT("Test negative relative angle.\r\n");
	enc.set_zero_angle(55); // set zero angle to 55 degrees
	float angle = enc.get_angle();
	float expect_angle = 360.0 - 55;
	if (angle != expect_angle) {
		TT_FAIL_PRINT("Expected angle to be %f but got %f.\r\n", expect_angle, angle);
		return false;
	}

	T_TEST_PRINT("Test setting zero angle too large.\r\n");
	enc.set_zero_angle(3600);
	angle = enc.get_angle();
	expect_angle = 0;
	if (angle != expect_angle) {
		TT_FAIL_PRINT("Expected angle to be %f but got %f.\r\n", expect_angle, angle);
		return false;
	}

	return true;
}

bool TestEncoderAngle() {
	TEST_PRINT("Test encoder angle.\r\n");
	SPI_HandleTypeDef * dummy_spi = NULL;
	GPIO_TypeDef * dummy_cs_port = NULL;
	uint16_t dummy_cs_pin = 0;
	AS5048A enc(dummy_spi, dummy_cs_port, dummy_cs_pin);

	T_TEST_PRINT("Test positive wrap.\r\n");
	enc.set_angle(450.5);
	float angle = enc.get_angle();
	float expect_angle = 450.5 - 360;
	if (angle != expect_angle) {
		TT_FAIL_PRINT("Expected angle to be %f but got %f.\r\n", expect_angle, angle);
		return false;
	}

	T_TEST_PRINT("Test negative wrap.\r\n");
	enc.set_angle(-500.9);
	angle = enc.get_angle();
	expect_angle = -500.9 + 2*360;
	if (angle != expect_angle) {
		TT_FAIL_PRINT("Expected angle to be %f but got %f.\r\n", expect_angle, angle);
		return false;
	}

	return true;
}

bool TestAS5048AParity() {
	TEST_PRINT("Test AS5048A SPI parity helper.\r\n");
	SPI_HandleTypeDef * dummy_spi = NULL;
	GPIO_TypeDef * dummy_cs_port = NULL;
	uint16_t dummy_cs_pin = 0;
	AS5048A enc(dummy_spi, dummy_cs_port, dummy_cs_pin);

	T_TEST_PRINT("Test parity on 0x0.\r\n");
	uint8_t par = enc.CalcEvenParity_(0b0000000000000000);
	uint8_t expect_par = 0;
	if (par != expect_par) {
		TT_FAIL_PRINT("Expected parity bit to be %d but got %d.\r\n", expect_par, par);
		return false;
	}

	T_TEST_PRINT("Test parity on 0x1.\r\n");
	par = enc.CalcEvenParity_(0b0000000000000001);
	expect_par = 1;
	if (par != expect_par) {
		TT_FAIL_PRINT("Expected parity bit to be %d but got %d.\r\n", expect_par, par);
		return false;
	}

	T_TEST_PRINT("Test parity on 15th bit is 1.\r\n");
	par = enc.CalcEvenParity_(0b0100000000000000);
	expect_par = 1;
	if (par != expect_par) {
		TT_FAIL_PRINT("Expected parity bit to be %d but got %d.\r\n", expect_par, par);
		return false;
	}

	T_TEST_PRINT("Test parity on ignore 16th bit.\r\n");
	par = enc.CalcEvenParity_(0b1000000000000000);
	expect_par = 0;
	if (par != expect_par) {
		TT_FAIL_PRINT("Expected parity bit to be %d but got %d.\r\n", expect_par, par);
		return false;
	}

	return true;
}

bool TestAS5048APackets() {
	TEST_PRINT("Test AS5048A SPI Packet Assemblers.\r\n");
	SPI_HandleTypeDef * dummy_spi = NULL;
	GPIO_TypeDef * dummy_cs_port = NULL;
	uint16_t dummy_cs_pin = 0;
	AS5048A enc(dummy_spi, dummy_cs_port, dummy_cs_pin);

	T_TEST_PRINT("Test CreateCommandPacket (write).\r\n");
	uint16_t pack = enc.CreateCommandPacket_(0xBEEF, 1);
	uint16_t expect_pack = 0b1111111011101111;
	if (pack != expect_pack) {
		TT_FAIL_PRINT("Expected CommandPacket to be 0x%x but got 0x%x\r\n.", expect_pack, pack);
		return false;
	}

	T_TEST_PRINT("Test CreateCommandPacket (read).\r\n");
	pack = enc.CreateCommandPacket_(0xBEEF, 0);
	expect_pack = 0b0011111011101111;
	if (pack != expect_pack) {
		TT_FAIL_PRINT("Expected CommandPacket to be 0x%x but got 0x%x\r\n.", expect_pack, pack);
		return false;
	}

	T_TEST_PRINT("Test CreateWritePacket.\r\n");
	pack = enc.CreateWritePacket_(0xDEAD);
	expect_pack = 0b1001111010101101;
	if (pack != expect_pack) {
		TT_FAIL_PRINT("Expected WritePacket to be 0x%x but got 0x%x\r\n.", expect_pack, pack);
		return false;
	}

	T_TEST_PRINT("Test ParseReceivedPacket (nominal).\r\n");
	uint16_t received_pack = 0b1001111010101101;
	uint16_t data = enc.ParseReceivedPacket_(received_pack);
	uint16_t expect_data = 0xDEAD & (0xFFFF >> 2);
	if (data != expect_data) {
		TT_FAIL_PRINT("Expected data to be 0x%x but got 0x%x.\r\n", expect_data, data);
		return false;
	}

	T_TEST_PRINT("Test ParseReceivedPacket (parity error).\r\n");
	received_pack = 0b0001111010101101;
	data = enc.ParseReceivedPacket_(received_pack);
	expect_data = 0xFFFF; // PARSE_ERR
	if (data != expect_data) {
		TT_FAIL_PRINT("Expected data to be 0x%x but got 0x%x.\r\n", expect_data, data);
		return false;
	}

	T_TEST_PRINT("Test ParseReceivedPacket (host err).\r\n");
	received_pack = 0b0101111010101101;
	data = enc.ParseReceivedPacket_(received_pack);
	expect_data = 0xFFFF; // PARSE_ERR
	if (data != expect_data) {
		TT_FAIL_PRINT("Expected data to be 0x%x but got 0x%x.\r\n", expect_data, data);
		return false;
	}

	T_TEST_PRINT("Test ParseReceivedPacket (parity and host err).\r\n");
	received_pack = 0b1101111010101101;
	data = enc.ParseReceivedPacket_(received_pack);
	expect_data = 0xFFFF; // PARSE_ERR
	if (data != expect_data) {
		TT_FAIL_PRINT("Expected data to be 0x%x but got 0x%x.\r\n", expect_data, data);
		return false;
	}

	return true;
}

#ifdef TEST_SPI
bool TestEncoderSPI() {
	TEST_PRINT("Test AS5048A SPI Interface. Press button to zero encoder!\r\n");
	AS5048A enc(encoder_hspi, ENC_SPI_CS_GPIO_Port, ENC_SPI_CS_Pin);
	enc.Init();
	float enc_pos;
	do {
		enc.Update();
		enc_pos = enc.get_angle();
		printf("Encoder position: %4.2f\r\n", enc.get_angle());
		if (HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin) == GPIO_PIN_SET) {
			// zero encoder on button push
			enc.set_zero_angle();
		}
	} while(enc_pos != 0xFFFF);

	uint16_t error_reg_content = enc.ClearErrorFlag_();
	if (error_reg_content & 0b1) {
		T_FAIL_PRINT("Framing Error.\r\n");
	}
	if (error_reg_content & 0b10) {
		T_FAIL_PRINT("Command Invalid.\r\n");
	}
	if (error_reg_content & 0b100) {
		T_FAIL_PRINT("Parity Error.\r\n");
	}


	return false;
}
#endif

void TestEncoderAll() {
	bool enc_passed = true;
	L_PRINT("Test Encoder Class");
	enc_passed &= TestEncoderCreate();
	enc_passed &= TestEncoderZero();
	enc_passed &= TestEncoderAngle();
	if (enc_passed) {
		PASS_PRINT("Encoder Class\r\n");
	} else {
		FAIL_PRINT("Encoder Class\r\n");
	}

	L_PRINT("Test AS5048A Class");
	bool as5048a_passed = true;
	as5048a_passed &= TestAS5048AParity();
	as5048a_passed &= TestAS5048APackets();
	if (as5048a_passed) {
		PASS_PRINT("AS5048A Class\r\n");
	} else {
		FAIL_PRINT("AS5048A Class\r\n");
	}

#ifdef TEST_SPI
	L_PRINT("Test AS5048A SPI Interface. Will not exit.");
	while(true) {
		TestEncoderSPI();
		// restart test if comms fail
	}
#endif

}

