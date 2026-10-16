#include "gen/global.h"

struct Manager_17020 {
    void f(void* g, void* b, int v);
};
struct Global_17020 {
    char pad[8];
    Manager_17020* manager;
};
extern Global_17020* g_4dd700;
struct H1 {
    void* f();
};
struct H2_17020 {
    void* f();
};
struct X_17020 {
    char pad[0x14];
    int value;
};

bool CCameraHintAction::vfunc_8(int ) {
    void* b = ((H2_17020*)(*(H1 * *)&this->f_1c)->f())->f();
    g_4dd700->manager->f(g_4dd700, b, (*(X_17020 * *)&this->f_20)->value);
    return true;
}
