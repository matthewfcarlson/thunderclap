struct Obj_12db50 {
    virtual void F();
    virtual void R();
};
extern int PostEvent_StringAction_vftable;
struct PostEvent_StringAction {
    void* vf;
    int pad[6];
    int arg;
    Obj_12db50* object;
    void Init();
    PostEvent_StringAction* Build(int, Obj_12db50*);
};
PostEvent_StringAction* PostEvent_StringAction::Build(int a, Obj_12db50* p) {
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