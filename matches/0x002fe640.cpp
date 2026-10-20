#include "compat/ptr.h"
struct SimulatedObject {
    int vptr;
    char pad04[12];
    int field10;
    char pad14[4];
    int field18;
    int field1c;
    unsigned char field20;
    char pad21[3];
    int field24;
    int field28;
    void Init();
    SimulatedObject();
};
extern int g_counter_2fe640;
extern int physics_vftable;
SimulatedObject::SimulatedObject() {
    Init();
    field10 = 0;
    field18 = 0;
    field1c = 0;
    vptr = (hulk_intptr)&physics_vftable;
    field20 = 1;
    field24 = 3;
    field28 = g_counter_2fe640;
    ++g_counter_2fe640;
}