extern "C" void* __cdecl alloc(unsigned int);
extern "C" int CollisionThrownObjectCondition_vftable;

struct Helper { char pad[8]; void Go(); };
struct Cond {
    void* vp;
    char pad1[8];
    char flag;
    char pad2[3];
    Helper h;
    void Init(int);
};

struct Factory {
    Cond* vfunc_5();
};

Cond* Factory::vfunc_5() {
    Cond* p = (Cond*)alloc(0x18);
    if (p) {
        p->Init(0);
        p->vp = (void*)&CollisionThrownObjectCondition_vftable;
        p->flag = 1;
        p->h.Go();
        return p;
    }
    return 0;
}
