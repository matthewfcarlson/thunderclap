// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_001c5130 @ 0x001c5130
struct Object_1c5130 {
  char pad0[0x8c]; unsigned char dirty;
  char pad1[3];
  float rate;
  float level;
  float invDuration;
  void FUN_001c5130(float target, float duration);
};
void Object_1c5130::FUN_001c5130(float target, float duration) {
  dirty = 1;
  float v;
  if (0.0f <= target && target <= 1.0f) v = target;
  else if (target > 1.0f) v = 1.0f;
  else v = 0.0f;
  level = v;
  if (!(duration <= 0.0f)) {
    invDuration = 1.0f / duration;
  } else {
    rate = v;
    invDuration = 0.0f;
  }
}
