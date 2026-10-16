#include "decls/data/platform/xbox/unknown.h"

extern "C" int __stdcall FUN_0020e1a1(int, int, int);
extern "C" int __stdcall FUN_0020d7ff(int, int, int);
struct Global_240c20 {
    char pad[0x28];
    int field28;
    char pad2[4];
    int field30;
};
int __cdecl target(int param) {
    int result = FUN_0020e1a1((*(Global_240c20**)&DAT_004e5ce0)->field28, 0, param);
    if (result) {
        int value = FUN_0020d7ff((*(Global_240c20**)&DAT_004e5ce0)->field28, 0, result);
        (*(Global_240c20**)&DAT_004e5ce0)->field30 += value;
    }
    return result;
}