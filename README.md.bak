# 📦 EEPROM Utility for STM32 (24FC08 over I2C)

A minimal and efficient utility for storing and retrieving configuration values (like calibration data) using an external 24FC08 EEPROM over I2C on STM32 microcontrollers (HAL-based). 

---

## 📌 Features

- Simple `Write`, `Read`, and `Analyze` API
- Redundancy with big-endian & little-endian value storage
- Human-readable EEPROM memory dump for debugging
- Fully portable: just include the header

---

## 🔧 Dependencies

- STM32 HAL libraries
- `ee24.h` / `ee24.c` EEPROM driver (e.g., 24FC08)
- Configured UART for `printf` (e.g., `__io_putchar`)

---

## 🧠 API Reference

### `bool Write_EEPROM(I2C_HandleTypeDef *HI2c, uint8_t type, uint16_t value, bool debug);`

Writes a 16-bit value under a unique `type` ID.

| Parameter | Description |
|----------|-------------|
| `HI2c`   | I2C handle pointer |
| `type`   | Type ID (e.g., `0xA1`) |
| `value`  | Value to store |
| `debug`  | Enables debug output via UART |

---

### `int Read_EEPROM(I2C_HandleTypeDef *HI2c, uint8_t type, bool debug);`

Reads a previously stored 16-bit value by `type`.

Returns:
- The `value` on success
- `-1` if the type is not found or invalid

---

### `bool Analyze_EEPROM(I2C_HandleTypeDef *HI2c);`

Prints all used EEPROM slots in a table.

Returns:
- `true` if successful
- `false` if read fails

---

## 📘 Example Usage

```c
#include "eeprom_utils.h"
#include "i2c.h"
#include "usart.h"

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_I2C1_Init();
    MX_USART1_UART_Init();

    // Write calibration value
    Write_EEPROM(&hi2c1, STEERING_MAX, 1234, true);

    // Read back
    int value = Read_EEPROM(&hi2c1, STEERING_MAX, true);
    if (value >= 0) {
        printf("Read value: %d\n", value);
    }

    // Analyze EEPROM content
    Analyze_EEPROM(&hi2c1);

    while (1) {}
}
