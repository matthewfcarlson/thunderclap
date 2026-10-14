extern "C" char DAT_0042d1ec[];
typedef unsigned int u32_295c70;
class Base_295c70 {
  public:
    u32_295c70 vf;
    char pad[4];
    void Init();
};
class Child_295c70 {
  public:
    void Copy(void*);
};
class Thing_295c70 : public Base_295c70 {
  public:
    char pad8[8];
    u32_295c70 a;
    u32_295c70 b;
    Thing_295c70* Run(void* src);
};
Thing_295c70* Thing_295c70::Run(void* src) {
    Init();
    vf = ((int)DAT_0042d1ec);
    a = ((u32_295c70*)src)[4];
    b = ((u32_295c70*)src)[5];
    ((Child_295c70*)((char*)this + 8))->Copy((char*)src + 8);
    return this;
}