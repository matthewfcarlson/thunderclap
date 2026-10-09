// Same code shape as 0x0012db50 (propagated; names are from that function)
struct Obj {
    virtual void F();
    virtual void R();
};
extern int PostEvent_StringAction_vftable;
struct PostEvent_StringAction {
    void* vf;
    int pad[6];
    int arg;
    Obj* object;
    void Init();
    PostEvent_StringAction* Build(int, Obj*);
};
PostEvent_StringAction* PostEvent_StringAction::Build(int a, Obj* p) {
    Init();
    vf = &PostEvent_StringAction_vftable;
    object = 0;
    arg = a;
    if (p)
        p->F();
    if (object)
        object->R();
    object = p;
    return this;
}