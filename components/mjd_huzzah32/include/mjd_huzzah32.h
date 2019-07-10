/*
 * Goto README.md for instructions
 */
#ifndef __MJD_HUZZAH32_H__
#define __MJD_HUZZAH32_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "driver/adc.h"
#include "esp_adc_cal.h"

/**
 * Data Definitions
 */

/**
 * Function declarations
 */

/**
 * @brief Return the actual battery voltage level using ADC1.
 *        The GPIO#35 (VBAT SENSE) outputs the battery voltage measurement (halved value). This pin is not exposed on the HUZZAH32 board.
 *
 * => Calibration Characterization is based on the features of the ESP32 chip.
 *     a) The Reference voltage stored in eFuse BLOCK0.
 *     b) The Two Point values stored in eFuse BLOCK3.
 *     c) The default reference voltage that was supplied manually (if a and b are absent).
 *
 * @return float battery voltage level (unit=Volt)
 *
 * @dependency This func is specific for the Adafruit HUZZAH32 development board.
 *
 * @dependency Kconfig CONFIG_MJD_HUZZAH32_REFERENCE_VOLTAGE_MV (default 1100)
 *     The huzzah32_adc_voltage_reference (1100) is specific for this board when battery powered.
 *     It was measured using the func mjd_huzzah32_route_vref_to_gpio26() and stored in Kconfig.
 *
 * @important The battery voltage level reading is INVALID when powered by USB and no battery is connected (it will show a positive voltage of +-2*2.1V, not the expected 0V!).
 *
 * - ADC_WIDTH_BIT_10 gives more accurate results, compared to ADC_WIDTH_BIT_11 and ADC_WIDTH_BIT_12. I have no idea why.
 *
 * - Due to ADC characteristics, most accurate results are obtained within the following approximate voltage ranges:
 *      - 11dB attenuation (ADC_ATTEN_DB_11) voltages between 150 to 2450mV.
 *
 * Soshine 18650 LiFePO4 3.2V Battery 1800mAh specs:
 * - Operating voltage         3.2V (halved = 1.6V).
 * - Minimum discharge voltage 2.8V (halved = 1.4V).
 * - Maximum charged voltage   3.6V (halved = 1.8V).
 *
 */
float mjd_huzzah32_get_battery_voltage();

/**
 * @brief 1. Report the ESP32 eFuse contents in relation to the ADC Calibration Characterization.
 *        2. Report which ADC Calibration Characterisation will be used when measure the voltage of an ADC pin using esp_adc_cal_get_voltage().
 *
 * https://esp-idf.readthedocs.io/en/latest/api-reference/peripherals/adc.html
 *
 * The following information might be stored in the following eFuse Types:
 *   - "TP Two Point" BLOCK3: characterization based on Two Point values.
 *   - "VREF Voltage Reference" BLOCK0: characterization based on the reference voltage. Example dev boards: LOLIN D32.
 *
 * 1 of these 3 outcomes for characterisation:
 *   - "TP Two Point" BLOCK3: characterization based on Two Point values.
 *   - "VREF Voltage Reference" BLOCK0: characterization based on the reference voltage. Example dev boards: LOLIN D32.
 *   - "Default Vref": the ADC reference voltage is provided by the user as a parameter during characterization.
 * If "Two Point" or "eFuse Vref" values are unavailable, then the "Default Vref" method will be used.
 *
 * @return void
 *
 */
void mjd_huzzah32_log_adc_characterisations();

/**
 * @brief Route the actual VREF Voltage Reference of the ESP32 to a GPIO# using ADC2. Then use a multimeter to determine the voltage. The value will be around 1100 (milliVolt).
 *
 * @param int param_gpio_nr
 *
 * @return
 *     - ESP_OK Success
 *
 * @dependency This func is specific for the Adafruit HUZZAH32 development board.

 * @important The VREF for the HUZZAH32 that is used in the func mjd_huzzah32_get_battery_voltage() is stored in Kconfig CONFIG_MJD_HUZZAH32_REFERENCE_VOLTAGE_MV.
 * @important This code is not needed to measuring the actual BATTERY voltage (we just need to measure the VREF value once if no eFuses are written in the ESP32 module).
 * @important Do not enable Wifi or Bluetooth when running this func; due to a conflict when using ADC2.
 *
 */
esp_err_t mjd_huzzah32_route_vref_to_gpio(int param_gpio_nr);

#ifdef __cplusplus
}
#endif

#endif /* __MJD_HUZZAH32_H__ */
