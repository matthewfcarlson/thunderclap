#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042af64[];
extern "C" char DAT_0042b474[];
extern "C" char DAT_0042b47c[];
typedef unsigned int u32_26e360;
extern void __fastcall Init(void*);
extern u32_26e360 gSaved;
extern u32_26e360 gState_26e360;
class ConsoleClient {
  public:
    u32_26e360 a, b, c;
    void Run();
};
void ConsoleClient::Run() {
    a = ((hulk_intptr)DAT_0042b47c);
    b = ((hulk_intptr)DAT_0042b474);
    Init((void*)(this));
    gSaved = c;
    b = ((hulk_intptr)DAT_0042af64);
    a = ((hulk_intptr)DAT_003f6098);
    gState_26e360 = 0;
}