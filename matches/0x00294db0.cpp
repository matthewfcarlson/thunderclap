namespace pure3d {
class Base {
  public:
    Base();
    virtual void V();
};
class Font : public Base {
  public:
    Font();
    virtual void V();
};
void Font::V() {}
Font::Font() {}
} // namespace pure3d
