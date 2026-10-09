class Base {
  public:
    Base(int);
    virtual void V();
};
class SpriteObject : public Base {
  public:
    SpriteObject();
    virtual void V();
};
SpriteObject::SpriteObject() : Base(1) {}
