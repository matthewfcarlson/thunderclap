class Ref {
  public:
    virtual void A();
    virtual void B();
};
struct Obj {
    void** v;
    char pad4[4];
    Ref* m;
    char pad[0x1c];
    void* p28;
};
void cleanup(void*);
void __fastcall target(volatile Obj* self) {
    self->v = (void**)0x42c588;
    Ref* r = self->m;
    if (r) {
        r->B();
        self->m = 0;
    }
    cleanup(self->p28);
    self->v = (void**)0x3f6098;
}
