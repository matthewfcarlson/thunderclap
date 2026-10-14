void* operator new(unsigned n) throw();
class A_2c25b0 {
  public:
    A_2c25b0() throw();
    char p[0xa4];
};
class B_2c25b0 {
  public:
    B_2c25b0() throw();
    char p[4];
};
class Base_2c25b0 {
  public:
    Base_2c25b0() {
        m4 = 0;
        m8 = 0x19000;
        mc = 0;
        m10 = 0;
    }
    virtual void f0();
    int m4, m8, mc, m10;
};
class TextureLoader : public Base_2c25b0 {
  public:
    TextureLoader();
    virtual void f0();
    A_2c25b0* m14;
    B_2c25b0* m18;
};
TextureLoader::TextureLoader() {
    m14 = new A_2c25b0;
    m18 = new B_2c25b0;
}
