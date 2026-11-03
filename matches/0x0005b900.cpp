#include "compat/ptr.h"
#include "gen/fight.h"
extern "C" char hulk_at_003f9a8c[];
extern void* vA[];
struct ThisCall_00234960 {
};
class ParamFloatConstRange_5b900 {
  public:
    void* vptr;
    char pad[12];
    void* m10;
    ParamFloatConstRange_5b900(void* a, void* b);
};
ParamFloatConstRange_5b900::ParamFloatConstRange_5b900(void* a, void* b) {
    ((fight::ParamValueFloat *)(((ThisCall_00234960*)(this))))->FUN_00234960((const char *)a);
    vptr = (void*)((hulk_intptr)(hulk_at_003f9a8c + 0x4));
    m10 = b;
}
