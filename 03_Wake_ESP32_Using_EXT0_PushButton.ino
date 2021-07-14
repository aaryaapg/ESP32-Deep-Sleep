/* _____________________________Declarations_and_Variables______________________________ */
RTC_DATA_ATTR int counter = 0;
/* ______________________________________Functions______________________________________ */
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
/* ________________________________________Setup________________________________________ */
void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 has started");
  print_wakeup_reason();
  Serial.print("Wakeup Count = "); Serial.println(counter);
  counter++;
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_33,1); //1 = High, 0 = Low
  Serial.println("Going to sleep now");
  delay(1000);
  esp_deep_sleep_start();
}
/* ________________________________________Loop_________________________________________ */
void loop() {
  //Nothing here
}
