// Same code shape as 0x00113f80 (propagated; names are from that function)
extern void* __cdecl Alloc(unsigned int);
class Condition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void Init(int);
    int x;
    int y;
    int z;
    int w;
    int q;
};
extern int AIHistoryNameCondition_vftable;
class Factory_1328a0 {
  public:
    void* vfunc_5();
};
void* Factory_1328a0::vfunc_5() {
    Condition* p = (Condition*)Alloc(0x18);
    void* result;
    if (p) {
        p->Init(0);
        *(int**)p = &AIHistoryNameCondition_vftable;
        p->z = 0;
        p->w = 0;
        p->q = 0;
        result = p;
    } else
        result = 0;
    return result;
}