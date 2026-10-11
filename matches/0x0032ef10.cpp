extern "C" char DAT_00433cac[];
class Obj {
  public:
    virtual void A();
    virtual void B();
};
class Tail {
  public:
    void Go();
};
class Target {
  public:
    virtual void A();
    char pad[0x7c];
    Obj* a;
    Obj* b;
    void F();
};
void Target::F() {
    Obj* x = a;
    *(int*)this = ((int)DAT_00433cac);
    if (x)
        x->B();
    Obj* y = b;
    if (y)
        y->B();
    ((Tail*)this)->Go();
}