class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class A {
  public:
    A();
    char pad[8];
};
class B {
  public:
    B();
    char pad[12];
};
struct Triple {
    int u, v, w;
    Triple() : u(0), v(0), w(0) {}
};
class CGrabTrack : public Base {
  public:
    CGrabTrack();
    virtual void f();
    int x;
    float y;
    char pad0[4];
    A a;
    Triple triple;
    float z;
    int t;
    char flag;
    char pad1[3];
    B b, c;
};
CGrabTrack::CGrabTrack() : Base(), x(0), y(-1.0f), a(), triple(), z(0.25f), t(0), flag(0), b(), c() {
    *(int*)((char*)this + 8) = 1;
}