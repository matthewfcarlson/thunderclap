typedef unsigned int size_t;
void* operator new(size_t);
class Anim {
  public:
    Anim() throw();
    virtual void Init();
    char pad[0x48];
};
class Base {
  public:
    virtual void Other();
    int a;
    void* b;
    int c, d;
    Base() : a(0), b((void*)0x121000), c(0), d(0) {}
};
class Loader : public Base {
  public:
    Loader();
    virtual void Dummy();
    Anim* anim;
    int e, f, g;
};
Loader::Loader() : anim(0), e(0), f(-1), g(0) {
    anim = new Anim;
    anim->Init();
}
