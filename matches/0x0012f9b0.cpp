#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_12f9b0;
struct Action_12f9b0 {
    char pad[0x1c];
};
struct Manager_12f9b0 {
    Manager_12f9b0* doA();
    void doB(u32_12f9b0, int);
};
extern Manager_12f9b0* gManager_12f9b0;

bool hulkfight::StatAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    if (!this->f_20)
        return false;
    u32_12f9b0 x = *(u32_12f9b0*)((char*)this->f_1c + 0x10);
    gManager_12f9b0->doA()->doB(x, 1);
    return true;
}
