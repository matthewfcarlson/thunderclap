// STATUS: equivalent (tools/equiv.py level 3: 30022 inputs, branch coverage 28/32, incomplete)
// hulkfight::MissionProgressCondition::vfunc_6 @ 0x0012f670
#include "decls/address.h"
struct Names_12f670 {
    const char *FUN_0008a060(int id);
};

struct NameTable {
    Names_12f670 *FUN_00086310();
};

struct World {
    char pad00[0x54];
    NameTable *table;
};


static int StrCmp(const char *a, const char *b)
{
    while (*a == *b) {
        if (*a == 0)
            return 0;
        a++;
        b++;
    }
    return (unsigned char)*a < (unsigned char)*b ? -1 : 1;
}

namespace hulkfight {
class MissionProgressCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, int b, int c);
    char pad04[8];
    int id;
    int mode;
    const char *expected;
};
}

bool hulkfight::MissionProgressCondition::vfunc_6(int a, int b, int c)
{
    if (expected == 0 || id == 0)
        return false;
    const char *current = DAT_004dd700->table->FUN_00086310()->FUN_0008a060(id);
    switch (mode) {
    case 0:
        return StrCmp(current, expected) == 0;
    case 1:
        return StrCmp(current, expected) != 0;
    }
    return false;
}
