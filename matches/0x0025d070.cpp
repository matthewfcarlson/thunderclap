// FUN_0025d070 @ 0x0025d070
// 0x0025d070: claim the global slot for obj, reporting the current owner state through the out parameters
#include "decls/data/platform/xbox/unknown.h"

struct Slot_25d070 {
    char pad00[4];
    unsigned int limit;
    int field_08;
    int current;
    void* owner;
};

struct Obj_25d070 {
    char pad00[0x14];
    int link;
    int claimed;
};

int __cdecl FUN_0024c2f0(int* link);
unsigned int __cdecl FUN_0026fd80(unsigned int a, int b);

bool FUN_0025d070(Obj_25d070* obj, int arg2, unsigned int arg3, int unused, int* out5, int* out6, unsigned int* out7)
{
    if ((*(Slot_25d070**)&DAT_004e5ce0)->owner != 0)
        return false;
    *out5 = (*(Slot_25d070**)&DAT_004e5ce0)->current;
    *out6 = 1;
    if (arg3 > (*(Slot_25d070**)&DAT_004e5ce0)->limit)
        *out7 = FUN_0026fd80((*(Slot_25d070**)&DAT_004e5ce0)->limit, FUN_0024c2f0(&obj->link));
    else
        *out7 = arg3;
    (*(Slot_25d070**)&DAT_004e5ce0)->field_08 = arg2;
    obj->claimed = 1;
    (*(Slot_25d070**)&DAT_004e5ce0)->owner = obj;
    return true;
}
