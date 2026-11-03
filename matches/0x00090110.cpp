#include "gen/owners.h"
struct ThisCall_00090050 {
};
extern "C" int __fastcall FUN_00090110(void* self) {
    int i = ((owners::Table_90050 *)(((ThisCall_00090050*)(self))))->FUN_00090050((char *)"xp");
    if (i == -1)
        return 0;
    return *(int*)((char*)self + i * 0x40 + 0x38);
}