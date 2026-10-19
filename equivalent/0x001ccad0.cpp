// STATUS: equivalent (tools/equiv.py level 3: 8739 inputs, branch coverage 8/8)
// FUN_001ccad0 @ 0x001ccad0
// cl-flags: /GS
struct Receiver_1ccad0 { void FUN_001d3f00(const char*, const char*); };
extern "C" int __cdecl FUN_00267760(char*, unsigned int, const char*, ...);
struct Timer { float remaining; char text[256]; int id; };
struct Owner_1ccad0 {
 char pad[0x110]; Timer timers[16];
 Receiver_1ccad0* FUN_001d4c90();
 void update(float elapsed);
};
void Owner_1ccad0::update(float elapsed) {
 Receiver_1ccad0* receiver = FUN_001d4c90();
 if (receiver) {
 char buffer[64];
 for (int i=0;i<16;++i) {
  Timer& timer=timers[i];
  if (!(timer.remaining >= 0.0f)) continue;
  if ((timer.remaining -= elapsed) <= 0.0f) {
   FUN_00267760(buffer,64,"=timer: %.50s",timer.text);
   receiver->FUN_001d3f00(timer.text,buffer);
   timer.remaining=-1.0f;
   timer.text[0]=0;
   timer.id=-1;
  }
 }
 }
}