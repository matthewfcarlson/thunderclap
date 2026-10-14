struct H1 {
    void* f();
};
struct H2_147d0 {
    void* f();
};
struct H3_147d0 {
    char p[0x64];
    void* q;
};
struct H4 {
    char p[0x1c];
    void* z;
};
struct Helper_147d0 {
    char p[0x1c];
    void f(void*, void*);
};
class COpportunityBallAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(int);
    virtual void v7();
    virtual void v8();
    char pad[0x18];
    void* mA;
    void* mB;
    int index;
    int output;
};
struct V {
    int a, b, c;
};
struct B_147d0 {
    char p[0x20];
    V v;
};
bool COpportunityBallAction::vfunc_6(int arg) {
    void* a = ((H1*)mA)->f();
    a = ((H2_147d0*)a)->f();
    V local = ((B_147d0*)mB)->v;
    void* x = ((H3_147d0*)a)->q;
    void* base = ((H4*)x)->z;
    ((Helper_147d0*)((char*)base + (index << 6)))->f(&local, &output);
    return true;
}
