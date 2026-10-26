#include "decls/data/engine/audio.h"

extern "C" void _atexit(void (*)(void));
extern void __cdecl Handler(void);
class SeqEventWaitType_360080 {
  public:
    void Fn();
};
void __cdecl Target() {
    (*(SeqEventWaitType_360080*)&DAT_004e69b0).Fn();
    _atexit(Handler);
}
