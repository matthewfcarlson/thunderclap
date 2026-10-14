// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 4/4)
// FUN_002f4df0 @ 0x002f4df0
struct Sub_2f4df0 { void FUN_002f7a40(); void FUN_002f7a80(void*); };
struct G_2f4df0 { char pad[0xb0]; Sub_2f4df0 sub; };
struct Agent_2f4df0 { Agent_2f4df0* FUN_002f8800(); };
extern "C" unsigned char DAT_0055544c;
extern "C" G_2f4df0* DAT_00554c14;
extern "C" void __cdecl FUN_002ecb90(int);
extern "C" void __cdecl FUN_002f2e20();
extern "C" void __cdecl FUN_003077c0();
extern "C" void __cdecl FUN_002ed020();
extern "C" void __cdecl FUN_002ef0b0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
void FUN_002f4df0(int arg, void* handler){
  DAT_0055544c = 1;
  FUN_002ecb90(arg);
  FUN_002f2e20();
  FUN_003077c0();
  FUN_002ed020();
  FUN_002ef0b0();
  DAT_00554c14->sub.FUN_002f7a40();
  if (handler == 0) {
    void* mem = FUN_0008d690(0xc);
    if (mem) handler = ((Agent_2f4df0*)mem)->FUN_002f8800();
  }
  DAT_00554c14->sub.FUN_002f7a80(handler);
}
