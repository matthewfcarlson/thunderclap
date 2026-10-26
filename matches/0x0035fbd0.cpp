#include "decls/data/engine/audio.h"
// data: result = DAT_004e6338

class Thing {
  public:
    int Get();
};
extern Thing obj;
extern "C" __int64 __cdecl f(int, int, int);
void target() {
    int n = obj.Get();
    (*(__int64*)&DAT_004e6338) = f(n, 0, 0);
}