// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_001ec310 @ 0x001ec310
struct Item { unsigned int FUN_0008a2d0(); unsigned int FUN_000897f0(); };
struct Source { Item* FUN_00086310(); };
struct Sink { void FUN_001eb060(unsigned int, unsigned int); };
struct Handler { void FUN_001f3950(float); };
struct Owner { Handler* handler; Sink* sink; void FUN_001efa40(int, unsigned int, unsigned int); };
extern unsigned char DAT_004e36e0;
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
struct Target { Owner* owner; Source* source; unsigned char enabled; char padding[3]; float value; void FUN_001ec310(unsigned int); };
void Target::FUN_001ec310(unsigned int) {
 unsigned int cookie = DAT_004d9968;
 if (!DAT_004e36e0 && enabled) {
  Item* item = source->FUN_00086310();
  Sink* sink = owner->sink;
  unsigned int a = item->FUN_0008a2d0();
  unsigned int b = item->FUN_000897f0();
  sink->FUN_001eb060(b,a);
  a = item->FUN_0008a2d0();
  b = item->FUN_000897f0();
  owner->FUN_001efa40(1,b,a);
  float v = value;
  if (!(v < 0.0f) && !(v > 100.0f)) owner->handler->FUN_001f3950(v);
  DAT_004e36e0 = 1;
 }
 __security_check_cookie(cookie);
}
