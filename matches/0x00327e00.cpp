extern int gCounter;
class Base {
  public:
    Base();
    virtual void f();
};
class Shader : public Base {
  public:
    Shader();
    int pad[2];
    int id;
};
Shader::Shader() {
    id = gCounter++;
}
