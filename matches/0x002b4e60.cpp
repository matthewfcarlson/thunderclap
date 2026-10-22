#include "compat/ptr.h"
void* __cdecl alloc(hulk_uintptr);
class ShadowMeshBuffer_2b4e60 {
  public:
    ShadowMeshBuffer_2b4e60* Init(int) throw();
};
class ShadowMeshBufferLoader {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual ShadowMeshBuffer_2b4e60* vfunc_6(int);
};
ShadowMeshBuffer_2b4e60* ShadowMeshBufferLoader::vfunc_6(int x) {
    ShadowMeshBuffer_2b4e60* p = (ShadowMeshBuffer_2b4e60*)alloc(0x58);
    if (p)
        return p->Init(x);
    return 0;
}
