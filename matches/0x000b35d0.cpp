// Same code shape as 0x000af0d0 (propagated; names are from that function)
extern void* gameVtable;
extern void* refVtable_b35d0;
struct Obj_b35d0 {
    void** vf;
    char pad[4];
    struct Ref_b35d0* p;
};
struct Ref_b35d0 {
    virtual void a();
    virtual void b();
};
void __fastcall target(Obj_b35d0* self) {
    self->p;
    self->vf = (void**)&gameVtable;
    self->p->b();
    self->vf = (void**)&refVtable_b35d0;
}
