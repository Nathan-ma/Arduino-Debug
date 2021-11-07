#include <Arduino.h>
#include <Debug.h>

static DebugClass Debug("Main");

class ClassExample : public DebugClass {
 public:
  /* Constructor */
  ClassExample() : DebugClass("Example"){};

  /* Methods */
  void setup() {
    if (!error("This is ERROR")) Serial.println(C_BLUE "And it returns" C_RED " False" RESET_COLOR);
    warn("This is Warning");
    if (print("This is Print")) Serial.println(C_GRAY "And it returns" C_GREEN " True" RESET_COLOR);
    notice("This is Notice");
    detail("This is Detail");
  }
} Example;

void setup() {
  Serial.begin(115200);

  if (!Debug.error("This is ERROR")) Serial.println(C_BLUE "And it returns" C_RED " False" RESET_COLOR);
  Debug.warn("This is Warning");
  if (Debug.print("This is Print")) Serial.println(C_GRAY "And it returns" C_GREEN " True" RESET_COLOR);
  Debug.notice("This is Notice");
  Debug.detail("This is Detail");

  Example.setup();
}

void loop() {
}