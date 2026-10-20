// Same code shape as 0x0012db50 (propagated; names are from that function)
struct Obj_23e080 {
    virtual void F();
    virtual void R();
};
extern int WaitAction_23e080_vftable;
struct WaitAction_23e080 {
    void* vf;
    int pad[6];
    int arg;
    Obj_23e080* object;
    void Init();
    WaitAction_23e080* Build(int, Obj_23e080*);
};
WaitAction_23e080* WaitAction_23e080::Build(int a, Obj_23e080* p) {
    Init();
    vf = &WaitAction_23e080_vftable;
    object = 0;
    arg = a;
    if (p)
        p->F();
    if (object)
        object->R();
    object = p;
    return this;
}