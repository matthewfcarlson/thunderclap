#include "gen/owners.h"
class Obj2_221f70 {
  public:
    char pad[0x40];
    void callee1(int, int);
};
void owners::Obj_221f70::FUN_00221f70(hulk_intptr a, hulk_intptr b) {
    switch (state) {
    case 0:
    case 2:
        return callee2(((int)a), ((int)b));
    case 1:
        return ((Obj2_221f70*)((char*)this + 0x40))->callee1(((int)a), ((int)b));
    }
}
