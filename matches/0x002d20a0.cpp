class Base_2d20a0 {
  public:
    virtual void BV();
    Base_2d20a0();
};
class Sub_2d20a0 {
  public:
    char d[8];
    void Init(const void*);
};
class ParticleGenerator : public Base_2d20a0 {
  public:
    virtual void V();
    char pad[4];
    Sub_2d20a0 sub;
    char b;
    int a14, a18, a1c, a20;
    ParticleGenerator(const void* p);
};
ParticleGenerator::ParticleGenerator(const void* p) : Base_2d20a0() {
    b = *((const char*)p + 0x10);
    a14 = *(const int*)((const char*)p + 0x14);
    a18 = *(const int*)((const char*)p + 0x18);
    a1c = *(const int*)((const char*)p + 0x1c);
    a20 = *(const int*)((const char*)p + 0x20);
    sub.Init((const char*)p + 8);
}
