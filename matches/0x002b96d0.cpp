// Base_2b96d0's constructor is FUN_002a3e80 (RenderObjectLoader's, thiscall): declared, not defined here, so the call
// passes this in ecx (a free `void BaseInit()` byte-matched only because ecx still held this)
class Base_2b96d0 {
  public:
    Base_2b96d0();
    virtual void F();
    int x;
};
class OldBillboardQuadGroupLoader : public Base_2b96d0 {
  public:
    OldBillboardQuadGroupLoader();
    virtual void F();
};
OldBillboardQuadGroupLoader::OldBillboardQuadGroupLoader() : Base_2b96d0() {}
