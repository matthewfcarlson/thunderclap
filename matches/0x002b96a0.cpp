class Base {
  public:
    Base();
    virtual void A();
};
class BillboardQuadGroupLoader : public Base {
  public:
    BillboardQuadGroupLoader();
    virtual void A();
};
BillboardQuadGroupLoader::BillboardQuadGroupLoader() : Base() {}