#include "decls/data/engine/audio.h"
// data: result = DAT_004e6338

class Thing {
  public:
    int FUN_003469f5();
};
extern Thing obj;
extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
void target() {
    int n = obj.FUN_003469f5();
    (*(__int64*)&DAT_004e6338) = FUN_002672f0(n, 0, 0);
}