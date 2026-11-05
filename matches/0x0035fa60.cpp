#include "decls/data/engine/audio.h"
// data: gEffect = DAT_004e63c8

class Effect {
  public:
    void FUN_0025fa00(const char*, int);
    Effect(const char*, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003642d0();
void init() {
    ((Effect*)&DAT_004e63c8)->FUN_0025fa00("ListenerEffectPs2", 0);
    atexit(FUN_003642d0);
}