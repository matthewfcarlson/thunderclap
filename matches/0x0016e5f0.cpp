#include "gen/fight.h"

typedef unsigned char u8;
void* __cdecl Alloc(unsigned int);
extern char kVtbl[];
struct Sub0_16e5f0 {
    void Init(int);
};
struct Sub1_16e5f0 {
    void Init();
};
struct Obj_16e5f0 {
    void* vptr;
    char pad[0x18 - 4];
    int a, b, c;
    float d;
    int e, f;
    u8 flag;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::RayCastConeCondition>::vfunc_5() {
    Obj_16e5f0* p = (Obj_16e5f0*)Alloc(0x38);
    if (p) {
        ((Sub0_16e5f0*)p)->Init(0);
        p->vptr = (void*)kVtbl;
        ((Sub1_16e5f0*)((char*)p + 0x10))->Init();
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->e = 0;
        p->f = 0;
        p->d = 1.0f;
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
