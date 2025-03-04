/*

TTGO T-BEAM Tracker for The Things Network

Copyright (C) 2018 by Xose Pérez <xose dot perez at gmail dot com>

This code requires LMIC library by Matthijs Kooijman
https://github.com/matthijskooijman/arduino-lmic

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#pragma once

#include <Arduino.h>
#include <lmic.h>
void helium_register(void (*callback)(uint8_t message));

// -----------------------------------------------------------------------------
// Version
// -----------------------------------------------------------------------------

#define APP_NAME                "Helium TTGO"
#define APP_VERSION             "1.2-tm"

// -----------------------------------------------------------------------------
// Configuration
// -----------------------------------------------------------------------------

// Select which T-Beam board is being used. Only uncomment one.
//#define T_BEAM_V07  // AKA Rev0 (first board released)
 #define T_BEAM_V10  // AKA Rev1 (second board released)

// Select the payload format. Select apropriate decoder function as well. Only uncomment one.
#define PAYLOAD_USE_FULL
//#define PAYLOAD_USE_CAYENNE

//Uncomment if you always want to see the boot logo at boot time
 #define ALWAYS_SHOW_LOGO

//Uncomment to enable discarding network settings by long pressing second button
#define PREFS_DISCARD

// If you are having difficulty sending messages to Helium after the first successful send,
// uncomment the next option and experiment with values (~ 1 - 5)
 #define CLOCK_ERROR             2

#define DEBUG_PORT              Serial          // Serial debug port
#define SERIAL_BAUD             115200          // Serial debug baud rate
#define SLEEP_BETWEEN_MESSAGES  false           // Do sleep between messages
#define SEND_INTERVAL           (20 * 1000)     // Sleep for these many millis
#define MESSAGE_TO_SLEEP_DELAY  5000            // Time after message before going to sleep
#define LOGO_DELAY              2500            // Time to show logo on first boot
#define LORAWAN_PORT            10              // Port the messages will be sent to
#define LORAWAN_CONFIRMED_EVERY 100               // Send confirmed message every these many messages (0 means never)
#define LORAWAN_SF              DR_SF7         // Spreading factor (recommended DR_SF7 for ttn network map purposes, DR_SF10 works for slow moving trackers)
#define LORAWAN_ADR             0               // Enable ADR
#define REQUIRE_RADIO           true            // If true, we will fail to start if the radio is not found

// If not defined, we will wait for lock forever
#define GPS_WAIT_FOR_LOCK       (120 * 1000)     // Wait after every boot for GPS lock (may need longer than 5s because we turned the gps off during deep sleep)

// -----------------------------------------------------------------------------
// LoRa send criteria
// -----------------------------------------------------------------------------
#define MIN_DIST                 35.0      // MUST be decimal number; minimum distance in meters from the last sent location before we can send again. A hex is about 340m, divide by this value to get the pings per hex.
#define STATIONARY_TX_INTERVAL   60        // If stationary the LoRa frame will be sent once every N cycles... with 30sec cycle, interval of 60 means to transmit once every 30min
#define DISTANCE_TARGET          200.0     // MUST be decimal number; distance target in meters


// -----------------------------------------------------------------------------
// DEBUG
// -----------------------------------------------------------------------------

#ifdef DEBUG_PORT
#define DEBUG_MSG(...) DEBUG_PORT.printf( __VA_ARGS__ )
#else
#define DEBUG_MSG(...)
#endif

// -----------------------------------------------------------------------------
// Custom messages
// -----------------------------------------------------------------------------

#define EV_QUEUED       100
#define EV_PENDING      101
#define EV_ACK          102
#define EV_RESPONSE     103

// -----------------------------------------------------------------------------
// General
// -----------------------------------------------------------------------------

#define I2C_SDA         21
#define I2C_SCL         22

#if defined(T_BEAM_V07)
#define LED_PIN         14
#define BUTTON_PIN      39
#elif defined(T_BEAM_V10)
#define BUTTON_PIN      38
#endif

// -----------------------------------------------------------------------------
// OLED
// -----------------------------------------------------------------------------

#define SSD1306_ADDRESS 0x3C

// -----------------------------------------------------------------------------
// GPS
// -----------------------------------------------------------------------------

#define GPS_SERIAL_NUM  1
#define GPS_BAUDRATE    9600
#define USE_GPS         1

#if defined(T_BEAM_V07)
#define GPS_RX_PIN      12
#define GPS_TX_PIN      15
#elif defined(T_BEAM_V10)
#define GPS_RX_PIN      34
#define GPS_TX_PIN      12
#endif

// -----------------------------------------------------------------------------
// LoRa SPI
// -----------------------------------------------------------------------------

#define SCK_GPIO        5
#define MISO_GPIO       19
#define MOSI_GPIO       27
#define NSS_GPIO        18
#if defined(T_BEAM_V10)
#define RESET_GPIO      14
#else
#define RESET_GPIO      23
#endif
#define DIO0_GPIO       26
#define DIO1_GPIO       33 // Note: not really used on this board
#define DIO2_GPIO       32 // Note: not really used on this board

// -----------------------------------------------------------------------------
// AXP192 (Rev1-specific options)
// -----------------------------------------------------------------------------

// #define AXP192_SLAVE_ADDRESS  0x34 // Now defined in axp20x.h
#define GPS_POWER_CTRL_CH     3
#define LORA_POWER_CTRL_CH    2
#define PMU_IRQ               35
#define PMU_CHG_CURRENT AXP202_CHARGE_CUR_550MA // battery charge current
// possible values (mA):
// 100/190/280/360/450/550/630/700/780/880/960/1000/1080/1160/1240/1320
#define PMU_CHG_CUTOFF AXP202_TARGET_VOL_4_2V // battery charge cutoff
// possible values (V):
// 4_1/4_15/4_2/4_36

// blue onboard led settings
// possible values: 
// AXP20X_LED_OFF / AXP20X_LED_LOW_LEVEL (means LED ON) / AXP20X_LED_BLINK_1HZ / AXP20X_LED_BLINK_4HZ
#define PMU_LED_RUN_MODE AXP20X_LED_OFF 
#define PMU_LED_SLEEP_MODE AXP20X_LED_BLINK_1HZ
