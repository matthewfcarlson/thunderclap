#include "compat/ptr.h"
struct Ref_2397c0 {
    virtual void AddRef();
    virtual void Release();
};
struct Action_2397c0 {
    Action_2397c0() throw();
    virtual void V0();
    char pad04[0x18];
};
struct S_2397c0 {
    S_2397c0() throw();
    char p[0x28];
};
struct ExecuteAction_2397c0 : Action_2397c0 {
    Ref_2397c0* m1c;
    hulk_intptr m20;
    Ref_2397c0* m24;
    int m28;
    Ref_2397c0* m2c;
    Ref_2397c0* m30;
    Ref_2397c0* m34;
    S_2397c0 s;
    int m60;
    char m64;
    ExecuteAction_2397c0(Ref_2397c0* a, Ref_2397c0* b, Ref_2397c0* c, int d, Ref_2397c0* e, Ref_2397c0* f, Ref_2397c0* g);
    virtual void V0();
};
ExecuteAction_2397c0::ExecuteAction_2397c0(Ref_2397c0* a, Ref_2397c0* b, Ref_2397c0* c, int d, Ref_2397c0* e, Ref_2397c0* f, Ref_2397c0* g)
    : m1c(0), m20(0), m24(0), m28(d), m2c(e), m30(f), m34(0) {
    m60 = 0;
    m64 = 0;
    if (a)
        a->AddRef();
    if (m1c)
        m1c->Release();
    m1c = a;
    m20 = (hulk_intptr)b;
    if (c)
        c->AddRef();
    if (m24)
        m24->Release();
    m24 = c;
    if (g)
        g->AddRef();
    if (m34)
        m34->Release();
    m34 = g;
}
