#include "decls/data/engine/core.h"

#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042af64[];
extern "C" char DAT_0042afcc[];
extern "C" char DAT_0042afd4[];
struct Callback_267fd0 {
    virtual void A();
    virtual void B();
};
void Init(int);
struct TimerList_267fd0 {
    void* v0;
    void* v1;
    int value;
    char pad[12];
    Callback_267fd0* cb;
    int gap;
    int arg;
    void F();
};
void TimerList_267fd0::F() {
    v0 = (void*)((hulk_intptr)DAT_0042afd4);
    v1 = (void*)((hulk_intptr)DAT_0042afcc);
    Init(arg);
    cb->B();
    DAT_004cdbb0 = value;
    v1 = (void*)((hulk_intptr)DAT_0042af64);
    v0 = (void*)((hulk_intptr)DAT_003f6098);
}