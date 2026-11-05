#include "decls/data/engine/audio.h"
// data: the type descriptor DAT_004cc58c (typeid(...); its name() is type_info::name, 0x003469f5), result = DAT_004e6328

class TypeInfo_3469f5 {
  public:
    const char* FUN_003469f5();
};
extern "C" TypeInfo_3469f5 DAT_004cc58c;
unsigned __int64 FUN_002672f0(const char* s, int a, int b);
extern "C" void _ReadWriteBarrier();
void FUN_0035fb80() {
    const char* x = DAT_004cc58c.FUN_003469f5();
    _ReadWriteBarrier();
    unsigned __int64 r = FUN_002672f0(x, 0, 0);
    (*(unsigned int*)&DAT_004e6328) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e632c) = (unsigned int)(r >> 32);
}
