class Base_2bdee0 {
  public:
    Base_2bdee0(int);
    virtual void V();
};
class SpriteObject : public Base_2bdee0 {
  public:
    SpriteObject();
    virtual void V();
};
SpriteObject::SpriteObject() : Base_2bdee0(1) {}
