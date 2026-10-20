#include "compat/ptr.h"
struct Sub_1c5ae0 {
    void Set(unsigned int v, hulk_intptr x);
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
    sub.Set(((Helper*)x)->Get(), x);
}
