#ifndef I2C_H
#define I2C_H

#include <compat/twi.h>  // TW_STATUS, TW_START, TW_REP_START, TW_MT_SLA_ACK, TW_MR_SLA_ACK, TW_MT_DATA_ACK

uint8_t i2cStart(uint8_t address);
void i2cStop(void);
uint8_t i2cWrite(uint8_t data);
uint8_t i2cReadAck(void);
uint8_t i2cReadNak(void);

#endif
