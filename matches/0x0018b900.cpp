#include "compat/ptr.h"
#include "gen/hulkfight.h"
struct PropAtRestCondition_nv_18b900 {
    void Init(int);
};
extern void* __cdecl alloc(hulk_uintptr);
extern int prop_vtable;
void* Factory_vfunc5() {
    hulkfight::motion::PropAtRestCondition* p = (hulkfight::motion::PropAtRestCondition*)alloc(0x10);
    if (p) {
        ((PropAtRestCondition_nv_18b900*)(p))->Init(0);
        *((hulk_intptr*)p) = (hulk_intptr)&prop_vtable;
        (*(unsigned char *)&p->f_0c) = 1;
        return p;
    }
    return 0;
}
