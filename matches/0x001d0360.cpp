#include "decls/data/game/global.h"
// data: g_counter_1d0360 = DAT_004e23c8

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
CScenarioParams* CScenarioParams::target(const unsigned int* src) {
    InitBase();
    vf = ((hulk_intptr)DAT_00422370);
    data.Init();
    unsigned int n = *src;
    memcpy(&data, src, n);
    ++(*(unsigned int*)&DAT_004e23c8);
    id = (*(unsigned int*)&DAT_004e23c8);
    return this;
}