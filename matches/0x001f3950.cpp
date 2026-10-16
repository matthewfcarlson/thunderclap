#include "decls/data/game/global.h"

extern float gScale_1f3950;
void __cdecl Apply(int, float);
class Obj_1f3950 {
  public:
    char pad0[0xc0];
    int mPtr;
    char pad1[0x268];
    int mBusy;
    void Set(float value);
};
void Obj_1f3950::Set(float value) {
    *(volatile float*)((int)((char*)&DAT_004c7df0)) = value;
    if (mPtr != 0 && mBusy == 0) {
        int x = *(int*)(mPtr + 4);
        if (x != 0)
            Apply(x, value * 0.01f);
    }
}