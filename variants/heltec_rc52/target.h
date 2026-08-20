#pragma once

#ifdef RC52_HEADLESS_COMPANION
  #ifdef DISPLAY_CLASS
    #error "RC52 headless companion must not initialize a display"
  #endif
  #if !defined(BLE_PIN_CODE) || BLE_PIN_CODE != 123456
    #error "RC52 headless companion pairing PIN must default to 123456"
  #endif
  #ifdef ENABLE_USB_INTERFACE
    #error "RC52 headless companion must use BLE transport"
  #endif
#endif

#define RADIOLIB_STATIC_ONLY 1
#include <RadioLib.h>
#include "HeltecRC52Board.h"
#include <helpers/AutoDiscoverRTCClock.h>
#include <helpers/radiolib/CustomSX1262Wrapper.h>
#include <helpers/radiolib/RadioLibWrappers.h>
#include <helpers/sensors/EnvironmentSensorManager.h>
#include <helpers/ui/MomentaryButton.h>
#ifdef DISPLAY_CLASS
#include <helpers/ui/NV3001BDisplay.h>
#endif

extern HeltecRC52Board board;
extern WRAPPER_CLASS radio_driver;
extern AutoDiscoverRTCClock rtc_clock;
extern EnvironmentSensorManager sensors;
#ifdef DISPLAY_CLASS
extern DISPLAY_CLASS display;
#endif
extern MomentaryButton user_btn;

bool radio_init();
mesh::LocalIdentity radio_new_identity();
