#ifndef EEPROM_UTILS_H
#define EEPROM_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

#include "i2c.h"
#include "usart.h"
#include "usart.h"
#include "ee24.h"

// Function Prototypes
bool Write_EEPROM(I2C_HandleTypeDef *HI2c, uint8_t type, uint16_t value, bool debug);
int  Read_EEPROM(I2C_HandleTypeDef *HI2c, uint8_t type, bool debug);
bool Analyze_EEPROM(I2C_HandleTypeDef *HI2c);

#ifdef __cplusplus
}
#endif

#endif // EEPROM_UTILS_H
