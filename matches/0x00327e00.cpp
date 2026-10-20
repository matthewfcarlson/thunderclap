extern int gCounter_327e00;
class Base_327e00 {
  public:
    Base_327e00();
    virtual void f();
};
class pddiBaseShader_327e00 : public Base_327e00 {
  public:
    pddiBaseShader_327e00();
    int pad[2];
    int id;
};
pddiBaseShader_327e00::pddiBaseShader_327e00() {
    id = gCounter_327e00++;
}
