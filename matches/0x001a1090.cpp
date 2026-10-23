#include "gen/hulkfight.h"
typedef unsigned int u32_1a1090;
class TrackFactory_1a1090 {
  public:
    virtual void a();
    virtual void b();
};
class Entity_1a1090 {
  public:
    virtual void c();
    virtual void d();
    virtual void e();
};
class LoadObject_1a1090 {
  public:
    virtual void f();
    virtual void g();
};
class IRefCount_1a1090 {
  public:
    virtual void h();
};
extern void* __cdecl operator_new(unsigned int);
struct FireProjectileTrack_nv_1a1090 {
    u32_1a1090 init();
};
class Factory_1a1090 : public TrackFactory_1a1090, public Entity_1a1090, public LoadObject_1a1090, public IRefCount_1a1090 {
  public:
    virtual u32_1a1090 vfunc_5();
};
u32_1a1090 Factory_1a1090::vfunc_5() {
    hulkfight::motion::FireProjectileTrack* p = (hulkfight::motion::FireProjectileTrack*)operator_new(0xc0);
    if (p)
        return ((FireProjectileTrack_nv_1a1090*)(((hulkfight::motion::FireProjectileTrack*)(p))))->init();
    return 0;
}