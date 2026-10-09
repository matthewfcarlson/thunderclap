class Ref {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void Release(int);
};
class Holder {
  public:
    Ref* p;
    void Clear();
};
void Holder::Clear() {
    if (p)
        p->Release(1);
    p = 0;
}