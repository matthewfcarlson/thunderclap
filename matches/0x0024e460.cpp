#include "decls/data/engine/unknown.h"

#include "compat/ptr.h"
extern "C" char DAT_0042986c[];
typedef unsigned int u32_24e460;
extern char g2;
struct A_24e460 {
    void Init(void*, void*, int, int);
};
extern void Work(void*, u32_24e460);
struct C_24e460 {
    void End();
};
void Target(u32_24e460 param_1) {
    char local[0x48];
    ((A_24e460*)local)->Init(&g2, ((char*)&DAT_004e6340), 0x1c, 4);
    *(void**)local = (void*)((hulk_intptr)DAT_0042986c);
    Work(local, param_1);
    ((C_24e460*)local)->End();
}