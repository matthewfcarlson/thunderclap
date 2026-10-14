// Same code shape as 0x00236ec0 (propagated; names are from that function)
class Ref_239e10 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void Release(int);
};
class Holder_239e10 {
  public:
    Ref_239e10* p;
    void Clear();
};
void Holder_239e10::Clear() {
    if (p)
        p->Release(1);
    p = 0;
}