#include "compat/ptr.h"
#include "decls/data/engine/core.h"

extern "C" char DAT_003f6098[];
extern "C" char DAT_0042af64[];
extern "C" char DAT_0042b474[];
extern "C" char DAT_0042b47c[];
typedef unsigned int u32_26ea50;
extern "C" void __fastcall init_console(void*);
extern "C" void cleanup_console(u32_26ea50, void*);
class ConsoleClient {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad[4];
    u32_26ea50 field8;
    ConsoleClient* vfunc_2(unsigned char);
};
ConsoleClient* ConsoleClient::vfunc_2(unsigned char flag) {
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_0042b47c);
    *(hulk_uintptr*)((char*)this + 4) = ((hulk_intptr)DAT_0042b474);
    init_console((void*)(this));
    *(u32_26ea50*)((hulk_intptr)((char*)&DAT_004cdbb0)) = field8;
    *(hulk_uintptr*)((char*)this + 4) = ((hulk_intptr)DAT_0042af64);
    *(u32_26ea50*)((hulk_intptr)DAT_005283b0) = 0;
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_003f6098);
    if (flag & 1)
        cleanup_console(*(u32_26ea50*)((hulk_intptr)((char*)&DAT_004cdbb0)), this);
    return this;
}