extern int gCounter_327e00;
class Base_327e00 {
  public:
    Base_327e00();
    virtual void f();
};
class Shader : public Base_327e00 {
  public:
    Shader();
    int pad[2];
    int id;
};
Shader::Shader() {
    id = gCounter_327e00++;
}
