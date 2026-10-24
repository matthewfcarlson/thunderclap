#include "gen/global.h"

struct Part_1b90b0 {
    unsigned Get();
    void Set(unsigned);
};
struct Engine_1b90b0 {
    void Stop(int);
};
struct Sub_1b90b0 {
    char pad[0x124];
    Engine_1b90b0* p;
};
struct Global_1b90b0 {
    char pad[0x20];
    Sub_1b90b0* sub;
    char pad2[0x3c - 0x24];
    Part_1b90b0* part;
};
extern Global_1b90b0* g_1b90b0;
struct Item_1b90b0 {
    void Act(int, float, int, int);
};
Item_1b90b0* __stdcall Make();

void CRenderManager::FUN_001b90b0() {
    unsigned x = g_1b90b0->part->Get();
    g_1b90b0->part->Set((*(unsigned int *)&this->f_24) | x);
    Make()->Act(1, 0.5f, 0, 0);
    Engine_1b90b0* e = g_1b90b0->sub->p;
    if (e && this->f_32) {
        this->f_32 = 0;
        e->Stop(0);
    }
}
