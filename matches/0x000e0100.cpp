#include "decls/data/game/hulkfight.h"
// data: negativeOne = DAT_003f3388

class Obj {
  public:
    char pad[0x3c];
    float a;
    char pad2[4];
    float b;
    char pad3[8];
    unsigned char flag;
    void update();
};
void Obj::update() {
    if (a > DAT_003f3388 && b > DAT_003f3388) {
        flag = a <= b ? 1 : 0;
    }
}