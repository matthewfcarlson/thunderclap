#include "decls/data/engine/unknown.h"
// data: the type descriptor DAT_004cc3b0 (typeid(...); its name() is type_info::name, 0x003469f5), result = DAT_004e6358

class TypeInfo_3469f5 {
  public:
    const char* FUN_003469f5();
};
extern "C" TypeInfo_3469f5 DAT_004cc3b0;
unsigned __int64 FUN_002672f0(const char* s, int a, int b);
void FUN_0035fc70() {
    const char* id = DAT_004cc3b0.FUN_003469f5();
    unsigned __int64 r = FUN_002672f0(id, 0, 0);
    (*(unsigned int*)&DAT_004e6358) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e635c) = (unsigned int)(r >> 32);
}
