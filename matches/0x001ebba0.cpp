#include "decls/data/game/global.h"

class C_1ebba0 {
  public:
    C_1ebba0* Set(int x, int y);
    int a;
    int b;
};
C_1ebba0* C_1ebba0::Set(int x, int y) {
    (*(C_1ebba0**)&DAT_004e36dc) = this;
    a = x;
    b = y;
    return this;
}
