/* ______________________________________Macros______________________________________ */
#define TOUCH_THRESHOLD 40 //Greater the value, more the sensitivity. ESP will wake up for values below threshold
/* ______________________________________Variables______________________________________ */
int wakePin;
/* ______________________________________Setup______________________________________ */
void setup(){
  Serial.begin(115200);
  Serial.println("ESP32 has started");
  print_wakeup_reason();
  touchAttachInterrupt(T0, callback, TOUCH_THRESHOLD); // Setup interrupt on Touch Pad 0 (GPIO4)
  esp_sleep_enable_touchpad_wakeup(); //Configure Touchpad as wakeup source. This is done so that esp does not shut down the touch pins when it goes into deep sleep
  Serial.println("You have touched the touch pin. Now going to deep sleep");
  delay(1000);
  esp_deep_sleep_start();
}
/* ______________________________________Loop______________________________________ */
void loop(){
  //This will never be reached
}
/* ______________________________________Functions______________________________________ */
void callback(){
  /*
   * Will be executed when the threshold is crossed. 
   * Since we are usind deep sleep, this function is useless to us.
   * Hence, this function is empty
   */
}
void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;
  wakeup_reason = esp_sleep_get_wakeup_cause();
  switch(wakeup_reason)
  {
    case ESP_SLEEP_WAKEUP_EXT0 : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case ESP_SLEEP_WAKEUP_EXT1 : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
    case ESP_SLEEP_WAKEUP_TIMER : Serial.println("Wakeup caused by timer"); break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD : Serial.println("Wakeup caused by touchpad"); break;
    case ESP_SLEEP_WAKEUP_ULP : Serial.println("Wakeup caused by ULP program"); break;
    default : Serial.printf("Wakeup was not caused by deep sleep: %d\n",wakeup_reason); break;
  }
}
