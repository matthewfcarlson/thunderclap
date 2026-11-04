class Base_14c580 {
  public:
    virtual void F0();
    char pad[8];
};
class D : public Base_14c580 {
  public:
    virtual void F1();
    int mVal;
    bool SetCompare_0014c580(int v);
};
bool D::SetCompare_0014c580(int v) {
    mVal = v;
    return true;
}
