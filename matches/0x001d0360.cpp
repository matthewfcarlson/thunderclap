#include "compat/ptr.h"
extern "C" char DAT_00422370[];
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct DataInit {
    void Init();
};
struct CScenarioParams {
    hulk_uintptr vf;
    unsigned int pad4;
    unsigned int id;
    unsigned int padc;
    DataInit data;
    void InitBase();
    CScenarioParams* target(const unsigned int* src);
};
extern unsigned int g_counter_1d0360;
CScenarioParams* CScenarioParams::target(const unsigned int* src) {
    InitBase();
    vf = ((hulk_intptr)DAT_00422370);
    data.Init();
    unsigned int n = *src;
    memcpy(&data, src, n);
    ++g_counter_1d0360;
    id = g_counter_1d0360;
    return this;
}