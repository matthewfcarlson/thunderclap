// Same code shape as 0x000f2560 (propagated; names are from that function)
#include "decls/data/game/global.h"
// data: g_dat_f26e0 = DAT_004dd9cc

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


__int64 __cdecl fun_p2(int p);

struct DynamicCaster {
  public:
    virtual void f0();
};

struct FEAnimation_f26e0 {
    virtual void bv();
    int a;
    int b;
    FEAnimation_f26e0(int x, int y);
};

struct FETextureAnimation_f26e0 : FEAnimation_f26e0 {
    Result_f26e0* m_c;
    FETextureAnimation_f26e0(int p1, int p2);
};

FETextureAnimation_f26e0::FETextureAnimation_f26e0(int p1, int p2) : FEAnimation_f26e0(p1, p2) {
    Obj_f26e0* obj = (*(Obj_f26e0**)&DAT_004dd9cc);
    __int64 v = fun_p2(p2);
    m_c = obj->cast(&DynamicCaster(), v);
    if (m_c) {
        m_c->method0();
    }
}
