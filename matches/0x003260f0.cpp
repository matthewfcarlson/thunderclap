class Base {
  public:
    Base();
    virtual void g();
};
class pddiTexture : public Base {
  public:
    pddiTexture();
    virtual void f();
};
pddiTexture::pddiTexture() : Base() {}