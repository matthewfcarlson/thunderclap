extern void* gameVtable;
extern void* refVtable_af0d0;
struct Obj_af0d0 {
    void** vf;
    char pad[4];
    struct Ref_af0d0* p;
};
struct Ref_af0d0 {
    virtual void a();
    virtual void b();
};
void __fastcall target(Obj_af0d0* self) {
    self->p;
    self->vf = (void**)&gameVtable;
    self->p->b();
    self->vf = (void**)&refVtable_af0d0;
}
