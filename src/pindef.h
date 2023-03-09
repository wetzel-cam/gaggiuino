#ifndef PINDEF_H
#define PINDEF_H
  #ifdef ESP32
    #define thermoDO      15
    #define thermoCS       2
    #define thermoCLK      0

    // Pump
    #define zcPin          4
    #define dimmerPin     16

    #define brewPin       17
    #define relayPin       5
    #define steamPin      18
    #define valvePin      19
    #define waterPin      13

    #ifdef PCBV2
      // PCB V2
      #define mainBoilerRelayPin   5
      #define steamBoilerRelayPin 18
    #endif

    #define HX711_sck_1   22
    #define HX711_sck_2   22
    #define HX711_dout_1  12
    #define HX711_dout_2  14

    #define USART_LCD     Serial2 // PA2(TX) & PA3(RX)
    #define USART_ESP     Serial1 // PA9(TX) & PA10(RX)
    #define USART_DEBUG   Serial  // USB-CDC (Takes PA8,PA9,PA10,PA11)

    #define hw_SCL        22
    #define hw_SDA        21
  #else
    // STM32F4 pins definitions
    #define thermoDO      PB4
    #define thermoCS      PA6
    #define thermoCLK     PA5

    #define zcPin         PA0
    #define brewPin       PC14
    #define relayPin      PA15
    #define dimmerPin     PA1
    #define steamPin      PC15
    #define valvePin      PC13
    #define waterPin      PA12

    #ifdef PCBV2
      // PCB V2
      #define mainBoilerRelayPin  PB13
      #define steamBoilerRelayPin PB12
    #endif

    #define HX711_sck_1   PB0
    #define HX711_sck_2   PB1
    #define HX711_dout_1  PB8
    #define HX711_dout_2  PB9

    #define USART_LCD     Serial2 // PA2(TX) & PA3(RX)
    #define USART_ESP     Serial1 // PA9(TX) & PA10(RX)
    #define USART_DEBUG   Serial  // USB-CDC (Takes PA8,PA9,PA10,PA11)

    #define hw_SCL        PB6
    #define hw_SDA        PB7
  #endif
#endif
