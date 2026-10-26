#include "decls/data/engine/unknown.h"
// data: result = DAT_004e6348

class Obj {
  public:
    int Get();
};
extern Obj obj;
extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
void FUN_0035fc20() {
    int n = obj.Get();
    (*(__int64*)&DAT_004e6348) = FUN_002672f0(n, 0, 0);
}