#include "gen/owners.h"
class Inner_89820 {
  public:
};
class Outer_89820 {
  public:
    char pad[0xa8];
    Inner_89820 inner;
    void Forward(int);
};
void Outer_89820::Forward(int a0) {
    ((owners::Obj_88fe0 *)&inner)->FUN_00088fe0((unsigned int)a0);
}
