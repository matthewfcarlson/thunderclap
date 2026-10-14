// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 8/8)
// FUN_001ee020 @ 0x001ee020
struct B_1ee020 { unsigned char FUN_001f4710(); };
struct A_1ee020 { B_1ee020* b; void FUN_001f22f0(float, int); void FUN_001ef9c0(int); };
struct S_1ee020 { A_1ee020* a; char pad[4]; unsigned char active; void FUN_001ee020(); };
extern "C" unsigned char DAT_004e36e0;
extern "C" const float DAT_003f335c;
extern "C" void __stdcall FUN_001ec480(const float*, const char*);
extern "C" void __cdecl thunk_FUN_00270a50();
extern "C" void __cdecl FUN_002656a0();
extern "C" void __cdecl FUN_00240bb0();
void S_1ee020::FUN_001ee020(){
  DAT_004e36e0 = 0;
  if (active) {
    FUN_001ec480(&DAT_003f335c, "EnterPreGame");
    while (a->b->FUN_001f4710()) {
      thunk_FUN_00270a50(); FUN_002656a0(); FUN_00240bb0();
      if (active) a->FUN_001f22f0(0.001f, 0);
    }
    a->FUN_001ef9c0(1);
  }
}
