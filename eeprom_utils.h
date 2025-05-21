#ifndef EEPROM_UTILS_H
#define EEPROM_UTILS_H

#include "stm32f1xx_hal.h"  // Or adjust to match your STM32 series

#ifdef __cplusplus
extern "C" {
#endif

// EEPROM Type definitions (optional)
#define STEERING_MAX 0xA1
#define STEERING_MIN 0xA2
#define STEERING_0   0xA3
#define TPS_MAX      0xA4
#define TPS_MIN      0xA5

// Function Prototypes
bool Write_EEPROM(I2C_HandleTypeDef *hi2c, uint8_t type, uint16_t value, bool debug);
int  Read_EEPROM(I2C_HandleTypeDef *hi2c, uint8_t type, bool debug);
bool Analyze_EEPROM(I2C_HandleTypeDef *hi2c);

#ifdef __cplusplus
}
#endif

#endif // EEPROM_UTILS_H
