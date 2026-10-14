// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// CHand2HandAgent::vfunc_19 @ 0x000ffd30
extern unsigned char DAT_004e0a99;
struct CHand2HandAgent {
 char pad0[0x64];
 float value64;
 char pad68[0xc];
 float value74;
 char pad78[1];
 unsigned char flag79;
 char pad7a[0x53];
 unsigned char flagcd, flagce;
 char padcf[2];
 unsigned char flagd1, flagd2, flagd3;
 float lower, upper, adjusted, previous;
 char pade4[0x44];
 int count;
 void vfunc_19();
};
void CHand2HandAgent::vfunc_19() {
 if (!flagd1 && !flagd2) {
  if (flagcd || flagce || value64 > 0.0f || flag79 || count >= 3 || DAT_004e0a99) {
   previous = upper;
   adjusted = upper - (upper - lower) * 0.25f;
  }
 }
 if (flagd3) {
  float base = value74;
  lower = base;
  adjusted = base;
  upper = base + 2.0f;
  previous = base + 2.0f;
 }
}
