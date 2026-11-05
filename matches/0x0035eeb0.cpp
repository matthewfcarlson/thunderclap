#include "decls/data/engine/om.h"
#include "decls/data/game/global.h"
// data: the type descriptor DAT_004c8040 (typeid(...); its name() is type_info::name, 0x003469f5), result = DAT_004e58d0

class TypeInfo_3469f5 {
  public:
    const char* FUN_003469f5();
};
extern "C" TypeInfo_3469f5 DAT_004c8040;
unsigned __int64 FUN_002672f0(const char* s, int a, int b);
void FUN_0035eeb0() {
    const char* n = DAT_004c8040.FUN_003469f5();
    unsigned __int64 r = FUN_002672f0(n, 0, 0);
    (*(unsigned int*)&DAT_004e58d0) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e58d4) = (unsigned int)(r >> 32);
}
