// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000bf0e0 @ 0x000bf0e0
struct Inner { char pad[0x2c]; int f2c; };
struct Arg { char pad[0xc]; Inner* f0c; };
struct G { void FUN_002665a0(); };
struct S {
  char pad0[0x10]; int f10;
  char pad1[0x38-0x14]; int f38;
  char pad2[0x1bc8-0x3c]; unsigned char f1bc8;
  char pad3[0x1c0c-0x1bc9]; unsigned char f1c0c;
  char pad4[0x1c4c-0x1c0d]; unsigned char f1c4c;
  void FUN_000befc0(void*, int, int);
  void FUN_000bf0e0(Arg*, int);
};
extern "C" G* DAT_004dd9cc;
extern "C" void* DAT_0049f3c4;
extern "C" void* DAT_0049f3cc;
extern "C" void* DAT_0049f3b0;
extern "C" unsigned char DAT_004e222c;
extern "C" void __cdecl FUN_000fc100(void*, int);
void S::FUN_000bf0e0(Arg* a, int){
  DAT_004dd9cc->FUN_002665a0();
  FUN_000befc0(DAT_0049f3c4, 14, 1);
  FUN_000befc0(DAT_0049f3cc, 14, 1);
  FUN_000fc100(DAT_0049f3b0, 0);
  f10 = 8;
  DAT_004e222c = 1;
  f1c0c = 0;
  f1c4c = 0;
  f38 = a->f0c->f2c;
  f1bc8 = 1;
}
