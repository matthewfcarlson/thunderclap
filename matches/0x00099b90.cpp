#include "gen/owners.h"
class Inner_99b90 {
  public:
};
class Obj_99b90 {
  public:
    char pad[0xb8];
    Inner_99b90* m;
    void Fn(int a);
};
void Obj_99b90::Fn(int a) {
    if (m)
        ((owners::Thing_a0c10 *)m)->FUN_000a0c10(a);
}
