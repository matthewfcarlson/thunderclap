#include "decls/data/engine/audio.h"
// data: gResult = DAT_004e6328

class Thing {
  public:
    int FUN_003469f5();
};
extern Thing gThing;
extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
extern "C" void _ReadWriteBarrier();
void target() {
    int x = gThing.FUN_003469f5();
    _ReadWriteBarrier();
    (*(__int64*)&DAT_004e6328) = FUN_002672f0(x, 0, 0);
}