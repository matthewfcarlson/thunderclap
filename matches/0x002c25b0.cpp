void* operator new(unsigned n) throw();
class A {
  public:
    A() throw();
    char p[0xa4];
};
class B {
  public:
    B() throw();
    char p[4];
};
class Base {
  public:
    Base() {
        m4 = 0;
        m8 = 0x19000;
        mc = 0;
        m10 = 0;
    }
    virtual void f0();
    int m4, m8, mc, m10;
};
class TextureLoader : public Base {
  public:
    TextureLoader();
    virtual void f0();
    A* m14;
    B* m18;
};
TextureLoader::TextureLoader() {
    m14 = new A;
    m18 = new B;
}
