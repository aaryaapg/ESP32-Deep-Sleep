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
When someone touches the touchpin, so you can turn on the display and show something useful.
Now to allow the touch sensor to wake the ESP32 up, we have to do three things:
1. Configure a threshold value (once this value is crossed, the ESP32 will wakeup)
2. Enable the touch interrupt (so the ESP32 knows that it has to keep that powered on)
3. Actually go into deep sleep.

![image](https://user-images.githubusercontent.com/61982410/124773703-ce87f780-df5a-11eb-9a1b-11a8837ce295.png)

## References
1. https://lastminuteengineers.com/esp32-deep-sleep-wakeup-sources/ (Reason for wakeup method is wrong)
2. https://randomnerdtutorials.com/esp32-deep-sleep-arduino-ide-wake-up-sources/

