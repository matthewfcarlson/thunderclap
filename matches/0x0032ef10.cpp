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
    *(int*)this = 0x433cac;
    if (x)
        x->B();
    Obj* y = b;
    if (y)
        y->B();
    ((Tail*)this)->Go();
}