// Same code shape as 0x000af0d0 (propagated; names are from that function)
extern void* gameVtable;
extern void* refVtable_23a440;
struct Obj_23a440 {
    void** vf;
    char pad[4];
    struct Ref_23a440* p;
};
struct Ref_23a440 {
    virtual void a();
    virtual void b();
};
void __fastcall target(Obj_23a440* self) {
    self->p;
    self->vf = (void**)&gameVtable;
    self->p->b();
    self->vf = (void**)&refVtable_23a440;
}
