extern "C" char DAT_004288fc[];
typedef unsigned int u32_23cae0;
void* operator_new(unsigned int);
class Condition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    void Init(int);
};
struct Tail_23cae0 {
    void InitTail();
};
class Factory_23cae0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Condition* v5();
};
Condition* Factory_23cae0::v5() {
    Condition* p = (Condition*)operator_new(0x10);
    if (p) {
        p->Init(0);
        *(u32_23cae0*)p = ((int)DAT_004288fc);
        ((Tail_23cae0*)((char*)p + 12))->InitTail();
        return p;
    }
    return 0;
}