#include "gen/owners.h"
struct Args_caea0 {
    int a, b, c;
};
class Inner_caea0 {
  public:
    void B(Args_caea0);
};
class Obj_caea0 {
  public:
    char pad[0x88];
    Inner_caea0* m;
    void Run(Args_caea0 x);
};
void Obj_caea0::Run(Args_caea0 x) {
    if (m) {
        ((owners::Target_c7ad0 *)m)->FUN_000c7ad0();
        m->B(x);
    }
}