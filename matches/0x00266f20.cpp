#include "decls/data/engine/content.h"
// data: gItems_266f20 = DAT_00527c60

class Item_266f20 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void h();
    virtual int g(int);
};
struct Entry_266f20 {
    Item_266f20* ptr;
    char pad[12];
};
int target(int index, int value) {
    return ((Entry_266f20*)((char*)&DAT_00527c58 + 8))[index].ptr->g(value);
}