// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// HSlider::vfunc_7 @ 0x000e9800
struct Source { bool FUN_000f94f0(unsigned int, unsigned int, float*); };
struct Receiver { void FUN_000f8b00(float); };
struct HSlider {
 char pad0[0x90]; unsigned int key0, key1; char pad98[0x150-0x98]; float value; char pad154[8]; float minimum, maximum, fallback; char pad168[0x180-0x168]; Receiver* receiver;
 void vfunc_7(Source* source);
};
void HSlider::vfunc_7(Source* source) {
 if (!(key0 | key1)) return;
 float incoming;
 float v;
 if (source->FUN_000f94f0(key0,key1,&incoming)) v=incoming; else v=fallback;
 if (v >= minimum && v <= maximum) value=v;
 else if (v > maximum) value=maximum;
 else value=minimum;
 if (receiver) receiver->FUN_000f8b00(value);
}
