#include "compat/ptr.h"
int DAT_005554a4;
extern "C" hulk_intptr __cdecl FUN_0008d690(hulk_intptr);
extern "C" int __stdcall MakeArg(int);
struct d3dDevice_31ba60 {
    int Init(int);
};
int Target(int a, int b, int* out) {
    if (a == 0x12 && b == 0xb) {
        int value = DAT_005554a4;
        if (!value) {
            d3dDevice_31ba60* p = (d3dDevice_31ba60*)FUN_0008d690(0x14);
            if (p)
                value = p->Init(MakeArg(0));
            else
                value = 0;
            DAT_005554a4 = value;
        }
        *out = value;
        return 1;
    }
    *out = 0;
    return 100;
}