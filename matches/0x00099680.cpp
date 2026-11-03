#include "gen/owners.h"
class Sub {
  public:
};
class Owner {
    char pad[0x1e0];

  public:
    Sub sub;
};
class Obj {
    char pad[0xc4];
    Owner* m;

  public:
    void Fn(int a, int b);
};
void Obj::Fn(int a, int b) {
    ((owners::Target_ac780 *)&(m->sub))->FUN_000ac780(a);
    ((owners::Target_ac790 *)&(m->sub))->FUN_000ac790(b);
}