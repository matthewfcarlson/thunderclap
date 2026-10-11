namespace physics {
class Base {
  public:
    Base();
    virtual void V();
};
class SimpleFilterAbs3D : public Base {
  public:
    SimpleFilterAbs3D();
    virtual void V();
};
void SimpleFilterAbs3D::V() {}
SimpleFilterAbs3D::SimpleFilterAbs3D() {}
} // namespace physics
