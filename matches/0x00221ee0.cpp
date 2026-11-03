#include "gen/owners.h"
class Inner_221ee0 {
  public:
    char pad[0x10];
};
class Obj_221ee0 {
  public:
    void Run();
    void Other();
    char pad0[0x40];
    Inner_221ee0 inner;
    int state;
};
void Obj_221ee0::Run() {
    switch (state) {
    case 0:
        ((owners::Vec4_22b120 *)&inner)->FUN_0022b120();
        state = 1;
        break;
    case 1:
        ((owners::Vec4_22b120 *)&inner)->FUN_0022b120();
        break;
    case 2:
        Other();
        break;
    }
}
