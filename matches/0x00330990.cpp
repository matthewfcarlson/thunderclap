struct Obj {
    virtual void f();
    virtual void release();
};
struct Base {
    void destroy();
};
struct Toon {
    void* vptr;
    char pad[0x90];
    Obj* b;
    Obj* a;
};
extern int toonVtable;
void __fastcall target(Toon* self) {
    self->vptr = &toonVtable;
    if (self->a)
        self->a->release();
    if (self->b)
        self->b->release();
    ((Base*)self)->destroy();
}
