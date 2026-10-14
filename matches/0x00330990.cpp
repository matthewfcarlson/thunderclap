struct Obj_330990 {
    virtual void f();
    virtual void release();
};
struct Base_330990 {
    void destroy();
};
struct Toon {
    void* vptr;
    char pad[0x90];
    Obj_330990* b;
    Obj_330990* a;
};
extern int toonVtable;
void __fastcall target(Toon* self) {
    self->vptr = &toonVtable;
    if (self->a)
        self->a->release();
    if (self->b)
        self->b->release();
    ((Base_330990*)self)->destroy();
}
