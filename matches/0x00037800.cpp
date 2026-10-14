// Same code shape as 0x00037750 (propagated; names are from that function)
class Obj_37800 {
  public:
    virtual void f0();
    virtual void f1();
};
class Holder_37800 {
  public:
    Obj_37800* a;
    Obj_37800* b;
    void Clear();
};
void Holder_37800::Clear() {
    if (b) {
        b->f1();
        b = 0;
    }
    if (a) {
        a->f1();
        a = 0;
    }
}