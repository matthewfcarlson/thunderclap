#include "gen/hulkfight.h"

struct Vec_183d30 {
    int* b;
    int* e;
};
struct Holder_183d30 {
    char p[0x1c];
    Vec_183d30 vec;
};
struct Prop_183d30 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void Do(int idx, int flag);
    char p[0x94];
    Holder_183d30* v;
};
struct Mgr_183d30 {
    char p[0x128];
    Prop_183d30* dflt;
    Prop_183d30* Get(int i);
};
struct Info_183d30 {
    char p[0x10];
    int a;
    int b;
};
extern void* __fastcall FUN_000592a0(void*);
extern Mgr_183d30* __fastcall FUN_00059a30(void*);

bool hulkfight::motion::PropSetStateByIndexAction::vfunc_5(int __p0, int y) { int * x = (int *)__p0;

    if (!x && (*(void * *)&this->f_20)) {
        Mgr_183d30* m = FUN_00059a30(FUN_000592a0((*(void * *)&this->f_20)));
        int a = (*(Info_183d30 * *)&this->f_1c)->a;
        if (m) {
            Prop_183d30* r;
            if (a < 0)
                r = m->dflt;
            else if (a >= 8)
                return false;
            else
                r = m->Get(a);
            if (r) {
                Vec_183d30* v = &r->v->vec;
                int i = (*(Info_183d30 * *)&this->f_1c)->b;
                if (i >= 0 && i < (v->e - v->b))
                    r->Do(i, 1);
            }
        }
    }
    return false;
}
