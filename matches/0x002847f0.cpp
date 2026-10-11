extern "C" char DAT_003f6098[];
extern "C" char DAT_0042c588[];
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
    self->v = (void**)((int)DAT_0042c588);
    Ref* r = self->m;
    if (r) {
        r->B();
        self->m = 0;
    }
    cleanup(self->p28);
    self->v = (void**)((int)DAT_003f6098);
}
