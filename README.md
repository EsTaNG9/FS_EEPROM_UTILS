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
- [`ee24.h` / `ee24.c`](https://github.com/nimaltd/ee24) EEPROM driver (e.g., 24FC08)  
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

## 📘 Example Diagram
![EEPROM Wiring Diagram](./pics/diagram1.png)

---

## 📘 Example Usage

> 🔎 **Full example available in [`./examples/main.c`](./examples/main.c)**

```c
#include "eeprom_utils.h"
#include "i2c.h"
#include "usart.h"

#define STEERING_MAX 0xA1

EEPROM_Comms eeprom_comms = {
    .hi2c = &hi2c1,
    .huart = &huart1 //NULL, se não for preciso utilizar
};

int main(void) {

    // Write calibration value
    Write_EEPROM(&eeprom_comms, STEERING_MAX, 1234, true);

    // Read back
    int value = Read_EEPROM(&eeprom_comms, STEERING_MAX, true);
    if (value >= 0) {
        printf("Read value: %d\n", value);
    }

    // Analyze EEPROM content
    Analyze_EEPROM(&eeprom_comms);
	
}
