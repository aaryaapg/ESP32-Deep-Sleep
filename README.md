# ESP32-Deep-Sleep
## Important
Three things to mention about deep sleep.
1. `esp_deep_sleep_start` shuts down the processor, so any code you write beneath this line won't be executed.
2. When the ESP32 awakes from the deep sleep, it will rerun your setup function.
3. When you enter deep sleep, all data stored in memory is lost.

## Codes
### 01_Wake_ESP32_Using_RTC
The easiest way to wake the ESP32 up from sleep is to use an RTC to wake it up after a certain amount of time. This sketch puts ESP32 into deep sleep until the RTC triggers it after every 1 minute. It also prints the reason for wakeup.

![image](https://user-images.githubusercontent.com/61982410/124750508-2b77b380-df43-11eb-8457-4f39f62022bc.png)
### 02_Wake_ESP32_Using_Touchpin
When someone touches the touchpin, you can wake the ESP32 up by doing the following:-
1. Configure a threshold value (once this value is crossed, the ESP32 will wakeup)
2. Enable the touch interrupt (so the ESP32 knows that it has to keep that powered on)
3. Actually go into deep sleep.

When the ESP32 awakes from the deep sleep, it will rerun your setup function and all data from the memory is lost. Hence, I have also used RTC memory to store the counter values.

![image](https://user-images.githubusercontent.com/61982410/125252606-300ee400-e316-11eb-830c-c7675645fab9.png)
### 03_Wake_ESP32_Using_EXT0_Pushbutton
The ext0 wake up source option uses RTC GPIOs to wake up. So, RTC peripherals will be kept on during deep sleep if this wake up source is requested.

`esp_sleep_enable_ext0_wakeup(GPIO_NUM_X, level)`
* This function accepts as first argument the pin you want to use. X is the GPIO number. With this wake up source, you can only use pins that are RTC GPIOs.
* The second argument, level, can be either 1 or 0. This represents the state of the GPIO that will trigger wake up.

![image](https://user-images.githubusercontent.com/61982410/125676331-cfc277c4-ef18-4b90-b5bf-7edf66c4f030.png)


## References
1. https://lastminuteengineers.com/esp32-deep-sleep-wakeup-sources/ (Reason for wakeup method is wrong)
2. https://randomnerdtutorials.com/esp32-deep-sleep-arduino-ide-wake-up-sources/
3. https://savjee.be/videos/programming-esp32-with-arduino/esp32-power-modes-deep-sleep-explained/

# Arduino-Deep-Sleep
### 05_Wake&Sleep_Arduino_Using_1_Button_Only
This schematic helps us to control deep sleep in Arduino Uno using just one push button.

**Schematic**

![Schematic_Push Button Decoder_2021-08-12](https://user-images.githubusercontent.com/61982410/129197617-7c75536d-8e94-4d7a-820c-4f22325f51a7.png)

**Truth Table**

![image](https://user-images.githubusercontent.com/61982410/129198128-6f622a83-ad50-4955-8530-7cca6f286bd5.png)

## References
1. https://thekurks.net/blog/2018/1/24/guide-to-arduino-sleep-mode
2. https://github.com/RalphBacon/Arduino-Deep-Sleep
3. https://www.electroniclinic.com/arduino-sleep-modes-automatic-and-manual-to-save-power-arduino-deep-sleep/
4. https://forum.arduino.cc/t/arduino-atmega328pu-wake-up-with-a-long-button-press/400968
5. https://www.theengineeringprojects.com/2015/11/reset-arduino-programmatically.html : Reset after wake up
