// Same code shape as 0x00014860 (propagated; names are from that function)
class B_14940;
class C_14940;
class A_14940 {
  public:
    B_14940* f();
};
class B_14940 {
  public:
    C_14940* f();
};
class C_14940 {
  public:
    bool f(void*);
};
class Obj_14940 {
  public:
    char pad[0x1c];
    A_14940* a;
    char pad2[4];
    void* b;
};
bool __fastcall target(Obj_14940* self) {
    B_14940* x = self->a->f();
    C_14940* y = x->f();
    if (!y)
        return true;
    return y->f(self->b);
}