#include "compat/ptr.h"
extern "C" char DAT_0042c180[];
class Entity {
  public:
    hulk_intptr vptr;
    int a;
    int b;
    int c;
    Entity();
};
Entity::Entity() {
    a = 0;
    vptr = ((hulk_intptr)DAT_0042c180);
    b = 0;
    c = 0;
}