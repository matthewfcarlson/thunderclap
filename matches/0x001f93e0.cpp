#include "gen/owners.h"
class Elem_1f93e0 {
  public:
    char Test(int, int, int, int, int, int, int, int, int, int);
};
int owners::Obj_1f93e0::FUN_001f93e0(hulk_intptr a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
    int r = -1;
    if (count < 16) {
        if (((Elem_1f93e0*)((char*)this + (count * 5 + 0x8c) * 8))->Test(((int)a), b, c, d, e, f, g, h, i, j)) {
            r = count;
            count = r + 1;
        }
    }
    return r;
}