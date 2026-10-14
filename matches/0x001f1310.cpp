class B_1f1310 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
};
class Aux_1f1310 {
  public:
    void f();
};
extern void done(void*);
class C_1f1310 {
  public:
    void* a;
    B_1f1310* b;
};
void __fastcall target(C_1f1310* self) {
    void* p = self->a;
    if (p) {
        ((Aux_1f1310*)((char*)p + 0xa0))->f();
        done(p);
        self->a = 0;
    }
    if (self->b) {
        self->b->f2(1);
        self->b = 0;
    }
}