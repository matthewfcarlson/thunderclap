extern "C" char DAT_003f6098[];
extern "C" char DAT_0042c588[];
class Ref_2847f0 {
  public:
    virtual void A();
    virtual void B();
};
struct Obj_2847f0 {
    void** v;
    char pad4[4];
    Ref_2847f0* m;
    char pad[0x1c];
    void* p28;
};
void cleanup(void*);
void __fastcall target(volatile Obj_2847f0* self) {
    self->v = (void**)((int)DAT_0042c588);
    Ref_2847f0* r = self->m;
    if (r) {
        r->B();
        self->m = 0;
    }
    cleanup(self->p28);
    self->v = (void**)((int)DAT_003f6098);
}
