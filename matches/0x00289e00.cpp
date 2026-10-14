typedef unsigned int size_t;
void* operator new(size_t);
class Anim_289e00 {
  public:
    Anim_289e00() throw();
    virtual void Init();
    char pad[0x48];
};
class Base_289e00 {
  public:
    virtual void Other();
    int a;
    void* b;
    int c, d;
    Base_289e00() : a(0), b((void*)0x121000), c(0), d(0) {}
};
class Loader_289e00 : public Base_289e00 {
  public:
    Loader_289e00();
    virtual void Dummy();
    Anim_289e00* anim;
    int e, f, g;
};
Loader_289e00::Loader_289e00() : anim(0), e(0), f(-1), g(0) {
    anim = new Anim_289e00;
    anim->Init();
}
