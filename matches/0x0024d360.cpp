#include "compat/ptr.h"
extern "C" char DAT_00429394[];
class EntityLoader {
  public:
    void* vtable;
    int a;
    void* b;
    EntityLoader(void*);
};
EntityLoader::EntityLoader(void* p) {
    a = 0;
    vtable = (void*)((hulk_intptr)DAT_00429394);
    b = p;
}