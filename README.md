# ESP32-Deep-Sleep
## Important
Three things to mention about deep sleep.
1. `esp_deep_sleep_start` shuts down the processor, so any code you write beneath this line won't be executed.
2. When the ESP32 awakes from the deep sleep, it will rerun your setup function.
3. When you enter deep sleep, all data stored in memory is lost.

## Codes
### 01_Wake_ESP32_Using_RTC
The easiest way to wake the ESP32 up from sleep is to use an RTC to wake it up after a certain amount of time. This sketch puts ESP32 into deep sleep until the RTC triggers it after every 1 minute.
![image](https://user-images.githubusercontent.com/61982410/124750508-2b77b380-df43-11eb-8457-4f39f62022bc.png)


