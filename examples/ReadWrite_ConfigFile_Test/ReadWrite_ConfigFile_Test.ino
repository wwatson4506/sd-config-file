/**
 * SdConfigFile Library Example Sketch
 *
 * This example sketch shows how to read parameters from and write new
 * values to an SD Card Configuration File using the SdConfigFile library
 *
 * SdConfigFile <https://github.com/chillibasket/sd-config-file>
 * created:      25th January 2022
 * last updated: 27th February 2022
 * Copyright (C) 2022 by Simon Bluett
 *
 * Released in the public domain under the MIT license
 *
 * This example sketch requires the SdFat library to be installed:
 * SdFat <https://github.com/greiman/SdFat>
 */


/**
 * By default, the SdConfigFile library supports FAT16 and FAT32
 * SD card file system types. However, EXFAT support can also be
 * enabled by using one of the two "#defines" below. Note that
 * support for the EXFAT file system takes up more memory.
 *
 * SD_CONFIG_FILE_USE_EXFAT: support only EXFAT SD Cards
 * SD_CONFIG_FILE_USE_FSFAT: support both FAT16/32 and EXFAT SD Cards
 * default: FAT16 and FAT32 support only
 *
 * Uncomment the line below depending on your requirements:
 */
//#define SD_CONFIG_FILE_USE_EXFAT
//#define SD_CONFIG_FILE_USE_FSFAT


/**
 * Include the Sd config file library
 */
//#include <SD.h>
#include <SdConfigFile.h>


/**
 * Instantiate Sd config file object, passing
 * the chip select pin number as a variable
 */
SdConfigFile configFile(BUILTIN_SDCARD);


/**
 * Name of the configuration file to open
 */
String configFileName = "test_file.txt";
char configFileName2[] = "test_file2.txt";


// Define some variables which we will set using the
// values from the SD card configuration file
int intValue = 0;
long longValue = 0;
/**
 * Setup function
 */
void setup() {

    bool ok;
  // int chipSelect = 10; // only for SPI, can't use BUILTIN_SDCARD here

  // Start serial comms and wait for user to open the serial monitor
  while(!Serial && (millis() < 5000));

  // Try connecting to the SD card
  if (!SD.begin(BUILTIN_SDCARD)) {
    SD.sdfs.initErrorPrint(&Serial);
  }

///  code runs up to here

    // Use the "read" method and supply the directory and file name
    while (configFile.read(configFileName))
    {
        configFile.get("intValue", intValue);
        configFile.get("ParameterName", longValue);
    }
    Serial.print("intValue: "); Serial.println(intValue);
    Serial.print("ParameterName: "); Serial.println(longValue);
}


void loop() {
    // Empty!
}
