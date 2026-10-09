typedef unsigned int u32;
void* __cdecl Allocate(unsigned int);
class Initializer {
  public:
    void Init(int);
};
class OffsetInitializer {
  public:
    void Init();
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* Create();
};
class Condition {
  public:
    u32 vf;
    char pad4[8];
    int x;
    int y;
    char pad14[4];
};
void* Factory::Create() {
    Condition* p = (Condition*)Allocate(0x20);
    if (p) {
        ((Initializer*)p)->Init(0);
        p->vf = 0x41d44c;
        p->x = 2;
        p->y = 0;
        ((OffsetInitializer*)((char*)p + 0x18))->Init();
        return p;
    }
    return 0;
}