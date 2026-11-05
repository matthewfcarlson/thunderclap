#include "decls/data/engine/unknown.h"
// data: the type descriptor DAT_004cc38c (typeid(...); its name() is type_info::name, 0x003469f5), result = DAT_004e6348

class TypeInfo_3469f5 {
  public:
    const char* FUN_003469f5();
};
extern "C" TypeInfo_3469f5 DAT_004cc38c;
unsigned __int64 FUN_002672f0(const char* s, int a, int b);
void FUN_0035fc20() {
    const char* n = DAT_004cc38c.FUN_003469f5();
    unsigned __int64 r = FUN_002672f0(n, 0, 0);
    (*(unsigned int*)&DAT_004e6348) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e634c) = (unsigned int)(r >> 32);
}
