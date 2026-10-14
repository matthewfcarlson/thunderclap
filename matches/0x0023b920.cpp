// Same code shape as 0x000af0d0 (propagated; names are from that function)
extern void* gameVtable;
extern void* refVtable_23b920;
struct Obj_23b920 {
    void** vf;
    char pad[4];
    struct Ref_23b920* p;
};
struct Ref_23b920 {
    virtual void a();
    virtual void b();
};
void __fastcall target(Obj_23b920* self) {
    self->p;
    self->vf = (void**)&gameVtable;
    self->p->b();
    self->vf = (void**)&refVtable_23b920;
}
