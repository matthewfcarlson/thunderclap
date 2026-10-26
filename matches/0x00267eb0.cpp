#include "decls/data/engine/core.h"
// data: gValue_267eb0 = DAT_004cdbb0

void __cdecl Init();
class Object {
  public:
    virtual ~Object();
    int field;
    Object();
};
Object::Object() {
    field = DAT_004cdbb0;
    Init();
}