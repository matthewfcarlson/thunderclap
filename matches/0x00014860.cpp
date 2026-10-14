class B_14860;
class C_14860;
class A_14860 {
  public:
    B_14860* f();
};
class B_14860 {
  public:
    C_14860* f();
};
class C_14860 {
  public:
    bool f(void*);
};
class Obj_14860 {
  public:
    char pad[0x1c];
    A_14860* a;
    char pad2[4];
    void* b;
};
bool __fastcall target(Obj_14860* self) {
    B_14860* x = self->a->f();
    C_14860* y = x->f();
    if (!y)
        return true;
    return y->f(self->b);
}