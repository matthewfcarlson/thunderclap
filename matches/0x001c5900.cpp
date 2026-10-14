typedef unsigned int u32_1c5900;
struct Obj_1c5900 {
    virtual void f();
    char pad[4];
    Obj_1c5900* Create(u32_1c5900);
    bool Check();
};
struct Finder_1c5900 {
    Obj_1c5900* Find(u32_1c5900);
};
struct Registry_1c5900 {
    void Register(void*, Obj_1c5900*);
};
struct Manager_1c5900 {
    char p0[8];
    Registry_1c5900 registry;
    char p1[0x128 - 8 - sizeof(Registry_1c5900)];
    Finder_1c5900 finder;
    char p2[0x248 - 0x128 - sizeof(Finder_1c5900)];
    Obj_1c5900* saved;
    Obj_1c5900* Run(u32_1c5900, u32_1c5900);
};
Obj_1c5900* Manager_1c5900::Run(u32_1c5900 a, u32_1c5900 b) {
    Obj_1c5900* p = finder.Find(b);
    if (p) {
        p = p->Create(a);
        p->f();
        registry.Register((char*)p + 8, p);
        if (p->Check())
            saved = p;
        return p;
    }
    return 0;
}