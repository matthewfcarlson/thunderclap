#include "gen/hulkfight.h"

struct Params_124540 {
    virtual void f();
};
struct Ent_124540 {
    char p[0x328];
    int target;
};
struct Holder_124540 {};
struct Condition_124540 {
    virtual void a();
};
struct Base2 {
    virtual void b();
};
extern "C" void* __cdecl DynCast(void*, int, void*, void*, int);
struct T1 {
    virtual void f();
};
struct T2 {
    virtual void f();
};
extern T1 t1_124540;
extern T2 t2;
Holder_124540* __fastcall G1(Params_124540*);
Ent_124540* __fastcall G2(Holder_124540*);

bool hulkfight::ai::HasTargetCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; Params_124540 * p = (Params_124540 *)__p1; int b = (int)__p2;

    if (!DynCast(p, 0, &t1_124540, &t2, 0))
        return false;
    int t = G2(G1(p))->target;
    if (this->f_0c)
        return t != 0;
    return t == 0;
}
