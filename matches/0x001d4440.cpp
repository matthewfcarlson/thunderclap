// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"
class CAction_1d4440 {
  public:
    virtual void a();
    virtual void b();
    virtual CAction_1d4440* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class ScriptHandler_1d4440 : public CAction_1d4440 {
  public:
    ScriptHandler_1d4440* vfunc_2(unsigned char);
};
struct ScriptHandler_nv_1d4440 {
    void FUN_001d3410();
};
extern void thunk_FUN_00267090(ScriptHandler_1d4440*);
ScriptHandler_1d4440* ScriptHandler_1d4440::vfunc_2(unsigned char flags) {
    ((ScriptHandler_nv_1d4440*)(((ScriptHandler*)(this))))->FUN_001d3410();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}