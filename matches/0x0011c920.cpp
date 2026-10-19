typedef unsigned int u32_11c920;
struct V {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
struct Info_11c920 {
    char pad[8];
    u32_11c920 x;
    u32_11c920 y;
};
struct Pair_11c920 {
    u32_11c920 x;
    u32_11c920 y;
    Pair_11c920(u32_11c920 a, u32_11c920 b) : x(a), y(b) {}
};
struct Obj_11c920 {
    Info_11c920* G();
    void P1(Pair_11c920*);
    void P2(Pair_11c920*);
};
struct Mid_11c920 {
    Obj_11c920* H();
};
struct Manager_11c920 {
    void Reg(void*);
};
struct Root_11c920 {
    char pad[0x1c];
    Manager_11c920* m;
};
extern Root_11c920* gRoot_11c920;
Obj_11c920* __stdcall Conv();
struct PathFormationAction : V {
    char pad[0x80 - 4];
    Mid_11c920* mid;
    void vfunc_4();
};
void PathFormationAction::vfunc_4() {
    if (mid) {
        Info_11c920* i = mid->H()->G();
        Conv()->P1(&Pair_11c920(i->x, i->y));
        Conv()->P2(&Pair_11c920(i->x, i->y));
        gRoot_11c920->m->Reg((char*)this + 0x1c);
    }
}
