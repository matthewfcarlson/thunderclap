#include "decls/data/engine/core.h"

extern "C" char DAT_003f6098[];
extern "C" char DAT_0042af64[];
extern "C" char DAT_0042b474[];
extern "C" char DAT_0042b47c[];
typedef unsigned int u32_26ea50;
extern "C" void init_console();
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
    *(u32_26ea50*)this = ((int)DAT_0042b47c);
    *(u32_26ea50*)((char*)this + 4) = ((int)DAT_0042b474);
    init_console();
    *(u32_26ea50*)((int)((char*)&DAT_004cdbb0)) = field8;
    *(u32_26ea50*)((char*)this + 4) = ((int)DAT_0042af64);
    *(u32_26ea50*)((int)DAT_005283b0) = 0;
    *(u32_26ea50*)this = ((int)DAT_003f6098);
    if (flag & 1)
        cleanup_console(*(u32_26ea50*)((int)((char*)&DAT_004cdbb0)), this);
    return this;
}