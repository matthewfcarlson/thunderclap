extern "C" char DAT_0041916c[];
typedef unsigned int uint;
void* __cdecl Alloc(uint);
struct Base_18c540 {
    void Init(int);
};
struct Sub_18c540 {
    void Setup();
};
class ConditionFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
void* ConditionFactoryTemplate::vfunc_5() {
    Base_18c540* p = (Base_18c540*)Alloc(0x20);
    if (p) {
        p->Init(0);
        *(uint*)p = ((int)DAT_0041916c);
        ((uint*)p)[3] = 0xffffffff;
        ((uint*)p)[4] = 0;
        ((Sub_18c540*)((char*)p + 0x18))->Setup();
        return p;
    }
    return (void*)0;
}