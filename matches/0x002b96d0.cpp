class Base_2b96d0 {
  public:
    Base_2b96d0();
    int x;
};
Base_2b96d0::Base_2b96d0() {
    extern void BaseInit();
    BaseInit();
}
class OldBillboardQuadGroupLoader : public Base_2b96d0 {
  public:
    OldBillboardQuadGroupLoader();
    virtual void F();
};
OldBillboardQuadGroupLoader::OldBillboardQuadGroupLoader() : Base_2b96d0() {}