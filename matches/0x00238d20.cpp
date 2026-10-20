// Same code shape as 0x0012db50 (propagated; names are from that function)
struct Obj_238d20 {
    virtual void F();
    virtual void R();
};
extern int PrintAction_238d20_vftable;
struct PrintAction_238d20 {
    void* vf;
    int pad[6];
    int arg;
    Obj_238d20* object;
    void Init();
    PrintAction_238d20* Build(int, Obj_238d20*);
};
PrintAction_238d20* PrintAction_238d20::Build(int a, Obj_238d20* p) {
    Init();
    vf = &PrintAction_238d20_vftable;
    object = 0;
    arg = a;
    if (p)
        p->F();
    if (object)
        object->R();
    object = p;
    return this;
}