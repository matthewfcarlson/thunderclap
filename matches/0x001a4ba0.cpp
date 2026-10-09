extern "C" void* FUN_00344e74(void*, int, void*, void*, int);
extern int g_params;
extern int g_scen;

struct Rec {
    char pad0[4];
    int type;
    char pad1[0x10];
    int a;
    int b;
};
struct Getter {
    Rec* get();
};

class Event_StringCondition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool vfunc_6(void* p1, void* p2, void* p3);
    char pad[0xc];
    int a;
    int b;
};

bool Event_StringCondition::vfunc_6(void* p1, void* p2, void* p3) {
    Getter* g = (Getter*)FUN_00344e74(p2, 0, &g_params, &g_scen, 0);
    if (g) {
        Rec* r = g->get();
        if (r->type == 0x1b && r->a == a && r->b == b)
            return true;
    }
    return false;
}
