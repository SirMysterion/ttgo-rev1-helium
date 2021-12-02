/*

Credentials file

*/

#pragma once

#define USE_OTAA

#ifdef USE_OTAA

    // This EUI must be in little-endian format, so least-significant-byte (lsb)
    // first. When copying an EUI from ttnctl output, this means to reverse
    // the bytes. For TTN issued EUIs the last bytes should be 0x00, 0x00,
    // 0x00.
    //hekopath1 static const u1_t PROGMEM APPEUI[8]  = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    //hekopath2 
    static const u1_t PROGMEM APPEUI[8]  = {0x15, 0x2B, 0xE3, 0x89, 0xD6, 0xF9, 0x81, 0x60};

    // This should also be in little endian format (lsb), see above.
    // Note: You do not need to set this field, if unset it will be generated automatically based on the device macaddr
    //hekopath1     static u1_t PROGMEM DEVEUI[8]  = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    //hekopath2    
    static u1_t PROGMEM DEVEUI[8]  = {0x7B, 0x2A, 0xD5, 0x2A, 0x80, 0xF9, 0x81, 0x60};
    // This key should be in big endian format (msb) (or, since it is not really a
    // number but a block of memory, endianness does not really apply). In
    // practice, a key taken from ttnctl can be copied as-is.
    // The key shown here is the semtech default key.
    //hekopath1    static const u1_t PROGMEM APPKEY[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    //hekopath2 
    static const u1_t PROGMEM APPKEY[16] = {0x64, 0xD8, 0x21, 0xE3, 0xCF, 0x2E, 0xAB, 0x9A, 0xC3, 0x81, 0x94, 0x5E, 0x33, 0xD2, 0x08, 0x48};
#endif
