#include "decls/data/engine/core.h"
// data: gSaved = DAT_004cdbb0, gState_26e360 = DAT_005283b0

#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042af64[];
extern "C" char DAT_0042b474[];
extern "C" char DAT_0042b47c[];
typedef unsigned int u32_26e360;
extern void __fastcall Init(void*);
class ConsoleClient {
  public:
    hulk_uintptr a, b, c;
    void Run();
};
void ConsoleClient::Run() {
    a = ((hulk_intptr)DAT_0042b47c);
    b = ((hulk_intptr)DAT_0042b474);
    Init((void*)(this));
    (*(u32_26e360*)&DAT_004cdbb0) = c;
    b = ((hulk_intptr)DAT_0042af64);
    a = ((hulk_intptr)DAT_003f6098);
    (*(u32_26e360*)&DAT_005283b0) = 0;
}