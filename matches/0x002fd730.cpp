#include "gen/owners.h"
struct Temp {
    unsigned int FUN_0030f100();
};
extern "C" void * __fastcall FUN_0030edf0(void *);
void __cdecl FUN_002ef760(void* output, unsigned int result, float scale, unsigned int value, void* data);
void owners::Obj_2fd730::FUN_002fd730() {
    if (!flag) {
        flag = 1;
        FUN_002ef760(output, ((Temp *)FUN_0030edf0(context))->FUN_0030f100(), 1.0f, value, data);
    }
}