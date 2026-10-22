class DrawableContainer_2bdee0 {
  public:
    DrawableContainer_2bdee0(int);
    virtual void V();
};
class SpriteObject : public DrawableContainer_2bdee0 {
  public:
    SpriteObject();
    virtual void V();
};
SpriteObject::SpriteObject() : DrawableContainer_2bdee0(1) {}
