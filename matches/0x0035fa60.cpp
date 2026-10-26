#include "decls/data/engine/audio.h"
// data: gEffect = DAT_004e63c8

class Effect {
  public:
    Effect(const char*, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void init() {
    (*(Effect*)&DAT_004e63c8).Effect::Effect("ListenerEffectPs2", 0);
    atexit(cleanup);
}