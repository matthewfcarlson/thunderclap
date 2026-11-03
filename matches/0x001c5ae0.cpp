#include "compat/ptr.h"
#include "gen/Render.h"
struct Sub_1c5ae0 {
};
struct Helper {
    unsigned int Get();
};
struct Owner_1c5ae0 {
    char pad[0x128];
    Sub_1c5ae0 sub;
    void Run(hulk_intptr x);
};
void Owner_1c5ae0::Run(hulk_intptr x) {
    ((Render::StoreBase *)&sub)->FUN_001c7870((int)(((Helper*)x)->Get()), (int)x);
}
