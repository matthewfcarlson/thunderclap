extern "C" char DAT_0041d44c[];
typedef unsigned int u32_1ac930;
void* __cdecl Allocate(unsigned int);
class Initializer_1ac930 {
  public:
    void Init(int);
};
class OffsetInitializer {
  public:
    void Init();
};
class Factory_1ac930 {
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
    u32_1ac930 vf;
    char pad4[8];
    int x;
    int y;
    char pad14[4];
};
void* Factory_1ac930::Create() {
    Condition* p = (Condition*)Allocate(0x20);
    if (p) {
        ((Initializer_1ac930*)p)->Init(0);
        p->vf = ((int)DAT_0041d44c);
        p->x = 2;
        p->y = 0;
        ((OffsetInitializer*)((char*)p + 0x18))->Init();
        return p;
    }
    return 0;
}