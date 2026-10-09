// Same code shape as 0x000f2560 (propagated; names are from that function)
struct Result {
  public:
    virtual void method0();
};

struct Obj {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Result* cast(void* caster, __int64 val);
};

extern Obj* g_dat;

__int64 __cdecl fun_p2(int p);

struct DynamicCaster {
  public:
    virtual void f0();
};

struct Base {
    virtual void bv();
    int a;
    int b;
    Base(int x, int y);
};

struct FEShaderAnimation : Base {
    Result* m_c;
    FEShaderAnimation(int p1, int p2);
};

FEShaderAnimation::FEShaderAnimation(int p1, int p2) : Base(p1, p2) {
    Obj* obj = g_dat;
    __int64 v = fun_p2(p2);
    m_c = obj->cast(&DynamicCaster(), v);
    if (m_c) {
        m_c->method0();
    }
}
