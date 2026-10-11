typedef unsigned int u32;
struct V {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
struct Info {
    char pad[8];
    u32 x;
    u32 y;
};
struct Pair {
    u32 x;
    u32 y;
    Pair(u32 a, u32 b) : x(a), y(b) {}
};
struct Obj {
    Info* G();
    void P1();
    void P2();
};
struct Mid {
    Obj* H();
};
struct Manager {
    void Reg(void*);
};
struct Root {
    char pad[0x1c];
    Manager* m;
};
extern Root* gRoot;
Obj* __stdcall Conv(Pair*);
struct PathFormationAction : V {
    char pad[0x80 - 4];
    Mid* mid;
    void vfunc_4();
};
void PathFormationAction::vfunc_4() {
    if (mid) {
        Info* i = mid->H()->G();
        Conv(&Pair(i->x, i->y))->P1();
        Conv(&Pair(i->x, i->y))->P2();
        gRoot->m->Reg((char*)this + 0x1c);
    }
}
