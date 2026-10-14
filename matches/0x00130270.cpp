// Same code shape as 0x0012db50 (propagated; names are from that function)
struct Obj_130270 {
    virtual void F();
    virtual void R();
};
extern int PostEvent_StringAction_vftable;
struct PostEvent_StringAction {
    void* vf;
    int pad[6];
    int arg;
    Obj_130270* object;
    void Init();
    PostEvent_StringAction* Build(int, Obj_130270*);
};
PostEvent_StringAction* PostEvent_StringAction::Build(int a, Obj_130270* p) {
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