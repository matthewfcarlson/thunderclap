class Obj_37750 {
  public:
    virtual void f0();
    virtual void f1();
};
class Holder_37750 {
  public:
    Obj_37750* a;
    Obj_37750* b;
    void Clear();
};
void Holder_37750::Clear() {
    if (b) {
        b->f1();
        b = 0;
    }
    if (a) {
        a->f1();
        a = 0;
    }
}