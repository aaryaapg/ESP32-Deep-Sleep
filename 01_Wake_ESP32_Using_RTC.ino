/* ______________________________________Macros______________________________________ */
//Deep Sleep
#define DEEP_SLEEP_TIME 1 //Minutes

/* ______________________________________Setup______________________________________ */ 
void setup(){
  Serial.begin(115200);
  Serial.println("Taking measurements"); 
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
