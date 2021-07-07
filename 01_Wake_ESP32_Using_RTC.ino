/* ______________________________________Macros______________________________________ */
//Deep Sleep
#define DEEP_SLEEP_TIME 1 //Minutes

/* ______________________________________Setup______________________________________ */ 
void setup(){
  Serial.begin(115200);
  Serial.println("Taking measurements");   
  print_wakeup_reason(); //Print the wakeup reason for ESP32
  /*
   * Measurements are taken in the setup function because:
   * When the ESP32 awakes from the deep sleep, it will rerun your setup function. 
   * Also, when you enter deep sleep, all data stored in memory is lost.
   */
  goToDeepSleep(); //Any code written below this line will not be executed
}
/* ______________________________________Loop______________________________________ */ 
void loop(){
  
}
/* ______________________________________Functions______________________________________ */ 
void goToDeepSleep(){
    Serial.println("Going to sleep...");
    esp_sleep_enable_timer_wakeup(DEEP_SLEEP_TIME * 60 * 1000000); //Configure the timer: Parameter is the time (uS), It enables wakeup
    esp_deep_sleep_start(); //Go to deep sleep
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
