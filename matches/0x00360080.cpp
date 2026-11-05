#include "decls/data/engine/audio.h"

extern "C" void _atexit(void (*)(void));
extern "C" void __cdecl FUN_003643e0(void);
class SeqEventWaitType_360080 {
  public:
    void FUN_00250290();
};
void __cdecl Target() {
    (*(SeqEventWaitType_360080*)&DAT_004e69b0).FUN_00250290();
    _atexit(FUN_003643e0);
}
