class Base_14c580 {
  public:
    virtual void F0();
    char pad[8];
};
class D : public Base_14c580 {
  public:
    virtual void F1();
    int mVal;
    bool Set(int v);
};
bool D::Set(int v) {
    mVal = v;
    return true;
}
