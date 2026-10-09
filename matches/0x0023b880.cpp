// Same code shape as 0x000af0d0 (propagated; names are from that function)
extern void* gameVtable;
extern void* refVtable;
struct Obj {
    void** vf;
    char pad[4];
    struct Ref* p;
};
struct Ref {
    virtual void a();
    virtual void b();
};
void __fastcall target(Obj* self) {
    self->p;
    self->vf = (void**)&gameVtable;
    self->p->b();
    self->vf = (void**)&refVtable;
}
