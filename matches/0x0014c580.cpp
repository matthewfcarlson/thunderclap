class Base {
  public:
    virtual void F0();
    char pad[8];
};
class D : public Base {
  public:
    virtual void F1();
    int mVal;
    bool Set(int v);
};
bool D::Set(int v) {
    mVal = v;
    return true;
}
