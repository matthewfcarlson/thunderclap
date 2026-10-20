// Same code shape as 0x0012db50 (propagated; names are from that function)
struct Obj_23f220 {
    virtual void F();
    virtual void R();
};
extern int BreakPointAction_23f220_vftable;
struct BreakPointAction_23f220 {
    void* vf;
    int pad[6];
    int arg;
    Obj_23f220* object;
    void Init();
    BreakPointAction_23f220* Build(int, Obj_23f220*);
};
BreakPointAction_23f220* BreakPointAction_23f220::Build(int a, Obj_23f220* p) {
    Init();
    vf = &BreakPointAction_23f220_vftable;
    object = 0;
    arg = a;
    if (p)
        p->F();
    if (object)
        object->R();
    object = p;
    return this;
}