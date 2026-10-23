#include "compat/ptr.h"
extern "C" float DAT_004c7df8;
static const float DAT_003f3358 = 0.01f;
extern void __cdecl FUN_00247890(int, float);
class Obj_1f39d0 {
  public:
    char p0[8];
    int* items[1];
    char p1[0x88 - 0x0c];
    int count;
    int at8c;
    char p2[0xc0 - 0x90];
    int skip;
    char p3[0x32c - 0xc4];
    int flag;
    void Update(float);
};
void Obj_1f39d0::Update(float x) {
    DAT_004c7df8 = x;
    if (flag == 0) {
        int i = 0;
        if (count > 0) {
            int* p = (int*)((char*)this + 8);
            do {
                hulk_intptr v = *p;
                if (v != at8c && v != skip) {
                    int q = *(int*)(v + 4);
                    if (q)
                        FUN_00247890(q, DAT_004c7df8 * DAT_003f3358);
                }
                ++i;
                ++p;
            } while (i < count);
        }
    }
}