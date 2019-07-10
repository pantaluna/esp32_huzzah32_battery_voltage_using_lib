## Project Description
The main purpose of this project is to demonstrate how to obtain with a simple function call the actual battery voltage of the Lion battery that is hooked up to the JST-PH2 connector when using the Adafruit HUZZAH32 development board.



The program also

- Verifies what method will be used by the ESP-IDF ADC component in relation to the calibration of the ADC. The ADC peripheral of the ESP32 is used for example to read the battery voltage.
- Assists to verify the actual VREF Voltage Reference of the ESP32. This can be done by routing the actual voltage reference value to an analog GPIO using the ADC1 or the ADC2 peripheral. And then use a multimeter to verify the VREF voltage. The value will be around 1100mV.



This project uses the component "mjd_huzzah32". Use it to get insights in how to use this component. Go to the component directory "components/mjd_huzzah32" for the documentation.



## What are the HW SW requirements of the ESP32 MJD Starter Kit?

### Hardware

- A decent ESP development board. I suggest to buy a popular development board with good technical documentation and a significant user base. Examples: [Adafruit HUZZAH32](https://www.adafruit.com/product/3405),  [Espressif ESP32-DevKitC](http://espressif.com/en/products/hardware/esp32-devkitc/overview), [Pycom WiPy](https://pycom.io/hardware/), [Wemos D32](https://wiki.wemos.cc/products:d32:d32).
- The peripherals that are used in the project.
  @tip The README of each component contains a section "Shop Products".
  @example A Bosch BME280 meteo sensor breakout board.

### Software: ESP-IDF v3.2

- A working installation of the **Espressif ESP-IDF *V3.2* development framework**** (detailed instructions @ http://esp-idf.readthedocs.io/en/latest/get-started/index.html).

```
mkdir ~/esp
cd    ~/esp
git clone -b v3.2 --recursive https://github.com/espressif/esp-idf.git esp-idf-v3.2
```

- A C language editor or the Eclipse IDE CDT (instructions also @ http://esp-idf.readthedocs.io/en/latest/get-started/index.html).



## Running the example
- Run `make menuconfig` and verify the settings of the "mjd_huzzah32" component:
     - Component config => Adafruit HUZZAH32
- Run `make flash monitor` to build and upload the example to your board and connect to its serial terminal.
- The battery voltage is dumped in the UART debug log.



## Reference: the ESP32 MJD Starter Kit SDK

Do you also want to create innovative IoT projects that use the ESP32 chip, or ESP32-based modules, of the popular company Espressif? Well, I did and still do. And I hope you do too.

The objective of this well documented Starter Kit is to accelerate the development of your IoT projects for ESP32 hardware using the ESP-IDF framework from Espressif and get inspired what kind of apps you can build for ESP32 using various hardware modules.

Go to https://github.com/pantaluna/esp32-mjd-starter-kit

