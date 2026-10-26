#include "decls/data/engine/audio.h"
// data: gResult = DAT_004e6328

class Thing {
  public:
    int get();
};
extern Thing gThing;
extern "C" __int64 __cdecl calc(int, int, int);
extern "C" void _ReadWriteBarrier();
void target() {
    int x = gThing.get();
    _ReadWriteBarrier();
    (*(__int64*)&DAT_004e6328) = calc(x, 0, 0);
}