// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001c4390 @ 0x001c4390
struct State_1c4390 {
 char pad[0x14];
 unsigned char firstActive; char pad15[3];
 float firstValue, firstTarget, firstRate;
 unsigned char secondActive; char pad25[3];
 float secondValue, secondTarget, secondRate;
 unsigned char dirty;
 void FUN_001c4390(float target, unsigned char secondEnabled, float secondDuration, unsigned char firstEnabled, float firstDuration);
};
void State_1c4390::FUN_001c4390(float target, unsigned char secondEnabled, float secondDuration, unsigned char firstEnabled, float firstDuration) {
 float duration = firstEnabled ? firstDuration : 0.0f;
 if (duration == 0.0f) {
  firstTarget = 1.0f;
  firstValue = 1.0f;
  firstRate = 0.0f;
  firstActive = 0;
 } else {
  firstActive = 1;
  firstTarget = 1.0f;
  firstRate = (1.0f - firstValue) / duration;
 }
 duration = secondEnabled ? secondDuration : 0.0f;
 if (duration == 0.0f) {
  secondTarget = target;
  secondValue = target;
  secondRate = 0.0f;
  secondActive = 0;
 } else {
  secondActive = 1;
  secondTarget = target;
  secondRate = (target - secondValue) / duration;
 }
 dirty = 1;
}
