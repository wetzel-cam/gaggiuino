#ifndef INTERNALWATCHDOG_H
#define INTERNALWATCHDOG_H
#include <Arduino.h>

#ifdef ESP32 // Needed to use a different lib for the Watchdog timer
  #define SLEEPY_DOG
  #include <Adafruit_SleepyDog.h>
#else
  #define IWATCHDOG
  #include <IWatchdog.h>
#endif

#include "../lcd/lcd.h"

/*Checking whether system is booting after a hard reset initiated by the internal watchdog.*/
static inline void iwdcInit(void) {
  // IWDC init
  #ifdef IWATCHDOG
    if(IWatchdog.isReset()) {
      lcdShowPopup("WATCHDOG RESTARTED");
      IWatchdog.clearReset();
    }
    IWatchdog.begin(3000000);
  #endif
  #ifdef SLEEPY_DOG
    if (esp_reset_reason() == ESP_RST_TASK_WDT) {
      lcdShowPopup("WATCHDOG RESTARTED");
      Watchdog.disable();
    }
    Watchdog.enable(3000);
  #endif
  LOG_INFO("Internal watchdog Init");
}

static inline void watchdogReload(void) {
  #ifdef IWATCHDOG
    IWatchdog.reload();
  #endif
  #ifdef SLEEPY_DOG
    Watchdog.reset();
  #endif
}
#endif