#include "compat/ptr.h"
extern "C" char DAT_0042c694[];
class SimpleFrameController {
  public:
    char pad[0x40];
};
struct ThisCall_0027b070 {
    void Init();
};
SimpleFrameController* __fastcall FUN_00284cd0(SimpleFrameController* p) {
    ((ThisCall_0027b070*)(p))->Init();
    p->pad[0x10] = 0;
    *(int*)(p->pad + 0x20) = 0;
    *(int*)(p->pad + 0x24) = 0;
    *(int*)(p->pad + 0x2c) = 0;
    *(int*)(p->pad + 0x30) = 0;
    *(int*)(p->pad + 0x34) = 0;
    *(int*)(p->pad + 0x3c) = 0;
    *(int*)(p->pad + 0x18) = 0x3f800000;
    *(hulk_intptr*)p = ((hulk_intptr)DAT_0042c694);
    *(int*)(p->pad + 0x28) = 0x7f7fffff;
    p->pad[0x38] = 1;
    return p;
}