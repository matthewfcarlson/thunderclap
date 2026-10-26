#include "decls/data/game/global.h"

typedef unsigned char byte_19e8e0;
struct Alloc_19e8e0 {
    void f(void*, unsigned int);
};
namespace hulkfight { namespace motion { class ProjectileMissile {
  public:
    void tick();
    virtual void a();
    virtual void b();
    virtual ProjectileMissile* vfunc_2(byte_19e8e0);
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
}; }}
hulkfight::motion::ProjectileMissile* hulkfight::motion::ProjectileMissile::vfunc_2(byte_19e8e0 param_2) {
    tick();
    if (param_2 & 1)
        (*(Alloc_19e8e0*)&DAT_004e2210).f(this, 0xdc);
    return this;
}