#include "compat/ptr.h"
class CSPHulkProp;
class DynamicCaster_46400 {
  public:
    DynamicCaster_46400() {}
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
class Loader {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int Load(DynamicCaster_46400*, int, int);
    hulk_intptr Go(int x, int y);
};
hulk_intptr Loader::Go(int x, int y) {
    DynamicCaster_46400 caster;
    return Load(&caster, x, y);
}
