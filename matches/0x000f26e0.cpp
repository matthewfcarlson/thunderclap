// Same code shape as 0x000f2560 (propagated; names are from that function)
struct Result_f26e0 {
  public:
    virtual void method0();
};

struct Obj_f26e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Result_f26e0* cast(void* caster, __int64 val);
};

extern Obj_f26e0* g_dat_f26e0;

__int64 __cdecl fun_p2(int p);

struct DynamicCaster {
  public:
    virtual void f0();
};

struct Base_f26e0 {
    virtual void bv();
    int a;
    int b;
    Base_f26e0(int x, int y);
};

struct FEShaderAnimation : Base_f26e0 {
    Result_f26e0* m_c;
    FEShaderAnimation(int p1, int p2);
};

FEShaderAnimation::FEShaderAnimation(int p1, int p2) : Base_f26e0(p1, p2) {
    Obj_f26e0* obj = g_dat_f26e0;
    __int64 v = fun_p2(p2);
    m_c = obj->cast(&DynamicCaster(), v);
    if (m_c) {
        m_c->method0();
    }
}
