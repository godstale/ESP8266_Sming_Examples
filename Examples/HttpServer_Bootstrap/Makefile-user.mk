## Local build configuration
## Parameters configured here will override default and ENV values.
## Uncomment and change examples:

## Add your source directories here separated by space
MODULES = app
EXTRA_INCDIR = include

## ESP_HOME sets the path where ESP tools and SDK are located.
## Windows:
#ESP_HOME = c:\Espressif

## MacOS / Linux:
# ESP_HOME = /opt/esp-open-sdk

## SMING_HOME sets the path where Sming framework is located.
## Windows:
SMING_HOME = C:/tools/sming/Sming

## MacOS / Linux
# SMING_HOME = /opt/sming/Sming

## COM port parameter is reqruied to flash firmware correctly.
## Windows: 
COM_PORT = COM4

## MacOS / Linux:
# COM_PORT = /dev/tty.usbserial

## Com port speed
COM_SPEED	= 115200

## Configure flash parameters (for ESP12-E and other new boards):
SPI_MODE = dio
SPI_SIZE = 4M

## SPIFFS options
DISABLE_SPIFFS = 0
#SPIFF_FILES = files
# Path to spiffy
SPIFFY = C:/tools/mingw64/bin/spiffy

