struct Result_f2560 {
  public:
    virtual void method0();
};

struct Obj_f2560 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Result_f2560* cast(void* caster, __int64 val);
};

extern Obj_f2560* g_dat_f2560;

__int64 __cdecl fun_p2(int p);

struct DynamicCaster {
  public:
    virtual void f0();
};

struct FEAnimation_f2560 {
    virtual void bv();
    int a;
    int b;
    FEAnimation_f2560(int x, int y);
};

struct FEShaderAnimation : FEAnimation_f2560 {
    Result_f2560* m_c;
    FEShaderAnimation(int p1, int p2);
};

FEShaderAnimation::FEShaderAnimation(int p1, int p2) : FEAnimation_f2560(p1, p2) {
    Obj_f2560* obj = g_dat_f2560;
    __int64 v = fun_p2(p2);
    m_c = obj->cast(&DynamicCaster(), v);
    if (m_c) {
        m_c->method0();
    }
}
