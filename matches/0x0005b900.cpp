#include "compat/ptr.h"
extern "C" char hulk_at_003f9a8c[];
extern void* vA[];
struct ThisCall_00234960 {
    void FUN_00234960(void*);
};
class ParamFloatConstRange_5b900 {
  public:
    void* vptr;
    char pad[12];
    void* m10;
    ParamFloatConstRange_5b900(void* a, void* b);
};
ParamFloatConstRange_5b900::ParamFloatConstRange_5b900(void* a, void* b) {
    ((ThisCall_00234960*)(this))->FUN_00234960(a);
    vptr = (void*)((hulk_intptr)(hulk_at_003f9a8c + 0x4));
    m10 = b;
}
