#include "decls/data/game/hulkfight.h"
// data: gCounter_362f0 = DAT_004dc2a8

class Obj_362f0 {
    char pad0[0x398];

  public:
    unsigned char flag;
    char pad1[3];
    int mode;
    char pad2[0x1d4c - 0x3a0];
    unsigned char enabled;
    void Update();
};
void Obj_362f0::Update() {
    if (enabled) {
        int n = ++(*(int*)&DAT_004dc2a8);
        flag = (n % 2 == 0);
        if (n % 3 == 1)
            mode = 0;
        else
            mode = (n % 3 != 2) + 1;
    }
}