#include "gen/hulkfight.h"

typedef unsigned int u32_12f9b0;
struct Action_12f9b0 {
    char pad[0x1c];
};
struct Manager_12f9b0 {
    Manager_12f9b0* doA(u32_12f9b0, int);
    void doB();
};
extern Manager_12f9b0* gManager_12f9b0;

bool hulkfight::StatAction::vfunc_3(int a, int b) {
    if (!this->f_20)
        return false;
    u32_12f9b0 x = *(u32_12f9b0*)((char*)this->f_1c + 0x10);
    Manager_12f9b0* p = gManager_12f9b0->doA(x, 1);
    p->doB();
    return true;
}
