extern "C" char DAT_0042d1ec[];
typedef unsigned int u32;
class Base {
  public:
    u32 vf;
    char pad[4];
    void Init();
};
class Child {
  public:
    void Copy(void*);
};
class Thing : public Base {
  public:
    char pad8[8];
    u32 a;
    u32 b;
    Thing* Run(void* src);
};
Thing* Thing::Run(void* src) {
    Init();
    vf = ((int)DAT_0042d1ec);
    a = ((u32*)src)[4];
    b = ((u32*)src)[5];
    ((Child*)((char*)this + 8))->Copy((char*)src + 8);
    return this;
}