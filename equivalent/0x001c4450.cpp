// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001c4450 @ 0x001c4450
struct Transition_1c4450 {
 char pad[0x14];
 unsigned char active1; char pad15[3];
 float current1, target1, rate1;
 unsigned char active2; char pad25[3];
 float current2, target2, rate2;
 void FUN_001c4450(unsigned char first, float firstTime, unsigned char second, float secondTime);
};
void Transition_1c4450::FUN_001c4450(unsigned char first, float firstTime, unsigned char second, float secondTime) {
 float duration = second ? secondTime : 0.0f;
 float target = second ? 0.0f : 1.0f;
 target1 = target;
 if (duration == 0.0f) {
  current1 = target;
  rate1 = 0.0f;
  active1 = 0;
 } else {
  active1 = 1;
  rate1 = (target - current1) / duration;
 }
 duration = first ? firstTime : 0.0f;
 target = first ? 0.0f : current2;
 target2 = target;
 if (duration == 0.0f) {
  current2 = target;
  rate2 = 0.0f;
  active2 = 0;
 } else {
  active2 = 1;
  rate2 = (target - current2) / duration;
 }
}
