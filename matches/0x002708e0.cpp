#include "compat/ptr.h"
#include "decls/data/engine/core.h"

extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042b680[];
extern "C" char DAT_0042b688[];
extern "C" char DAT_0042b6b0[];
extern int gValue_2708e0;
class ControllerBuffer {
  public:
    hulk_intptr vptr;
    hulk_intptr vptr4;
    int ref;
    int enabled;
    int a;
    int b;
    int c;
    int d;
    int e;
    int pad;
    int f;
    ControllerBuffer(int);
};
void InitBase();
ControllerBuffer::ControllerBuffer(int value) {
    vptr = ((hulk_intptr)DAT_0042b6b0);
    vptr4 = ((hulk_intptr)DAT_0042afa8);
    ref = *(int*)((hulk_intptr)((char*)&DAT_004cdbb0));
    InitBase();
    vptr = ((hulk_intptr)DAT_0042b688);
    vptr4 = ((hulk_intptr)DAT_0042b680);
    enabled = 1;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    pad = 0;
    f = value;
    InitBase();
}