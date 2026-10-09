class Base {
  public:
    Base();
    int x;
};
Base::Base() {
    extern void BaseInit();
    BaseInit();
}
class OldBillboardQuadGroupLoader : public Base {
  public:
    OldBillboardQuadGroupLoader();
    virtual void F();
};
OldBillboardQuadGroupLoader::OldBillboardQuadGroupLoader() : Base() {}