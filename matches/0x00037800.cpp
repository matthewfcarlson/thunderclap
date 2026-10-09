// Same code shape as 0x00037750 (propagated; names are from that function)
class Obj {
  public:
    virtual void f0();
    virtual void f1();
};
class Holder {
  public:
    Obj* a;
    Obj* b;
    void Clear();
};
void Holder::Clear() {
    if (b) {
        b->f1();
        b = 0;
    }
    if (a) {
        a->f1();
        a = 0;
    }
}