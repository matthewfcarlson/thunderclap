#include "decls/data/records.h"

class Item_266f20 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void h();
    virtual int g(void*);
};
extern "C" int FUN_00266f20(int index, void* value) {
    return ((Item_266f20*)DAT_00527c60[index].allocator)->g(value);
}
