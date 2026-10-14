extern "C" char DAT_00433cac[];
class Obj_32ef10 {
  public:
    virtual void A();
    virtual void B();
};
class Tail_32ef10 {
  public:
    void Go();
};
class Target_32ef10 {
  public:
    virtual void A();
    char pad[0x7c];
    Obj_32ef10* a;
    Obj_32ef10* b;
    void F();
};
void Target_32ef10::F() {
    Obj_32ef10* x = a;
    *(int*)this = ((int)DAT_00433cac);
    if (x)
        x->B();
    Obj_32ef10* y = b;
    if (y)
        y->B();
    ((Tail_32ef10*)this)->Go();
}